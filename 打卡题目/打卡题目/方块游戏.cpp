#include<iostream>
#include <set>
using namespace std;
int cnt[26];
void turn(string s1,string s2){
    int t1[26]={0}; int t2[26]={0};
    for(auto i:s1) t1[i-'a']++;
    for(auto i:s2) t2[i-'a']++;
    for(int i=0;i<26;i++)
    cnt[i]+=max(t1[i],t2[i]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        turn(s1,s2);
    }
    for(int i=0;i<26;i++)
    cout<<cnt[i]<<endl;
    return 0;
}


