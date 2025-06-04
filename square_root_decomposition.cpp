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
// Things will remain the same , just some new algorithms will introduce.So , don't panic.
//flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
void solve(){
  int n;cin>>n;
  int m;cin>>m;
  vector<ll>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int mx = sqrt(n);
  vector<vector<ll>>prefix(n+1 , vector<ll>(mx+5, 0));
  vector<vector<ll>>wprefix(n+1 , vector<ll>(mx+5 , 0));
  for(int i=0;i<n;i++){
     for(int j=1;j<=sqrt(n);j++){
        prefix[i][j] = (i-j>=0?prefix[i-j][j]:0) + arr[i];
        ll l = (i/j) + 1;
        wprefix[i][j] = (i-j>=0?wprefix[i-j][j]:0) + l*arr[i];
     }
  } 
   
  auto cal=[&](int i , int j , int d)-> ll {
      ll sum = wprefix[j][d];
      if(i-d>=0){
        sum-=wprefix[i-d][d];
        ll l = (i / d);
        sum-=((l)*(prefix[j][d] - prefix[i-d][d]));
      }
      return sum;
  };

  while(m--){
     int s , d , k;cin>>s>>d>>k;
     ll ans = 0;
     ll prev = 1;
     int start = s-1 , end = (start + (k-1)*d);
     if(d > mx){
        for(int i=start;i<=end;i+=d){
           ans+=(arr[i]*prev);
           prev++;
        }
        cout<<ans<<" ";
     }else{

        cout<<cal(start , end , d)<<" ";
     }
  }cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}