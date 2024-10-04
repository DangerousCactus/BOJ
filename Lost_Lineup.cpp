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

  int n;
  cin >> n;

  vi idxs(n);
  idxs[0] = 1;

  rep(i, 1, n) {
    int x;
    cin >> x;
    idxs[x + 1] = i + 1;
  }

  for (auto& x : idxs) {
    cout << x << ' ';
  }
}