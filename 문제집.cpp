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

  vector<vi> adj(n);
  vi deg(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;

    adj[a - 1].push_back(b - 1);
    deg[b - 1]++;
  }

  priority_queue<int, vi, greater<>> pq;
  rep(i, 0, n) {
    if (deg[i] == 0) {
      pq.push(i);
    }
  }

  while (sz(pq)) {
    auto z = pq.top();
    pq.pop();

    cout << z + 1 << ' ';

    for (auto& x : adj[z]) {
      if (--deg[x] == 0) {
        pq.push(x);
      }
    }
  }
}