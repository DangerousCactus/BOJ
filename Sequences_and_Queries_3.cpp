#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
  Node *l = 0, *r = 0;
  int lo, hi;
  vector<int> nums;

  Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
    nums.assign(v.begin() + lo, v.begin() + hi);
    sort(all(nums));

    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
    }
  }

  int query(int L, int R, int k) {
    if (R <= lo || hi <= L)
      return 0;
    if (L <= lo && hi <= R) {
      auto it =  upper_bound(all(nums), k);
      return nums.end() - it;
    }
    return l->query(L, R, k) + r->query(L, R, k);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi nums(n);
  for (auto& x : nums) {
    cin >> x;
  }

  Node node(nums, 0, n);

  int q;
  cin >> q;

  int lastAns = 0;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;

    a ^= lastAns;
    b ^= lastAns;
    c ^= lastAns;

    lastAns = node.query(a - 1, b, c);
    cout << lastAns << '\n';
  }
}