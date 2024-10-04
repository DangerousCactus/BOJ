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

  int sum = accumulate(all(nums), 0);

  if (2 * count(all(nums), 0) >= n) {
    cout << "INVALID";
  } else if (sum > 0) {
    cout << "APPROVED";
  } else if (sum <= 0) {
    cout << "REJECTED";
  } else {
    assert(false);
  }
}