#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// f(x) = ax^2 + bx + c
// let SX = x_(k+1) + x_(k+2) + ... + x_n =  SN-SK
// SX = sum upto and including X
// DP[n] = max(DP[k] + f(SX))   {0 <= k < n}
// DP[n] = max(DP[k] + A*SX*SX + B*SX + C)   {0 <= k < n}
// DP[n] = max(DP[k] + A*SN*SN + A*SK*SK - 2*A*SN*SK + B*SX - B*SK + C)
//  DP[n] = A*SN*SN + B*SN + C + max(- 2*A*SN*SK + DP[k] + A*SK*SK - B*SK)

struct Line {
  mutable int k;
  mutable ll m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
  // ( for doubles , use in f = 1/.0 , div (a , b) = a/b)
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {  // f loored division
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end())
      return x->p = inf, 0;
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z))
      z = erase(z);
    if (x != begin() && isect(--x, y))
      isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  ll a, b, c;
  cin >> n >> a >> b >> c;

  vi p(n + 1, 0);
  rep(i, 1, n + 1) {
    cin >> p[i];
    p[i] += p[i - 1];
  }

  LineContainer lc;
  ll best = 0;
  lc.add(0, 0);

  rep(i, 1, n + 1) {
    best = a * p[i] * p[i] + b * p[i] + c + lc.query(p[i]);
    lc.add(-2 * a * p[i], best + a * p[i] * p[i] - b * p[i]);
  }

  cout << best;
}