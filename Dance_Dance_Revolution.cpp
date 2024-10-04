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

  vector<map<int, int>> adj(5);  // cost, dest
  adj[0] = {{1, 2}, {2, 2}, {3, 2}, {4, 2}};
  adj[1] = {{1, 1}, {2, 3}, {3, 4}, {4, 3}};
  adj[2] = {{1, 3}, {2, 1}, {3, 3}, {4, 4}};
  adj[3] = {{1, 4}, {2, 3}, {3, 1}, {4, 3}};
  adj[4] = {{1, 3}, {2, 4}, {3, 3}, {4, 1}};

  vi nums;
  {
    int x;
    for (cin >> x; x != 0; cin >> x) {
      nums.push_back(x);
    }
  }

  vector<vi> DP(5, vi(5, -1));
  DP[0][0] = 0;

  for (auto& z : nums) {
    vector<vi> nDP(5, vi(5, -1));

    rep(i, 0, 5) {
      rep(j, 0, 5) {
        if (DP[i][j] == -1) {
          continue;
        }

        if (nDP[i][z] == -1) {
          nDP[i][z] = INT_MAX;
        }
        nDP[i][z] = min(nDP[i][z], DP[i][j] + adj[j][z]);

        if (nDP[z][j] == -1) {
          nDP[z][j] = INT_MAX;
        }
        nDP[z][j] = min(nDP[z][j], DP[i][j] + adj[i][z]);
      }
    }

    DP = nDP;
  }

  int out = INT_MAX;
  for (auto& x : DP) {
    for (auto& y : x) {
      if (y != -1) {
        out = min(out, y);
      }
    }
  }
  cout << out;
}