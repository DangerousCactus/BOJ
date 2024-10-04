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

  int n, m, r;
  cin >> n >> m >> r;

  vi items(n);
  for (auto& x : items) {
    cin >> x;
  }

  vector<vector<pii>> adj(n);  // cost, dest

  rep(i, 0, r) {
    int a, b, l;
    cin >> a >> b >> l;

    adj[a - 1].emplace_back(l, b - 1);
    adj[b - 1].emplace_back(l, a - 1);
  }

  int best = 0;

  rep(i, 0, n) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    vi dist(n, INT_MAX);
    dist[i] = 0;
    pq.emplace(0, i);

    while (sz(pq)) {
      auto [c, z] = pq.top();
      pq.pop();

      if (c != dist[z]) {
        continue;
      }

      for (auto& [dc, nz] : adj[z]) {
        if (c + dc < dist[nz]) {
          dist[nz] = c + dc;
          pq.emplace(dist[nz], nz);
        }
      }
    }

    int total = 0;
    rep(j, 0, n) {
      if (dist[j] <= m) {
        total += items[j];
      }
    }

    best = max(best, total);
  }

  cout << best;
}