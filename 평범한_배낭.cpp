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

  int n, k;
  cin >> n >> k;

  vector<int> DP(k + 1, -1);
  DP[0] = 0;

  rep(j, 0, n) {
    int c, v;
    cin >> c >> v;

    int idx = k;
    while (idx - c >= 0) {
      if (DP[idx - c] >= 0) {
        DP[idx] = max(DP[idx], DP[idx - c] + v);
      }
      idx--;
    }
  }

  cout << *max_element(all(DP));
}