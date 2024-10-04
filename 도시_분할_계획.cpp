#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  vi e;
  vector<pii> st;
  UF(int n) : e(n, -1) {}
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

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  UF uf(n);
  priority_queue<vi, vector<vi>, greater<>> pq;

  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;

    pq.push(vi{c, a - 1, b - 1});
  }

  int cost = 0;
  while (sz(pq)) {
    auto z = pq.top();
    pq.pop();

    int a = z[1], b = z[2], c = z[0];

    if (uf.join(a, b)) {
      cost += c;
    }

    if (uf.size(a) == n) {
      cost -= c;
      break;
    }
  }

  cout << cost;
}