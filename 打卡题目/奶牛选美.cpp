#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int x;
	int y;
};
int abs(int a,int b)
{
	if(a>b) return a-b;
	else return b-a;
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<node>v[3];
char a[55][55];
int n,m;
int cnt=0;
bool vis[55][55];

void dfs(int x,int y)
{
	if(vis[x][y]||a[x][y]!='X') return;
	
	vis[x][y]=1;
//	cout<<x<<" "<<y<<endl;
	node p;
	p.x=x;
	p.y=y;
//	cout<<cnt<<endl;
	v[cnt].push_back(p);
	for(int i=0;i<4;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(vis[x1][y1]||x1<1||y1<1||x1>n||y1>m||a[x1][y1]!='X') continue;
		dfs(x1,y1);
	}
	
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j]&&a[i][j]=='X') dfs(i,j),cnt++;
		}
	}
	int min1=1000000;
	for(int i=0;i<v[0].size();i++)
	{
		for(int j=0;j<v[1].size();j++)
		{
			if(min1>abs(v[0][i].x-v[1][j].x)+abs(v[0][i].y-v[1][j].y)-1)
			{
				min1=abs(v[0][i].x-v[1][j].x)+abs(v[0][i].y-v[1][j].y)-1;
			}
		}
	}
	cout<<min1<<endl;
}
