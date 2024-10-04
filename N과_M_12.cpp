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

  int n, m;
  cin >> n >> m;

  vi nums(n);
  for (auto& x : nums) {
    cin >> x;
  }
  sort(all(nums));

  set<vi> ans;
  vi out;

  function<void(int, int)> solve = [&](int x, int needed) {
    if (needed == 0) {
      ans.insert(out);
      return;
    }

    rep(i, x, n + 1) {
      out.push_back(nums[i - 1]);
      solve(i, needed - 1);
      out.pop_back();
    }
  };

  solve(1, m);

  for (auto& x : ans) {
    for (auto& y : x) {
      cout << y << ' ';
    }
    cout << '\n';
  }
}