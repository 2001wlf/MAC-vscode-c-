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
      string s;
      cin>>s;
      stack<char>s;
      for(int i=0;i<s.size();i++)
      {
            if(s.top()==s[i])
            {
                  s.pop_back();
            }
            else s.insert(s[i]);
      }
      cout<<<s.size()<<endl;
      return 0;
}