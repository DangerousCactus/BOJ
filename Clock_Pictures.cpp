#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const vi& s) {
  vi p(sz(s));
  rep(i, 1, sz(s)) {
    int g = p[i - 1];
    while (g && s[i] != s[g])
      g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}
vi match(const vi& s, const vi& pat) {
  vi temp = pat;
  temp.push_back(-1);
  temp.insert(temp.end(), all(pat));

  vi p = pi(temp), res;
  rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat))
      res.push_back(i - 2 * sz(pat));
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi a(n), b(n);
  for (auto& x : a) {
    cin >> x;
  }

  for (auto& x : b) {
    cin >> x;
  }

  sort(all(a));
  sort(all(b));

  a.insert(a.end(), a.begin(), a.begin() + n);

  vi c;
  adjacent_difference(a.begin(), a.end(), back_inserter(c));

  if (sz(match(c, b)) == 0) {
    cout << "im";
  }
  cout << "possible";
}