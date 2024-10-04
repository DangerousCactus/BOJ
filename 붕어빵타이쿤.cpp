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

  int n, m;
  cin >> n >> m;

  vi board(n);
  for (auto& row : board) {
    rep(i, 0, m) {
      int num;
      cin >> num;
      row = (row << 1) | num;
    }
  }

  auto solve = [&n, &m, &board](int mask) -> string {
    vi ans(n);
    ans[0] = mask;

    rep(i, 1, n) {
      ans[i] = board[i - 1];

      if (i - 2 >= 0) {
        ans[i] ^= ans[i - 2];
      }
      ans[i] ^= ans[i - 1];
      ans[i] ^= (ans[i - 1] << 1) & ((1 << m) - 1);
      ans[i] ^= (ans[i - 1] >> 1) & ((1 << m) - 1);
    }

    // verify
    int lastRow = board[n - 1];
    if (n - 2 >= 0) {
      lastRow ^= ans[n - 2];
    }
    lastRow ^= ans[n - 1];
    lastRow ^= (ans[n - 1] >> 1) & ((1 << m) - 1);
    lastRow ^= (ans[n - 1] << 1) & ((1 << m) - 1);

    string out;
    if (lastRow == 0) {
      rep(i, 0, n) {
        for (int j = m - 1; j >= 0; j--) {
          out.push_back('0' + ((ans[i] & (1 << j)) != 0));
          out.push_back(' ');
        }
        out.push_back('\n');
      }
    }
    return out;
  };

  string ans;

  // consider every possible mask for top row
  rep(i, 0, (1 << m)) {
    auto out = solve(i);

    if (sz(out) == 0) {
      continue;
    }

    if (sz(ans) == 0) {
      ans = out;
    } else {
      int oldCost = count(all(ans), '1');
      int newCost = count(all(out), '1');

      if (newCost < oldCost || (newCost == oldCost && out < ans)) {
        ans = out;
      }
    }
  }

  if (sz(ans) == 0) {
    cout << "IMPOSSIBLE";
  } else {
    cout << ans;
  }
}