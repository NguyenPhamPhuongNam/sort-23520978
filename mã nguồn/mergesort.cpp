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

int a[nax];
int b[nax];
int c[nax];
void merge(int a[], int x, int y, int z) {
    int n1 = y - x + 1;
    int n2 = z - y;
    for (int i = 0; i < n1; ++i) {
        b[i] = a[x + i];
    }
    for (int i = 0; i < n2; ++i) {
        c[i] = a[y + 1 + i];
    }
    int m, n, p;
    m = 0;
    n = 0;
    p = x;
    while (m < n1 && n < n2) {
        if (b[m] < c[n]) {
            a[p] = b[m];
            m++;
        }
        else {
            a[p] = c[n];
            n++;
        }
        p++;
    }
    while (m < n1) {
        a[p] = b[m];
        m++;
        p++;
    }
    while (n < n2) {
        a[p] = c[n];
        n++;
        p++;
    }
}
void mergesort(int a[], int l, int r) {
    int mid;
    if(l<r){
        int mid= l+(r-l)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}
signed main() {
    freopen("/file/sinh test/merge_sort.txt", "w", stdout);
    for (int tests = 1; tests <= 10; tests++) {
        string fname = "/file/sinh test/Test_" + to_string(tests) + ".txt";
        ifstream inp(fname);
        int n;
        inp >> n;
        for (int i = 0; i < n; ++i) {
            inp >> a[i];
        }
        auto start = high_resolution_clock::now();
        mergesort(a, 0, n-1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << ( double)duration.count() / 1000 << endl;
    }
    return 0;
}




