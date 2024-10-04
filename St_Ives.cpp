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

  long double x;
  while(cin >> x, x != 0){
    long double out = 1;
    rep(i, 0, 4){
      out = out * x + 1;
    }

    cout << fixed << setprecision(2) << out << '\n';
  }
}