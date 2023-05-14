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
#define int long long
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
      for(int i=1;i<=40;i++)
      printf("imageList.add(R.drawable.avatar%02d);\n",i);

      return 0;
}



/*
imageList.add(R.drawable.avatar01);
imageList.add(R.drawable.avatar02);
imageList.add(R.drawable.avatar03);
imageList.add(R.drawable.avatar04);
imageList.add(R.drawable.avatar05);
imageList.add(R.drawable.avatar06);
imageList.add(R.drawable.avatar07);
imageList.add(R.drawable.avatar08);
imageList.add(R.drawable.avatar10);
imageList.add(R.drawable.avatar11);
imageList.add(R.drawable.avatar12);
imageList.add(R.drawable.avatar13);
imageList.add(R.drawable.avatar14);
imageList.add(R.drawable.avatar15);
imageList.add(R.drawable.avatar16);
imageList.add(R.drawable.avatar17);
imageList.add(R.drawable.avatar18);
imageList.add(R.drawable.avatar19);
imageList.add(R.drawable.avatar20);
imageList.add(R.drawable.avatar25);
imageList.add(R.drawable.avatar27);
imageList.add(R.drawable.avatar31);
imageList.add(R.drawable.avatar32);
imageList.add(R.drawable.avatar33);
imageList.add(R.drawable.avatar34);
imageList.add(R.drawable.avatar35);
imageList.add(R.drawable.avatar36);
imageList.add(R.drawable.avatar37);
imageList.add(R.drawable.avatar38);
imageList.add(R.drawable.avatar39);
imageList.add(R.drawable.avatar40);
*/