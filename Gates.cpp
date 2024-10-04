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

  int g, p;
  cin >> g >> p;

  set<int> gates;
  rep(i, 1, g + 1) {
    gates.insert(i);
  }

  vi planes(p);
  for (auto& x : planes) {
    cin >> x;
  }

  int ct = 0;
  for (auto& x : planes) {
    if (!sz(gates) || x < *gates.begin()) {
      break;
    }

    auto it = prev(gates.upper_bound(x));
    gates.erase(it);
    ct++;
  }

  cout << ct;
}