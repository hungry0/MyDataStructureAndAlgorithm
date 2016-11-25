#pragma once
#include "binnode.h"
#include <ostream>

/*
递归版中序遍历
*/

template <typename T> //元素类型、操作器
void travIn_R(BinNodePosi(T) x)
{ //二叉树中序遍历算法（递归版）
	if (!x) return;

	travIn_R(x->lc);

	std::cout << x->data<<" ";

	travIn_R(x->rc);
}
