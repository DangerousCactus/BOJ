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

  string a, b;
  cin >> a >> b;

  vector<vi> DP(sz(a) + 1, vi(sz(b) + 1, -1));

  function<int(int, int)> solve = [&](int i, int j) {
    if (i == sz(a) || j == sz(b)) {
      return 0;
    }

    int& out = DP[i][j];
    if (out != -1) {
      return out;
    }

    if (a[i] == b[j]) {
      out = 1 + solve(i + 1, j + 1);
    } else {
      out = max(solve(i + 1, j), solve(i, j + 1));
    }

    return out;
  };

  cout << solve(0, 0) << '\n';

  int i = 0, j = 0;
  while (DP[i][j] > 0) {
    if (a[i] == b[j]) {
      cout << a[i];
      i++, j++;
    } else if (DP[i + 1][j] >= DP[i][j + 1]) {
      i++;
    } else if (DP[i + 1][j] < DP[i][j + 1]) {
      j++;
    } else {
      assert(false);
    }
  }
}