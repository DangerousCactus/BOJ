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
    x.resize(m);
    for (auto& y : x) {
      cin >> y;
    }
  }

  int ans = 0;
  while (any_of(all(g), [](auto x) { return count(all(x), '1') > 0; })) {
    vector<string> ng = g;
    vector<vector<bool>> air(n, vector<bool>(m));

    queue<pii> q;
    set<pii> vis;
    rep(i, 0, m) {
      q.emplace(-1, i);
      q.emplace(n, i);
    }
    rep(i, 0, n) {
      q.emplace(i, -1);
      q.emplace(i, m);
    }

    while (sz(q)) {
      auto [x, y] = q.front();
      q.pop();

      for (auto& [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == '1') {
          continue;
        }

        if (vis.emplace(nx, ny).second) {
          air[nx][ny] = true;
          q.emplace(nx, ny);
        }
      }
    }

    rep(i, 0, n) {
      rep(j, 0, m) {
        if (g[i][j] == '0') {
          continue;
        }

        int ct = 0;
        for (auto& [dx, dy] : dirs) {
          int nx = i + dx;
          int ny = j + dy;

          if (nx >= 0 && ny >= 0 && nx < n && ny < m && air[nx][ny]) {
            ct++;
          }
        }

        if (ct >= 2) {
          ng[i][j] = '0';
        }
      }
    }

    g = ng;
    ans++;
  }

  cout << ans;
}