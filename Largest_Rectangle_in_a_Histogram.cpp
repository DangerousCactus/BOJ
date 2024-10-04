#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - pw * 2 + 1);
      rep(j, 0, sz(jmp[k])) jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    assert(a < b);  // or return in f i f a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  while (cin >> n) {
    vector<ll> nums(n);
    priority_queue<pii, vector<pii>, greater<>> q;

    rep(i, 0, n) {
      cin >> nums[i];
      q.emplace(nums[i], i);
    }

    RMQ rmq(nums);
    set<int> bounds{-1, n};

    ll best = rmq.query(0, n) * n;
    while (sz(q)) {
      auto [v, idx] = q.top();
      q.pop();
      auto it = bounds.insert(idx).first;

      int l = *prev(it);
      int r = *next(it);

      best = max(best, (r - l - 1) * rmq.query(l + 1, r));
    }

    cout << best << '\n';
  }
}