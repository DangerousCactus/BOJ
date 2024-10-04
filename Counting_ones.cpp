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

  ll a, b;
  cin >> a >> b;
  b++;

  ll total = 0;

  for (ll curr = 2; curr != (1LL << 62); curr <<= 1) {
    ll diff = b - a;
    total += (diff / curr) * (curr / 2);

    ll start = a + (diff / curr) * curr;
    ll sm = start % curr;
    ll em = b % curr;

    if (sm < em) {
      total += max(0LL, em - max(curr / 2, sm));
    } else if (em < sm) {
      total += curr - max(curr / 2, sm);
      total += max(0LL, em - curr / 2);
    }
  }

  cout << total;
}