#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define PI acos(-1)
#define INF 0x3f3f3f3f
#define mod 7
using namespace std;
const int N=1e6;
int dp[1009][1009];
int main(){
	ios;
	int N,V;
	cin>>N>>V;
	for(int i=1;i<=N;i++){
		int v,w,s;
		cin>>v>>w>>s;
// 		for(int j=V;j>=1;j--){
// 			for(int k=0;k<=s&&k*v<=j;k++){
// 				dp[j]=max(dp[j],dp[j-k*v]+k*w);
// 			}
// 		}
        for(int j=0;j<=V;j++)
        {
            for(int k=0;k<=s&&k*v<=j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*v]+k*w);
            }
        }
	}
	cout<<dp[N][V]<<endl;
	return 0;
}
