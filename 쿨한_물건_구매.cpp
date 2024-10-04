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

  ll d, p, q;
  cin >> d >> p >> q;

  ll best = LLONG_MAX;

  rep(i, 0, 2) {
    ll a = d / p + (d % p != 0);
    ll total = a * p;
    best = min(best, total);

    int iter = 0;
    while (a && iter < 3E4) {
      total += q;

      while (a && (total - p >= d)) {
        total -= p;
        a--;
      }
      best = min(best, total);
      iter++;
    }

    swap(p, q);
  }
  cout << best;
}