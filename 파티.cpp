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

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<pii>> adj1(n), adj2(n);  // dist, dest
  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    adj1[a - 1].emplace_back(c, b - 1);
    adj2[b - 1].emplace_back(c, a - 1);
  }

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

  auto out1 = getDist(adj1, x - 1);
  auto out2 = getDist(adj2, x - 1);

  transform(all(out1), out2.begin(), out2.begin(), plus<>());

  cout << *max_element(all(out2));
}