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

  int t = 1;
  string s, a;
  while(cin >> s >> a, s != "END"){
    sort(all(s));
    sort(all(a));

    cout << "Case " << t++ << ": ";
    if(a == s){
      cout << "same";
    }else{
      cout << "different";
    }
    cout << '\n';
  }
}