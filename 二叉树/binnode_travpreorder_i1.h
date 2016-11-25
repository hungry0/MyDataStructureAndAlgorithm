#pragma once
#include "binnode.h"
#include <stack>
#include "binnode_macro_basic.h"

template<typename T>
void travPre_I1(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> s;

	if (x != NULL)
		s.push(x);

	while(!s.empty())
	{
		x = s.pop();

		cout << x->data << " ";

		if (HasRChild(*x))	s.push(x->rc);
		if (HasLChild(*x))	s.push(x->lc);
	}
}
