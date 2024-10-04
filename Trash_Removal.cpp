#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long double PI = acos(-1);

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
  P rotate(long double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
  if (sz(pts) <= 1)
    return pts;
  sort(all(pts));
  vector<P> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (P p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
        t--;
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template <class P>
double lineDist(const P& a, const P& b, const P& p) {
  return (double)(b - a).cross(p - a) / (b - a).dist();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  int n;
  while (cin >> n, n != 0) {
    vector<P> pts(n);
    for (auto& [x, y] : pts) {
      cin >> x >> y;
    }

    auto hull = convexHull(pts);  // CCW
    reverse(all(hull));

    hull.push_back(hull.front());

    double best = INT_MAX;

    rep(i, 0, sz(hull) - 1) {
      double mx = 0;

      for (auto& p : hull) {
        Point<long double> pd(p.x, p.y);
        mx = max(mx, abs(lineDist(hull[i], hull[i + 1], p)));
      }

      best = min(best, mx);
    }

    best = ceil(best * 100) / 100;

    cout << "Case " << t++ << ": " << fixed << setprecision(2) << best << '\n';
  }
}