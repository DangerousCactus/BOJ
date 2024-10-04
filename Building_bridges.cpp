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

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    __int128 total = 1;
    rep(i, 1, m + 1) {
      total = total * i;
    }

    rep(i, 1, n + 1) {
      total = total / i;
    }

    rep(i, 1, m - n + 1) {
      total = total / i;
    }

    cout << (ll)total << '\n';
  }
}