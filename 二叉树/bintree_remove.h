#pragma once
#include "bintree.h"
#include "binnode_macro_basic.h"

template<typename T>
static int removeAt(BinNodePosi(T) x)
{
	if (!x) return 0;

	int n = 1 + removeAt(x->lc) + removeAt(x->rc);

	//	release(x->data);
	//	release(x);

	delete x;

	return n;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)	//É¾³ý×ÓÊ÷
{
	FromParentTo( *x ) = nullptr;
	this->updateHeightAbove(x->parent);

	int n = removeAt(x);

	_size -= n;

	return n;
}