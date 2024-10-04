#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll& x, ll& y) {
  if (!b)
    return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}

const ll mod = 10007;
struct Mod {
  ll x;
  Mod(ll xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
  Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
  Mod operator/(Mod b) { return *this * invert(b); }
  Mod invert(Mod a) {
    ll x, y, g = euclid(a.x, mod, x, y);
    assert(g == 1);
    return Mod((x + mod) % mod);
  }
  Mod operator^(ll e) {
    if (!e)
      return Mod(1);
    Mod r = *this ^ (e / 2);
    r = r * r;
    return e & 1 ? *this * r : r;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  Mod ans(0);

  auto achooseb = [](int a, int b) {
    Mod out(1);
    rep(i, b + 1, a + 1) {
      out = out * i;
    }

    rep(i, 1, a - b + 1) {
      out = out / i;
    }

    return out;
  };

  bool add = true;
  rep(i, 1, n / 4 + 1) {
    // choose i ranks
    Mod ways = achooseb(13, i);
    ways = ways * achooseb(52 - 4 * i, n - 4 * i);

    if (add) {
      ans = ans + ways;
    } else {
      ans = ans - ways;
    }
    add = !add;
  }

  cout << ans.x;
}