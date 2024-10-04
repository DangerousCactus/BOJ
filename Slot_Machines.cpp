#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const vi& s) {
  vi p(sz(s));
  rep(i, 1, sz(s)) {
    int g = p[i - 1];
    while (g && s[i] != s[g])
      g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi nums(n);
  for (auto& x : nums) {
    cin >> x;
  }

  reverse(all(nums));
  auto kmp = pi(nums);
  reverse(all(nums));

  auto it = max_element(all(kmp));
  int idx = kmp.end() - 1 - it;

  auto truncatedKmp = pi({nums.begin() + idx, nums.end()});

  rep(i, 0, sz(truncatedKmp)) {
    if (i % 2 && truncatedKmp[i] == i / 2 + 1) {
      cout << idx << ' ' << i / 2 + 1;
      exit(0);
    }
  }

  cout << idx << ' ' << sz(truncatedKmp);
}