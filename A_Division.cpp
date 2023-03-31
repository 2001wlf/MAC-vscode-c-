/*
 * @Author: Dragonw
 * @LastEditors: Dragonw
 * @LastEditTime: 2022-05-07 22:22:59
 * @FilePath: /Desktop/c++/A_Division.cpp
 * 
 */
#include<iostream>
#include<cstdio>
#include<iterator>
#include<cstring>
#include<string>
#include<stack>
#include<algorithm>
#include<set>
#include<cmath>
#include<map>
#include<deque>
#include<queue>
#include<vector>
#include<iomanip>
#include<unordered_map>
using namespace std;
#define endl '\n'
#define sin scanf
#define sout printf
#define all(x) (x).begin(),(x).end() 
#define PII pair<int,int> 
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const int Mod=1e9+7;
const int maxn = 1e6+10;
ll f[201][201];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("input.txt","r",stdin);
	int n,k,m;
	cin>>n>>k>>m;
	memset(f,-INF,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int v;
		sin("%d",&v);
		for(int j=1;j<=m;j++)
		{
			for(int u=max(i-k,0);u<i;u++)
			{
				f[i][j]=max(f[i][j],f[u][j-1]+v);
			}
		}
	}
	ll res=-1;
	for(int i=n-k+1;i<=n;i++)
	{
		res=max(res,f[i][m]);
	}
	cout<<res<<endl;
	return 0;
}