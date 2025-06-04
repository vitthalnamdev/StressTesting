// // C++ program to demonstrate generate function in STL
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// // function to generate random numbers in range [0-999] :
// std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// int main()
// {
//    // for diffe rent values each time we run the code
//    srand(time(NULL));
//    int t = 1;
//    cout << t << endl;
//    while (t--)
//    {
//        int n = rng()%10 + 1;
//        int k = rng()%100 + 1;
//        cout<<n<<" "<<k<<endl;
//        for(int i=0;i<n;i++){
//           int x = rng()%200 + 1;
//           cout<<x<<" ";
//        }cout<<endl;
//    }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Customize n and q
    int n = 10; // length of array
    int q = 10; // number of queries

    cout << n << " " << q << "\n";

    // Random number generator
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto rand_val = [&](int l, int r) {
        return uniform_int_distribution<int>(l, r)(rng);
    };

    // Generate initial array with values from 1 to 40
    for (int i = 1; i <= n; ++i) {
        cout << rand_val(1, 40) << " ";
    }
    cout << "\n";

    // Generate queries
    for (int i = 0; i < q; ++i) {
        int type = rand_val(1, 2); // 1 or 2
        if (type == 1) {
            int l = rand_val(1, n);
            int r = rand_val(1, n);
            if (l > r) swap(l, r);
            cout << "1 " << l << " " << r << "\n";
        } else {
            int pos = rand_val(1, n);
            int val = rand_val(1, 40);
            cout << "2 " << pos << " " << val << "\n";
        }
    }

    return 0;
}

 
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     srand(time(0));

//     int t = 1; // Number of test cases
//     cout << t << "\n";

//     while (t--) {
//         int k = rand() % 5 + 1; // k from 10 to 49
//         int min_n = 2 * k;
//         int n = min_n + rand() % (20 - min_n + 1); // n in [2k, 1000]

//         int a_len = k + rand() % (n - 2 * k + 1); // |A| in [k, n-k]
//         int b_len = n - a_len;

//         auto generate_array = [&](int len) {
//             vector<int> res;
//             deque<int> window;
//             for (int i = 0; i < len; ++i) {
//                 set<int> recent(window.begin(), window.end());
//                 vector<int> options;
//                 for (int val = 1; val <= k; ++val) {
//                     if (recent.count(val) == 0)
//                         options.push_back(val);
//                 }
//                 assert(!options.empty());
//                 int chosen = options[rand() % options.size()];
//                 res.push_back(chosen);
//                 window.push_back(chosen);
//                 if (window.size() > k - 1) window.pop_front();
//             }
//             return res;
//         };

//         vector<int> A = generate_array(a_len);
//         vector<int> B = generate_array(b_len);
//         vector<int> C = A;
//         C.insert(C.end(), B.begin(), B.end());

//         // Output n and k
//         cout << n << " " << k << "\n";

//         // Output the full C array to a file or stdout for the checker
//         for (int val : C) cout << val << " ";
//         cout << "\n";
//     }

//     return 0;
// }
