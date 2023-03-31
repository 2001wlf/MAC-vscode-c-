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
#define MAXSIZE 100
#define MAXQSIZE 100
#define  SElemType int
#define QElemType int 
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;
void InitQueue(SqQueue &q)
{
	q.base=new QElemType[MAXQSIZE];
	q.front=q.rear=0;
	return ;
}
int QueueLength(SqQueue q)
{
	return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;
}
void ClearQueue(SqQueue &q)
{
	q.front=q.rear;
}
bool QueueEmpty(SqQueue q)
{
	return q.rear==q.front;
}
void GetFront(SqQueue q,QElemType &e)
{
	if((q.rear+1)%MAXQSIZE==q.front)
		return ;
	e=q.base[q.front];
	return ;
}
bool EnQueue(SqQueue &q,QElemType e)
{
	if((q.rear+1)%MAXQSIZE==q.front)//队列已满
		return false;
	q.base[q.rear]=e;
	q.rear=(q.rear+1)%MAXQSIZE;
	return true;
}
bool DeQueue(LinkQueue &q,QElemType &e)
{
	if(q.front==q.rear) return false;
	e=q.base[q.front];
	q.front=(q.front+1)%MAXQSIZE;
	return true;
}
void DestroyQueue(SqQueue &q)
{
	if(q.base)
	{
		delete [] q.base;
		q.front=q.rear;
		q.base=NULL:
	}
	return ;
}
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;	
void initStack(SqStack &s)
{
	s.base =new SElemType[MAXSIZE];
	s.top=s.base;
	s.stacksize=MAXSIZE;
}
bool StackEmpty(SqStack s)
{
	if(s.top==s.base) return true;
	return false;
}
int StackLength(SqStack s)
{
	return s.top-s.base;
}
void ClearStack(SqStack &s)
{
	s.top=s.base;
}
void DestroyStack(SqStack &s)
{
	if(s.base)
	{
		delete [] s.base;
		s.stacksize=0;
		s.base=s.top=NULL;
	}
}
bool Push(SqStack &s,SElemType e)
{
	if(s.top-s.base==s.stacksize)
	{
		return false;
	}
	*s.top++=e;
	return true;
}
bool Pop(SqStack &s,SElemType &e)
{
	if(s.top==s.base)
		return false;
	e=*--s.top;
	return false;
}
bool GetTop(SqStack s,SElemType &e)
{
	if(s.top==s.base) return false;
	e=*(s.top-1);
	return true;
}
void show_help()
{
	cout<<"******* Data Structure ******"<<endl;
    cout<<"1----清空顺序栈"<<endl;
    cout<<"2----判断顺序栈是否为空"<<endl;
    cout<<"3----求顺序栈长度"<<endl;
    cout<<"4----在顺序栈栈顶放入元素"<<endl;
    cout<<"5----将顺序栈的栈顶元素推出"<<endl;
    cout<<"6----得到顺序栈栈顶元素"<<endl;
    cout<<"     退出，输入0"<<endl;
    return ;
}
void show_help1(){
	cout<<"******* Data Structure ******"<<endl;
    cout<<"1----清空循环队列"<<endl;
    cout<<"2----判断循环队列是否为空"<<endl;
    cout<<"3----求循环队列长度"<<endl;
    cout<<"4----在循环队列尾部进行入队"<<endl;
    cout<<"5----在循环队列头部进行出队"<<endl;
    cout<<"6----得到循环队列头部元素"<<endl;
    cout<<"     退出，输入0"<<endl;
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("input.txt","r",stdin);
	SqStack s;
	SqQueue q;
	initStack(s);
	while(1)
    {
        cout<<"";
        cin>>operate_code;
        if(operate_code=='1')
        {
           	ClearStack(s);
        }
        else if (operate_code=='2')
        {
            if(StackEmpty(s))
            {
                cout<<"顺序栈为空"<<endl;
            }
            else cout<<"顺序栈非空"<<endl;
        }
        else if (operate_code=='3')
        {
            cout<<StackLength(s)<<endl;
        }
        else if (operate_code=='4')
        {   
            Elemtype e;
            cout<<"输入要放入的元素："<<endl;
            cin>>e;
            if(Push(s,e)) cout<<"success"<<endl;
            else cout<<"error"<<endl;
        }
        else if (operate_code=='5')
        {
			Elemtype e;
			if(Pop(s,e))
			{
				cout<<"success the value is:"<<e<<endl;
			}           
			else cout<<"error"<<endl;
        }
        else if (operate_code=='6')
        {
            Elemtype e;
            if(GetTop(s,e))
            {
            	cout<<"success the value is: "<<e<<endl;
            }
            else cout<<"error"<<endl;
        }
        else if (operate_code=='0')
        {
            break;
        }
        else
        {
            cout<<"\n操作码错误！！！"<<endl;
            show_help();
        }
    }
    DestroyStack(s);
    return 0;
    InitQueue(q);
    while(1)
    {
        cout<<"";
        cin>>operate_code;
        if(operate_code=='1')
        {
           	ClearQueue(q);
        }
        else if (operate_code=='2')
        {
            if(QueueEmpty(q))
            {
                cout<<"循环队列为空"<<endl;
            }
            else cout<<"循环队列非空"<<endl;
        }
        else if (operate_code=='3')
        {
            cout<<QueueLength(q)<<endl;
        }
        else if (operate_code=='4')
        {   
            Elemtype e;
            cout<<"输入要放入的元素："<<endl;
            cin>>e;
            if(EnQueue(q,e)) cout<<"success"<<endl;
            else cout<<"error"<<endl;
        }
        else if (operate_code=='5')
        {
			Elemtype e;
			if(DeQueue(q,e))
			{
				cout<<"success the value is:"<<e<<endl;
			}           
			else cout<<"error"<<endl;
        }
        else if (operate_code=='6')
        {
            Elemtype e;
            if(GetFront(q,e))
            {
            	cout<<"success the value is: "<<e<<endl;
            }
            else cout<<"error"<<endl;
        }
        else if (operate_code=='0')
        {
            break;
        }
        else
        {
            cout<<"\n操作码错误！！！"<<endl;
            show_help();
        }
    }
	DestroyQueue(q);
	return 0;
}	