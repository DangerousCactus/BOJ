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

  vector<vector<pii>> adj(n);
  rep(i, 0, m) {
    int a, b, c;
    adj[a - 1].emplace_back(c, b - 1);
  }

  int a, b;
  cin >> a >> b;
  a--, b--;

  vi best{-1, -1, -1};
  vector<bool> vis;

  queue<vi> q;  // cost, dest, numRoads
  while (sz(q)) {
    auto v = q.front();
    int c = v[0], z = v[1], t = v[2];

    if (z == b) {
      best = max(best, v);
      continue;
    }

    if(vis[z]){

    }

    for (auto& [nc, nd] : adj[z]){
      
    }
  }

  cout << best[0] << '\n' << best[2];
}