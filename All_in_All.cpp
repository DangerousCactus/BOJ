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

  string s, t;
  while (cin >> s >> t) {
    auto sidx = s.begin();
    auto tidx = t.begin();
    while (sidx != s.end() && tidx != t.end()) {
      if (*sidx == *tidx) {
        sidx++, tidx++;
      } else {
        tidx++;
      }
    }

    cout << (sidx == s.end() ? "Yes" : "No") << '\n';
  }
}