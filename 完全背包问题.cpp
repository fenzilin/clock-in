#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define PI acos(-1)
#define INF 0x3f3f3f3f
#define mod 7
using namespace std;
//const int N=1e6;
int v[1009],w[1009],dp[1009];
int main(){
	ios;
	int N,V;
	cin>>N>>V;
	for(int i=1;i<=N;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=v[i];j<=V;j++){
				dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
    // for(int i=1;i<=N;i++)
    // {
    //     for(int j=0;j<=V;j++)
    //     {
    //         dp[i][j]=dp[i-1][j];
    //         if(j>=v[i])dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
    //     }
    // }
	cout<<dp[V]<<endl;
	return 0;
}
