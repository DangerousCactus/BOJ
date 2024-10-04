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

  typedef struct {
    vi links = vi(26, -1);
    int outLinks = 0;
    bool wordEnd = false;

    int& operator[](int x) { return links[x]; }
  } Node;

  while (cin >> n) {
    vector<string> words(n);
    vector<Node> d(1);

    for (auto& x : words) {
      cin >> x;

      int curr = 0;
      for (auto& c : x) {
        if (d[curr][c - 'a'] == -1) {
          d[curr][c - 'a'] = sz(d);
          d.push_back({});
          d[curr].outLinks++;
        }

        curr = d[curr][c - 'a'];
      }
      d[curr].wordEnd = true;
    }

    long double total = 0;
    for (auto& x : words) {
      int curr = d[0][x[0] - 'a'];
      total++;
      int i = 1;

      while (i < sz(x)) {
        if (d[curr].outLinks != 1 || d[curr].wordEnd) {
          total++;
        }
        curr = d[curr][x[i] - 'a'];
        i++;
      }

      // cerr << "ADDED " << total - oldTotal << " BY " << x << endl;
    }

    cout << fixed << setprecision(2) << round(total * 100 / sz(words)) / 100
         << '\n';
  }
}