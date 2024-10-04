#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi nums;
unordered_map<int, int> ct;

void add(int ind, int end) {
  ct[nums[ind]]++;
}  // add a [ ind ] (end = 0 or 1)
void del(int ind, int end) {
  if (--ct[nums[ind]] == 0) {
    ct.erase(nums[ind]);
  }
}  // remove a [ ind ]
int calc() {
  return sz(ct);
}  // compute current answer
vi mo(vector<pii> Q) {
  int L = 0, R = 0, blk = 350;  // ∼N/sqrt (Q)
  vi s(sz(Q)), res = s;
#define K(x) pii(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(all(s), 0);
  sort(all(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    pii q = Q[qi];
    while (L > q.first)
      add(--L, 0);
    while (R < q.second)
      add(R++, 1);
    while (L < q.first)
      del(L++, 0);
    while (R > q.second)
      del(--R, 1);
    res[qi] = calc();
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  nums.resize(n);
  for (auto& x : nums) {
    cin >> x;
  }

  int q;
  cin >> q;

  vector<pii> queries(q);
  for (auto& [a, b] : queries) {
    cin >> a >> b;
    a--;
  }

  auto ans = mo(queries);
  for (auto& x : ans) {
    cout << x << '\n';
  }
}