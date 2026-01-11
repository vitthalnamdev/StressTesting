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

const int mod = 1e6 + 3;

inline void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>brr(n);
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    int secondOperation = INT_MAX;

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        while (num <= brr[i]) {
            cnt++; num *= 2;
        }
        secondOperation = min(secondOperation , cnt - 1);
    }
    cout << secondOperation << endl;
    int firstOperation = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        for (int j = 0; j < secondOperation; j++) {num *= 2;}
        int left = brr[i] - num;
        for (int j = 0; j < secondOperation; j++) {
            left = (left/2 + (left&1));
        }
        firstOperation += left;
    }
    cout << firstOperation + secondOperation << endl;

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
