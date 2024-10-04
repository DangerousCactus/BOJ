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

  vector<vi> adj(n);
  vi deg(n);
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
    deg[a - 1]++;
    deg[b - 1]++;
  }

  vi p(n, -1);

  function<void(int, int)> dfs = [&](int c, int par) {
    for (auto& x : adj[c]) {
      if (x != par) {
        p[x] = c;
        dfs(x, c);
      }
    }
  };

  dfs(0, -1);

  rep(i, 1, n) {
    cout << p[i] + 1 << '\n';
  }
}