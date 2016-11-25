#pragma once
#include "binnode.h"
#include <stack>

template<typename T>
static void GoGlongLeftBranch(BinNodePosi(T) x,std::stack<BinNodePosi(T)> s)
{
	while(x)
	{
		cout << x->data << " ";
		s.push(x->rc);
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

		x = s.pop();
	}
}
