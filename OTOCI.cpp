#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RollbackUF {
  vi e;
  vector<pii> st;
  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return sz(st); }
  void rollback(int t) {
    for (int i = time(); i-- > t;)
      e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

const int inf = 0;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, val = -inf;
  Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interva l of −in f

  int query(int L, int R) {
    if (R <= lo || hi <= L)
      return 0;
    if (L <= lo && hi <= R)
      return val;
    push();
    return l->query(L, R) + r->query(L, R);
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R) {
      val = x;
    } else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = l->val + r->val;
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
  }
};

template <bool VALS_EDGES> struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, depth, rt, pos;
  Node *tree;
  HLD(vector<vi> adj_)
      : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N), rt(N), pos(N),
        tree(new Node(0, N)) {
    dfsSz(0);
    dfsHld(0);
  }
  void dfsSz(int v) {
    if (par[v] != -1)                          // if parent is set
      adj[v].erase(find(all(adj[v]), par[v])); // remove it
    for (int &u : adj[v]) {                    // for each child
      par[u] = v, depth[u] = depth[v] + 1;
      dfsSz(u);         // recurse
      siz[v] += siz[u]; // update size
      if (siz[u] > siz[adj[v][0]])
        swap(u, adj[v][0]);
    }
  }
  void dfsHld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfsHld(u);
    }
  }
  template <class B> void process(int u, int v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]])
        swap(u, v);
      op(pos[rt[v]], pos[v] + 1);
    }
    if (depth[u] > depth[v])
      swap(u, v);
    op(pos[u] + VALS_EDGES, pos[v] + 1);
  }
  void modifyPath(int u, int v, int val) {
    process(u, v, [&](int l, int r) { tree->set(l, r, val); });
  }
  int queryPath(int u, int v) { // Modify depending on problem
    int res = 0;
    process(u, v, [&](int l, int r) { res += tree->query(l, r); });
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi penguins(n);
  for (auto &x : penguins) {
    cin >> x;
  }

  int q;
  cin >> q;

  vector<tuple<string, int, int>> queries(q);

  RollbackUF uf(n);
  vector<vi> adj(n);

  for (auto &[a, b, c] : queries) {
    cin >> a >> b >> c;

    if (a == "bridge" && uf.join(b - 1, c - 1)) {
      adj[b - 1].push_back(c - 1);
      adj[c - 1].push_back(b - 1);
    }
  }

  HLD<false> hld(adj);
  rep(i, 0, n) {
    hld.modifyPath(i, i, penguins[i]);
    // cout << hld.queryPath(i, i) << endl;
  }

  // cout << hld.queryPath(0, 1) << endl;
  // cout << hld.queryPath(1, 2) << endl;
  // cout << hld.queryPath(0, 2) << endl;

  uf = RollbackUF(n);

  for (auto &[s, a, b] : queries) {
    if (s == "excursion") {
      if (uf.find(a - 1) == uf.find(b - 1)) {
        cout << hld.queryPath(a - 1, b - 1) << '\n';
      } else {
        cout << "impossible\n";
      }
    } else if (s == "bridge") {
      if (uf.join(a - 1, b - 1)) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    } else if (s == "penguins") {
      hld.modifyPath(a - 1, a - 1, b);
    }
  }
}