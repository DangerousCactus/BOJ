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

  int t;
  cin >> t;

  while (t--) {
    int n, w;
    cin >> n >> w;

    vector<vi> board(2, vi(n));
    for (auto& x : board) {
      for (auto& y : x) {
        cin >> y;
      }
    }

    if (n == 1) {
      cout << 1 + (board[0][0] + board[1][0] > w) << '\n';
      continue;
    }

    vector<vector<vi>> DP(n + 1, vector<vi>(4, vi(4, -1)));

    function<int(int, int, int)> solve = [&](int curr, int mask, int joinMask) {
      int& out = DP[curr][mask][joinMask];
      if (out != -1) {
        return out;
      }

      if (curr == n - 1) {
        if (mask & joinMask) {
          return 4 * n;
        }

        if ((mask | joinMask) == 0 && board[0][n - 1] + board[1][n - 1] <= w) {
          return 1;
        }

        return 2 - __builtin_popcount(mask | joinMask);
      }

      out = 2 - __builtin_popcount(mask) + solve(curr + 1, 0b00, joinMask);

      if (mask == 0b00) {
        if (board[0][curr] + board[1][curr] <= w) {
          out = min(out, 1 + solve(curr + 1, 0b00, joinMask));
        }
        if (board[0][curr] + board[0][curr + 1] <= w) {
          out = min(out, 2 + solve(curr + 1, 0b01, joinMask));
        }
        if (board[1][curr] + board[1][curr + 1] <= w) {
          out = min(out, 2 + solve(curr + 1, 0b10, joinMask));
        }
        if (board[0][curr] + board[0][curr + 1] <= w &&
            board[1][curr] + board[1][curr + 1] <= w) {
          out = min(out, 2 + solve(curr + 1, 0b11, joinMask));
        }
      }

      if (mask == 0b01 && board[1][curr] + board[1][curr + 1] <= w) {
        out = min(out, 1 + solve(curr + 1, 0b10, joinMask));
      }

      if (mask == 0b10 && board[0][curr] + board[0][curr + 1] <= w) {
        out = min(out, 1 + solve(curr + 1, 0b01, joinMask));
      }

      return out;
    };

    vi best;
    best.push_back(solve(0, 0, 0));

    if (board[0][0] + board[0][n - 1] <= w) {
      best.push_back(1 + solve(0, 0b01, 0b01));
    }

    if (board[1][0] + board[1][n - 1] <= w) {
      best.push_back(1 + solve(0, 0b10, 0b10));
    }

    if (board[0][0] + board[0][n - 1] <= w &&
        board[1][0] + board[1][n - 1] <= w) {
      best.push_back(2 + solve(0, 0b11, 0b11));
    }

    cout << *min_element(all(best)) << '\n';
  }
}