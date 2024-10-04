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

  int n;
  cin >> n;

  vi a(n);
  for (auto& x : a) {
    cin >> x;
  }

  int m;
  cin >> m;

  vi b(m);
  for (auto& x : b) {
    cin >> x;
  }
  unordered_map<int, int> ma;

  vi pa;
  for (auto& x : a) {
    pa.push_back(0);
    for (auto& px : pa) {
      px += x;
      ma[px]++;
    }
  }

  ll out = 0;
  vi pb;
  for (auto& x : b) {
    pb.push_back(0);
    for (auto& px : pb) {
      px += x;
      out += ma[t - px];
    }
  }

  cout << out;
}