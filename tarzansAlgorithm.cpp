#include <bits/stdc++.h>
using namespace std;

class TarjanSCC {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> disc, low, inStack;
    stack<int> st;
    vector<vector<int>> sccs;

public:
    TarjanSCC(int n) : n(n), adj(n), disc(n, -1), low(n, -1), inStack(n, 0), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = 1;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (disc[u] == low[u]) {
            vector<int> scc;
            int v;
            do {
                v = st.top(); st.pop();
                inStack[v] = 0;
                scc.push_back(v);
            } while (u != v);
            sccs.push_back(scc);
        }
    }

    vector<vector<int>> getSCCs() {
        for (int i = 0; i < n; i++)
            if (disc[i] == -1)
                dfs(i);
        return sccs;
    }
};

int main() {
    int n = 5; // number of nodes
    TarjanSCC tarjan(n);

    // Example edges
    tarjan.addEdge(1, 0);
    tarjan.addEdge(0, 2);
    tarjan.addEdge(2, 1);
    tarjan.addEdge(0, 3);
    tarjan.addEdge(3, 4);

    vector<vector<int>> sccs = tarjan.getSCCs();

    cout << "Strongly Connected Components:\n";
    for (auto& scc : sccs) {
        for (int node : scc)
            cout << node << " ";
        cout << "\n";
    }

    return 0;
}
