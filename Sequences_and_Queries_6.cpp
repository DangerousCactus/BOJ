#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi nums;
vi ct(100007);
vector<list<int>::iterator> iter(100007);
vector<list<int>> mxct(1);

void add(int ind, int end) {
  mxct[ct[nums[ind]]].erase(iter[nums[ind]]);
  ct[nums[ind]]++;

  if (sz(mxct) <= ct[nums[ind]]) {
    mxct.emplace_back();
  }

  mxct[ct[nums[ind]]].push_back(nums[ind]);
  iter[nums[ind]] = prev(mxct[ct[nums[ind]]].end());
}  // add a [ ind ] (end = 0 or 1)

void del(int ind, int end) {
  mxct[ct[nums[ind]]].erase(iter[nums[ind]]);
  ct[nums[ind]]--;

  mxct[ct[nums[ind]]].push_back(nums[ind]);
  iter[nums[ind]] = prev(mxct[ct[nums[ind]]].end());

  while (sz(mxct) && sz(mxct.back()) == 0) {
    mxct.pop_back();
  }
}  // remove a [ ind ]

int calc() {
  return sz(mxct) - 1;
}  // compute current answer

vi mo(vector<pii> Q) {
  int L = 0, R = 0;
  const int blk = 316;  // ∼N/sqrt (Q)
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

  mxct.reserve(100007);
  rep(i, 0, 100007) {
    mxct[0].push_back(i);
    iter[i] = prev(mxct[0].end());
  }

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