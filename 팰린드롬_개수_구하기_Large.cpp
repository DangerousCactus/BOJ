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

  const int mod = 10007;

  string s;
  cin >> s;

  int n = sz(s);

  unordered_map<char, set<int>> positions;
  rep(i, 0, n) {
    positions[s[i]].insert(i);
  }

  vector<vi> DP[2];
  DP[0] = DP[1] = vector<vi>(n + 1, vi(n + 1, -1));

  // return number of (possibly empty, if allowed) palindromic subsequences
  function<int(int, int, bool)> solve = [&](int a, int b,
                                            bool allowEmpty) -> int {  // [)
    if (a > b) {
      return 0;
    }

    if (a == b) {
      return allowEmpty;
    }

    if (a + 1 == b) {
      return 1 + allowEmpty;
    }

    int out = 1;
    out += solve(a + 1, b, allowEmpty);
    // int& out = DP[a][b];
    // if (out != -1) {
    //   return out;
    // }

    auto e = positions[s[a]].end();
    for (auto it = next(positions[s[a]].lower_bound(a)); it != e && *it < b;
         it++) {
      out += solve(a + 1, *it, true) + solve(a + 1, *it, allowEmpty);
      out %= mod;
    }

    cerr << a << ' ' << b << ' ' << s.substr(a, b - a) << ' ' << allowEmpty
         << ' ' << out << endl;
    return out;
  };

  cout << solve(0, sz(s), false);
}