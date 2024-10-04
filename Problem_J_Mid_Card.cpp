#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> seg_func(vector<ll>& ar, vector<ll>& br) {
  ll m = 1000000007;
  int na = ar.size();
  int nb = br.size();
  vector<ll> cr(min(na + nb - 1, 101), 0);
  int n = cr.size();
  rep(a, 0, na) {
    rep(b, 0, nb) {
      if (a + b == n) {
        break;
      }
      cr[a + b] += (ar[a] * br[b]) % m;
      cr[a + b] %= m;
    }
  }
  return cr;
}

// set up seg tree
vector<vector<vector<ll>>> create_tree(vector<ll> ar) {
  int n = ar.size();

  vector<vector<ll>> basear;
  rep(i, 0, n) {
    vector<ll> tmp;
    tmp.push_back(1);
    tmp.push_back(ar[i]);
    basear.push_back(tmp);
  }

  vector<vector<vector<ll>>> seg;
  seg.push_back(basear);
  int layercount = 0;
  while (seg[layercount].size() != 1) {  // generate next layer
    vector<vector<ll>> layer;
    rep(ii, 0, seg.back().size() / 2) {
      layer.push_back(
          seg_func(seg[layercount][ii * 2], seg[layercount][ii * 2 + 1]));
    }
    seg.push_back(layer);
    layercount++;
  }
  return seg;
}

ll query(vector<vector<vector<ll>>> seg, int l, int r, int k) {
  vector<ll> ans;
  ans.push_back(1);
  int li = l;
  int ri = r;
  rep(i, 0, seg.size()) {
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

// update function reimplemented in main, change to actually use pointers
void update(vector<vector<vector<ll>>> seg, int index, vector<ll> val) {
  unsigned int i = index;
  seg[0][i] = val;
  rep(ii, 1, seg.size()) {
    i /= 2;
    if (i == seg[ii].size()) {
      break;
    }
    seg[ii][i] = seg_func(seg[ii - 1][i * 2], seg[ii - 1][i * 2 + 1]);
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, c, t;
  cin >> n >> c >> t;

  vector<ll> ar;
  rep(snth, 0, n) {
    ll a, b;
    cin >> a >> b;
    ar.push_back(b - a + 1);
  }
  vector<vector<vector<ll>>> sar = create_tree(ar);

  rep(snt, 0, t) {
    int command;
    int d1, d2, d3;
    cin >> command;
    cin >> d1 >> d2 >> d3;
    if (command == 0) {
      cout << query(sar, d1 - 1, d2 - 1, d3) << "\n";
    } else {
      vector<ll> nar;
      nar.push_back(1);
      nar.push_back(d3 - d2 + 1);
      // update(sar,d1-1,nar);
      unsigned int i = d1 - 1;
      sar[0][i] = nar;
      rep(ii, 1, sar.size()) {
        i /= 2;
        if (i == sar[ii].size()) {
          break;
        }
        sar[ii][i] = seg_func(sar[ii - 1][i * 2], sar[ii - 1][i * 2 + 1]);
      }
    }
  }
  return 0;
}