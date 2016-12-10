#pragma once
#include "bst.h"
#include "bst_removeat.h"
#include "bintree.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:二叉搜索树的移除实现

Analysis:
① 首先查找该节点，查找不到，则不必删除，返回false
② 查找到了，调用removeAt方法
③ 减小节点数，调整树高

**************************************************************/

template <typename T>
bool BST<T>::remove(const T& e)
{
	BinNodePosi(T)& x = search(e);

	if (!x)
		return false;

	removeAt(x, _hot);

	--BinTree<T>::_size;

	BinTree<T>::updateHeightAbove(_hot);

	return true;
}

