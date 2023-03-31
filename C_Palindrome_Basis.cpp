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
     // ios::sync_with_stdio(false);
      //cin.tie(0),cout.tie(0);
      //freopen("input.txt","r",stdin);
      int n;
      cin>>n;
      getchar();
      while(n--)
      {
            string s;
            getline(cin,s);
            cout<<s<<endl<<"AI: ";
            string ans;
            if(s[0]==' ')
                  s.erase(s.begin());
            if(s.back()==' ')
                  s.erase(s.end()-1);
            for(int i=0;i<s.size();i++)
            {
                  if(s[i]==' ')
                  {
                        while(s[i+1]==' ')
                              s.erase(s.begin()+i+1);
                        if(!isalnum(s[i+1]))
                              s.erase(s.begin()+i);
                  }
            }
            for(int i=0;i<s.size();i++)
            {
                  if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I')
                  {
                        s[i]='a'-'A'+s[i];
                  }
            }
            for(int i=0;;i++)
            {
                  i=s.find("can you",i);
                  if(i==-1)
                        break;
                  if(i==0||!isalnum(s[i-1])&&(i==s.size()-7||!isalnum(s[i+7])))
                  {
                        s.replace(i,7,"@ can");
                  }
            }
            for(int i=0;;i++)
            {
                  i=s.find("could you",i);
                  if(i==-1)
                        break;
                  if(i==0||!isalnum(s[i-1])&&(i==s.size()-9||!isalnum(s[i+9])))
                  {
                        s.replace(i,9,"@ could");
                  }
            }
            for(int i=0;;i++)
            {
                  i=s.find("I",i);
                  if(i==-1) break;
                  if((i==0||!isalnum(s[i-1])&&(i==s.size()-1||!isalnum(s[i+1]))))
                        s.replace(i,1,"you");
            }
            for(int i=0;;i++)
            {
                  i=s.find("me",i);
                  if(i==-1) break;
                  if((i==0||!isalnum(s[i-1])||(i==s.size()-2)||!isalnum(s[i+2])))
                        s.replace(i,2,"you");
            }
            for(int i=0;i<s.size();i++)
            {
                  if(s[i]=='@') s[i]='I';
                  if(s[i]=='?') s[i]='!';
            }
            cout<<s<<endl;
      }
      return 0;
}