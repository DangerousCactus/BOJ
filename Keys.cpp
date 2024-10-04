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

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<string> g(n + 2, string(m + 2, '.'));

    rep(i, 1, n + 1) {
      rep(j, 1, m + 1) {
        cin >> g[i][j];
      }
    }

    set<char> keys;
    {
      string s;
      cin >> s;
      for (auto& c : s) {
        keys.insert(c);
      }
    }

    map<char, vector<pii>> doors;
    int out = 0;
    queue<pii> q;
    set<pii> vis;
    q.emplace(0, 0);
    vis.emplace(0, 0);

    while (sz(q)) {
      auto [x, y] = q.front();
      // cerr << x << ' ' << y << endl;
      q.pop();

      if (g[x][y] == '*') {
        continue;
      }

      if (g[x][y] == '$') {
        out++;
      }

      for (auto& [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || ny < 0 || nx == n + 2 || ny == m + 2) {
          continue;
        }

        char curr = g[nx][ny];

        if ((curr == '.' || curr == '$' || islower(curr)) &&
            vis.emplace(nx, ny).second) {
          q.emplace(nx, ny);
        }

        if (islower(curr)) {
          if (keys.insert(curr).second) {
            for (auto& space : doors[curr]) {
              if (vis.insert(space).second) {
                q.push(space);
              }
            }
          }
        } else if (isupper(curr)) {
          if (keys.count(curr ^ ' ') && vis.emplace(nx, ny).second) {
            q.emplace(nx, ny);
          } else if (!keys.count(curr ^ ' ')) {
            doors[curr ^ ' '].emplace_back(nx, ny);
          }
        }
      }
    }

    cout << out << '\n';
  }
}