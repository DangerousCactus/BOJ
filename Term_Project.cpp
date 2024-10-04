#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template <class G, class F>
int dfs(int j, G& g, F& f) {
  int low = val[j] = ++Time, x;
  z.push_back(j);
  for (auto e : g[j])
    if (comp[e] < 0)
      low = min(low, val[e] ?: dfs(e, g, f));
  if (low == val[j]) {
    do {
      x = z.back();
      z.pop_back();
      comp[x] = ncomps;
      cont.push_back(x);
    } while (x != j);
    f(cont);
    cont.clear();
    ncomps++;
  }
  return val[j] = low;
}
template <class G, class F>
void scc(G& g, F f) {
  int n = sz(g);
  val.assign(n, 0);
  comp.assign(n, -1);
  Time = ncomps = 0;
  rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vi nums(n);

    vector<vi> adj(n);
    rep(i, 0, n) {
      int x;
      cin >> x;

      adj[i].push_back(x - 1);
    }

    scc(adj, [](...) {});
    map<int, int> m;
    for (auto& x : comp) {
      m[x]++;
    }

    int ans = 0;
    rep(i, 0, n) {
      if (m[comp[i]] == 1 && adj[i][0] != i) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}