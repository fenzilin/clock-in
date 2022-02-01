#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+100;
struct node
{
    int w;
    int id;
};
bool comp(node a,node b)
{
    return a.w<b.w;
}
node a[N];
bool vis[N];
int main()
{
    int n;
    scanf("%d",&n);
    vis[0]=1;
    vis[n+1]=1;
    a[n+1].w=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].w);
        a[i].id=i;
    }
    sort(a+1,a+n+1,comp);
    int t=1;
    int ans=-1000;
    for(int i=1;i<=n;i++)
    {
        while(a[i].w==a[i+1].w)
        {
            if(!vis[a[i].id+1]&&!vis[a[i].id-1]) t++;
            else if(vis[a[i].id+1]&&vis[a[i].id-1]) t--;
            vis[a[i].id]=1;
            // cout<<t<<endl;
            i++;
        }
        if(!vis[a[i].id+1]&&!vis[a[i].id-1]) t++;
        else if(vis[a[i].id+1]&&vis[a[i].id-1]) t--;
        vis[a[i].id]=1;
        ans=max(ans,t);
    }
    cout<<ans<<endl;
}
