#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//------------------------DEBUG START-------------------------------------
#define debug(x) cerr << #x << " ", _print(x),cerr << endl;
void _print(int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
template <class T1, class T2>void _print(pair<T1, T2> a) {cerr << "{ "; cerr << a.first << " " << a.second; cerr << " }";}
template <class T>void _print(vector<T> &a) {cerr << "[ "; for (T i : a) {_print(i); cerr << " ";} cerr << " ]";}
template <class T>void _print(set<T> &a) {cerr << "[ "; for (T i : a) {_print(i); cerr << " ";} cerr << " ]";}
template <class T>void _print(multiset<T> &a) {cerr << "[ "; for (T i : a) {_print(i); cerr << " ";} cerr << " ]";}
//------------------------DEBUG END-------------------------------------

void dfs1(int node , int parent , vector<int>adj[] , vector<int>&vis) {
    int n = (int)vis.size();
    if (node == (n - 1)) {
        vis[node] = 1;
        return;
    }
    for (auto i : adj[node]) {
        if (i == parent) {continue;}
        dfs1(i , node , adj , vis);
        vis[node] |= vis[i];
    }
}

void marknvisited(vector<int>adj[] , vector<int>&vis) {
    dfs1(1 , -1 , adj , vis);
}
vector<vector<int>>result;
bool dfs2(int node , int parent , vector<int>adj[] , vector<int>&vis , int n) {

    if (node == n) {
        return true;
    }

    if (vis[node] && (parent != -1)) {
        result.push_back({2 , parent});
    }

    int nNode = -1;
    for (auto i : adj[node]) {
        if (i == parent) {continue;}
        if (vis[i]) {
            nNode = i; continue;
        }
        result.push_back({1});
        bool curr = dfs2(i , node , adj , vis , n);
        if (curr) {return curr;}

    }

    if (nNode != -1) {
        result.push_back({1});
        bool curr = dfs2(nNode , node , adj , vis , n);
        if (curr) {
            return true;
        }
    }

    result.push_back({1});
    result.push_back({2 , node});
    return false;
}

inline void solve() {
    result.clear();
    int n; cin >> n;
    vector<int>adj[n + 1];
    for (int i = 1; i < n; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visn(n + 1 , 0);
    marknvisited(adj , visn);
    dfs2(1, -1 , adj , visn , n);
    cout << (int)result.size() << endl;
    for (auto i : result) {
        for (auto j : i) {cout << j << " ";}
        cout << endl;
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
