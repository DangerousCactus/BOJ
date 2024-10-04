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

  vector<string> board(9);
  for (auto& x : board) {
    cin >> x;
  }

  function<void(int, int, vector<string>&)> solve = [&](int x, int y,
                                                        vector<string>& g) {
    // cout << x << ' ' << y << endl;
    if (x == 9) {
      for (auto& a : g) {
        cout << a << endl;
      }
      exit(0);
    }

    if (g[x][y] != '0') {
      solve(x + (y + 1) / 9, (y + 1) % 9, g);
      return;
    }

    rep(i, 1, 10) {
      char cand = '0';
      cand += i;

      bool possible = true;

      rep(j, 0, 9) {
        if (g[j][y] == cand) {
          possible = false;
        }

        if (g[x][j] == cand) {
          possible = false;
        }
      }
      int bx = x / 3 * 3;
      int by = y / 3 * 3;

      rep(a, bx, bx + 3) {
        rep(b, by, by + 3) {
          if (g[a][b] == cand) {
            possible = false;
          }
        }
      }

      if (possible) {
        g[x][y] = cand;
        solve(x + (y + 1) / 9, (y + 1) % 9, g);
        g[x][y] = '0';
      }
    }
  };

  solve(0, 0, board);
  assert(false);
}