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

  int n, e;
  cin >> n >> e;

  vector<vector<pii>> adj(n);
  rep(i, 0, e) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a - 1].emplace_back(c, b - 1);
    adj[b - 1].emplace_back(c, a - 1);
  }

  int v1, v2;
  cin >> v1 >> v2;
  v1--, v2--;

  auto getDist = [&](vector<vector<pii>>& adj, int source) -> vi {
    vi d(n, INT_MAX);
    d[source] = 0;

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, source);

    while (sz(pq)) {
      auto [c, z] = pq.top();
      pq.pop();

      if (c != d[z]) {
        continue;
      }

      for (auto& [cost, dest] : adj[z]) {
        if (c + cost < d[dest]) {
          d[dest] = c + cost;
          pq.emplace(d[dest], dest);
        }
      }
    }

    return d;
  };

  auto fromStart = getDist(adj, 0);
  auto fromEnd = getDist(adj, n - 1);

  auto between = getDist(adj, v1);

  if (fromStart[n - 1] == INT_MAX || fromStart[v1] == INT_MAX ||
      fromStart[v2] == INT_MAX) {
    cout << -1;
  } else {
    cout << between[v2] +
                min(fromStart[v1] + fromEnd[v2], fromStart[v2] + fromEnd[v1]);
  }
}