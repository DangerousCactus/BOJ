#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool find(int j, vector<vi> &g, vi &btoa, vi &vis) {
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

int dfsMatching(vector<vi> &g, vi &btoa) {
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

vi cover(vector<vi> &g, int n, int m) {
  vi match(m, -1);
  int res = dfsMatching(g, match);
  vector<bool> lfound(n, true), seen(m);
  for (int it : match)
    if (it != -1)
      lfound[it] = false;
  vi q, cover;
  rep(i, 0, n) if (lfound[i]) q.push_back(i);
  while (!q.empty()) {
    int i = q.back();
    q.pop_back();
    lfound[i] = 1;
    for (int e : g[i])
      if (!seen[e] && match[e] != -1) {
        seen[e] = true;
        q.push_back(match[e]);
      }
  }
  rep(i, 0, n) if (!lfound[i]) cover.push_back(i);
  rep(i, 0, m) if (seen[i]) cover.push_back(n + i);
  assert(sz(cover) == res);
  return cover;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    int c, d, v;
    cin >> c >> d >> v;
    map<int, vi> cl, ch, dl, dh;

    int clidx = 0;
    int dlidx = 0;

    rep(i, 0, v) {
      char c1, c2;
      int a, b;
      cin >> c1 >> a >> c2 >> b;
      a--, b--;
      if (c1 == 'C') {
        cl[a].push_back(clidx);
        dh[b].push_back(clidx);
        clidx++;
      } else {
        dl[a].push_back(dlidx);
        ch[b].push_back(dlidx);
        dlidx++;
      }
    }

    vector<vi> adj(clidx);

    for (auto &x : cl) {
      auto currCat = x.first;
      for (auto &y : ch[currCat]) {
        for (auto &z : x.second) {
          adj[z].push_back(y);
        }
      }
    }

    for (auto &x : dl) {
      auto currDog = x.first;
      for (auto &y : dh[currDog]) {
        for (auto &z : x.second) {
          adj[y].push_back(z);
        }
      }
    }

    // make an edge to all other conflicting viewers
    cout << v - sz(cover(adj, clidx, dlidx)) << '\n';
  }
}