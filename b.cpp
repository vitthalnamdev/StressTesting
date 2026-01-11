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
   int ind;
   int dir;
   int position;
   node() {}
   node(int _ind , int _dir , int _position) {
      ind = _ind;
      dir = _dir;
      position = _position;
   }

   bool operator<(const node &other) const {
      return ind < other.ind;
   }
};



inline void solve() {
   int n; cin >> n;
   vector<int>w(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> w[i];
   }
   set<node>interval;
   int q; cin >> q;



   auto getl = [&](int ind)->int{
      if(interval.size()==0){
         return 0;
      }
      auto it = *interval.lower_bound(node(ind , INT_MAX , INT_MAX));
      if (it.dir == -1) {
         return it.position;
      } else{
         return it.position - w[ind];
      }
   };

   interval.insert(node(n , -1 , 0));
   while (q--) {
      int type , v;
      cin >> type >> v;
      if (type != 3) {
         while ((int)interval.size() > 0) {
            auto [ind , dir , position] = *interval.begin();
            if (ind <= v) {
               interval.erase(interval.begin());
            } else {
               break;
            }
         }
      }

      if (type == 1) {
         int currL = getl(v);
         interval.insert(node(v , -1 , currL));
      } else if (type == 2) {
         int currL = getl(v);
         int currR = currL + w[v];
         interval.insert(node(v , 1 , currR));
      } else {
         auto check = [&](int mid)->bool{
            int currL = getl(mid);
            int currR = currL + w[mid];
            return ((currL < (int)(v + 1)) && ((v + 1) <= (currR)));
         };

         int start = 1 , end = n;
         while ((end - start) > 1) {
            int mid = (start + end) >> 1;
            if (check(mid)) {
               end = mid;
            } else {
               start = mid + 1;
            }
         }

         if (check(start)) {
            cout << n - start + 1 << endl;
         } else if (check(end)) {
            cout << n - end + 1 << endl;
         } else {
            cout << 0 << endl;
         }
      }
      
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
