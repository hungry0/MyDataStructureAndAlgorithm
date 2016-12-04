#include <iostream>
#include "graph.h"
#include "Graphmatrix.h"
#include "graph_tsort.h"

using namespace std;

void main()
{
	GraphMatrix<int, int> G;

	for (auto i = 0; i < 6; i++)
	{
		G.insert(i);
	}

	G.insert(1, 1, 0, 2);
	G.insert(1, 1, 1, 2);

	G.insert(1, 1, 2, 3);
	G.insert(1, 1, 3, 4);
	G.insert(1, 1, 4, 5);

//	G.dfs(1);

//	G.bfs(0);

	auto s = G.tSort(0);

//	cout << s->size();

	while (!s->empty())
	{
		cout << s->top() << " ";
		s->pop();
	}
		

	system("pause");
}