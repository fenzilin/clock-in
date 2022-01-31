#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int ans=0;
map<int,int>mps;
int Max=0;
int a[110];
struct node
{
    int x;
    int w;
}; 
int n;
void bfs(int x)
{  
    queue<node>q;
    for(int i=1;i<=n;i++) mps[a[i]]=-1;
    ans=0;
    node s;
    s.x=x;
    s.w=1;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        mps[s.x]=1;
        ans++;
        node b;
        for(int i=1;i<=s.w;i++)
        {
            if(mps[s.x+i]==-1) mps[s.x+i]=1,b.x=s.x+i,b.w=s.w+1,q.push(b);
            if(mps[s.x-i]==-1) mps[s.x-i]=1,b.x=s.x-i,b.w=s.w+1,q.push(b);
        }
    }


}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],mps[a[i]]=-1;
    for(int i=1;i<=n;i++)
    {
        // cout<<a[i]<<" "<<"dd"<<endl;
        bfs(a[i]);
        Max=max(ans,Max);
    }
    cout<<Max<<endl;
}
