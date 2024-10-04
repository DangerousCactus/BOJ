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

  vector<vi> nums(4, vi(4));
  for (auto& x : nums) {
    for (auto& y : x) {
      cin >> y;
    }
  }

  set<int> sums;

  rep(i, 0, 4){
    sums.insert(nums[0][i] + nums[1][i] + nums[2][i] + nums[3][i]);
    sums.insert(nums[i][0] + nums[i][1] + nums[i][2] + nums[i][3]);
  }

  if (sz(sums) != 1) {
    cout << "not ";
  }
  cout << "magic";
}