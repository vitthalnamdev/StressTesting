#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, int parent, vector<int> &dist) {
    for (auto i : adj[node]) {
        if (i == parent) continue;
        dist[i] = dist[node] + 1;
        dfs(i, adj, node, dist);
    }
}

inline void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n + 1, 0);
    dfs(1, adj, -1, dist);

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[dist[i]]++;
    }
    int ans = *max_element(dp.begin(), dp.end());

    int curr = 0;
    for (int i = 1; i <= n; i++) {
        int temp = (int)adj[i].size();
        if (i != 1) {
            temp--;
        }
        curr = max(curr, 1 + temp);
    }
    cout << max(ans, curr) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}