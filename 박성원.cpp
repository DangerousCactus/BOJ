#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod;  // change to something e lse
struct Mod {
  ll x;
  Mod() : x(0) {}
  Mod(ll xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
  Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
  Mod operator^(ll e) {
    if (!e)
      return Mod(1);
    Mod r = *this ^ (e / 2);
    r = r * r;
    return e & 1 ? *this * r : r;
  }
  bool operator<(Mod& o) { return x < o.x; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<string> num(n);
  for (auto& x : num) {
    cin >> x;
  }
  // sort(all(num));
  cin >> mod;

  ll count = 0;
  ll total = 1;
  rep(i, 1, n + 1) {
    total *= i;
  }

  vector<vector<ll>> m(1 << n, vector<ll>(101, 0));
  m[0][0] = 1;

  rep(i, 0, n) {
    rep(j, 0, n) {
      rep(mask, 0, 1 << n) {
        if (__builtin_popcount(mask) != i || (mask & (1 << j))) {
          continue;
        }

        Mod pow = 10;
        int p = 0;
        rep(a, 0, n) {
          if (mask & (1 << a)) {
            p += sz(num[a]);
          }
        }
        pow = pow ^ p;

        Mod offset;
        for (auto it = num[j].rbegin(); it != num[j].rend(); it++) {
          offset = offset + (Mod(*it - '0') * pow);
          pow = pow * 10;
        }

        rep(k, 0, 101) {
          m[mask ^ (1 << j)][(offset + k).x] += m[mask][k];
        }
      }
    }
  }

  // do {
  //   Mod curr = 0;
  //   Mod pow = 1;
  //   for (auto& x : num) {
  //     for (auto it = x.rbegin(); it != x.rend(); it++) {
  //       curr = curr + (Mod(*it - '0') * pow);
  //       pow = pow * 10;
  //     }
  //   }

  //   // cout << curr.x << endl;
  //   if (curr.x == 0) {
  //     count++;
  //   }
  //   total++;
  // } while (next_permutation(all(num)));

  count = m[(1 << n) - 1][0];
  if (count == 0) {
    cout << "0/1";
  } else {
    auto g = gcd(count, total);
    cout << count / g << '/' << total / g;
  }
}