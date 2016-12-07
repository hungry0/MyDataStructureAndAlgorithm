#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"

/*
 *后继节点，即中序遍历中后边的节点
 */

template <typename T>
BinNode<T>* BinNode<T>::succ()
{
	BinNodePosi(T) s = this;

	if(s->rc)
	{
		s = s->rc;

		while (HasLChild(*s))
			s = s->lc;
	}else
	{
		while (IsRChild(*s))
		{
			s = s->parent;
		}

		s = s->parent;
	}

	return s;
}

