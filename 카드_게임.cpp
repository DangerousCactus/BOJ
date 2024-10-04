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
  UF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    // if (e[a] > e[b])
    //   swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<bool> nums(n + 1);
  UF uf(n + 2);

  rep(i, 0, m) {
    int x;
    cin >> x;
    nums[x] = true;
  }

  rep(i, 0, n - 1) {
    if (!nums[i]) {
      uf.join(i + 1, i);
    }
  }

  while (k--) {
    int x;
    cin >> x;

    auto cand = uf.find(x + 1);
    if (cand == uf.find(n + 1)) {
      cand = uf.find(1);
    }

    cout << cand << '\n';
    uf.join(uf.find(cand + 1), cand);
  }
}