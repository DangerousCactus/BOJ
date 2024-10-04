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
    cin >> a >> b >> c;

    adj[a - 1].emplace_back(c, b - 1);
  }

  int source, dest;
  cin >> source >> dest;
  source--, dest--;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
  vi parent(n, -1);
  vector<ll> cost(n, LLONG_MAX);
  cost[source] = 0;

  pq.emplace(0, source);

  while (sz(pq)) {
    auto [c, z] = pq.top();
    pq.pop();

    if (c != cost[z]) {
      continue;
    }

    for (auto& [dc, x] : adj[z]) {
      if (c + dc < cost[x]) {
        cost[x] = c + dc;
        parent[x] = z;
        pq.emplace(cost[x], x);
      }
    }
  }

  cout << cost[dest] << '\n';
  deque<int> route;

  int curr = dest;
  while (curr != source) {
    route.push_front(curr);
    curr = parent[curr];
  }
  route.push_front(source);

  cout << sz(route) << '\n';
  for (auto& x : route) {
    cout << x + 1 << ' ';
  }
}