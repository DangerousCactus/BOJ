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

  auto it = nums.begin();

  pair<int, pii> best = {INT_MAX, {}};

  while (it != nums.end()) {
    auto uit = upper_bound(next(it), nums.end(), -*it);

    if (uit != nums.end()) {
      best = min(best, {abs(*it + *uit), {*it, *uit}});
    }

    if (uit != it + 1) {
      auto pit = prev(uit);
      best = min(best, {abs(*it + *pit), {*it, *pit}});
    }
    it++;
  }

  cout << best.second.first << ' ' << best.second.second;
}