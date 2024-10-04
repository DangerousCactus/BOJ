#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class I>
int lis(const vector<I>& S) {
  if (S.empty())
    return {};

  vi res;
  rep(i, 0, sz(S)) {
    auto it = lower_bound(all(res), S[i]);
    if (it == res.end())
      res.emplace_back(), it = res.end() - 1;
    *it = S[i];
  }

  return sz(res);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi nums(n);
  for (auto& x : nums) {
    cin >> x;
    x *= -1;
  }

  int ans = 0;
  rep(i, 0, n) {
    vi left, right;

    copy(nums.begin(), nums.begin() + i + 1, back_inserter(left));
    copy(nums.begin() + i, nums.end(), back_inserter(right));
    reverse(all(left));
    ans = max(ans, lis(left) + lis(right) - 1);
  }

  cout << ans;
}