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

  vector<vi> nums(n, vi(4));
  for (auto& x : nums) {
    for (auto& y : x) {
      cin >> y;
    }
  }

  vi ab;
  ab.reserve(n * n);
  rep(i, 0, n) {
    rep(j, 0, n) {
      ab.push_back(nums[i][0] + nums[j][1]);
    }
  }

  sort(all(ab));
  ll out = 0;

  rep(i, 0, n) {
    rep(j, 0, n) {
      auto [it1, it2] = equal_range(all(ab), -nums[i][2] - nums[j][3]);
      out += distance(it1, it2);
    }
  }

  cout << out;
}