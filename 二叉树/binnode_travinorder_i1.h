#pragma once
#include "binnode.h"
#include <stack>
/*
 *								实现原理
 *						
 *	沿着左分支，一直向下加入栈中，弹出一个，打印之后，转向它的右子节点，继续重复前面的过程。
 */

template<typename T>
static void GoALongLeftBranch(BinNodePosi(T) x,std::stack<BinNodePosi(T)> &S)
{
	while(x)
	{
		S.push(x);
		x = x->lc;
	}
}

template<typename T>
void travIn_I1(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> S;
	
	while(true)
	{
		GoALongLeftBranch(x, S);

		if(S.empty())
			break;

		x = S.top(); S.pop();

		std::cout << x->data<<" ";

		x = x->rc;
	}
}
