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
    for ( int i = 1; i <= n; i ++ ) cin >> m[i]; //����ϴ�����ε�˳��
    for ( int i = 1; i <= n; i ++ ) cin >> v[i]; //�����Ӧid
    for ( int i = 1; i <= n; i ++ ) //�������ε���ϴ�Ʋ����
        cout << v[m[m[m[i]]]] << endl;

    return 0;
}

