#pragma once
#include "binnode.h"
#include <stack>
#include "binnode_macro_basic.h"

template<typename T>
static void gotoHLVFL(BinNodePosi(T) x,std::stack<BinNodePosi(T)> S)
{
	while(BinNodePosi(T) x = S.top())
	{
		if(HasLChild(*x))
		{
			if (HasRChild(*x))
				S.push(x->rc);
			S.push(x->lc);
		}
		else
			S.push(x->rc);
	}

	S.pop();
}

template<typename T>
void travPost_I(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> S;
	if (x)	S.push(x);

	while (!S.empty())
	{
		if(S.pop() != x->parent)	//’ª∂•∑«∏∏º¥”“–÷
			gotoHLVFL(S);

		x = S.pop();

		cout << x->data << " ";
	
	}
}
