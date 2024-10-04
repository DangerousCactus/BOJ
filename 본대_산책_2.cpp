#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1E9 + 7;  // change to something e lse
struct Mod {
  ll x;
  Mod() : x(0) {}
  Mod(ll xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
  Mod operator*(const Mod b) const { return Mod((x * b.x) % mod); }

  Mod operator^(ll e) {
    if (!e)
      return Mod(1);
    Mod r = *this ^ (e / 2);
    r = r * r;
    return e & 1 ? *this * r : r;
  }
};

template <class T, int N>
struct Matrix {
  typedef Matrix M;
  array<array<T, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) a.d[i][j] =
        a.d[i][j] + (d[i][k] * m.d[k][j]);
    return a;
  }
  vector<T> operator*(const vector<T>& vec) const {
    vector<T> ret(N);
    rep(i, 0, N) rep(j, 0, N) ret[i] = ret[i] + (d[i][j] * vec[j]);
    return ret;
  }
  M operator^(ll p) const {
    assert(p >= 0);
    M a, b(*this);
    rep(i, 0, N) a.d[i][i] = 1;
    while (p) {
      if (p & 1)
        a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll d;
  cin >> d;

  Matrix<Mod, 8> m;
  m.d = {array<Mod, 8>{0, 1, 1, 0, 0, 0, 0, 0},
         array<Mod, 8>{1, 0, 1, 1, 0, 0, 0, 0},
         array<Mod, 8>{1, 1, 0, 1, 1, 0, 0, 0},
         array<Mod, 8>{0, 1, 1, 0, 1, 1, 0, 0},
         array<Mod, 8>{0, 0, 1, 1, 0, 1, 0, 1},
         array<Mod, 8>{0, 0, 0, 1, 1, 0, 1, 0},
         array<Mod, 8>{0, 0, 0, 0, 0, 1, 0, 1},
         array<Mod, 8>{0, 0, 0, 0, 1, 0, 1, 0}};

  m = m ^ d;
  vector<Mod> init(8);
  init[0] = 1;
  cout << (m * init)[0].x;
}