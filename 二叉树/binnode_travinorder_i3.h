#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"

/**************************************************************

Author：hungry
Date:2016.11.30
Description:非递归中序遍历（三）

Analysis:
① 从root节点开始遍历
② 如果不是回溯并且有左孩子，则一直遍历到最末端左节点
③ 如果正在回溯或者没有左孩子了，则先打印
④ 打印之后，如果该节点有右孩子，则转向右孩子，并关闭回溯标志
⑤ 如果没有右孩子，则指向后继节点，开启回溯标志

**************************************************************/

template<typename T>
void travIn_I3(BinNodePosi(T) x)
{
	auto backtrack = false;

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
