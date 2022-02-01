#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
struct node
{
	int x;
	int y;
};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dis[1100][1100];
int a[1100][1100];
bool vis[1100][1100];
void dijkstra(int sx,int sy)
{
	memset(dis,0x3f,sizeof(dis));
	deque<node>q;
	node p;
	p.x=sx;
	p.y=sy;
	dis[sx][sy]=0;
	q.push_front(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop_front();
		vis[p.x][p.y]=1;
//		int w=p.w; 
		if(p.x==0&&p.y==0) break;
		for(int i=0;i<4;i++)
		{
			int xx=p.x+dx[i];
			int yy=p.y+dy[i];
			if(xx>=1002||xx<0||yy<0||yy>=1002) continue;
			if(vis[xx][yy]) continue;
			if(dis[xx][yy]>dis[p.x][p.y]+a[xx][yy])
			{
				node b;
				dis[xx][yy]=dis[p.x][p.y]+a[xx][yy];
				b.x=xx;
				b.y=yy;
				if(a[xx][yy]) q.push_back(b);
				else q.push_front(b); 
			}
			
		}	
	}	
}
int main()
{
	int n,sx,sy;
	scanf("%d%d%d",&n,&sx,&sy);
	int x,y; 
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	dijkstra(sx,sy);
	cout<<dis[0][0]<<endl;
	
}

