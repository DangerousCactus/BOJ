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

  vector<vi> g(n, vi(n));
  for (auto& x : g) {
    for (auto& y : x) {
      cin >> y;
    }
  }

  vector<vi> DP(n + 1, vi(n + 1));

  rep(i, 1, n + 1) {
    rep(j, 1, n + 1) {
      DP[i][j] =
          g[i - 1][j - 1] + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
    }
  }

  rep(i, 0, m) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << DP[x2][y2] - DP[x1 - 1][y2] - DP[x2][y1 - 1] + DP[x1 - 1][y1 - 1] << '\n';
  }
}