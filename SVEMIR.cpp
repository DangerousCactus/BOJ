#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  vi e;
  vector<pii> st;
  UF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  int time() { return sz(st); }
  void rollback(int t) {
    for (int i = time(); i-- > t;)
      e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<pii>> planets(3, vector<pii>(n));
  rep(i, 0, n) {
    rep(j, 0, 3) {
      cin >> planets[j][i].first;
      planets[j][i].second = i;
    }
  }

  UF uf(n);

  priority_queue<vi, vector<vi>, greater<>> pq;
  ll cost = 0;

  for (auto& x : planets) {
    sort(all(x));
    rep(i, 0, n - 1) {
      pq.push(
          vi{abs(x[i].first - x[i + 1].first), x[i].second, x[i + 1].second});
    }
  }

  while (sz(pq)) {
    auto z = pq.top();
    pq.pop();

    if (uf.join(z[1], z[2])) {
      cost += z[0];
    }
  }

  cout << cost;
}