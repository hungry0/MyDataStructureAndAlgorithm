#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"

/**************************************************************

Author：hungry
Date:2016.11.30
Description:非递归中序遍历（四）

Analysis:
① 如果有左孩子，遍历到没有左孩子为止
② 没有左孩子，直接打印
③ 如果没有右孩子，则指向后继节点，打印该节点
④ 一直回溯并打印，直到当前节点有了右孩子
⑤ 指向当前节点的右孩子
⑥ 没有后继节点则代表全部遍历结束

**************************************************************/

template<typename T>
void travIn_I4(BinNodePosi(T) x)
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
