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
template <class T1, class T2>void _print(pair<T1, T2> a){cerr << "{ ";cerr << a.first << " " << a.second;cerr << " }";}
template <class T>void _print(vector<T> &a){cerr << "[ ";for (T i : a){_print(i);cerr << " ";}cerr << " ]";}
template <class T>void _print(set<T> &a){cerr << "[ ";for (T i : a){_print(i);cerr << " ";}cerr << " ]";}
template <class T>void _print(multiset<T> &a){cerr << "[ ";for (T i : a){_print(i);cerr << " ";}cerr << " ]";}
//------------------------DEBUG END-------------------------------------


inline void solve() {
   int n;cin>>n;
   string s;cin>>s;
   int startInd = -1, endInd = -1;
   for(int i=0;i<n;i++){
   	 if(s[i]=='1'){
   	 	 startInd = i;
   	 	 break;
   	 }
   }      
   for(int i=n-1;i>=0;i--){
   	  if(s[i]=='1'){
   	  	 endInd = i;break;
   	  }
   }
   if(startInd==-1){
   	 cout<<"Yes"<<endl;return;
   }
   for(int i=startInd;i<=endInd;i++){
   	  if(s[i]=='0'){
   	  	 cout<<"Yes"<<endl;return;
   	  }
   }
   if(((endInd - startInd)<=2) && (startInd!=endInd)){
   	  cout<<"No"<<endl;return;
   }
   cout<<"Yes"<<endl;
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
