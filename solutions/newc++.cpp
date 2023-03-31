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
template<class T>
inline void read(T &x)
{
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
int vis[maxn];
int a[maxn];
int dis[maxn];
int maxval=0;
int dfs(int x,int d)
{
      if(a[x]==-1||dis[x])
      {
            maxval=max(maxval,dis[x]+d);
            return d<<1;
      }
      int res=dfs(a[x],d+1);
      dis[x]=dis[a[x]]+1;
      return res;
}
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      //freopen("input.txt","r",stdin);
      int n,m;
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
            cin>>a[i];
      }
      int ans=0;
      for(int i=1;i<=m;i++)
      {
            int x;
            cin>>x;
            ans+=dfs(x,0);
            cout<<ans-maxval<<endl;
      }
      return 0;
}