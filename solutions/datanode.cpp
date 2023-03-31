#include <iostream>
#define Elemtype int
using namespace std;
//1.定义存储表示
typedef struct LNode
{
    Elemtype value;
    LNode *next;
}LNode,*LinkList;

void Init_List(LinkList &l)
{
    l=new LNode;
    l->next=NULL;
    return ;
}
//2.定义操作函数1
bool ClearList(LinkList &l)
{
    LinkList p,q;
    p=l->next;
    while(p)
    {
        q=p->next;
        delete p;
        p=q;
    }
    l->next=NULL;
    return true;
}
//3.定义操作函数2

//4.定义操作函数3
int ListLength(LinkList l)
{
    LinkList p=l->next;
    int count=0;
    while(p)
    {
        ++count;
        p=p->next;
    }
    return count;
}
bool ListEmpty(LinkList l)
{
    if(l->next==NULL)
    {
        return true;
    }
    else return false;
}
bool GetElem(LinkList &l,int i,Elemtype &e)
{
    LinkList p=l->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return false;
    }
    e=p->value;
    return true;
}
LNode* LocateElem(LinkList l,Elemtype e)
{
    LinkList p=l->next;
    while(p&&p->value!=e)
    {
        p=p->next;
    }
    return p;
}
bool ListInsert(LinkList &l,int i,Elemtype e)
{
    LinkList p=l;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p) return false;
    LinkList s=new LNode;
    s->value=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool Getpro(LinkList &l,int i,LinkList &ans)
{
    LinkList p;
    p=l;
    int j=0;
    while(p&&j<i-2)
    {
        p=p->next;
        ++j;
    }
    if(!p) return false;
    else ans=p;
    return true;
}
bool getnext(LinkList &l,int i,LinkList &ans)
{
    LinkList p;
    p=l;
    int j=0;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p) return false;
    else ans=p;
    return true;
}
bool ListDelete(LinkList &l,int i,Elemtype &e)
{
    LinkList p=l;
    int j=0;
    while(p->next&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i-1) return false;
    LinkList r=p->next;
    p->next=r->next;
    e=r->value;
    delete r;
    return true;
}

void Destroy_List(LinkList &l)
{
    LinkList p;
    while(l)
    {
        p=l;
        l=l->next;
        delete p;
    }
    return ;
}
void displaylist(LinkList l)
{
    LinkList p=l->next;
    while(p)
    {
        cout<<(p->value)<<" ";
        p=p->next;
    }
    cout<<endl;
}
void show_help()
{
    cout<<"******* Data Structure ******"<<endl;
    cout<<"1----清空线性表"<<endl;
    cout<<"2----判断线性表是否为空"<<endl;
    cout<<"3----求线性表长度"<<endl;
    cout<<"4----获取线性表指定位置元素"<<endl;
    cout<<"5----求前驱"<<endl;
    cout<<"6----求后继"<<endl;
    cout<<"7----在线性表指定位置插入元素"<<endl;
    cout<<"8----删除线性表指定位置元素"<<endl;
    cout<<"9----显示线性表"<<endl;
    cout<<"     退出，输入0"<<endl;
}
void merge(LinkList a,LinkList b,LinkList &c)
{
    LinkList p=a->next;
    LinkList q=b->next;
    LinkList p1=c;
    while(p&&q)
    {
        if(p->value<=q->value)
        {
            LinkList s=new LNode;
            s->value=p->value;
            s->next=NULL;
            p1->next=s;
            p1=s;
            p=p->next;
        }
        else {
            LinkList s=new LNode;
            s->value=q->value;
            s->next=NULL;
            p1->next=s;
            p1=s;
            q=q->next;
        }
    }
    while(p)
    {
        LinkList s=new LNode;
        s->value=p->value;
        s->next=NULL;
        p1->next=s;
        p1=s;
        p=p->next;
    }
    while(q)
    {
        LinkList s=new LNode;
        s->value=q->value;
        s->next=NULL;
        p1->next=s;
        p1=s;
        q=q->next;
    }
    return ;
}
int main()
{
    freopen("input.txt","r",stdin);
    char operate_code;
    show_help();
    LinkList l,a,b,c;
    Init_List(a);
    Init_List(b);
    Init_List(c);
    ListInsert(a,1,1);
    ListInsert(a,2,2);
    ListInsert(a,3,3);
    ListInsert(b,1,1);
    ListInsert(b,2,2);
    ListInsert(b,3,3);
    displaylist(a);
    displaylist(b);
    //return 0;
    merge(a,b,c);
    displaylist(c);
    return 0;
    Init_List(l);
    //定义线性表变量，如SqList L;
    //调用初始化线性表函数，如Init_List(L);
    while(1)
    {
        cout<<"";
        cin>>operate_code;
        if(operate_code=='1')
        {
            ClearList(l);
        }
        else if (operate_code=='2')
        {
            if(ListEmpty(l))
            {
                cout<<"单链表为空"<<endl;
            }
            else cout<<"单链表非空"<<endl;
        }
        else if (operate_code=='3')
        {
            cout<<ListLength(l)<<endl;
        }
        else if (operate_code=='4')
        {   
            Elemtype ans;
            int x;
            cin>>x;
            if(GetElem(l,x,ans))
            {
                cout<<x<<": "<<ans<<endl;
            }
            else cout<<"Error"<<endl;
        }
        else if (operate_code=='5')
        {
            int x;
            cin>>x;
            LinkList ans;
            if(Getpro(l,x,ans))
            {
                cout<<"yes"<<endl;
            }
            else cout<<"no"<<endl;
        }
        else if (operate_code=='6')
        {
            int x;
            cin>>x;
            LinkList ans;
            if(getnext(l,x,ans))
            {
                cout<<"yes"<<endl;
            }
            else cout<<"no"<<endl;
        }
        else if (operate_code=='7')
        {
            int x;
            Elemtype ans=0;
            cin>>x;
            cin>>ans;
            ListInsert(l,x,ans);

        }
        else if (operate_code=='8')
        {
            int x;
            Elemtype ans=0;
            cin>>x>>ans;
            ListDelete(l,x,ans);
        }
        else if (operate_code=='9')
        {
            displaylist(l);
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
    //调用销毁线性表函数，如Destroy_List(L);
    Destroy_List(l);
    return 0;
}