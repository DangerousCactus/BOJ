#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T, int N>
struct Matrix {
  typedef Matrix M;
  array<array<T, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) a.d[i][j] =
        a.d[i][j] + d[i][k] * m.d[k][j];
    return a;
  }
  vector<T> operator*(const vector<T>& vec) const {
    vector<T> ret(N);
    rep(i, 0, N) rep(j, 0, N) ret[i] += d[i][j] * vec[j];
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

int main() {
  cin.tie(0)->sync_with_stdio(0);

  const int MAXN = 20;

  int t, n, d;
  cin >> t >> n >> d;

  vector<Matrix<Mod, MAXN>> matrices(t);
  rep(i, 0, t) {
    int m;
    cin >> m;

    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;

      matrices[i].d[a - 1][b - 1] = c;
    }
  }

  Matrix<Mod, MAXN> ans;
  ans = ans ^ 0;

  auto culmat = matrices[0];
  rep(i, 1, t) {
    culmat = culmat * matrices[i];
  }

  ans = ans * (culmat ^ (d / t));

  rep(i, 0, d % t) {
    ans = ans * matrices[i];
  }
  // rep(i, 0, d){
  //   ans = ans * matrices[i % t];
  // }

  rep(i, 0, n) {
    rep(j, 0, n) {
      cout << ans.d[i][j].x << ' ';
    }
    cout << '\n';
  }
}