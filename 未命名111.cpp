#include<iostream>
using namespace std;
const int N = 1000;
int a[N],b[N]; 
int n,res1,res2;
int main() {
	cin >> n;
	for(int i = 0;i < n; i++) scanf("%d",&a[i]);
	for(int i = 0;i < n; i++) scanf("%d",&b[i]);
	for(int i = 0;i < n; i++)
	{
		if(a[i]==b[i])
			{
				res1++;
				
			}
		for(int j = 0;j < n; j++)
		{
			
			if(a[i]==b[j]&&(i!=j))
			{
				res2++;
			}
		}
	}
	cout<<res1<<endl;
	cout<<res2<<endl;
	return 0;
}
