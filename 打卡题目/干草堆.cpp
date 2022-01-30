#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+100;
int f[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a,b;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&a,&b);
        f[a]++;
        f[b+1]--;
    }
    for(int i=1;i<=n;i++) f[i]=f[i]+f[i-1];
    sort(f+1,f+n+1);
    cout<<f[(n+1)/2]<<endl;
    
}
