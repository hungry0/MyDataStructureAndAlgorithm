#pragma once
#include "binnode.h"
#include <ostream>

/**************************************************************

Author：hungry
Date:2016.11.30
Description:递归中序遍历

Analysis:
① 递归左子树
② 打印当前节点
③ 递归右子树
④ 当前节点为空，则return

**************************************************************/

template <typename T>
void travIn_R(BinNodePosi(T) x)
{ 
	if (!x) return;

	travIn_R(x->lc);

	std::cout << x->data<<" ";

	travIn_R(x->rc);
}
