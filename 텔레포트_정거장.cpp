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

  int n, m, s, e;
  cin >> n >> m >> s >> e;
  s--, e--;

  vector<vi> adj(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  int cost = 0;
  queue<int> q({s});

  vector<bool> vis(n);
  vis[s] = 1;

  while (sz(q)) {
    queue<int> nq;
    while (sz(q)) {
      auto z = q.front();
      q.pop();

      if (z == e) {
        cout << cost;
        exit(0);
      }

      if (z + 1 < n && !vis[z + 1]) {
        vis[z + 1] = true;
        nq.push(z + 1);
      }

      if (z - 1 >= 0 && !vis[z - 1]) {
        vis[z - 1] = true;
        nq.push(z - 1);
      }

      for (auto& x : adj[z]) {
        if (!vis[x]) {
          vis[x] = true;
          nq.push(x);
        }
      }
    }
    cost++;
    q = nq;
  }
}