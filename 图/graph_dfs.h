#pragma once
#include "Graphmatrix.h"

/*
 * 深度优先搜索
 */

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s)
{
	reset();

	int clock = 0;

	int v = s;

	do
	{
		if(status(v) == UNDISCOVERED)
			DFS(v, clock);

	} while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int& clock)
{
	dTime(v) = ++clock;

	status(v) = DISCOVERED;

	for (int u = firstNbr(v);-1 < u; u = nextNbr(v,u))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			type(v, u) = TREE;
			parent(u) = v;
			DFS(u, clock);
			break;

		case DISCOVERED:
			type(v, u) = BACKWARD;
			break;
				
		default:					//已访问完毕，即Visited状态
			type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
			break;
		}
	}

	status(v) = VISITED;
	fTime(v) = ++clock;
}




