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

  vi nums(n);
  for (auto& x : nums) {
    cin >> x;
  }

  sort(all(nums));

  pair<ll, vi> best = {LLONG_MAX, {}};

  for (auto it = nums.begin(); it != nums.end(); it++) {
    for (auto it2 = next(it); it2 < nums.end(); it2++) {
      ll curr = *it + *it2;

      auto uit = upper_bound(next(it2), nums.end(), -curr);

      if (uit != nums.end()) {
        best = min(best, {abs(curr + *uit), {*it, *it2, *uit}});
      }

      if (uit != it2 + 1) {
        auto pit = prev(uit);
        best = min(best, {abs(curr + *pit), {*it, *it2, *pit}});
      }
    }
  }

  sort(all(best.second));
  for (auto& x : best.second) {
    cout << x << ' ';
  }
}