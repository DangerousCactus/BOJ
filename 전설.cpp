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

  int c, n;
  cin >> c >> n;

  typedef struct {
    bool terminal = false;
    vi links = vi(26, -1);

    int& operator[](int x) { return links[x]; }
  } Node;



  vector<Node> nodes(1);

  vector<string> colors(c);
  vector<string> names(n);

  for (auto& x : colors) {
    cin >> x;
  }

  for (auto& x : names) {
    cin >> x;
  }

  for (auto& x : colors) {
    int curr = 0;
    for (auto& ch : x) {
      if (nodes[curr][ch - 'a'] == -1) {
        nodes[curr][ch - 'a'] = sz(nodes);
        nodes.emplace_back();
      }

      curr = nodes[curr][ch - 'a'];
    }

    for (auto& y : names) {
      int ncurr = curr;
      for (auto& ch : y) {
        if (nodes[ncurr][ch - 'a'] == -1) {
          nodes[ncurr][ch - 'a'] = sz(nodes);
          nodes.emplace_back();
        }

        ncurr = nodes[ncurr][ch - 'a'];
      }
      nodes[ncurr].terminal = true;
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int curr = 0;
    string s;
    cin >> s;

    bool fail = false;

    for (auto& ch : s) {
      if (nodes[curr][ch - 'a'] != -1) {
        curr = nodes[curr][ch - 'a'];
      } else {
        fail = true;
      }
    }

    if (!fail && nodes[curr].terminal) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}