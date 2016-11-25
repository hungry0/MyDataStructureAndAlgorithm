#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"

/*
 * 不带辅助栈的版本，回去查书
 */

template<typename T>
void travIn_I3(BinNodePosi(T) x)
{
	bool backtrack = false;

	while (true)
	{
		if(!backtrack && HasLChild(*x))
		{
			x = x->lc;
		}else
		{
			cout << x->data << " ";

			if(HasRChild(*x))
			{
				x = x->rc;
				backtrack = false;
			}else
			{
				if (!(x = x->succ())) break;
				backtrack = true;
			}
		}
	}
}
