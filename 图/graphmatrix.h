#pragma once
#include "graph.h"
#include "vector.h"
#include "vector_bracket.h"
#include "vector_remove.h"
#include "vector_insert.h"
#include "vector_constructor_by_copying.h"
#include "vector_assignment.h"

template<typename Tv>
struct Vertex
{
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	int priority;

	Vertex(Tv const& d = static_cast<Tv>(NULL)) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1), fTime(-1), parent(-1), priority(INT_MAX)
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
	Vector< Vector< Edge< Te >* > > E;

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

	Tv& vertex(int i) override
	{
		return V[i].data;
	}

	int inDegree(int i) override
	{
		return V[i].inDegree;
	}

	int outDegree(int i) override
	{
		return V[i].outDegree;
	}

	int firstNbr(int i) override
	{
		return nextNbr(i, n);
	}

	int nextNbr(int i, int j) override
	{
		while ((-1 < j) && !exists(i, --j));

		return j;
	}

	VStatus& status(int i) override
	{
		return V[i].status;
	}

	int& dTime(int i) override
	{
		return V[i].dTime;
	}

	int& fTime(int i) override
	{
		return V[i].fTime;
	}

	int& parent(int i) override
	{
		return V[i].parent;
	}

	int& priority(int i) override
	{
		return V[i].priority;
	}

	//插入顶点
	int insert(Tv const& vertex) override
	{
		for (int j = 0; j < n; j++)
			E[j].insert(NULL);

		n += 1;

		E.insert(Vector< Edge<Te>*> (n, n, static_cast<Edge<Te>*>(NULL)));

		return V.insert(Vertex<Tv>(vertex));
	}

	//删除顶点
	int remove(int i) override
	{
		//释放内存
		for (int j = 0; j < n; j++)
		{
			if (exists(i, j))
			{
				delete E[i][j];
				V[j].inDegree -= 1;
			}
		}

		//删除该节点指向边的集合
		E.remove(i);
		n--;

		Tv vBak = vertex(i);
		V.remove(i);

		for (int j = 0; j < n; j++)
		{
			if (Edge<Te>* e = E[j].remove(i))
			{
				delete e;
				V[j].outDegree -= 1;
			}
		}

		return vBak;
	}

	//两点之间是否存在边
	bool exists(int i, int j) override
	{
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL;
	}

	EType& type(int i, int j) override
	{
		return E[i][j]->type;
	}

	Te& edge(int i, int j) override
	{
		return E[i][j]->data;
	}

	int& weight(int i, int j) override
	{
		return E[i][j]->weight;
	}

	void insert(Te const& edge, int w, int i, int j) override
	{
		if (exists(i, j))
			return;

		E[i][j] = new Edge<Te>(edge, w);
		e++;

		V[i].outDegree += 1;
		V[j].inDegree += 1;
	}

	Te remove(int i, int j) override
	{
		Te eBak = E[i][j]->data;

		delete E[i][j];
		E[i][j] = NULL;

		e--;

		V[i].outDegree -= 1;
		V[j].inDegree -= 1;

		return eBak;
	}
};
