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

  vector<string> triangle = {"  *  ", " * * ", "*****"};

  int curr = 3;
  while (curr < n) {
    vector<string> nextLayer;
    for (auto& row : triangle) {
      nextLayer.insert(nextLayer.end(), row + ' ' + row);
    }

    for (auto& row : triangle) {
      row = string(curr, ' ') + row + string(curr, ' ');
    }

    triangle.insert(triangle.end(), all(nextLayer));

    curr *= 2;
  }

  for (auto& row : triangle) {
    cout << row << '\n';
  }
}