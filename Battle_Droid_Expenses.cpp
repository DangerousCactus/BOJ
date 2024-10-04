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

  vector<double> prices{350.34, 230.9, 190.55, 125.3, 180.9};

  int t;
  cin >> t;

  while (t--) {
    long double ans = 0;
    rep(i, 0, 5) {
      long double x;
      cin >> x;

      ans += x * prices[i];
    }
    cout << '$' << fixed << setprecision(2) << ans << '\n';
  }
}