#pragma once
#include <stack>

typedef enum {UNDISCOVERED,DISCOVERED,VISITED} VStatus;
typedef enum {UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD} EType;

template<typename Tv,typename Te>
class Graph
{
public:
	void reset()
	{
		for (int i = 0; i < n; i++)
		{
			status(i) = UNDISCOVERED;
			dTime(i) = -1;
			fTime(i) = -1;
			parent(i) = -1;
			priority(i) = INT_MAX;

			for (int j = 0; j < n; j++)
			{
				if (exists(i, j))
					type(i,j) = EType::UNDETERMINED;
			}
		}
	}

	void BFS(int,int&);
	void DFS(int, int&);
	void BCC(int, int&, std::stack<int>&);		//基于DFS的双连通分解算法
	bool TSort(int, int&, std::stack<Tv>*);		//基于DFS的拓扑排序

public:
	int n;
	virtual int insert(Tv const&) = 0;	//插入顶点
	virtual Tv remove(int) = 0;
	virtual Tv& vertex(int) = 0;
	virtual int inDegree(int) = 0;
	virtual int outDegree(int) = 0;
	virtual int firstNbr(int) = 0;			//第一个邻节点
	virtual int nextNbr(int,int) = 0;		//下一个临接点

	virtual VStatus& status(int) = 0;
	virtual int& dTime(int) = 0;			//第一次访问的时间
	virtual int& fTime(int) = 0;			//第二次访问的时间
	virtual int& parent(int) = 0;	
	virtual int& priority(int) = 0;

	int e;
	virtual bool exists(int, int) = 0;
	virtual void insert(Te const&, int, int, int) = 0;
	virtual Te remove(int, int) = 0;
	virtual EType& type(int, int) = 0;
	virtual Te& edge(int, int) = 0;
	virtual int& weight(int, int) = 0;

	void dfs(int);
	void bfs(int);
	void bcc(int);

	std::stack<Tv>* tSort(int);		//基于dfs的拓扑排序

	void prim(int);					//最小支撑树
	void dijkstra(int);				//最短路径算法
};
