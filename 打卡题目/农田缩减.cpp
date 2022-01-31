#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int x;
    int y;
};
const int N=5e4+100;
node a[N];
node b[N];
bool comp1(node a,node b)
{
    return a.x<b.x;
}
bool comp2(node a,node b)
{
    return a.y<b.y;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        b[i].x=a[i].x;
        b[i].y=a[i].y;
    }
    sort(a+1,a+n+1,comp1);
    sort(b+1,b+n+1,comp2);
    int ans=2000000000;
    if((a[1].x!=b[1].x||a[1].y!=b[1].y)&&(a[1].x!=b[n].x||a[1].y!=b[n].y))
    {
        ans=min((a[n].x-a[2].x)*(b[n].y-b[1].y),ans);
    }
    else if((a[1].x==b[1].x&&a[1].y==b[1].y)&&(a[1].x!=b[n].x||a[1].y!=b[n].y))
    {
        ans=min((a[n].x-a[2].x)*(b[n].y-b[2].y),ans);
    }
    else if((a[1].x!=b[1].x||a[1].y!=b[1].y)&&(a[1].x==b[n].x&&a[1].y==b[n].y))
    {

        ans=min((a[n].x-a[1].x)*(b[n-1].y-b[1].y),ans);
    }
    if((a[n].x!=b[1].x||a[n].y!=b[1].y)&&(a[n].x!=b[n].x||a[n].y!=b[n].y))
    {
        ans=min((a[n-1].x-a[1].x)*(b[n].y-b[1].y),ans);
    }
    else if((a[n].x==b[1].x&&a[n].y==b[1].y)&&(a[n].x!=b[n].x||a[n].y!=b[n].y))
    {
        ans=min((a[n-1].x-a[1].x)*(b[n].y-b[2].y),ans);
    }
    else if((a[n].x!=b[1].x||a[n].y!=b[1].y)&&(a[n].x==b[n].x&&a[n].y==b[n].y))
    {
        ans=min((a[n-1].x-a[1].x)*(b[n-1].y-b[1].y),ans);
    }
    if((b[1].x!=a[1].x||b[1].y!=a[1].y)&&(b[1].x!=a[n].x||b[1].y!=a[n].y))
    {
        ans=min((a[n].x-a[1].x)*(b[n].y-b[2].y),ans);
    }
    if((b[n].x!=a[1].x||b[n].y!=a[1].y)&&(b[n].x!=a[n].x||b[n].y!=a[n].y))
    {
        ans=min((a[n].x-a[1].x)*(b[n-1].y-b[1].y),ans);
    }
    cout<<ans<<endl;


}
