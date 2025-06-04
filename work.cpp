#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll recursion(int i, int j, int n, int m, int mask, vector<vector<ll>> &arr, vector<vector<vector<ll>>> &dp) {
    if (i >= n) return 0;
    if (j >= m) return recursion(i + 1, 0, n, m, mask, arr, dp);
    if (dp[i][j][mask] != -1) return dp[i][j][mask];

    int bit = i * n + j;
    if (mask & (1 << bit)) {
        return dp[i][j][mask] = recursion(i, j + 1, n, m, mask, arr, dp);
    }

    ll ans = arr[i][j] ^ recursion(i, j + 1, n, m, mask, arr, dp);

    // Horizontal domino
    if (j + 1 < m) {
        int bit1 = i * n + j;
        int bit2 = i * n + j + 1;
        if (!(mask & (1 << bit2))) {
            int new_mask = mask | (1 << bit1) | (1 << bit2);
            ans = max(ans, recursion(i, j + 2, n, m, new_mask, arr, dp));
        }
    }

    // Vertical domino
    if (i + 1 < n) {
        int bit1 = i * n + j;
        int bit2 = (i + 1) * n + j;
        if (!(mask & (1 << bit2))) {
            int new_mask = mask | (1 << bit1) | (1 << bit2);
            ans = max(ans, recursion(i, j + 1, n, m, new_mask, arr, dp));
        }
    }

    return dp[i][j][mask] = ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    int total = (1 << (n * m));
    
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(total, -1)));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cout << recursion(0, 0, n, m, 0, arr, dp) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
