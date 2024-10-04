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

  vi memory(n);
  for (auto& x : memory) {
    cin >> x;
  }

  vi costs(n);
  for (auto& x : costs) {
    cin >> x;
  }

  vi best(100 * n + 1, -1);
  best[0] = 0;

  rep(i, 0, n) {
    for (int j = sz(best); j >= costs[i]; j--) {
      if (best[j - costs[i]] != -1) {
        best[j] = max(best[j], best[j - costs[i]] + memory[i]);
      }
    }
  }

  rep(i, 0, sz(best)) {
    if (best[i] >= m) {
      cout << i;
      break;
    }
  }
}