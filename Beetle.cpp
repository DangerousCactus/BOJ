#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vi ldrops, rdrops;

  rep(i, 0, n) {
    int x;
    cin >> x;

    assert(x != 0);

    if (x >= 0) {
      rdrops.push_back(x);
    } else {
      ldrops.push_back(-x);
    }
  }

  sort(all(ldrops));
  sort(all(rdrops));

  vector<vector<vector<pll>>> DP(2);  // time elapsed
  fill(all(DP), vector<vector<pll>>(n + 1, vector<pll>(n + 1, pii{-1, -1})));

  function<pll(int, int, bool)> solve = [&](int l, int r, bool isLeft) {
    auto& ans = DP[isLeft][l][r];  // water, time

    if (ans.first != -1) {
      return ans;
    }

    ans = pii{0, 0};

    if (l + r == 1) {
      if (l && isLeft) {
        return ans = pii{max(0, m - ldrops.front()), ldrops.front()};
      } else if (r && !isLeft) {
        return ans = pii{max(0, m - rdrops.front()), rdrops.front()};
      }
    }

    if (isLeft && l > 0) {
      if (l > 1) {
        auto out = solve(l - 1, r, true);
        out.second += ldrops[l - 1] - ldrops[l - 2];
        out.first += max(0LL, m - out.second);
        ans = max(ans, out);
      }

      if (r > 0) {
        auto out = solve(l - 1, r, false);
        out.second += ldrops[l - 1] + rdrops[r - 1];
        out.first += max(0LL, m - out.second);
        ans = max(ans, out);
      }

    } else if (!isLeft && r > 0) {
      if (l > 0) {
        auto out = solve(l, r - 1, true);
        out.second += ldrops[l - 1] + rdrops[r - 1];
        out.first += max(0LL, m - out.second);
        ans = max(ans, out);
      }
      if (r > 1) {
        auto out = solve(l, r - 1, false);
        out.second += rdrops[r - 1] - rdrops[r - 2];
        out.first += max(0LL, m - out.second);
        ans = max(ans, out);
      }
    }

    return ans;
  };

  pll ans = {0, 0};

  rep(i, 0, sz(ldrops) + 1) {
    rep(j, 0, sz(rdrops) + 1) {
      rep(k, 0, 2) {
        auto temp = solve(i, j, k);
        // cout << "solve " << i << ' ' << j << ' ' << k << " is " << temp.first
        //      << ' ' << temp.second << '\n';
        ans = max(ans, temp);
      }
    }
  }

  cout << ans.first;
}