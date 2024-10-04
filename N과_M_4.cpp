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

  vi out;

  function<void(int, int)> solve = [&](int x, int needed) {
    if (needed == 0) {
      for (auto& z : out) {
        cout << z << ' ';
      }
      cout << '\n';
      return;
    }

    rep(i, x, n + 1) {
      out.push_back(i);
      solve(i, needed - 1);
      out.pop_back();
    }
  };

  solve(1, m);
}