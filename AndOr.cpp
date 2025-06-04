#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
 
typedef long long ll; 
#define M 1000000007
#define all(a) a.begin() , a.end()
#define yes cout<<"YES\n" ;
#define no cout<<"NO\n" ;
#define fori(n) for(int i=0;i<n;i++) 
#define forj(n) for(int j=0;j<n;j++) 
#define parr(a,n) for(int i=0;i<n;i++) cout<<a[i] << " "; cout<<"\n"; 
vector< int> dp;
                    
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> q(m, vector<int>(2));
    for (int i = 0; i < m; i++){
        cin >> q[i][0] >> q[i][1];
    }
    vector<int> b(n, 0);
    b[0] = a[0];
    for (int i = 1; i<n; i++){
        if(i%2 != 0){
            b[i] = b[i - 1] & a[i];
        }else{
            b[i] = b[i - 1] | a[i];
        }
    }
    for (int i = 0; i < m; i++){
        int ind = q[i][0];
        ind--;
        int x = q[i][1];
        if(x == a[ind]){
            cout << b.back()<<endl;
        }else{
            a[ind] = x;

            int j = ind;
            bool y = true;
            while(j<n){
                int changed = 0;
                if(j%2 != 0){
                    changed = b[j - 1] & a[j];
                }else{
                    changed = b[j - 1] | a[j];
                }

                if(changed == b[j]) {
                    cout << b.back() << endl;
                    y = false;
                    break;
                }else{
                    b[j] = changed;
                }
                j++;
            }
            if(y) {
                cout << b.back() << endl;
            }
        }
    }
}
int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  
  int t=1;
  cin>>t;
  while(t--){
   solve();
    
  }
  return 0;
}