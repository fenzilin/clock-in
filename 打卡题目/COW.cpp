#include<iostream>
using namespace std;
const int N=1e5+100;
int f[5];
typedef long long ll;
char a[N];
int main()
{
    int n;
    cin>>n;
    cin>>a+1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='C') f[1]++;
        else if(a[i]=='O') f[2]=f[2]+f[1];
        else ans+=f[2];
    }
    cout<<ans<<endl;
}
