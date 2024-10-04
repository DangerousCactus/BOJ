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
  n /= 2;

  vector<pii> top, bottom, left, right;  // coord, idx
  map<int, vector<pii>*> mapping{
      {1, &top}, {2, &bottom}, {3, &left}, {4, &right}};

  rep(i, 0, n) {
    rep(j, 0, 2) {
      pii point;
      cin >> point.first >> point.second;
      mapping[point.first]->emplace_back(point.second, i);
    }
  }

  sort(all(top));
  sort(all(right));
  sort(all(bottom), greater<>());
  sort(all(left), greater<>());

  vi order;
  transform(all(top), back_inserter(order), [](auto p) { return p.second; });
  transform(all(right), back_inserter(order), [](auto p) { return p.second; });
  transform(all(bottom), back_inserter(order), [](auto p) { return p.second; });
  transform(all(left), back_inserter(order), [](auto p) { return p.second; });

  int total = 0;
  int mx = 0;

  rep(i, 0, n) {
    ll mask = 0;

    auto start = find(all(order), i);
    auto it = next(start);
    while (*it != *start) {
      mask ^= (1 << *it);
      it++;
    }

    int ct = __builtin_popcountll(mask);
    total += ct;
    mx = max(mx, ct);
  }

  cout << total / 2 << '\n' << mx;
}