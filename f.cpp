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

struct node {
public:
   ll value , left , right;
   node() {}
   node(ll _value , ll _left , ll _right) {
      this->value = _value;
      this->left = _left;
      this->right = _right;
   }
};


vector<vector<node>>dp(8001 , vector<node>(8001));

inline void solve() {
   ll n; cin >> n;
   vector<ll>arr(n + 1), cost(n + 1);
   for (ll i = 0; i < n; i++) {
      cin >> arr[i];
   }
   for (ll i = 0; i < n; i++) {
      cin >> cost[i];
   }
   for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
         dp[i][j] = node(LLONG_MAX , arr[i] , arr[j]);
      }
   }
   for (ll i = 0; i < n; i++) {
      dp[i][i] = node(0 , arr[i] , arr[i]);
   }

   auto mini = [&](node & a , ll ai , node & b , ll bi)->node{
      ll a_left = a.left;
      node res1 , res2;
      if (a_left < arr[ai]) {
         res1 = node(a.value + cost[ai] , a_left , a.right);
      } else{
         res2 = node(a.value , arr[ai] , a.right);
      }

      ll b_right = b.right;

      if (b_right > arr[bi]) {
         res2 = node(b.value + cost[bi] , b.left , b.right);
      } else{
         res2 = node(b.value , b.left , arr[bi]);
      }
      if (res1.value > res2.value) {
         return res2;
      } else if (res1.value < res2.value) {
         return res1;
      } else{
         return res1;
      }
   };


   for (ll i = n - 1; i >= 0; i--) {
      for (ll j = i + 1; j < n; j++) {
         dp[i][j] = mini(dp[i + 1][j] , i , dp[i][j - 1] , j);
      }
   }
   cout << dp[0][n - 1].value << endl;

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
