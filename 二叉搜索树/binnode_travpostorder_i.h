#pragma once
#include "binnode.h"
#include <stack>
#include "binnode_macro_basic.h"

/**************************************************************

Author：hungry
Date:2016.11.30
Description:非递归后续遍历

Analysis:
① 将root节点push进辅助栈中
② 如果栈顶不是当前元素的父节点（则必为其右兄），则执行③[不会存在都不是的情况，要不JB它挂在谁身上？]
   否则执行⑤
③ 如果有左孩子，则先放右孩子（存在的话）在放左孩子，否则直接放右孩子
④ 遍历停止状态是节点没有左孩子并且没有右孩子
⑤ 从栈中弹出一个，打印
⑥ 重复以上过程，直到栈为空

**************************************************************/

template<typename T>
static void gotoHLVFL(std::stack<BinNodePosi(T)> &S)
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
		if(S.top() != x->parent)	//栈顶非父即右兄（是右兄，则遍历右兄这颗子数）
		{
			gotoHLVFL(S);
		}
			
		x = S.top();  S.pop();

		std::cout << x->data << " ";
	}
}
