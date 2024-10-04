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

  int n;
  cin >> n;

  vector<vector<vi>> DP(n, vector<vi>(n, vi(3, -1)));
  rep(i, 0, n) {
    rep(j, 0, n) {
      int x;
      cin >> x;

      if (x == 1) {
        DP[i][j].assign(3, 0);
      }
    }
  }

  DP[0][1][0] = 1;

  // 0 -> right, 1-> down, 2-> diag
  function<int(int, int, int)> solve = [&](int x, int y, int d) {
    if (x < 0 || y < 0) {
      return 0;
    }

    int& out = DP[x][y][d];

    if (out != -1) {
      return out;
    }

    out = 0;
    if (d == 0) {
      out += solve(x, y - 1, 0);
      out += solve(x, y - 1, 2);
    } else if (d == 1) {
      out += solve(x - 1, y, 1);
      out += solve(x - 1, y, 2);
    } else if (d == 2) {
      out += solve(x - 1, y - 1, 0);
      out += solve(x - 1, y - 1, 1);
      out += solve(x - 1, y - 1, 2);
    }

    return out;
  };

  int ans = 0;
  ans += solve(n - 1, n - 1, 0);
  ans += solve(n - 1, n - 1, 1);
  ans += solve(n - 1, n - 1, 2);

  cout << ans;
}