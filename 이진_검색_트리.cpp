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

  vi nums;
  {
    int x;
    while (cin >> x) {
      nums.push_back(x);
    }
  }

  function<void(int, int)> solve = [&](int start, int end) {
    if (start >= end) {
      return;
    }

    auto idx = start + 1;
    while (nums[start] >= nums[idx] && idx < end) {
      idx++;
    }

    solve(start + 1, idx);
    solve(idx, end);

    cout << nums[start] << endl;
  };

  solve(0, sz(nums));
}