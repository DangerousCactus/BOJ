#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x−axis in interva l [−pi , pi ]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); }  // makes d is t ()=1
  P perp() const { return P(-y, x); }        // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a ’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

template <class P>
int sideOf(P s, P e, P p) {
  return sgn(s.cross(e, p));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    map<Point<ll>, int> idx;

    vector<Point<ll>> pts(n);
    for (auto& [x, y] : pts) {
      cin >> x >> y;
      idx[Point<ll>{x, y}] = sz(idx);
    }

    auto mn = *min_element(all(pts));
    auto mx = *max_element(all(pts));

    vector<Point<ll>> top, bottom;

    vector<Point<ll>> onLine;

    for (auto& x : pts) {
      if (x == mn || x == mx) {
        continue;
      }

      auto res = sideOf(mn, mx, x);
      if (res == 1) {
        top.push_back(x);
      } else if (res == 0) {
        onLine.push_back(x);
      } else if (res == -1) {
        bottom.push_back(x);
      }
    }

    if (sz(top) == 0) {
      top.insert(top.end(), all(onLine));
    } else {
      bottom.insert(bottom.end(), all(onLine));
    }

    sort(all(top));
    sort(all(bottom));

    vector<Point<ll>> out;
    out.push_back(mn);
    out.insert(out.end(), all(top));
    out.push_back(mx);
    out.insert(out.end(), bottom.rbegin(), bottom.rend());

    for (auto& x : out) {
      cout << idx[x] << ' ';
    }
    cout << '\n';
  }
}