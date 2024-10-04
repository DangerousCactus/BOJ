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

  string s1, s2;
  cin >> s1 >> s2;

  int n = sz(s1);
  int m = sz(s2);

  vector<vi> DP(n + 1, vi(m + 1, -1));

  function<int(int, int)> solve = [&](int i, int j) {
    if (i == -1 || j == -1) {
      return 0;
    }

    int& out = DP[i][j];
    if (out == -1) {
      if (s1[i] == s2[j]) {
        out = 1 + solve(i - 1, j - 1);
      }

      out = max({out, solve(i - 1, j), solve(i, j - 1)});
    }

    return out;
  };

  cout << solve(n - 1, m - 1);
}