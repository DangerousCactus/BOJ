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

  auto mex = [](set<int> s) {
    int val = 0;
    while (s.count(val)) {
      val++;
    }
    return val;
  };

  int n;
  cin >> n;

  vi grundy(1007, -1);
  grundy[0] = grundy[1] = 0;

  function<int(int)> solve = [&](int x) {
    if (grundy[x] != -1) {
      return grundy[x];
    }

    set<int> reachable;
    rep(i, 0, x - 1) {
      reachable.insert(solve(i) ^ solve(x - 2 - i));
    }

    return grundy[x] = mex(reachable);
  };

  if (solve(n) == 0) {
    cout << 2;
  } else {
    cout << 1;
  }
}