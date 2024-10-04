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

  vector<vi> nums(n, vi(3));
  rep(i, 0, 3) {
    rep(j, 0, n) {
      int x;
      cin >> x;
      nums[x - 1][i] = j;
    }
  }

  sort(all(nums));

  map<int, int> ma;

  int ans = 0;
  for (auto& v : nums) {
    int a = v[1], b = v[2];

    auto it = ma.upper_bound(a);

    if (it == ma.begin() || prev(it)->second > b) {
      // cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
      ans++;
      ma[a] = b;

      it = ma.find(a);
      while (next(it) != ma.end() && next(it)->second > b) {
        ma.erase(next(it));
      }
    }
  }

  cout << ans;
}