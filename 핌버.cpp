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

  vi fib{1, 1};
  rep(i, 0, 35) {
    fib.push_back(fib[i] + fib[i + 1]);
  }

  vi DP(3E6 + 7, -1);
  DP[0] = 0;

  auto mex = [](int s) {
    int x = 0;
    while (s & (1 << x)) {
      x++;
    }
    return x;
  };

  function<int(int)> solve = [&](int x) {
    if (DP[x] != -1) {
      return DP[x];
    }

    int reachable = 0;
    for (auto& f : fib) {
      if (f <= x) {
        reachable |= (1 << solve(x - f));
      } else {
        break;
      }
    }

    return DP[x] = mex(reachable);
  };

  int xorAcc = 0;
  int n;
  cin >> n;

  rep(i, 0, n) {
    int x;
    cin >> x;
    xorAcc ^= solve(x);
  }

  cout << (xorAcc == 0 ? "cubelover" : "koosaga");
}