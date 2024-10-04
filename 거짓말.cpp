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

  int n, m, numTruth;
  cin >> n >> m >> numTruth;

  set<int> truth;
  rep(i, 0, numTruth) {
    int x;
    cin >> x;
    truth.insert(x);
  }

  vector<set<int>> parties(m);
  for (auto& party : parties) {
    int p;
    cin >> p;

    rep(i, 0, p) {
      int x;
      cin >> x;
      party.insert(x);
    }
  }

  int ct = 0;
  rep(z, 0, 100) {
    ct = 0;
    for (auto& party : parties) {
      vi out;
      set_intersection(all(party), all(truth), back_inserter(out));
      if (sz(out)) {
        truth.insert(all(party));
      } else {
        ct++;
      }
    }
  }

  cout << ct;
}