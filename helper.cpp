#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
  #define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1 , class T2>void _print(pair<T1,T2>a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T>void _print(vector<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(set<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(multiset<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
////------DEBUG END---------////
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m) {
a %= m;
long long res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
//flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

vector<ll>dp;
vector<ll>lines;
ll res = 0;
int dfs(int node , int parent , vector<int>adj[]){
     int cnt = 1;
     vector<ll>sums;
     vector<ll>cntnodes;
     for(auto i:adj[node])
     {
         if(i==parent){
             continue;
         }

         ll now = dfs(i , node , adj); 
         dp[node]+=(dp[i]+now+1);
         sums.push_back(dp[i] + now + 1);
         cntnodes.push_back(now);
         dp[node]%=mod;
         cnt+=now;
     }
     ll total = dp[node];
     for(auto i:adj[node]) 
     {
        if(i==parent){continue;}
        total-=dp[i];
        res+=(dp[i] + total*lines[i]);
     }
     lines[node] = cnt;
     return cnt;
}

 

void solve(){
    int n,k;cin>>n>>k;
    dp.resize(n+1, 0);
    lines.resize(n+1 , 0);
    vector<int>adj[n+1];
    for(int i=1;i<n;i++){
         int x , y;cin>>x>>y;
         adj[x].push_back(y);
         adj[y].push_back(x);
    }
    if(k%2){
         cout<<1<<endl;return;
    }
    ll total = (ll)(n*(n-1))/2;
    dfs(1 , -1 , adj);
    ll ans = 0;
    for(int i=1;i<=n;i++){
       ans+=dp[i];
    }
    for(int i=1;i<=n;i++){
         cout<<dp[i]<<" ";
    }cout<<endl;
    ll numerator = (ans + res)%mod;
    ll denominator = (total)%mod;
    denominator = inv(denominator);
    numerator = (numerator*denominator)%mod;
    cout<<numerator<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}