#pragma once
#include "graph.h"
#include "queue.h"

/*
	广度遍历
*/

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s)
{
	reset();

	int clock = 0;

	int v = s;

	do
	{
		if (status(v) == UNDISCOVERED)
			BFS(v, clock);
	}
	while (s != (v = (++v % n)));

	v = n - 1;

	while (parent(v) != -1)
	{
		std::cout << v << " ";
		v = parent(v);
	}
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock)
{
	Queue<int> Q;

	status(v) = DISCOVERED;

	Q.enqueue(v);

	while (!Q.isEmpty())
	{
		int v = Q.dequeue();

		dTime(v) = ++clock;

		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
		{
			if (status(u) == UNDISCOVERED)
			{
				status(u) = DISCOVERED;

				Q.enqueue(u);

				type(v, u) = TREE;

				parent(u) = v;
			}
			else //已被发现或者已访问完毕
			{
				type(v, u) = CROSS;
			}
		}

		status(v) = VISITED;
	}
}


