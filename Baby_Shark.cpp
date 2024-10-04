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

  int n;
  cin >> n;

  map<int, vector<pii>> m;

  vector<vi> g(n, vi(n));
  rep(i, 0, n) {
    rep(j, 0, n) {
      cin >> g[i][j];
      m[g[i][j]].emplace_back(i, j);
    }
  }

  int sharkSize = 2;
  int growIn = 2;

  auto dist = [&](pii start, pii dest) {
    queue<pii> q({start});
    set<pii> vis{start};

    int depth = 0;

    while (sz(q)) {
      queue<pii> nq;
      while (sz(q)) {
        auto [x, y] = q.front();
        q.pop();

        if (dest == pii{x, y}) {
          return depth;
        }

        for (auto& [dx, dy] : dirs) {
          int nx = x + dx;
          int ny = y + dy;

          if (nx < 0 || ny < 0 || nx == n || ny == n || g[nx][ny] > sharkSize) {
            continue;
          }

          if (vis.insert({nx, ny}).second) {
            nq.push({nx, ny});
          }
        }
      }
      q = nq;
      depth++;
    }

    return INT_MAX;
  };

  set<pii> candidates;
  candidates.insert(all(m[1]));

  pii start = m[9][0];
  g[start.first][start.second] = 0;
  int t = 0;

  while (sz(candidates)) {
    pair<int, pii> best{INT_MAX, {INT_MAX, INT_MAX}};

    for (auto it = candidates.begin(); it != candidates.end(); it++) {
      best = min(best, pair<int, pii>{dist(start, *it), *it});
    }

    if (best.first == INT_MAX) {
      break;
    }

    // cerr << "move " << start.first << ' ' << start.second << " to ";
    t += best.first;
    start = best.second;
    // cerr << start.first << ' ' << start.second << " cost: ";
    // cerr << best.first << endl;

    candidates.erase(best.second);

    if (--growIn == 0) {
      candidates.insert(all(m[sharkSize]));
      growIn = ++sharkSize;
    }
  }

  cout << t;
}