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

  deque<pii> q;  // cost, dest
  q.emplace_back(0, n);

  vi cost(MAXN, INT_MAX);  // cost, ways
  cost[n] = 0;

  while (sz(q)) {
    auto [c, z] = q.front();
    q.pop_front();

    if (c != cost[z]) {
      continue;
    }

    vector<pii> cands{{z - 1, 1}, {z + 1, 1}, {2 * z, 0}};

    for (auto& [cand, dc] : cands) {
      if (cand >= 0 && cand < MAXN) {
        if (c + dc < cost[cand]) {
          cost[cand] = c + dc;
          if (dc == 0) {
            q.emplace_front(cost[cand], cand);
          } else {
            q.emplace_back(cost[cand], cand);
          }
        }
      }
    }
  }

  cout << cost[k];
}