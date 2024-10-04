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

  vector<bool> color(n);
  queue<int> q;
  rep(i, 0, n) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }

  while (sz(q)) {
    auto z = q.front();
    q.pop();

    for(auto & x : adj[z]){
      if(!color[z]){
        color[x] = true;
      }

      if(--deg[x] == 1){
        q.push(x);
      }
    }
  }

  int total = accumulate(all(color), 0);
  cout << min(total, n - total);
}