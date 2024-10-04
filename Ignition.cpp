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

  vector<vector<pii>> adj(n);  // cost, dest

  rep(i, 0, n) {
    int a, b, c;
    a--, b--;
    adj[a].emplace_back(c, b);
    adj[c].emplace_back(a, b);
  }

  auto solve = [&adj](int start) {

  };

  double best = INT_MAX;

  rep(i, 0, n) {
    best = min(best, solve(i));
  }

  cout << fixed << setprecision(1) << best;
}