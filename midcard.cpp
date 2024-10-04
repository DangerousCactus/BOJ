#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;
typedef __int128_t ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> seg_func(vector<ll>& ar, vector<ll>& br) {
  ll m = 1000000007;
  int na = (int)ar.size();
  int nb = (int)br.size();
  vector<ll> cr(min(na + nb - 1, 101), 0);

  int n = sz(cr);
  rep(a, 0, na) {
    rep(b, 0, min(nb, n - a)) {
      cr[a + b] += (ar[a] * br[b]) % m;
      cr[a + b] %= m;

      if (cr[a + b] < 0) {
        cr[a + b] = m - cr[a + b];
      }
    }
  }

  return cr;
}

vector<vector<vector<ll>>> create_tree(vector<ll>& ar) {
  vector<vector<ll>> basear;
  for (auto& x : ar) {
    basear.push_back(vector<ll>{1, x});
  }

  vector<vector<vector<ll>>> seg;
  seg.push_back(basear);

  while (sz(seg.back()) != 1) {
    vector<vector<ll>> layer;
    rep(ii, 0, sz(seg.back()) / 2) {
      layer.push_back(seg_func(seg.back()[2 * ii], seg.back()[2 * ii + 1]));
    }
    seg.push_back(layer);
  }
  return seg;
}

ll query(vector<vector<vector<ll>>>& seg, int l, int r, int k) {
  vector<ll> ans{1};
  int li = l;
  int ri = r;

  rep(i, 0, sz(seg)) {
    if (li > ri) {
      break;
    }
    if (li % 2 == 1) {
      ans = seg_func(ans, seg[i][li]);
      li++;
    }
    if (ri % 2 == 0) {
      ans = seg_func(ans, seg[i][ri]);
      ri--;
    }

    li /= 2;
    ri /= 2;
  }
  return ans[k];
}

void update(vector<vector<vector<ll>>>& seg, int index, vector<ll> val) {
  int i = index;
  seg[0][i] = val;

  rep(ii, 1, sz(seg)) {
    i /= 2;
    if (i == sz(seg[ii])) {
      break;
    }
    seg[ii][i] = seg_func(seg[ii - 1][i * 2], seg[ii - 1][i * 2 + 1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c, t;
  cin >> n >> c >> t;

  vector<ll> ar;
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    ar.push_back(b - a + 1);
  }

  auto sar = create_tree(ar);

  while (t--) {
    vector<ll> q(4);
    for (auto& x : q) {
      long long xx;
      cin >> xx;
      x = xx;
    }

    if (q[0] == 0) {
      long long out = query(sar, q[1] - 1LL, q[2] - 1LL, q[3]);
      assert(out >= 0 && out < 1E9 + 7);
      cout << out << '\n';
    } else {
      update(sar, q[1] - 1, vector<ll>{1, q[3] - q[2] + 1});
    }
  }

  return 0;
}