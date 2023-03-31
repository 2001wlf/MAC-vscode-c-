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
#define maxSize 100 
// 循环队列类型定义 
typedef struct { 
	int *data; 
	int front;// 队首指针 所指位置未赋值 
	int rear;// 队尾指针 
} QNode; // 初始化队列 
void initQueue(QNode &q) { 
	q.data = new int[maxSize] ; 
	q.front=0 ; 
	q.rear=0;// 队首和队尾指针重合并指向0 
}
// 入队（从队头插入） 
void Insert_head(QNode &q,int x) { 
	if(q.rear==(q.front-1+maxSize)%maxSize) 
	{ // 如果队满，则不能入队 
		cout << "队满，不能入队" << endl ; 
	} 
	else { 
		q.data[q.front]=x; 
		q.front=(q.front-1+maxSize)%maxSize; 
		cout << "成功插入" << '\n' ; 
	} 
}
// 出队（从队尾出队） 
void Delete_tail(QNode &q) { 
	if(q.rear==q.front) { 
		cout << "队空，不能出队" << "\n" ; 
	} 
	else { 
		int x=q.data[q.rear]; 
		q.rear=(q.rear-1+maxSize)%maxSize; 
		cout << "已删除" << x ; 
	} 
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("input.txt","r",stdin);
	
	return 0;
}	