#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int dp[maxn][maxn];
int arr[maxn][maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+arr[i][j];	
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}