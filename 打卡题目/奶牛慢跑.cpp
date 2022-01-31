#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e9;
int n,v[100009],minn=N;
int ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%*d%d",&v[i]);
    for(int i=n;i>=1;i--)
    {
        if(v[i]<=minn)
        {
            ans++;
            minn=v[i];
        }
    }
    printf("%d",ans);
    return 0;
}
