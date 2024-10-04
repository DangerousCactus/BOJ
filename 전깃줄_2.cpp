#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class I>
vi lis(const vector<I>& S) {
  if (S.empty())
    return {};
  vi prev(sz(S));
  typedef pair<I, int> p;
  vector<p> res;
  rep(i, 0, sz(S)) {
    // change 0 −> i for longest non−decreasing subsequence
    auto it = lower_bound(all(res), p{S[i], 0});
    if (it == res.end())
      res.emplace_back(), it = res.end() - 1;
    *it = {S[i], i};
    prev[i] = it == res.begin() ? 0 : (it - 1)->second;
  }
  int L = sz(res), cur = res.back().second;
  vi ans(L);
  while (L--)
    ans[L] = cur, cur = prev[cur];
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pii> lines(n);
  for (auto& [a, b] : lines) {
    cin >> b >> a;
  }

  sort(all(lines), [](pii& i, pii& j) { return i.second < j.second; });

  auto used = lis(lines);
  vi indices(n);
  iota(all(indices), 0);

  deque<int> removed;
  set_difference(all(indices), all(used), back_inserter(removed));

  cout << sz(removed) << '\n';
  for (auto& x : removed) {
    cout << lines[x].second << '\n';
  }
}