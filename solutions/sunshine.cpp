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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans1=n/4;
        bool ok1=true;
        bool ok2=true;
        if((n-ans1*4)%6!=0)
        {
            ok1=false;
            //continue;
        }
        ll ans2=n/6;
        if((n-ans2*6)%4!=0)
        {
            ok2=false;
            //cout<<-1<<endl;
            //continue;
        }
        if(!ok1&&!ok2)
        {
            cout<<-1<<endl;
            continue;
        }
        ll minn,maxn;
        if(ok1)
        {
            minn=maxn=ans1+(n!=ans1*4);
        }        //cout<<ans2+(n==ans2*6)<<" "<<ans1+(n==ans1*4)<<endl;
        cout<<ok1<<" "<<ok2<<endl;
        if(ok2)
        {
            if(!ok1)
            {
                minn=maxn=ans2+(n!=ans2*6);
            }
            else 
            {
                minn=min(minn,ans2+(n!=ans2*6));
                maxn=max(maxn,ans2+(n!=ans2*6));
            }
        }
        cout<<minn<<" "<<maxn<<endl;
    }
    return 0;
}    