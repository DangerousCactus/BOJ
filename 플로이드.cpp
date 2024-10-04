#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
  int n = sz(m);
  rep(i, 0, n) m[i][i] = min(m[i][i], 0LL);
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) if (m[i][k] != inf && m[k][j] != inf) {
    auto newDist = max(m[i][k] + m[k][j], -inf);
    m[i][j] = min(m[i][j], newDist);
  }
  rep(k, 0, n) if (m[k][k] < 0) rep(i, 0, n)
      rep(j, 0, n) if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<ll>> dist(n, vector<ll>(n, inf));

  rep(i, 0, m) {
    ll a, b, c;
    cin >> a >> b >> c;

    dist[a - 1][b - 1] = min(dist[a - 1][b - 1], c);
  }

  floydWarshall(dist);
  for (auto& x : dist) {
    for (auto& y : x) {
      if (y == inf) {
        y = 0;
      }
      cout << y << ' ';
    }
    cout << '\n';
  }
}