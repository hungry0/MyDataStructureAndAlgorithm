#pragma once
#include "bintree.h"
#include "binnode_macro_basic.h"

/*
 * 参考《算法导论》，实现更高层次的封装插入操作
 */

template <typename T>
void BinTree<T>::insert(T const& e)
{
	if (_root == nullptr)
	{
		insertAsRoot(e);
		return;
	}
		
	BinNodePosi(T) currNode = _root;

	while (true)
	{
		while (e < currNode->data && currNode->parent)
		{
			currNode = currNode->lc;
		}

		if (!HasChild(*currNode))
			insertAsLC(currNode, e);
	}
}

