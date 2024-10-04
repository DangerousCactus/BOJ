#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  string inorder, preorder, postorder;

  map<char, pair<char, char>> m;
  rep(i, 0, n) {
    char a, b, c;
    cin >> a >> b >> c;

    m[a] = {b, c};
  }


  function<void(char)> traverse = [&](char c) {
    if (c == '.') {
      return;
    }
    preorder += c;
    traverse(m[c].first);
    inorder += c;
    traverse(m[c].second);
    postorder += c;
  };

  traverse('A');
  cout << preorder << '\n' << inorder << '\n' << postorder;
}