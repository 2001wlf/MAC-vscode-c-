/*
 * @Author: Dragonw
 * @LastEditors: Dragonw
 * @LastEditTime: 2022-05-02 09:28:24
 * @FilePath: /c++/datalab4.cpp
 * 
 */
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
#define MAX_SIZE 100
#define TElemType char
typedef struct BiNode{
      TElemType data;
      struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
void PreOrderTraverse(BiTree T)
{
      if(T)
      {
            cout<<T->data;
            PreOrderTraverse(T->lchild);
            PreOrderTraverse(T->rchild);
      }
      return ;
}
void InOrderTraverse(BiTree T)
{
      if(T)
      {
            InOrderTraverse(T->lchild);
            cout<<T->data;
            InOrderTraverse(T->rchild);
      }
      return ;
}
void PostOrderTraverse(BiTree T)
{
      if(T)
      {
            PostOrderTraverse(T->lchild);
            PostOrderTraverse(T->rchild);
            cout<<T->data;
      }
      return ;
}
void InOrderTraverse1(BiTree T)
{
      stack<BiTree>s;
      BiTree q=T;
      while(q||!s.empty())
      {
            if(q)
            {
                  s.push(q);
                  q=q->lchild;
            }
            else 
            {
                  BiTree now=s.top();
                  s.pop();
                  cout<<now->data;
                  q=now->rchild;
            }
      }
      return ;
}
int ans=0;
int Depth(BiTree T)
{
      if(T==NULL) return 0;
      else 
      {
            int m,n;
            m=Depth(T->lchild);
            n=Depth(T->rchild);
            if(m>n)
            {
                  return m+1;
            }
            else return n+1;
      }
}
int LeafCount(BiTree T)
{
      if(T==NULL)
      {
            return 0;
      }
      if(T->lchild==NULL&&T->rchild==NULL)
      {
            return 1;
      }
      else return LeafCount(T->lchild)+LeafCount(T->rchild);
}
int NodeCount(BiTree T)
{
      if(T==NULL)
      {
            return 0;
      }
      else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
void CreateBiTree(BiTree &T)
{
      char ch;
      cin>>ch;
      if(ch=='#')
      {
            T=NULL;
      }
      else 
      {
            T=new BiNode;
            T->data=ch;
            CreateBiTree(T->lchild);
            CreateBiTree(T->rchild);
      }
      return ;
}
void LevelOrderTraverse(BiTree T)
{
      queue<BiTree>q;
      if(T!=NULL)
      q.push(T);
      while(q.size())
      {
            BiTree node=q.front();
            q.pop();
            cout<<node->data;
            if(node->lchild)
            {
                  q.push(node->lchild);
            }
            if(node->rchild)
            {
                  q.push(node->rchild);
            }
      }
      return ;
}
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      //freopen("input.txt","r",stdin);
      BiTree T;
      CreateBiTree(T);
      cout<<endl;
      PreOrderTraverse(T);
      cout<<endl;
      InOrderTraverse(T);
      cout<<endl;
      InOrderTraverse1(T);
      cout<<endl;
      PostOrderTraverse(T);
      cout<<endl;
      LevelOrderTraverse(T);
      cout<<endl;
      cout<<Depth(T)<<endl;
      return 0;
}