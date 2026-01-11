/**
 *    author:  tourist
 *    created: 11.10.2025 13:53:46
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> seq;
    int at = 0;
    while (at < n) {
      int till = at + 1;
      while (till < n && a[till] == a[till - 1] + 1) {
        till += 1;
      }
      till += a[at] - 1;
      assert(till <= n);
      seq.emplace_back(till - at, a[at] - 1);
      at = till;
    }
    vector<int> res;
    int cur = 0;
    for (auto& [len, shift] : seq | views::reverse) {
      while (cur % len != shift) {
        cur += 1;
        res.push_back(-1);
      }
      res.push_back(len);
    }
    cout << res.size() << '\n';
    for (int x : res | views::reverse) {
      if (x == -1) {
        cout << 2 << '\n';
      } else {
        cout << 1 << " " << x << '\n';
      }
    }
  }
  return 0;
}
