#pragma once
#include "binnode.h"
#include <stack>

/**************************************************************

Author：hungry
Date:2016.11.30
Description:非递归中序遍历（二）

Analysis:
① 同非递归版本一

**************************************************************/

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
