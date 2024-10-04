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
  vi g(n);

  function<int(int, vi&)> solve = [&](int row, auto& board) {
    if (row == n) {
      return 1;
    }

    int out = 0;
    rep(col, 0, n) {
      if (board[row] & (1 << col)) {
        continue;
      }

      auto oldBoard = board;
      rep(j, 0, n - row) {
        if (row + j < n) {
          board[row + j] |= (1 << col);

          if (col - j >= 0) {
            board[row + j] |= 1 << (col - j);
          }

          if (col + j < n) {
            board[row + j] |= 1 << (col + j);
          }
        }
      }

      out += solve(row + 1, board);
      board = oldBoard;
    }

    return out;
  };

  cout << solve(0, g);
}