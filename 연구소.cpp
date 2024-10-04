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

  vector<vi> g(n, vi(m));
  for (auto& x : g) {
    for (auto& y : x) {
      cin >> y;
    }
  }

  int best = 0;
  rep(i, 0, n * m) {
    rep(j, i + 1, n * m) {
      rep(k, j + 1, n * m) {
        auto ng = g;

        vector<pii> coords{{i / m, i % m}, {j / m, j % m}, {k / m, k % m}};
        bool consider = true;
        for (auto& [x, y] : coords) {
          consider = consider && (g[x][y] == 0);
          ng[x][y] = 1;
        }

        if (!consider) {
          continue;
        }

        set<pii> vis;
        queue<pii> q;
        rep(u, 0, n) {
          rep(v, 0, m) {
            if (ng[u][v] == 2) {
              q.emplace(u, v);
              vis.emplace(u, v);
            }
          }
        }

        while (sz(q)) {
          auto [x, y] = q.front();
          q.pop();

          for (auto& [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || ny < 0 || nx == n || ny == m) {
              continue;
            }

            if (ng[nx][ny] != 0 || vis.count({nx, ny})) {
              continue;
            }

            vis.emplace(nx, ny);
            q.emplace(nx, ny);
            ng[nx][ny] = 2;
          }
        }

        int total = 0;
        rep(u, 0, n) {
          rep(v, 0, m) {
            total += (ng[u][v] == 0);
          }
        }

        best = max(best, total);
      }
    }
  }
  cout << best;
}