#pragma once
#include "binnode.h"
#include <stack>

/**************************************************************

Author：hungry
Date:2016.11.30
Description:非递归版先序遍历（二）

Analysis:
① 沿着当前节点一直访问左孩子并直接访问，然后将右孩子放入栈中
② 访问到没有左孩子为止，然后从栈中弹出一个节点
③ 重复以上过程，直到栈为空

**************************************************************/

template<typename T>
static void GoGlongLeftBranch(BinNodePosi(T) x,std::stack<BinNodePosi(T)> &s)
{
	while(x)
	{
		std::cout << x->data << " ";

		if(HasRChild(*x))  s.push(x->rc);

		x = x->lc;
	}
}

template<typename T>
void travPre_I2(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> s;

	while (true)
	{
		GoGlongLeftBranch(x,s);

		if (s.empty())	break;

		x = s.top(); s.pop();
	}
}
