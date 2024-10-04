#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 400007;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  queue<pii> q;  // cost, dest
  q.emplace(0, n);

  vector<pii> cost(MAXN, {INT_MAX, 0});  // cost, ways
  cost[n] = {0, 1};

  while (sz(q)) {
    auto [c, z] = q.front();
    q.pop();

    if (c != cost[z].first) {
      continue;
    }

    vi cands{z - 1, z + 1, 2 * z};

    for (auto& cand : cands) {
      if (cand >= 0 && cand < MAXN) {
        if (c + 1 < cost[cand].first) {
          cost[cand] = {c + 1, cost[z].second};
          q.emplace(c + 1, cand);
        } else if (c + 1 == cost[cand].first) {
          cost[cand].second += cost[z].second;
        }
      }
    }
  }

  cout << cost[k].first << '\n' << cost[k].second;
}