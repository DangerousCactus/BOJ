#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
  typedef int T;
  T unit = INT_MIN;
  function<T(T, T)> f;
  // T f(T a, T b) { return max(a, b); }  // (any associative fn)
  vector<T> s;
  int n;
  Tree(function<T(T, T)> f, T unit, int n = 0)
      : unit(unit), s(2 * n, unit), n(n), f(f) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) {  // query [ b , e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2)
        ra = f(ra, s[b++]);
      if (e % 2)
        rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  Tree maxtree([](int a, int b) { return max(a, b); }, INT_MIN, n);
  Tree mintree([](int a, int b) { return min(a, b); }, INT_MAX, n);

  rep(i, 0, n) {
    int x;
    cin >> x;
    maxtree.update(i, x);
    mintree.update(i, x);
  }

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    cout << mintree.query(a - 1, b) << ' ';
    cout << maxtree.query(a - 1, b) << '\n';
  }
}