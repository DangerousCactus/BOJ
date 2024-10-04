#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  vi e;
  vector<vi> group;
  UF(int n) : e(n, -1), group(n, vi()) {
    rep(i, 0, n) {
      group[i].push_back(i);
    }
  }
  vi& getGroup(int x) { return group[find(x)]; }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    group[a].insert(group[a].end(), all(group[b]));
    group[b].clear();
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  while (cin >> n >> m) {
    UF uf(n + 1);
    vector<ll> weight(n + 1, 0);

    rep(i, 0, m) {
      char c;
      int a, b, w;
      cin >> c >> a >> b;

      if (c == '!') {
        cin >> w;

        if (uf.size(a) < uf.size(b)) {
          swap(a, b);
          w *= -1;
        }

        // b is smaller
        int delta = w + weight[a] - weight[b];

        // add delta to every element of b
        if (delta != 0) {
          for (auto& x : uf.getGroup(b)) {
            weight[x] += delta;
          }
        }

        uf.join(a, b);

      } else if (c == '?') {
        if (uf.find(a) == uf.find(b)) {
          cout << weight[b] - weight[a] << '\n';
        } else {
          cout << "UNKNOWN\n";
        }
      }
    }
  }
}