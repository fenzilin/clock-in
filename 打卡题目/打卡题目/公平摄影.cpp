#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5+9;
typedef pair<int,int> pii;
pii a[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char s[2];
        cin>>x>>s;
        if(s[0]=='G')a[i]={x,1};
        else a[i]={x,-1};
    }
    sort(a+1,a+1+n);
    unordered_map<int,int> m;
    int maxx=0,last=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(!m.count(sum))m[sum]=a[i].first;
        sum+=a[i].second;
        if(m.count(sum))maxx=max(maxx,a[i].first-m[sum]);
        if(i==1||a[i].second!=a[i-1].second)last=a[i].first;
        maxx=max(maxx,a[i].first-last);
    }
    cout<<maxx;
    return 0;
}
