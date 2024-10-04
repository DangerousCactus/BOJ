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

  ll n;
  cin >> n;

  if (n == 1) {
    cout << 1;
    exit(0);
  }

  vector<ll> ways{0, 1, 2};
  rep(i, 3, 92) {
    ways.push_back(ways[i - 1] + ways[i - 2]);
  }

  function<int(ll, int, vi&)> solve = [&](ll val, int idx, vi& taken) -> int {
    int out = INT_MAX;

    if (val == 1) {
      out = accumulate(all(taken), sz(taken) - 1);
      return out;
    }
    if (idx == sz(ways)) {
      return out;
    }

    if (val % ways[idx] == 0) {
      taken.push_back(idx);
      out = min(out, solve(val / ways[idx], idx, taken));
      taken.pop_back();
    }
    out = min(out, solve(val, idx + 1, taken));

    return out;
  };

  vi nums;
  auto out = solve(n, 2, nums);
  if (out == INT_MAX) {
    cout << "NIE";
  } else {
    cout << out;
  }
}