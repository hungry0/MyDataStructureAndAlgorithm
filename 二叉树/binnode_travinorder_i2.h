#pragma once
#include "binnode.h"
#include <stack>

/*
 *	实现思路如同迭代版I1
 */

template<typename T>
void travIn_I2(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> S;

	while (true)
	{
		if(x)
		{
			S.push(x);
			x = x->lc;
		}else if(!S.empty())
		{
			x = S.top(); S.pop();

			cout << x->data << " ";

			x = x->rc;
		}
		else
			break;
	}
}
