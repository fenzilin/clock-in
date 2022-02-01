#include<iostream>
using namespace std;
const int N=6;

bool vis[N][N];
char a[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int l=0;
int r=0;
int ans=0;
int n;
void dfs(int x,int y)
{
    if(vis[x][y]) return;
    vis[x][y]=1;
    
    if(a[x][y]=='(') l++;
    else r++;
    if(l==r)
    {
        ans=max(l+r,ans);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        // cout<<xx<<" "<<yy<<endl;
        if(vis[xx][yy]) continue;
        if(xx<1||xx>n||yy<1||yy>n)
        {
            // cout<<"cc"<<endl;
            continue;
            } 
        if(a[x][y]==')'&&a[xx][yy]=='(')
        {
           
            continue;
        }
        
        dfs(xx,yy);
        vis[xx][yy]=0;
        if(a[xx][yy]=='(') l--;
        else r--;
        
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]+1;
    dfs(1,1);
    cout<<ans<<endl;
}
