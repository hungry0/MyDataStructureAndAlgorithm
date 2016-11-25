#pragma once
#include "bintree.h"
#include <queue>

template <typename T>
void BinNode<T>::travLevel()
{
	std::queue<BinNodePosi(T)> Q;

	Q.push(this);

	while (!Q.empty())
	{
		BinNodePosi(T) x = Q.pop();

		std::cout << x->data << " ";

		Q.push(x->lc);
		Q.push(x->rc);
	}
}

