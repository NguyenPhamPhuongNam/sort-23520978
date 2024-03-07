#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
const int INF = 1e18;
const int nax = (int)(1000001);
const int mod = 100000007;
#define all(x) (x).begin(), (x).end()
#define double long double
#define sz(x) (x).size()
mt19937_64 rng ((int64_t)(new char));

int randomnumber(int start, int end) {
    uniform_int_distribution<> dis(start, end);
    return dis(rng);
}

int a[nax], b[nax];
void quicksort(int left, int right) {
    if (left >= right) {
        return;
    }
    int rd = randomnumber(left, right), v = a[rd];
    int pivot = left - 1;
    for (int i = left; i <= right; ++i) {
        if (a[i] < v) {
            b[++pivot] = a[i];
        }
    }
    for (int i = left; i <= right; ++i) {
        if (a[i] == v) {
            b[++pivot] = a[i];
        }
    }
    for (int i = left; i <= right; ++i) {
        if (a[i] > v) {
            b[++pivot] = a[i];
        }
    }
    for (int i = left; i <= right; ++i) {
        a[i] = b[i];
    }
    quicksort(left, rd - 1);
    quicksort(rd + 1, right);
}
signed main() {
    freopen("/file/sinh test/quick_sort.txt", "w", stdout);
    for (int tests = 1; tests <= 10; tests++) {
        string fname = "/file/sinh test/Test_" + to_string(tests) + ".txt";
        ifstream inp(fname);
        int n;
        inp >> n;
        for (int i = 0; i < n; ++i) {
            inp >> a[i];
        }
        auto start = high_resolution_clock::now();
        quicksort( 0, n-1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << ( double)duration.count() / 1000 << endl;
    }
    return 0;
}

