#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

array<vi, 2> manacher(const vi& s) {
  int n = sz(s);
  array<vi, 2> p = {vi(n + 1), vi(n)};
  rep(z, 0, 2) for (int i = 0, l = 0, r = 0; i < n; i++) {
    int t = r - i + !z;
    if (i < r)
      p[z][i] = min(t, p[z][l + t]);
    int L = i - p[z][i], R = i + p[z][i] - !z;
    while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
      p[z][i]++, L--, R++;
    if (R > r)
      l = L, r = R;
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

  auto p = manacher(nums);

  int m;
  cin >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    if ((b - a) % 2 == 0) {
      cout << (p[1][(a + b) / 2] >= (b - a) / 2);
    } else {
      cout << (p[0][(a + b + 1) / 2] >= (b - a) / 2 + 1);
    }

    cout << '\n';
  }
}