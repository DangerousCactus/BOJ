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

  int t;
  cin >> t;

  rep(z, 1, t + 1) {
    int c, n;
    cin >> c >> n;

    vi nums(n);
    for (auto& x : nums) {
      cin >> x;
    }

    rep(i, 0, n) {
      rep(j, i + 1, n) {
        if (nums[i] + nums[j] == c) {
          cout << "Case #" << z << ": " << i + 1 << ' ' << j + 1 << '\n';
        }
      }
    }
  }
}