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

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vi> nums(2, vi(n));
    for (auto& x : nums) {
      for (auto& y : x) {
        cin >> y;
      }
    }

    vector<vi> DP(n + 1, vi(4, -1));
    DP.back().assign(4, 0);

    function<int(int, int)> solve = [&](int col, int mask) {
      int& out = DP[col][mask];
      if (out == -1) {
        out = solve(col + 1, 0);

        if (~mask & 1) {
          out = max(out, solve(col + 1, 1) + nums[0][col]);
        }

        if (~mask & 2) {
          out = max(out, solve(col + 1, 2) + nums[1][col]);
        }
      }

      return out;
    };

    cout << solve(0, 0) << '\n';
  }
}