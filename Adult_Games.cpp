#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1E6 + 7;
const int MOD = 1E9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  vector<ll> ans(MAXN), pans(MAXN);
  pans[1] = 3;
  ans[1] = 7;

  rep(i, 2, MAXN) {
    ans[i] += 3 * ans[i - 1];
    ans[i] += 4 * pans[i - 1];
    ans[i] %= MOD;
    pans[i] = ans[i - 1] + 2 * pans[i - 1];
    pans[i] %= MOD;
  }

  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
}