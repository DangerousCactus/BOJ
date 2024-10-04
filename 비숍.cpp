#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<bitset<200>> vb;
struct Maxclique {
  double limit = 0.025, pk = 0;
  struct Vertex {
    int i, d = 0;
  };
  typedef vector<Vertex> vv;
  vb e;
  vv V;
  vector<vi> C;
  vi qmax, q, S, old;
  void init(vv& r) {
    for (auto& v : r)
      v.d = 0;
    for (auto& v : r)
      for (auto j : r)
        v.d += e[v.i][j.i];
    sort(all(r), [](auto a, auto b) { return a.d > b.d; });
    int mxD = r[0].d;
    rep(i, 0, sz(r)) r[i].d = min(i, mxD) + 1;
  }
  void expand(vv& R, int lev = 1) {
    S[lev] += S[lev - 1] - old[lev];
    old[lev] = S[lev - 1];
    while (sz(R)) {
      if (sz(q) + R.back().d <= sz(qmax))
        return;
      q.push_back(R.back().i);
      vv T;
      for (auto v : R)
        if (e[R.back().i][v.i])
          T.push_back({v.i});
      if (sz(T)) {
        if (S[lev]++ / ++pk < limit)
          init(T);
        int j = 0, mxk = 1, mnk = max(sz(qmax) - sz(q) + 1, 1);
        C[1].clear(), C[2].clear();
        for (auto v : T) {
          int k = 1;
          auto f = [&](int i) { return e[v.i][i]; };
          while (any_of(all(C[k]), f))
            k++;
          if (k > mxk)
            mxk = k, C[mxk + 1].clear();
          if (k < mnk)
            T[j++].i = v.i;
          C[k].push_back(v.i);
        }
        if (j > 0)
          T[j - 1].d = 0;
        rep(k, mnk, mxk + 1) for (int i : C[k]) T[j].i = i, T[j++].d = k;
        expand(T, lev + 1);
      } else if (sz(q) > sz(qmax))
        qmax = q;
      q.pop_back(), R.pop_back();
    }
  }
  vi maxClique() {
    init(V), expand(V);
    return qmax;
  }
  Maxclique(vb conn) : e(conn), C(sz(e) + 1), S(sz(C)), old(S) {
    rep(i, 0, sz(e)) V.push_back({i});
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int sum = 0;

  vector<vi> g(n, vi(n));
  for (auto& x : g) {
    for (auto& y : x) {
      cin >> y;
      sum += y;
    }
  }

  if (sum == 0) {
    cout << 0;
    exit(0);
  }

  vb conn(n * n);  // set bit to 1 if connected

  rep(i, 0, n) {
    rep(j, 0, n) {
      rep(a, 0, n) {
        rep(b, 0, n) {
          if (abs(i - a) != abs(j - b) && g[i][j] != 0 && g[a][b] != 0) {
            conn[i * n + j][a * n + b] = 1;
          }
        }
      }

      conn[i * n + j][i * n + j] = 0;
    }
  }

  Maxclique mc(conn);

  cout << sz(mc.maxClique());
}