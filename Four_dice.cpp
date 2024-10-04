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

  int best = 0;

  while (t--) {
    vi nums(4);
    map<int, int> s;

    for (auto& x : nums) {
      cin >> x;
      s[x]++;
    }

    if (sz(s) == 1) {
      best = max(best, 50000 + 5000 * s.begin()->first);
    } else if (sz(s) == 2) {
      if (s.begin()->second == 2) {
        best = max(best, (accumulate(all(nums), 0) / 2) * 500 + 2000);
      } else {
        int top = 0;
        for (auto& x : nums) {
          if (count(all(nums), x) == 3) {
            top = x;
          }
        }
        best = max(best, 10000 + 1000 * top);
      }
    } else if (sz(s) == 3) {
      int top = 0;
      for (auto& x : nums) {
        if (count(all(nums), x) == 2) {
          top = x;
        }
      }
      best = max(best, 1000 + 100 * top);
    } else {
      best = max(best, 100 * *max_element(all(nums)));
    }
  }

  cout << best;
}