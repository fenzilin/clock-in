#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
string a[N], b[N];
string T = "ATGC";
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];

    for(int i = 0; i < m; i ++) {
        vector <int> cnt(5);
        int ok = 1;
        for(int j = 1; j <= n; j ++) cnt[T.find(a[j][i])]++;
        for(int j = 1; j <= n; j ++) if(cnt[T.find(b[j][i])]) ok = 0;
        if(ok) ans++;
    }
    return cout << ans, 0;
}
