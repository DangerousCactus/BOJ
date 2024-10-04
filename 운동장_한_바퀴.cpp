#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long double PI = acos(-1);

int main() {
  cin.tie(0)->sync_with_stdio(0);

  long double d, r;
  cin >> d >> r;

  cout << fixed << setprecision(6) << 2 * d + 2 * PI * r;
}