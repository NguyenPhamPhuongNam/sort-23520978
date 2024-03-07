#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
#define int long long
const int INF = 1e18;
const int nax = (int)(1000001);
const int mod = 100000007;
#define all(x) (x).begin(), (x).end()
#define double long double
#define sz(x) (x).size()
int a[nax];
mt19937_64 rng ((int64_t)(new char));

int randomnumber(int start, int end) {
    uniform_int_distribution<> dis(start, end);
    return dis(rng);
}
signed main() {
    freopen("/file/sinh test/sort.txt", "w", stdout);
    for (int tests = 1; tests <= 10; tests++) {
        string fname = "/file/sinh test/Test_" + to_string(tests) + ".txt";
        ifstream inp(fname);
        int n;
        inp >> n;
        for (int i = 0; i < n; ++i) {
            inp >> a[i];
        }
        auto start = high_resolution_clock::now();
        sort(a, a+n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << ( double)duration.count() / 1000 << endl;
    }
    return 0;
}



