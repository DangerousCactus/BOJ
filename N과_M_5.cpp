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

  set<vi> ans;

  vi order(n);
  for (auto& x : order) {
    cin >> x;
  }
  sort(all(order));

  do {
    if (sz(set<int>(order.begin(), order.begin() + m)) == m) {
      ans.emplace(order.begin(), order.begin() + m);
    }
  } while (next_permutation(all(order)));

  for (auto& x : ans) {
    for (auto& y : x) {
      cout << y << ' ';
    }
    cout << '\n';
  }
}
