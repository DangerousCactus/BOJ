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
    int f;
    cin >> f;

    vi lines(f);
    for (auto& x : lines) {
      cin >> x;
    }

    pii s, e;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;

    map<pii, int> cost;
    cost[s] = 0;

    queue<pii> q({s});

    while (sz(q)) {
      auto [x, y] = q.front();
      q.pop();

      vector<pii> candidates;

      for(auto & p : candidates){
        if(cost[p] > cost[{x, y}] + 1){

        }
        q.push(p);
      }

      for (auto& [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || nx == f) {
          continue;
        }

        if (ny < 0 || nx > 0) {
          nx--;
          ny = lines[nx];
        }

        if (ny > lines[nx] || nx + 1 < f) {
          nx++;
          ny = 0;
        }
      }
    }

    cout << cost[e] << '\n';
  }
}