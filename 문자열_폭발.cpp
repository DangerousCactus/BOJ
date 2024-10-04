#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const string& s) {
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
  string s, pat;
  cin >> s >> pat;

  auto kp = pi(pat);

  deque<pair<int, char>> d;
  for (auto& c : s) {
    if (!sz(d)) {
      d.emplace_back(pat[0] == c, c);
    } else {
      int idx = d.back().first;

      while (c != pat[d.back().first] && idx != 0) {
        idx = kp[idx];
      }

      if (c == pat[idx]) {
        d.emplace_back(idx + 1, c);
      } else {
        d.emplace_back(0, c);
      }
    }

    if (d.back().first == sz(pat)) {
      rep(i, 0, sz(pat)) {
        d.pop_back();
      }
    }
  }

  if (!sz(d)) {
    cout << "FRULA";
  } else {
    for (auto& x : d) {
      cout << x.second;
    }
  }
}