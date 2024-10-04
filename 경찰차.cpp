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

  int n, m;
  cin >> n >> m;

  vector<pii> pts(m);
  for (auto& [x, y] : pts) {
    cin >> x >> y;
  }

  auto f = [](pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
  };

  vector<map<pair<pii, pii>, int>> vals(m + 1);
  vals[0][make_pair(pii{1, 1}, pii{n, n})] = 0;

  rep(i, 1, m + 1) {
    for (auto& [coord, cost] : vals[i - 1]) {
      auto it = vals[i].find(make_pair(pts[i - 1], coord.second));
      if (it == vals[i].end() ||
          it->second > cost + f(pts[i - 1], coord.first)) {
        vals[i][make_pair(pts[i - 1], coord.second)] =
            cost + f(coord.first, pts[i - 1]);
      }

      it = vals[i].find(make_pair(coord.first, pts[i - 1]));
      if (it == vals[i].end() ||
          it->second > cost + f(coord.second, pts[i - 1])) {
        vals[i][make_pair(coord.first, pts[i - 1])] =
            cost + f(coord.second, pts[i - 1]);
      }
    }
  }

  pair<pii, pii> key;
  int best = INT_MAX;
  for (auto& [k, v] : vals.back()) {
    if (v < best) {
      key = k;
      best = v;
    }
  }
  cout << best << '\n';

  stack<int> cars;
  if (key.first == pts.back()) {
    cars.push(1);
  } else if (key.second == pts.back()) {
    cars.push(2);
  } else {
    assert(false);
  }

  for (int i = m - 1; i > 0; i--) {
    for (auto& [k, v] : vals[i]) {
      if (k.first == pts[i - 1]) {
        if (best == v + f(pts[i - 1], k.second)) {
          key = k;
          best = v;
          cars.push(2);
          break;
        }
      } else if (k.second == pts[i - 1]) {
        if (best == v + f(pts[i - 1], k.first)) {
          key = k;
          best = v;
          cars.push(1);
          break;
        }
      }
    }
  }

  while (sz(cars)) {
    cout << cars.top() << '\n';
    cars.pop();
  }
}