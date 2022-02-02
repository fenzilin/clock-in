#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 110;

int n;
string v[N];
unordered_map<int, int> m;

int main()
{
    cin >> n;
    for ( int i = 1; i <= n; i ++ ) cin >> m[i]; //输入洗牌三次的顺序
    for ( int i = 1; i <= n; i ++ ) cin >> v[i]; //输入对应id
    for ( int i = 1; i <= n; i ++ ) //进行三次倒着洗牌并输出
        cout << v[m[m[m[i]]]] << endl;

    return 0;
}

