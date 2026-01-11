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
class BinaryLifting {
public:
    vector<vector<int>>tree;
    vector<int>depth;
    int LOG = 20;
    int N;
    BinaryLifting(int n) {
        N = n;
        tree.resize(n + 1 , vector<int>(LOG + 1, -1));
        depth.resize(n + 1 , 0);
    }

    void assign(int employee , int boss) {
        tree[employee][0] = boss;
    }

    void build(vector<int>adj[]) {
        for (int i = 1; i <= LOG; i++) {
            for (int j = 1; j <= N; j++) {
                if (tree[j][i - 1] != -1) {
                    tree[j][i] = tree[tree[j][i - 1]][i - 1];
                }
            }
        }
        dfs(1 , -1 , adj , 0);
    }

    void dfs(int node , int parent , vector<int>adj[] , int height) {
        depth[node] = height;
        for (auto i : adj[node]) {
            if (i == parent)continue;
            dfs(i , node , adj, height + 1);
        }
    }

    int lift(int node , int k) {
        int ans = node;
        for (int i = LOG; i >= 0; i--) {
            
            int cur = ((1 << i)&k);
            if (cur > 0 && (node!=-1)) {
                node = tree[node][i];
            }
        }
        return node;
    }

    int lca(int a , int b) {

        if (depth[a] < depth[b]) {swap(a , b);}

        a = lift(a , depth[a] - depth[b]);

        if (a == b) {
            return a;
        }

        for (int i = LOG; i >= 0; i--) {
            if (tree[a][i] != tree[b][i]) {
                a = tree[a][i];
                b = tree[b][i];
            }
        }
        return tree[a][0];
    }
};


inline void solve() {
    int n , q; cin >> n >> q;
    BinaryLifting t(n);
    vector<int>adj[n + 1];
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
        t.assign(i , x);
    }
    t.build(adj);
    while (q--) {
        int a , b; cin >> a >> b;
        cout<<t.lca(a , b)<<endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
