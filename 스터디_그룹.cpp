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

  int n, k, d;
  cin >> n >> k >> d;

  vector<pii> students(n);  // skill, student

  for (auto& x : students) {
    int m, z;
    cin >> m >> x.first;

    while (m--) {
      cin >> z;
      x.second ^= (1 << (z - 1));
    }
  }

  int best = 0;
  sort(all(students));

  vi ct(k);

  int a = 0, b = 0;
  while (b < n) {
    while (students[b].first - students[a].first > d) {
      rep(i, 0, 32) {
        if (students[a].second & (1 << i)) {
          ct[i]--;
        }
      }

      a++;
    }

    rep(i, 0, 32) {
      if (students[b].second & (1 << i)) {
        ct[i]++;
      }
    }
    b++;

    int totalKnow = 0;
    int allKnow = 0;

    for (auto& x : ct) {
      totalKnow += (x != 0);
    }

    for (auto& x : ct) {
      allKnow += (x == (b - a));
    }

    best = max(best, (totalKnow - allKnow) * (b - a));
  }

  cout << best;
}