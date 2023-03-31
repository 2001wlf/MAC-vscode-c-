#include<iostream>
#include<cstring>
//#include<malloc.h>
#include <algorithm>
#include <queue>
 
#define MAX_VERTEX 20
#define GQSIZE 20
#define maxnum 120
#define INF 10000000
 
using namespace std;
 
typedef char VertexType;  //各个结构体的定义
 
typedef struct ANode{
	int AdjVex;
	struct ANode *NextArc;
}ArcNode;
 
typedef struct VNode{
	VertexType Data;
	ArcNode *FirstArc;
}VerNode,AdjList[MAX_VERTEX];
 
typedef struct Graph{
	AdjList Vertices;   //相当于VerNode Vertices[MAX_VERTEX];
	int VerNum, ArcNum;
}ALGraph;
 
typedef struct Queue{
	int Base[GQSIZE];
	int front, rear;
}GCQueue;
 
int LocateVex(ALGraph G, VertexType V)
{
	int i = 0;
	while (i<G.VerNum && V!=G.Vertices[i].Data)
	{
		i++;
	}
	if (i < G.VerNum)
		return i;
	else
	{
		return -1;
	}
}
 
void CreateGraph(ALGraph &G)   //创建无向图（包括生成相应的邻接表）
{
	int VNum, ANum;
	VertexType V1, V2;
	cout << "请分别输入顶点数和边数：" << endl;
	cin >> VNum >> ANum;
	G.VerNum = VNum;
	G.ArcNum = ANum;
	cout << "请输入各顶点：" << endl;
	for (int i = 0; i != G.VerNum; i++)
	{
		cin >> G.Vertices[i].Data;
		G.Vertices[i].FirstArc = NULL;
	}
	for (int j = 0; j != G.ArcNum; j++)
	{
		cout << "请输入边所在的两顶点：" << endl;
		cin >> V1 >> V2;
		int k = LocateVex(G, V1);
		int l = LocateVex(G, V2);
 
		if (k >= 0 && l >= 0)
		{
			ArcNode *P = (ArcNode*)malloc(sizeof(ArcNode));
			P->AdjVex = l;
			P->NextArc = NULL;
			if (!G.Vertices[k].FirstArc)
				G.Vertices[k].FirstArc = P;
			else
			{
				ArcNode *L = G.Vertices[k].FirstArc;
				while (L->NextArc)
				{
					L = L->NextArc;
				}
				L->NextArc = P;
			}
		}
		else
			cout << "没有这条边！！" << endl;
	}
 
	cout << endl;
	cout << "输出邻接表：" << endl;
	for (int i = 0; i != G.VerNum; i++)
	{
		cout <<i << G.Vertices[i].Data;
		ArcNode *H = G.Vertices[i].FirstArc;
		while (H)
		{
			cout <<"->"<< H->AdjVex;
			H = H->NextArc;
		}
		cout << endl;
	}
}
 
int FirstAdjvex(ALGraph G, int v)  //查找第一个邻接点
{
	if (G.Vertices[v].FirstArc)
		return G.Vertices[v].FirstArc->AdjVex;
	else return -1;
}
 
int NextAdjvex(ALGraph G, int v, int w)  //查找下一个邻接点
{
	int flag = 0;
	ArcNode *P = G.Vertices[v].FirstArc;
	while (P)
	{
		if (P->AdjVex == w)
		{
			flag = 1;
			break;
		}
		else
			P = P->NextArc;
	}
	if (flag&&P->NextArc)
		return P->NextArc->AdjVex;
	else return -1;
}
 
bool Visited[MAX_VERTEX];
void DFS(ALGraph G, int v)  //递归的深度优先搜索
{
	Visited[v] = true;
	cout << G.Vertices[v].Data << " ";
	for (int w = FirstAdjvex(G, v); w >= 0; w = NextAdjvex(G, v, w))
	{
		if (!Visited[w])
			DFS(G, w);
	}
}
void DFSTraverse(ALGraph G)
{
	for (int v = 0; v != G.VerNum; v++)   //此处for语句不可和下面for语句合并，这是先前的初始化，放在下面会导致初始化前就会被赋值
	{
		Visited[v] = false;
	}
	for (int v = 0; v !=G.VerNum; v++)
	{
		if (!Visited[v])
			DFS(G, v);
	}
	cout << endl;
}
 
void BFSTraverse(ALGraph G)  //基于队列的广度优先搜索
{
	GCQueue Q;
	Q.front = Q.rear = 0;
	for (int v = 0; v != G.VerNum; v++)
	{
		Visited[v] = false;
	}
	for (int v = 0; v != G.VerNum; v++)
	{
		if (!Visited[v])
		{
			Visited[v]=true;
			cout << G.Vertices[v].Data << " ";
			if (((Q.rear + 1) % GQSIZE) == Q.front)
			{
				cout << "队满，不能入队！！！" << endl;
				return;
			}
			Q.Base[Q.rear] = v;
			Q.rear = (Q.rear + 1) % GQSIZE;
 
			while (Q.rear!=Q.front)
			{
				int u = Q.Base[Q.front];
				Q.front = (Q.front + 1) % GQSIZE;
				for (int w = FirstAdjvex(G, u); w >= 0; w = NextAdjvex(G, u, w))
				{
					if (!Visited[w])
					{
						Visited[w] = true;
						cout << G.Vertices[w].Data << " ";
						if (((Q.rear + 1) % GQSIZE) == Q.front)
						{
							cout << "队满，不能入队！！！" << endl;
							return;
						}
						Q.Base[Q.rear] = w;
						Q.rear = (Q.rear + 1) % GQSIZE;
 
					}
				}
 
			}
 
		}
	}
}
int main()
{
	ALGraph G;
	CreateGraph(G);
	cout << "深度优先遍历为：";
	DFSTraverse(G);
	cout << endl;
	cout << "广度优先遍历为：";
	BFSTraverse(G);
	cout << endl;
	return 0;
}