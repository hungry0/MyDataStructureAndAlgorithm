#pragma once
#include "bintree.h"
#include <queue>

/**************************************************************

Author：hungry
Date:2016.11.30
Description:层次遍历

Analysis:
① 使用辅助队列
② 将左右孩子都放入队列
③ 循环处理，直到队列为空

**************************************************************/

template <typename T>
void BinNode<T>::travLevel()
{
	std::queue<BinNodePosi(T)> Q;

	Q.push(this);

	while (!Q.empty())
	{
		BinNodePosi(T) x = Q.front();
		
		std::cout << x->data << " ";

		Q.pop();

		if(HasLChild(*x)) Q.push(x->lc);
		if(HasRChild(*x)) Q.push(x->rc);
	}
}

