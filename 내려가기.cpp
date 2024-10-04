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

  int n;
  cin >> n;

  vi lo(3), hi(3);
  rep(i, 0, n) {
    vi g(3);
    for (auto& x : g) {
      cin >> x;
    }

    vi newLo(3), newHi(3);
    newLo[0] = g[0] + min(lo[0], lo[1]);
    newLo[1] = g[1] + min({lo[0], lo[1], lo[2]});
    newLo[2] = g[2] + min(lo[1], lo[2]);

    newHi[0] = g[0] + max(hi[0], hi[1]);
    newHi[1] = g[1] + max({hi[0], hi[1], hi[2]});
    newHi[2] = g[2] + max(hi[1], hi[2]);

    lo = newLo;
    hi = newHi;
  }

  cout << *max_element(all(hi)) << ' ' << *min_element(all(lo));
}