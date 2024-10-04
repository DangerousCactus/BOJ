#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

array<vi, 2> manacher(const string& s) {
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
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  int n = sz(s);

  auto m = manacher(s);
  vector<vi> adj(n + 1);

  vi DP(n + 1);
  iota(all(DP), 0);

  // even pos
  rep(i, 0, sz(m[1])) {
    rep(j, 1, m[1][i] + 1) {
      adj[i - j].push_back(i + j + 1);
    }
  }

  // odd pos
  rep(i, 0, sz(m[0])) {
    rep(j, 1, m[0][i] + 1) {
      adj[i - j].push_back(i + j);
    }
  }

  rep(i, 0, sz(DP)) {
    if (i > 0) {
      DP[i] = min(DP[i], DP[i - 1] + 1);
    }
    for (auto& x : adj[i]) {
      DP[x] = min(DP[x], DP[i] + 1);
    }
  }

  cout << DP.back();
}
