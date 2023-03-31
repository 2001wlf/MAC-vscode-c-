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

typedef struct QNode { 
	int data; 
	struct QNode * rear; 
	struct QNode * next; 
}QNode,*linklist; 
//链式队列的初始化 
int InitLinkQueue(linklist &L){ 
	L = new QNode; 
	if(L==NULL){ 
		printf("内存分配失败！\n"); 
		return 1; 
	}
	L->rear=L; 
	return 1; 
}
//链式队列的建立 
int Create(linklist & L,int n) { 
	srand(time(0)); 
	linklist P; 
	for(int i=0;i<n;i++) { 
		P = new QNode; 
		P->data=rand()%100+1; 
		L->rear->next=P; 
		L->rear=P; 
	}
	P->next=L;
	return 1;
}
//入队操作 
int EnQueue(linklist & L,int e) { 
	linklist P; 
	P=(linklist)malloc(sizeof(QNode)); 
	P->data=e; 
	P->next=L; 
	L->rear->next=P; 
	L->rear=P; 
	return 1; 
}
//出队操作 
int DeQueue(linklist & L,int & e) { 
	linklist temp; 
	e=L->next->data; 
	temp=L->next; 
	L->next=L->next->next; 
	delete(temp); 
	return 1; 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("input.txt","r",stdin);

    return 0; 
}    