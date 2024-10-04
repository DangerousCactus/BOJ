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

  vi in(n), post(n);
  vi inidx(n + 1);

  rep(i, 0, n) {
    cin >> in[i];
    inidx[in[i]] = i;
  }

  for (auto& x : post) {
    cin >> x;
  }

  function<void(int, int, int, int)> solve = [&](int il, int ir, int pl,
                                                 int pr) {
    if (il > ir) {
      return;
    }

    int m = inidx[post[pr]];
    int ls = m - il;

    cout << post[pr] << ' ';

    if (il != ir) {
      solve(il, m - 1, pl, pl + ls - 1);
      solve(m + 1, ir, pl + ls, pr - 1);
    }
  };

  solve(0, n - 1, 0, n - 1);
}