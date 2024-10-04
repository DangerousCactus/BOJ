#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topoSort(const vector<vi>& gr) {
  vi indeg(sz(gr)), ret;
  for (auto& li : gr)
    for (int x : li)
      indeg[x]++;
  queue<int> q;  // use priority queue for l e x i c . la rges t ans .
  rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
  while (!q.empty()) {
    int i = q.front();  // top () for pr ior ity queue
    ret.push_back(i);
    q.pop();
    for (int x : gr[i])
      if (--indeg[x] == 0)
        q.push(x);
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);

  rep(i, 0, m) {
    int k;
    cin >> k;

    vi order(k);
    for (auto& x : order) {
      cin >> x;
      x--;
    }

    rep(i, 0, k - 1) {
      adj[order[i]].push_back(order[i + 1]);
    }
  }

  auto out = topoSort(adj);
  if (sz(out) != n) {
    cout << 0;
  } else {
    for (auto& x : out) {
      cout << x + 1 << '\n';
    }
  }
}