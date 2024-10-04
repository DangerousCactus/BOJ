#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - pw * 2 + 1);
      rep(j, 0, sz(jmp[k])) jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    assert(a < b);  // or return in f i f a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};

struct LCA {
  int T = 0;
  vi time, path, ret;
  vi depth;
  RMQ<int> rmq;
  LCA(vector<vector<pii>>& C)
      : time(sz(C)), depth(sz(C)), rmq((dfs(C, 0, -1, 0), ret)) {}
  void dfs(vector<vector<pii>>& C, int v, int par, int d) {
    depth[v] = d;
    time[v] = T++;
    for (auto [c, y] : C[v])
      if (y != par) {
        path.push_back(v), ret.push_back(time[v]);
        dfs(C, y, v, d + c);
      }
  }
  int lca(int a, int b) {
    if (a == b)
      return a;
    tie(a, b) = minmax(time[a], time[b]);
    return path[rmq.query(a, b)];
  }
  int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<pii>> adj(n);
  rep(i, 0, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].emplace_back(c, b - 1);
    adj[b - 1].emplace_back(c, a - 1);
  }

  LCA lca(adj);

  int m;
  cin >> m;

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;

    cout << lca.dist(a - 1, b - 1) << '\n';
  }
}