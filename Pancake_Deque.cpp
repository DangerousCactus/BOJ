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

  rep(c, 1, t + 1) {
    int n;
    cin >> n;

    deque<int> d(n);
    for (auto& x : d) {
      cin >> x;
    }

    int best = -1;
    int total = 0;
    while (sz(d)) {
      if (d.front() < d.back()) {
        if (d.front() >= best) {
          total++;
        }
        best = max(best, d.front());
        d.pop_front();
      } else {
        if (d.back() >= best) {
          total++;
        }
        best = max(best, d.back());
        d.pop_back();
      }
    }

    cout << "Case #" << c << ": " << total << '\n';
  }
}