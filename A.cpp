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
#include<unordered_set>
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
int n,m;
int xe,ye,xb,yb;
int g[1001][1001];
struct node
{
      int x,y;
      int cost;//暂时设置为曼哈顿距离
      bool operator>(const node& other) const {
        return cost > other.cost;}
    bool operator<(const node& other) const {
        return cost < other.cost;}
};
unordered_set<int>going_set,saw_set;
int fa[maxn];
int cal(int dx,int dy)
{
      return abs(dx-xe)+abs(dy-ye);
}
void lu(node now)
{
    int x,y;
    x=now.x;
    y=now.y;
    cout<<"yes"<<endl;
//    return ;
    while (~fa[x*m+y]){
        //cout<<"("<<x<<","<<y<<")"<<" ";
        x=fa[x*m+y]/m;
        y=fa[x*m+y]%m;
        if(!y)
        {
            x--;
            y=m;
        }
    }
    return ;
}
bool A_star()
{
      priority_queue<node,vector<node>,greater<node> >q;
      node n1;
      n1.x=xb;
      n1.y=yb;
      n1.cost=abs(xe-xb)+abs(yb-ye);
      q.push(n1);
      int dir[4][2]={1,0,-1,0,0,1,0,-1};
      going_set.insert(xb*m+yb);
      while(q.size())
      {
            node now=q.top();
        //    lu(now);
            cout<<"现在位于"<<now.x<<" "<<now.y<<" "<<now.cost<<endl;
            //cout<<now.x<<" "<<now.y<<endl;
          cout<<"道路为:";
          lu(now);
          cout<<endl;
            q.pop();
            going_set.erase(now.x*m+now.y);
            saw_set.insert(now.x*m+now.y);
            if(now.x==xe&&now.y==ye)
            {
                  //追踪结束
                  return true;
            }
            else 
            {
                cout<<"筛选了节点：";
                  for(int i=0;i<4;i++)
                  {
                   //   cout<<"yes"<<endl;
                        int dx=now.x+dir[i][0];
                        int dy=now.y+dir[i][1];
                    //    cout<<dx<<" "<<dy<<endl;
                        if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!saw_set.count(dx*m+dy)&&!going_set.count(dx*m+dy)&&g[dx][dy]!=1)
                        {
                           // cout<<"yes"<<endl;
                              fa[dx*m+dy]=now.x*m+now.y;
                              node next1;
                              next1.x=dx;
                              next1.y=dy;
                              next1.cost=now.cost+1+cal(dx,dy);
                              q.push(next1);
                              going_set.insert(dx*m+dy);
                              cout<<dx<<" "<<dy<<" "<<next1.cost<<endl;
                        }
                  }
            }
      }
      return false;
}
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;i++)
      {
            for(int j=1;j<=m;j++)
            {
                  cin>>g[i][j];
                 // cout<<g[i][j]<<" ";
                  if(g[i][j]==2)
                  {
                        xb=i;
                        yb=j;
                  }
                  if(g[i][j]==3)
                  {
                        xe=i;
                        ye=j;
                  }
            }
           // cout<<endl;
      }
      //cout<<xb<<" "<<yb<<" "<<xe<<" "<<ye<<endl;
      vector<pair<int,int> >ans;
      fa[xb*m+yb]=-1;
      if(A_star())
      {
            int nx=xe;
            int ny=ye;
            pair<int,int>now;
            while(~fa[nx*m+ny])
            {
                //cout<<"yes";
                  now.first=nx;
                  now.second=ny;
                  ans.push_back(now);
                  int& fa1=fa[nx*m+ny];
                  nx=fa1/m;
                  ny=fa1%m;
                  if(!ny)
                  {
                        nx--;
                        ny=m;
                  }
            }
            now.first=xb;
            now.second=yb;
            ans.push_back(now);
            for(int i=0;i<ans.size();i++)
            {
                  cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
      }
      else cout<<"Search failed!"<<endl;
      return 0;
}