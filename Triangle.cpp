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

  while (t--) {
    vi a(3), b(3);
    for (auto& x : a) {
      cin >> x;
    }

    for (auto& x : b) {
      cin >> x;
    }

    sort(all(a));
    sort(all(b));

    if (a == b && a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}