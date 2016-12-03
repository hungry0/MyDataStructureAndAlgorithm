#pragma once
#include "binnode.h"
#include <stack>
#include "binnode_macro_basic.h"
#include <iostream>

/**************************************************************

Author：hungry
Date:2016.11.30
Description:非递归版先序遍历（一）

Analysis:
① 将root节点放入栈中
② 弹出一个节点，直接访问，然后将该节点的右孩子和左孩子按顺序放入栈中
③ 重复以上过程，直到栈为空

**************************************************************/

template<typename T>
void travPre_I1(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> s;

	if (x != nullptr)
		s.push(x);

	while(!s.empty())
	{
		x = s.top(); s.pop();

		std::cout << x->data << " ";

		if (HasRChild(*x))	s.push(x->rc);
		if (HasLChild(*x))	s.push(x->lc);
	}
}
