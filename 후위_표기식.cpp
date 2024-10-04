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

  string s;
  cin >> s;

  string out;
  stack<char> st;

  for (auto& c : s) {
    if (c >= 'A' && c <= 'Z') {
      out += c;
    } else if (c == '(') {
      st.push('(');
    } else if (c == ')') {
      while (sz(st) && st.top() != '(') {
        out += st.top();
        st.pop();
      }
      st.pop();
    } else {
      if (c == '+' || c == '-') {
        while (sz(st) && st.top() != '(') {
          out += st.top();
          st.pop();
        }
      } else {
        while (sz(st) && (st.top() == '*' || st.top() == '/')) {
          out += st.top();
          st.pop();
        }
      }
      st.push(c);
    }
  }

  while (sz(st)) {
    out += st.top();
    st.pop();
  }

  cout << out;
}