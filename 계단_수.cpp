#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1E9;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  if (n < 10) {
    cout << 0;
    exit(0);
  }

  vector<vector<vector<ll>>> cache(
      n + 1, vector<vector<ll>>(1 << 10, vector<ll>(10, -1)));

  function<ll(int, int, int)> solve = [&](int digit, int mask, int last) -> ll {
    // cout << digit << ' ' << mask << ' ' << last << endl;
    auto& out = cache[digit][mask][last];

    if (out != -1) {
      return out;
    }

    if (digit == 1) {
      if (mask == 0 || mask == (1 << last)) {
        return 1;
      }
      return mask == 0;
    }

    out = 0;

    if (last - 1 >= 0) {
      out += solve(digit - 1, mask & ~(1 << last), last - 1);
    }

    if (last + 1 <= 9) {
      out += solve(digit - 1, mask & ~(1 << last), last + 1);
    }

    out %= mod;
    return out;
  };

  ll ans = 0;
  rep(i, 1, 10) {
    ans += solve(n, (1 << 10) - 1, i);
    ans %= mod;
  }

  cout << ans;
}