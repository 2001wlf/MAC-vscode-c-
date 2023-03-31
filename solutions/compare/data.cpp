/*
 * @Author: Dragonw
 * @LastEditors: Dragonw
 * @LastEditTime: 2022-05-19 18:27:06
 * @FilePath: /c++/solutions/compare/data.cpp
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
template<class T>
inline void read(T &x)
{
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
struct node
{
      int c,t,id;
}no[maxn];
bool cmp(node a,node b)
{
      if(a.c==b.c)
      {
            if(a.t==b.t)
            {
                  return a.id<b.id;
            }
            return a.t>b.t;
      }
      return a.c<b.c;
}
bool vis[maxn];
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      //freopen("input.txt","r",stdin);
      int n,m;
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
            cin>>no[i].c>>no[i].t;
            no[i].id=i;
      }
      sort(no+1,no+n+1,cmp);
      for(int i=1;i<=n;i++)
      {
          //  cout<<no[i].c<<" ";
            if(!vis[no[i].c])
            {
                 cout<<no[i].id<<" ";
                 vis[no[i].c]=1;
            }
            else continue;
      }
      return 0;
}