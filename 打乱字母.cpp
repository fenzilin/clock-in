#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e4+100;
vector<string>a,b,c;
int main()
{
  int n;
  cin>>n;
  string s;
  for(int i=1;i<=n;i++)
  {
      cin>>s;
      sort(s.begin(),s.end());
      a.push_back(s);
      b.push_back(s);
      reverse(s.begin(),s.end());
      c.push_back(s);
  }
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
//  cout<<b[0]<<" "<<c[0]<<endl;
  for(int i=0;i<a.size();i++)
  {
      string s1=a[i];
      int l=0,r=a.size()-1;
      int mod;
      while(l<r)
      {
          mod=(l+r)/2;
          if(c[mod]>=s1) r=mod;
          else l=mod+1;    
      }
      cout<<l+1<<" ";
      l=0;r=c.size()-1;
      reverse(s1.begin(),s1.end());
      while(l<r)
      {
          mod=(l+r+1)/2;
          if(b[mod]<=s1) l=mod;
          else r=mod-1;
      }
      cout<<l+1<<endl;
  }
  
}
