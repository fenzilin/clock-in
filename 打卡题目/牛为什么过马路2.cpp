#include<iostream>
#include<map>
using namespace std;
int res;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<=25;i++)
    {
        char x=i+'A';
        bool falg=false;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]==x)
            {
                j++;
                map<char ,int >mp;
                while(s[j]!=x)
                {
                   mp[s[j]]++;
                   j++;
                }
                for(auto k:mp)
                {
                    if(k.second==1)res++;
                }
                falg=true;
            }
            if(falg)break;
        }
    }
    cout<<res/2;
    return 0;
}
