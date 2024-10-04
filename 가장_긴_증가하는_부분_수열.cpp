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
  }

  vi DP;
  for (auto& x : nums) {
    auto it = lower_bound(all(DP), x);
    if (it == DP.end()) {
      DP.push_back(x);
    } else {
      *it = x;
    }
  }

  cout << lis(nums);
}