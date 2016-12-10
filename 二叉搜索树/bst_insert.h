#pragma once
#include "binnode.h"
#include "bst.h"
#include "bintree.h"
#include "binree_updateheight.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:搜索树的插入实现

Analysis:
① 插入一个数值e，先调用搜索方法，查看是否已经有此值
② 如果已经含有此值，则直接返回该节点
③ 否则返回的是该节点的位置，将该节点的值设置为e（因为是指针的引用，所以改指针的指向即可修改该节点的值）
④ 将节点数自加一，并整理树高

**************************************************************/


template <typename T>
BinNode<T>* BST<T>::insert(const T& e)
{
	BinNodePosi(T)& x = search(e);

	if (x)
		return x;

	x = new BinNode<T>(e, _hot);

	++BinTree<T>::_size;

	BinTree<T>::updateHeightAbove(x);

	return x;
}

