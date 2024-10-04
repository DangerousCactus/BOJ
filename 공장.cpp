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

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi m(1000007);
  rep(i, 0, n) {
    int x;
    cin >> x;
    m[x] = i;
  }

  vi nums(n);
  rep(i, 0, n) {
    int x;
    cin >> x;
    nums[m[x]] = i;
  }

  Tree<int> tree;
  rep(i, 0, n) {
    tree.insert(i);
  }

  ll total = 0;

  for (int i = n - 1; i >= 0; i--) {
    auto order = tree.order_of_key(nums[i]);
    total += (sz(tree) - 1) - order;
    tree.erase(nums[i]);
  }

  cout << total;
}