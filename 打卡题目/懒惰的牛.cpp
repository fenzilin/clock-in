#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;
int s[N], n, m;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) { 
        int a, b;
        cin >> a >> b;
        s[b + 1] += a;
    }
    for(int i = 1; i < N; i ++) s[i] += s[i - 1];
    int res = -1;
    for(int i = 0; i < N; i ++) {
        int l = max(1, i - m), r = min(i + m, N - 1);
        res = max(res, s[r] - s[l - 1]);
    }
    cout << res;
    return 0;
}

