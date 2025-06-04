#include <bits/stdc++.h>
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
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
void _print(int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
template <class T1, class T2>
void _print(pair<T1, T2> a)
{
    cerr << "{ ";
    cerr << a.first << " " << a.second;
    cerr << " }";
}
template <class T>
void _print(vector<T> &a)
{
    cerr << "[ ";
    for (T i : a)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T>
void _print(set<T> &a)
{
    cerr << "[ ";
    for (T i : a)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T>
void _print(multiset<T> &a)
{
    cerr << "[ ";
    for (T i : a)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
////------DEBUG END---------////
int mod = 1e9 + 7;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll inv(ll a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
// flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
 template<class T>
class segTree{
 public:
 int n;
 vector<T>tree;
 vector<T>lazy;
 T NEUTRAL = 0;
 T NO_OPERATION = 0;
 
 segTree(vector<int>arr , int _n){
   n = _n;
   tree.resize(4*(n+1)+4 , NEUTRAL);
   lazy.resize(4*(n+1)+4 , NO_OPERATION);
   build(arr , 0 , n-1,1);
 }
 
 segTree(int _n){
    n = _n;
    tree.resize(4*(_n+1) + 4 , NEUTRAL);
    lazy.resize(4*(_n+1) + 4 , NO_OPERATION);
 }
 
 
 T fun(T a , T b){
     return max(a , b);
 }
 
 
 void modify(T &a , int value , int l , int r){
      if(value==NO_OPERATION || r < l){return;}
      a-=(long long int)(value*max(0,(r-l+1)));
      a = max(0 , a);
 }
 
 void modify(T &a , int value){
    a+=value;
 }
 
 void propagate(int ind , int l , int r){
     if(lazy[ind]==NO_OPERATION || (r-l<=0)){
         return;
     }
     // int mid = (l+r)/2; 
     // modify(tree[2*ind]  , lazy[ind] /(r-l+1) , l , mid);
     // modify(tree[2*ind+1]  , lazy[ind] /(r-l+1) , mid+1 , r);
     // modify(lazy[2*ind]  , lazy[ind] /(r-l+1)  , l , mid);
     // modify(lazy[2*ind+1]  , lazy[ind] /(r-l+1) , mid+1 , r);
     modify(tree[2*ind] , lazy[ind]);
     modify(tree[2*ind+1] , lazy[ind]);
     modify(lazy[2*ind] , lazy[ind]);
     modify(lazy[2*ind+1] , lazy[ind]);
     lazy[ind]  = NO_OPERATION;
 }
  
 T build(vector<int>&arr, int l , int r , int ind){
    if(l==r){ return tree[ind] = arr[l];}
    int mid = (l+r)/2;
    T left = build(arr , l , mid , 2*ind);
    T right = build(arr , mid + 1 , r , 2*ind + 1);
    tree[ind] = fun(left,right);  
    return tree[ind];
 }
 
 T update(int l , int r , int ind , int i , int value){
    propagate(ind , l , r);
    if(l>i || r<i){return tree[ind];}
    if(l==r && l==i){return tree[ind] = value;}
    int mid = (l+r)/2;
    T left = update(l , mid , 2*ind , i , value);
    T right = update(mid+1 , r , 2*ind + 1 , i , value);
    return tree[ind] = fun(left , right);
 }
 
 void update(int ind , int value){
    update(0 , n-1 , 1 , ind , value);
 }
  
 
  T first_max_element(int l , int r , int ind , int x){
     propagate(ind,l,r);
     if(tree[ind]<x){
       return -1;
     }
     if(l==r){
        return l;
     }
     int mid = (l+r)/2;
     T left = first_max_element(l , mid , 2*ind , x);
     if(left!=-1){
       return left;
     }
     T right = first_max_element(mid + 1 , r , 2*ind + 1 , x);
     return right; 
  }
 
  T first_max_element(int x){
     return first_max_element(0 , n-1 , 1 , x);
  }
 
 
  T query(int l , int r , int a , int b , int ind){
      propagate(ind , l , r);
      if(l>b || r<a){
          return NEUTRAL;
      }
      if(l>=a && r<=b){
         return tree[ind];
      } 
      int mid = (l+r)/2;
      T left = query(l,mid,a,b,2*ind);
      T right = query(mid+1,r,a,b,2*ind+1);
      return fun(left , right);
  }
 
   T query(int l,int r){
       return query(0,n-1,l,r,1);
   }
 
  void range_update(int l , int r , int a , int b , int ind,int value){
    propagate(ind , l , r);
    if(l>b || r<a){return;}
    if(l>=a && r<=b){
       modify(lazy[ind],value);
       modify(tree[ind],value);
       return;
    }
    int mid = (l+r)/2;
    range_update(l,mid,a,b,2*ind,value);
    range_update(mid+1,r,a,b,2*ind+1,value);
    tree[ind] = fun(tree[2*ind] , tree[2*ind + 1]);
  }
 
  void range_update(int l , int r , int value){
     range_update(0 , n-1 , l , r , 1,value);
  }
 
  T get_idx(int l,int r , int i , int ind){
    propagate(ind , l , r);
    if(l>i || r<i){return NEUTRAL;}
    int mid = (l+r)/2;
    T left = get_idx(l,mid,i,2*ind);
    T right = get_idx(mid+1,r,i,2*ind+1);
    return fun(left,right);
  }
 
  T get_idx(int ind){
     return get_idx(0,n-1,ind,1);
  }
};


void solve()
{

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}