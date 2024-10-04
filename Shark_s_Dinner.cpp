#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
  if (btoa[j] == -1)
    return 1;
  vis[j] = 1;
  int di = btoa[j];
  for (int e : g[di])
    if (!vis[e] && find(e, g, btoa, vis)) {
      btoa[e] = di;
      return 1;
    }
  return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
  vi vis;
  rep(i, 0, sz(g)) {
    vis.assign(sz(btoa), 0);
    for (int j : g[i])
      if (find(j, g, btoa, vis)) {
        btoa[j] = i;
        break;
      }
  }
  return sz(btoa) - (int)count(all(btoa), -1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<vi, int> m;

  vector<vi> sharks(n, vi(3));
  for (auto& x : sharks) {
    for (auto& y : x) {
      cin >> y;
    }
    m[x]++;
  }

  sort(all(sharks));
  sharks.erase(unique(all(sharks)), sharks.end());

  vector<vi> adj(sz(sharks));
  rep(i, 0, sz(sharks)) {
    rep(j, 0, sz(sharks)) {
      if (sharks[i][0] >= sharks[j][0] && sharks[i][1] >= sharks[j][1] &&
          sharks[i][2] >= sharks[j][2] && i != j) {
        adj[i].push_back(j);
      }
    }

    rep(k, 0, m[sharks[i]]) {
      adj.push_back(adj[i]);
    }
  }

  vi btoa(n, -1);

  cout << sz(sharks) - dfsMatching(adj, btoa);
}