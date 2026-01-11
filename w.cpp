#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (1e9) + 7;
void solve() {

    ll n, m; cin >> n >> m;
    vector<ll>arr(n); 
    for (int i = 0; i < n; i++)cin >> arr[i];
    ll dp[n][m + 2];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= m; i++) {
        if (arr[n - 1] == 0) {
            dp[n - 1][i] = 1;
        } else {
            dp[n - 1][arr[n - 1]] = 1;
        }
    }
    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != 0) {
            for (int j = arr[i] - 1; j <= arr[i] + 1; j++) {
                dp[i][arr[i]] += dp[i + 1][j];
                dp[i][arr[i]] %= MOD;
            }
            continue;
        }
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i + 1][j - 1] + dp[i + 1][j] + dp[i + 1][j + 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[0][i];
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main() {
    solve();
    return 0;
}