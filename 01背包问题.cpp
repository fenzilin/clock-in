#include<iostream>
using namespace std;
int dp[1010][1010];
int v[1010],w[1010];
int main()
{
    int n,v1;
    cin>>n>>v1;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v1;j++)
        {
            if(j>=v[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            else dp[i][j]=dp[i-1][j];
            
        }
    }
    cout<<dp[n][v1]<<endl;
}
