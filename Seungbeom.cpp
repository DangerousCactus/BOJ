#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, mset = inf, madd = 0, val = -inf;
  Node(int lo, int hi) : lo(lo), hi(hi) {}  // Large interva l of −in f
  Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = max(l->val, r->val);
    } else
      val = v[lo];
  }
  int query(int L, int R) {
    if (R <= lo || hi <= L)
      return -inf;
    if (L <= lo && hi <= R)
      return val;
    push();
    return max(l->query(L, R), r->query(L, R));
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R)
      mset = val = x, madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void add(int L, int R, int x) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R) {
      if (mset != inf)
        mset += x;
      else
        madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int idx = 0;
  vi s(n), e(n);
  vector<vi> adj(n);

  {
    int x;
    cin >> x;
  }

  rep(i, 1, n) {
    int x;
    cin >> x;

    adj[i].push_back(x - 1);
    adj[x - 1].push_back(i);
  }

  // in the dfs:
  // set node index of current, on exit set node end

  function<void(int, int)> dfs = [&](int z, int p) {
    s[z] = idx++;

    for (auto& x : adj[z]) {
      if (x == p) {
        continue;
      }
      dfs(x, z);
    }

    e[z] = idx;
  };

  dfs(0, -1);

  Node tree(0, n);
  tree.set(0, n, 0);

  while (m--) {
    int x, z, w;
    cin >> x >> z;
    z--;

    if (x == 1) {
      cin >> w;
      tree.add(s[z], e[z], w);
    } else {
      cout << tree.query(s[z], s[z] + 1) << '\n';
    }
  }
}