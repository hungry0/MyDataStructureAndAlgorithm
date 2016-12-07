#pragma once
#include "binnode.h"
#include "bst.h"
#include "bintree.h"
#include "binree_updateheight.h"

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

