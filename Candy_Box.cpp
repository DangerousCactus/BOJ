#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {  // a [ pos ] += d i f
    for (; pos < sz(s); pos |= pos + 1)
      s[pos] += dif;
  }
  ll query(int pos) {  // sum of values in [0 , pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1)
      res += s[pos - 1];
    return res;
  }
  int lower_bound(ll sum) {  // min pos s t sum of [0 , pos ] >= sum
    // Returns n i f no sum is >= sum, or −1 i f empty sum is .
    if (sum <= 0)
      return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vi> ops(n);
  Tree<int> ranks;
  for (auto& x : ops) {
    int t, a, b;
    cin >> t >> a;
    if (t == 2) {
      cin >> b;
      x = vi{a, b};
      ranks.insert(a);
    } else {
      x = vi{a};
    }
  }

  FT ft(sz(ranks));

  for (auto& op : ops) {
    if (sz(op) == 1) {
      int pos = ft.lower_bound(op[0]);
      cout << *ranks.find_by_order(pos) << '\n';
      ft.update(pos, -1);
    } else if (sz(op) == 2) {
      int rank = ranks.order_of_key(op[0]);
      ft.update(rank, op[1]);
    } else {
      assert(false);
    }
  }
}