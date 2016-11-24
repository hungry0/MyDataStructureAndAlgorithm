#pragma once
#include "graph.h"
#include "vector.h"

template<typename Tv>
struct Vertex
{
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	int priority;

	Vertex(Tv const& d = (Tv)NULL) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1), fTime(-1), parent(-1), priority(INT_MAX)
	{
	}
};

template<typename Te>
struct Edge
{
	Te data;
	int weight;
	EType type;
	Edge(Te const& d, int w) :data(d), weight(w), type(UNDETERMINED){}
};

template<typename Tv,typename Te>
class GraphMatrix : public Graph<Tv, Te>
{
private:
	Vector< Vertex<Tv>> V;
	Vector< Vector< Edge<Te>*>> E;

public:
	GraphMatrix()
	{
		n = e = 0;
	}

	~GraphMatrix()
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				delete E[j][k];
			}
		}
	}

	virtual Tv& vertex(int i)
	{
		return V[i].data;
	}

	virtual int inDegree(int i)
	{
		return V[i].inDegree;
	}

	virtual int outDegree(int i)
	{
		return V[i].outDegree;
	}

	virtual int firstNbr(int i)
	{
		return nextNbr(i, n);
	}

	virtual int nextNbr(int i, int j)
	{
		while ((-1 < j) && !exists(i, --j));
		
		return j;
	}

	virtual int& dTime(int i)
	{
		return V[i].dTime;
	}

	virtual int& fTime(int i)
	{
		return V[i].fTime;
	}

	virtual int& parent(int i)
	{
		return V[i].parent;
	}

	virtual int& priority(int i)
	{
		return V[i].priority;
	}

	//插入顶点
	virtual int insert(Tv const& vertex)
	{
		for (int j = 0; j < n; j++)
			E[j].insert(NULL);
		n++;

		return V.insert(Vertex<Tv>(vertex));
	}

	//删除顶点
	virtual int remove(int i)
	{
		//释放内存
		for (int j = 0; j < n; j++)
		{
			if (exists(i, j))
			{
				delete E[i][j];
				V[j].inDegree--;
			}
		}

		//删除该节点指向边的集合
		E.remove(i);
		n--;

		Tv vBak = vertex(i);
		V.remove(i);

		for (int j = 0; j < n; j++)
		{
			if (Edge<Te> * e = E[j].remove(i))
			{
				delete e;
				V[j].outDegree--;
			}
		}

		return vBak;
	}

	//两点之间是否存在边
	virtual bool exists(int i, int j)
	{
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
	}

	virtual EType& type(int i, int j)
	{
		return E[i][j]->type;
	}

	virtual Te& edge(int i, int j)
	{
		return E[i][j]->data;
	}

	virtual int& weight(int i, int j)
	{
		return E[i][j]->weight;
	}

	virtual void insert(Te const& edge, int w, int i, int j)
	{
		if (exists(i, j))
			return;

		E[i][j] = new Edge<Te>(edge, w);
		e++;

		V[i].outDegree++;
		V[j].inDegree++;
	}

	virtual Te remove(int i, int j)
	{
		Te eBak = E[i][j];

		delete E[i][j];
		E[i][j] = NULL;

		e--;

		V[i].outDegree--;
		V[j].inDegree--;

		return eBak;
	}


};
