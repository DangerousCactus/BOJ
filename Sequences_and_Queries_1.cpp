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
  static constexpr T unit = 0;
  T f(T a, T b) { return a + b; }  // (any associative fn)
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

  // largest values on top
  priority_queue<pii> pq;
  rep(i, 0, n) {
    int a;
    cin >> a;
    pq.emplace(a, i);
  }

  int q;
  cin >> q;
  vector<vi> queries(q, vi(4));
  rep(i, 0, q) {
    cin >> queries[i][1] >> queries[i][2] >> queries[i][0];
    queries[i][3] = i;
  }

  sort(all(queries), greater<>());

  Tree tr(n);
  vi ans(q);

  for (auto& x : queries) {
    while (sz(pq) && pq.top().first > x[0]) {
      tr.update(pq.top().second, 1);
      pq.pop();
    }

    ans[x[3]] = tr.query(x[1] - 1, x[2]);
  }

  for (auto& x : ans) {
    cout << x << '\n';
  }
}