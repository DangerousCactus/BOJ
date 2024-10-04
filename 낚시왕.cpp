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

  typedef struct {
    int s, z;
    pii d;
  } shark;

  map<int, pii> dirs{{1, {-1, 0}}, {2, {1, 0}}, {3, {0, 1}}, {4, {0, -1}}};

  int r, c, m;
  cin >> r >> c >> m;

  vector<vi> g(r, vi(c, -1));

  vector<shark> sharks;
  rep(i, 0, m) {
    int a, b, d;
    shark s;
    cin >> a >> b;
    cin >> s.s >> d >> s.z;
    s.d = dirs[d];

    g[a - 1][b - 1] = sz(sharks);
    sharks.push_back(s);
  }

  ll total = 0;

  rep(i, 0, c) {
    rep(j, 0, r) {
      if (g[j][i] != -1) {
        total += sharks[g[j][i]].z;
        g[j][i] = -1;
        break;
      }
    }

    vector<vi> ng(r, vi(c, -1));

    rep(cr, 0, r) {
      rep(cc, 0, c) {
        if (g[cr][cc] == -1) {
          continue;
        }

        auto& s = sharks[g[cr][cc]];
        auto& dir = s.d;
        int time = s.s;

        if (dir.first != 0) {
          time %= (r - 1) * 2;
        } else {
          time %= (c - 1) * 2;
        }

        int nx = cr;
        int ny = cc;

        while (time) {
          nx += dir.first;
          ny += dir.second;

          if (nx < 0) {
            nx = 1;
            dir = pii{-dir.first, -dir.second};
          }

          if (ny < 0) {
            ny = 1;
            dir = pii{-dir.first, -dir.second};
          }

          if(nx == r){
            nx = r - 2;
            dir = pii{-dir.first, -dir.second};
          }

          if(ny == c){
            ny = c - 2;
            dir = pii{-dir.first, -dir.second};
          }

          time--;
        }

        if(ng[nx][ny] == -1 || s.z > sharks[ng[nx][ny]].z){
          ng[nx][ny] = g[cr][cc];
        }
      }
    }

    g = ng;
  }

  cout << total;
}
