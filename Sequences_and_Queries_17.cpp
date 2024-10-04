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
  static constexpr T unit = INT_MAX;
  T f(T a, T b) { return min(a, b); }  // (any associative fn)
  vector<T> s;
  int n;
  Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
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

  int n;
  cin >> n;
  vi nums(n);
  Tree tree(n);

  rep(i, 0, n) {
    cin >> nums[i];
    tree.update(i, nums[i]);
  }

  int q;
  cin >> q;

  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;

    if (t == 1) {
      tree.update(a - 1, nums[a - 1] = b);
    } else if (t == 2) {
      cout << tree.query(a - 1, b) << '\n';
    }
  }
}