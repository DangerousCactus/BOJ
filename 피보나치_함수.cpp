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

  vector<pii> nums{{1, 0}, {0, 1}};

  rep(i, 0, 45) {
    nums.emplace_back(nums[i].first + nums[i + 1].first,
                      nums[i].second + nums[i + 1].second);
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    cout << nums[n].first << ' ' << nums[n].second << '\n';
  }
}