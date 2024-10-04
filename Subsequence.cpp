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

  int n, s;
  cin >> n >> s;

  vi nums(n);
  for (auto& x : nums) {
    cin >> x;
  }

  int lo = 0, hi = 0;
  int ans = INT_MAX;
  int total = 0;

  while (hi < n) {
    if (total >= s) {
      ans = min(ans, hi - lo);
      total -= nums[lo++];
    } else if (total < s) {
      total += nums[hi++];
    }
  }

  while (total - nums[lo] >= s) {
    total -= nums[lo++];
  }

  if (total >= s) {
    ans = min(ans, hi - lo);
  }

  if (ans == INT_MAX) {
    ans = 0;
  }

  cout << ans;
}