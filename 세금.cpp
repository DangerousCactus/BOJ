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
  cout.tie(0);

  int n, m, k, s, d;
  cin >> n >> m >> k >> s >> d;
  s--, d--;

  vector<vector<pii>> adj(n);  // cost, dest

  rep(i, 0, m) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a - 1].emplace_back(w, b - 1);
    adj[b - 1].emplace_back(w, a - 1);
  }

  vi increases(k);
  for (auto& x : increases) {
    cin >> x;
  }

  vector<vi> best(n, vi(n + 1, INT_MAX));  // node, steps -> lowest cost
  best[s][0] = 0;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;  // cost, steps, node
  pq.emplace(0, 0, s);

  while (sz(pq)) {
    auto [c, steps, z] = pq.top();
    pq.pop();

    if (steps == n || z == d || c != best[z][steps]) {
      continue;
    }

    for (auto& [nc, nx] : adj[z]) {
      if (best[nx][steps + 1] > c + nc) {
        pq.emplace(best[nx][steps + 1] = c + nc, steps + 1, nx);
      }
    }
  }

  cout << *min_element(all(best[d])) << '\n';

  int total = 0;
  for (auto& x : increases) {
    total += x;

    int out = INT_MAX;

    rep(i, 0, n + 1) {
      if (best[d][i] != INT_MAX) {
        out = min(out, i * total + best[d][i]);
      }
    }

    cout << out << '\n';
  }
}