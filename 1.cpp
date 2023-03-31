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
unordered_map<char,double>ss;
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      freopen("input.txt","r",stdin);
      ss['j']=(5+10)/2.0;
      ss['d']=(3+5)/2.0;
      ss['e']=(0.5+0.1)/2;
      ss['l']=(1+2)/2.0;
      ss['m']=(0.5+1)/2;
      ss['n']=(15+20)/2.0;
      ss['p']=(2+3)/2.0;
      ss['t']=(1+3)/2.0;
      ss['v']=(20+25)/2.0;
      string s;
      while(cin>>s)
      {
            double ans=0;
            for(auto x:s)
            {
                  ans+=ss[x];
            }
            cout<<fixed<<setprecision(2)<<ans<<endl;
      }
      return 0;
}