#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9 + 7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        static int block_size = 0;
        if (block_size == 0) block_size = sqrt(1e5); // You can pass block_size as parameter
        if (l / block_size != other.l / block_size)
            return l / block_size < other.l / block_size;
        return ((l / block_size) & 1) ? (r < other.r) : (r > other.r); // Optimize for cache locality
    }
};

int main() {
    fast_io;

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    int answer = 0;
    vector<int> res(m);
    unordered_map<int, int, custom_hash> freq;

    auto add = [&](int x) {
        if (freq[x] == x) answer--;
        freq[x]++;
        if (freq[x] == x) answer++;
    };

    auto remove = [&](int x) {
        if (freq[x] == x) answer--;
        freq[x]--;
        if (freq[x] == x) answer++;
    };

    for (const auto &q : queries) {
        while (r < q.r) add(arr[++r]);
        while (l > q.l) add(arr[--l]);
        while (r > q.r) remove(arr[r--]);
        while (l < q.l) remove(arr[l++]);
        res[q.idx] = answer;
    }

    for (int x : res) cout << x << '\n';
}
