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

  if (nums[n - 2] - nums[n - 3] == nums[n - 1] - nums[n - 2]) {
    cout << nums.back() + nums[n - 1] - nums[n - 2];
  } else {
    cout << nums.back() * (nums[n - 1] / nums[n - 2]);
  }
}