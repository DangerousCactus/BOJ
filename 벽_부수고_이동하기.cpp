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

  const vector<pii> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int n, m;
  cin >> n >> m;

  vector<string> g(n);
  for (auto& x : g) {
    cin >> x;
  }

  vector<vector<vi>> DP(n, vector<vi>(m, vi(2, INT_MAX)));
  DP[0][0].assign(2, 1);

  queue<tuple<int, int, bool>> q;
  q.emplace(0, 0, 0);

  while (sz(q)) {
    auto [x, y, jump] = q.front();
    q.pop();

    for (auto& [dx, dy] : dirs) {
      int nx = x + dx;
      int ny = y + dy;

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (g[nx][ny] == '0') {
          if (DP[nx][ny][jump] == INT_MAX) {
            DP[nx][ny][jump] = DP[x][y][jump] + 1;
            q.emplace(nx, ny, jump);
          }
        } else if (!jump) {
          if (DP[nx][ny][1] == INT_MAX) {
            DP[nx][ny][1] = DP[x][y][jump] + 1;
            q.emplace(nx, ny, 1);
          }
        }
      }
    }
  }

  if (DP[n - 1][m - 1] == vi(2, INT_MAX)) {
    cout << -1;
  } else {
    cout << *min_element(all(DP[n - 1][m - 1]));
  }
  cout << '\n';
}