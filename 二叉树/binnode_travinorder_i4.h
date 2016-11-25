#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"

template<typename T>
void travIn_I4(BinNodePosi(T) x)	//ÖÐÐò±éÀúµü´ú°æ#4
{
	while (true)
	{
		if (HasLChild(*x))
		{
			x = x->lc;
		}else
		{
			cout << x->data << " ";
			while (!HasRChild(*x))
			{
				if (!(x = x->succ())) return;
				else cout << x->data << " ";
			}

			x = x->rc;
		}
	}
}
