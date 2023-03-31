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
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      //freopen("input.txt","r",stdin);
      int t;
      cin>>t;
      while(t--)
      {
            int m;
            cin>>m;
            vector<vector<int> >s;
            vector<int>last1;
            last1.resize(m+1);
            s.resize(m+1);
            for(int i=1;i<=m;i++)
            {
                  int n;
                  cin>>n;
                  s[i].resize(n+1);
                  for(auto x:s)
                  {
                        last[x]=i;
                  }
            }
            vector<int>ans(m+1,-1);
            for(int i=1;i<=m;i++)
            {
                  for(int j=1;j<s[i].size();j++)
                  {
                        if(last1[j]==s[i][j])
                        {
                              ans[j]=s[i][j];
                        }
                  }
                  if(ans[i]==-1)
                  {
                        cout<<-1<<endl;
                        break;
                  }
            }
            for(int i=1;i<=m;i++)
            {
                  cout<<ans[i]<<" ";
            }
            cout<<endl;
      }
      return 0;
}