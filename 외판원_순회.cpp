#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1E8;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vi> g(n, vi(n));
  for (auto& x : g) {
    for (auto& y : x) {
      cin >> y;
      if (y == 0) {
        y = inf;
      }
    }
  }

  // always use -1 for DP values in the future if uninitialized
  vector<vi> DP(1 << n, vi(n, inf));

  function<int(int, int)> solve = [&](int mask, int last) {
    int& out = DP[mask][last];

    if (out != inf) {
      return out;
    }

    if (mask == 0) {
      return g[last][0];
    }

    rep(i, 0, n) {
      if ((mask & (1 << i))) {
        out = min(out, g[last][i] + solve(mask ^ (1 << i), i));
      }
    }

    if (out == inf) {
      out--;
    }
    return out;
  };

  cout << solve(((1 << n) - 1) ^ 1, 0);
}