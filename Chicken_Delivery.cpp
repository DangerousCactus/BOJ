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

  vector<vi> g(n, vi(n));
  vector<pii> houses, stores;

  rep(i, 0, n) {
    rep(j, 0, n) {
      cin >> g[i][j];

      if (g[i][j] == 1) {
        houses.emplace_back(i, j);
      } else if (g[i][j] == 2) {
        stores.emplace_back(i, j);
      }
    }
  }

  int best = INT_MAX;
  rep(mask, 0, 1 << sz(stores)) {
    if (__builtin_popcount(mask) != m) {
      continue;
    }

    int total = 0;

    for (auto& [hx, hy] : houses) {
      int hbest = INT_MAX;

      rep(i, 0, sz(stores)) {
        if (mask & (1 << i)) {
          int newDist = abs(hx - stores[i].first) + abs(hy - stores[i].second);
          hbest = min(hbest, newDist);
        }
      }

      total += hbest;
    }

    best = min(best, total);
  }

  cout << best;
}