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

  vi books(n);
  for (auto& x : books) {
    cin >> x;
  }

  sort(books.rbegin(), books.rend());

  int ans = 0;
  rep(i, 0, n) {
    if (i % 3 == 2) {
      continue;
    }

    ans += books[i];
  }

  cout << ans;
}