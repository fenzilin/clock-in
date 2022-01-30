#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
char a[100];
char b[100];

int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a;
        b/=2;
    }
    return res;
    
}

int main()
{
    cin>>a>>b;
    ll x1=0,x2=0;
    int len1=strlen(a);
    int len2=strlen(b);
    for(int i=len1-1;i>=0;i--)
    { 
        x1+=(a[i]-'0')*qpow(2,len1-1-i);
    }
     for(int i=len2-1;i>=0;i--)
    {
        x2+=(b[i]-'0')*qpow(3,len2-1-i);
    }
    ll t=x1;
    for(int i=len1-1;i>=0;i--)
    {
        t=x1;
        if(a[i]=='0') t+=qpow(2,len1-1-i);
        else t-=qpow(2,len1-1-i);
        ll t1=x2;
        int vis;
        for(int j=len2-1;j>=0;j--)
        {    
             t1=x2;
             vis=b[j]-'0';
             t1-=(b[j]-'0')*qpow(3,len2-1-j);
             for(int k=0;k<3;k++)
             {
                 if(k==vis) continue;
                 if(t1+k*qpow(3,len2-1-j)==t) 
                 {
                     cout<<t<<endl;
                     return 0;
                 }
             }       
        }
    }
}
