#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;

    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  vi tin(n, -1), low(n, -1);
  int timer = 0;
  set<pii> edges;

  function<void(int, int)> dfs = [&](int z, int p) {
    tin[z] = low[z] = timer++;

    for (auto& x : adj[z]) {
      if (x == p) {
        continue;
      }

      if (tin[x] != -1) {
        low[z] = min(low[z], tin[x]);
      } else {
        dfs(x, z);
        low[z] = min(low[z], low[x]);

        if (tin[z] < low[x]) {
          edges.emplace(min(z, x), max(z, x));
        }
      }
    }
  };

  rep(i, 0, n) {
    if (tin[i] == -1) {
      dfs(i, -1);
    }
  }

  cout << sz(edges) << '\n';
  for (auto& [x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
}