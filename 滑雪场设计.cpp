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
#include<ctime>
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
int g[1001][1001];
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      freopen("input.txt","w",stdout);
      cout<<1000<<" "<<1000<<endl;
      for(int i=1;i<=1000;i++)
      {
            for(int j=1;j<=1000;j++)
            {
                  g[i][j]=rand()%2;
            }
            //cout<<endl;
      }
      g[101][120]=2;
      g[223][367]=3;
      for(int i=120;i<=1000;i++)
      {
            g[102][i]=0;
      }
      for(int i=222;i>=100;i--)
      {
            g[i][367]=0;
      }
      for(int i=1;i<=1000;i++)
      {
            for(int j=1;j<=1000;j++)
            {
                  cout<<g[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}