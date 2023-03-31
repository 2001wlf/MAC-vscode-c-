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
#define Maxsize 10 
int tag; 
typedef struct {
	int *data; 
	int front; 
	int rear; 
} SqQueue; //初始化 
void Init(SqQueue &q){ 
	q.front = 0; 
	q.rear = 0; 
	q.data = new int[Maxsize]; 
	tag = 0; 
}//判空 
bool Is_Empty(SqQueue q){ 
	if(q.front == q.rear && tag == 0) 
		return true; 
	return false; 
}//判满 
bool Is_Full(SqQueue q){ 
	if(q.front == ((q.rear) % Maxsize) && tag == 1) 
	return true; 
	return false; 
}//插入 
void Insert(SqQueue &q,int e){ 
	if(Is_Full(q)){ 
		cout << "循环队列已满\n"; 
	}
	else{
		q.data[q.rear] = e; 
		q.rear = (q.rear + 1) % Maxsize; 
		if(q.front == q.rear) 
			tag = 1; 
	} 
}//删除 
void Delete(SqQueue &q){ 
	if(Is_Empty(q)){ 
		cout << "循环队列是空的\n"; 
	}
	else{
		int x = q.data[q.front]; 
		q.front = (q.front + 1) % Maxsize; 
		if(q.front == q.rear) 
			tag = 0; 
		cout << "删除元素为：" << x << "\n"; 
	} 
}
void help()
{
	cout << "输入操作数(1,2,3,4)" << endl ; 
	cout << "1-->--> 判空" << endl; 
	cout << "2-->--> 判满" << endl; 
	cout << "3-->--> 插入" << endl; 
	cout << "4-->--> 删除" << endl;

}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("input.txt","r",stdin);
	SqQueue q; 
	Init(q); 
	int x ; 
	cin >> x; 
	help();
	while(x--){ 
		char op; 
		cin >> op; 
		if(op == '1') { 
			if(Is_Empty(q)) 
				cout <<endl<< "空的" << "\n"; 
			else
				cout <<endl<< "未空" << "\n"; 
		}
		else if(op == '2'){ 
			if(Is_Full(q)) 
				cout << "满的" << "\n"; 
			else
				cout << "未满" << "\n"; 
		}
		else if(op == '3'){ 
			cout << "输入插入元素："; 
			int e; 
			cin >> e; 
			Insert(q, e);
		}
		else if(op == '4'){ 
			Delete(q); 
		} 
	}
	return 0;
}	