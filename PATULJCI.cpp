#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution dis;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, c;
  cin >> n >> c;
  vi dwarves(n);
  vector<vi> colors(c);

  rep(i, 0, n) {
    cin >> dwarves[i];
    dwarves[i]--;
    colors[dwarves[i]].push_back(i);
  }

  int m;
  cin >> m;

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    bool found = false;
    rep(j, 0, 100) {
      int idx = dis(rng) % (b - a + 1) + a;

      int currColor = dwarves[idx];

      auto lower = lower_bound(all(colors[currColor]), a);
      auto upper = upper_bound(all(colors[currColor]), b);

      if ((upper - lower) * 2 > b - a + 1) {
        found = true;
        cout << "yes " << currColor + 1 << '\n';
        break;
      }
    }

    if (!found) {
      cout << "no\n";
    }
  }
}