#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 14;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  unordered_map<char, unordered_map<char, int>> scoring;
  scoring['A'] = {{'A', 10}, {'B', 8}, {'C', 7}, {'D', 5}, {'F', 1}};
  scoring['B'] = {{'A', 8}, {'B', 6}, {'C', 4}, {'D', 3}, {'F', 1}};
  scoring['C'] = {{'A', 7}, {'B', 4}, {'C', 3}, {'D', 2}, {'F', 1}};
  scoring['D'] = {{'A', 5}, {'B', 3}, {'C', 2}, {'D', 2}, {'F', 1}};
  scoring['F'] = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'F', 0}};

  vector<string> g(n);
  for (auto& x : g) {
    cin >> x;
  }

  int getScore[MAXN][MAXN][MAXN][MAXN];
  rep(i, 0, n) {
    rep(j, 0, m) {
      rep(k, 0, n) {
        rep(l, 0, m) {
          getScore[i][j][k][l] = scoring[g[i][j]][g[k][l]];
        }
      }
    }
  }

  vector<vi> maskTransition(1 << m);
  rep(i, 0, 1 << m) {
    rep(j, 0, 1 << m) {
      if ((i & j) != 0) {
        continue;
      }

      bool valid = true;
      rep(k, 0, m - 1) {
        if ((~(i | j) & (1 << k)) && (~(i | j) & (1 << (k + 1)))) {
          valid = false;
        }
      }
      if (!valid) {
        continue;
      }

      maskTransition[i].push_back(j);
    }
  }

  vi states((1 << m), 0);
  vi nextStates((1 << m), 0);

  vector<vi> transitions(1 << m);
  transitions[0].push_back(0);

  vector<vi> nextTransitions(1 << m);

  rep(i, 0, n) {
    nextTransitions.clear();
    nextTransitions.resize(1 << m);
    nextTransitions[0].push_back(0);
    int currMask = 0;

    for (auto& vNextMask : transitions) {
      for (auto& nextMask : vNextMask) {
        nextTransitions[currMask].push_back(nextMask);

        if (currMask & (1 << i)) {  // already taken
          continue;
        }

        // consider right
        if (i != n - 1) {
          int newMask = currMask | (1 << i) | (1 << (i + 1));
          nextTransitions[newMask].push_back(nextMask);
        }

        // consider down
        int newMask = currMask | (1 << i);
        nextTransitions[newMask].push_back(nextMask | (1 << i));
      }
      currMask++;
    }

    swap(transitions, nextTransitions);
  }

  rep(i, 0, n) {
    fill(all(nextStates), 0);

    // process states into transitions
    int currMask = 0;
    for (auto& vNextMask : transitions) {
      for (auto& nextMask : vNextMask) {
        int score = 0;

        rep(j, 0, m) {
          if (i != n - 1 && (currMask & (1 << j)) && (nextMask & (1 << j))) {
            score += getScore[i][j][i + 1][j];
          }
          else if (j != m - 1 && ((currMask & (1 << j)) ^ (nextMask & (1 << j)))) {
            score += getScore[i][j][i][j + 1];
            j++;
          }
        }

        for (auto& lastMask : maskTransition[currMask]) {
          nextStates[nextMask] =
              max(nextStates[nextMask], score + states[lastMask]);
        }
      }
      currMask++;
    }

    swap(states, nextStates);
  }

  cout << states[0];
}