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
      string name;
      double ans;
      double ans1,ans2;
}no[maxn];
bool cmp(node a,node b)
{
      return a.ans>b.ans;
}
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      freopen("input.txt","r",stdin);
      string s;
      double ans1,ans2;
      int k=0;
      while(cin>>s>>ans1>>ans2)
      {
            int ans=0;
            for(int i=1;i<=k;i++)
            {
                  if(s==no[i].name)
                  {
                        ans=i;
                        break;
                  }
            }
            if(ans==0)
            {
                  no[++k].name=s;
                  ans=k;
            }
            no[ans].ans1+=ans1;
            no[ans].ans2+=ans2;
      }
      //sort()
      for(int i=1;i<=k;i++)
      {
            no[i].ans=no[i].ans1/no[i].ans2;
         //   cout<<no[i].name<<" "<<no[i].ans1<<" "<<no[i].ans2<<" "<<no[i].ans1/no[i].ans2<<endl;
      }
      sort(no+1,no+k+1,cmp);
      for(int i=1;i<=30;i++)
      {
            //cout<<no[i].name;
            //cout<<no[i].ans1;
            //cout<<no[i].ans2;
            cout<<no[i].ans;
            cout<<endl;
            //cout<<no[i].name<<", "<<no[i].ans1<<", "<<no[i].ans2<<", "<<no[i].ans<<endl;
      }
      
      return 0;
}