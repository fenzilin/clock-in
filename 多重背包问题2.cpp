#include<bits/stdc++.h>
using namespace std;
const int N=2010;
const int MAX=2e6+100;
int w[N];
int v[N];
int s[N];
int w1[MAX];
int v1[MAX];
int n,m;
int dp[2010];
int sum=0;
int qmi(int a,int b)
{
    int res=1;
    while(b)
    {
        res*=a;
        b--;
    }
    return res;
}
void binary()
{
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        while(s[i]-qmi(2,cnt)>=0)
        {
            int k=qmi(2,cnt);
            s[i]-=qmi(2,cnt);
            w1[++sum]=w[i]*k;
            v1[sum]=v[i]*k;
            // cout<<v1[sum]<<" "<<w1[sum]<<" "<<k<<" "<<i<<endl;
            cnt++;
        }
        if(s[i])
        {
            w1[++sum]=w[i]*s[i];
            v1[sum]=v[i]*s[i];
        }
        
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&v[i],&w[i],&s[i]);
    binary();
    // cout<<sum<<endl;
    for(int i=1;i<=sum;i++)
    {
        for(int j=m;j>=v1[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v1[i]]+w1[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}
