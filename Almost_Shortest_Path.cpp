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
  while (cin >> n >> m, n != 0) {
    int s, d;
    cin >> s >> d;

    vector<vector<pii>> adj(n);   // cost, dest
    vector<vector<pii>> adjr(n);  // cost, dest
    rep(i, 0, m) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].emplace_back(c, b);
      adjr[b].emplace_back(c, a);
    }

    auto dijkstra = [](vector<vector<pii>>& adj, vi& dist, int source) {
      dist.assign(sz(adj), INT_MAX);

      priority_queue<pii, vector<pii>, greater<>> q;
      q.emplace(0, source);
      dist[source] = 0;

      while (sz(q)) {
        auto [c, z] = q.top();
        q.pop();

        if (c != dist[z]) {
          continue;
        }

        for (auto& [nc, x] : adj[z]) {
          if (c + nc < dist[x]) {
            dist[x] = c + nc;
            q.emplace(dist[x], x);
          }
        }
      }
    };

    vi dist, distr;
    dijkstra(adj, dist, s);
    dijkstra(adjr, distr, d);

    vector<vector<pii>> adj2(n);
    rep(z, 0, n) {
      for (auto& [c, x] : adj[z]) {
        if (dist[z] == INT_MAX || distr[x] == INT_MAX) {
          continue;
        }

        if (dist[z] + c + distr[x] == dist[d]) {
          continue;
        }

        adj2[z].emplace_back(c, x);
      }
    }

    dijkstra(adj2, dist, s);
    if (dist[d] == INT_MAX) {
      dist[d] = -1;
    }
    cout << dist[d] << '\n';
  }
}