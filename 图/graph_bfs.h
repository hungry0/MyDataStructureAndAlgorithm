#pragma once
#include "graph.h"
#include <queue>

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
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock)
{
}


