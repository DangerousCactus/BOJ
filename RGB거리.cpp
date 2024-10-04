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

  vector<vi> costs(n, vi(3));
  for (auto& house : costs) {
    for (auto& color : house) {
      cin >> color;
    }
  }

  vector<vi> DP(n + 1, vi(3, INT_MAX));
  fill(all(DP[n]), 0);

  function<int(int, int)> solve = [&](int i, int c) -> int {
    int& ans = DP[i][c];

    if (ans != INT_MAX) {
      return ans;
    }

    rep(j, 0, 3) {
      if (c == j) {
        continue;
      }

      ans = min(ans, solve(i + 1, j) + costs[i][c]);
    }
    return ans;
  };

  cout << min({solve(0, 0), solve(0, 1), solve(0, 2)});
}