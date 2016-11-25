#pragma once
#include "../../¶ş²æÊ÷/¶ş²æÊ÷/bintree.h"
#include "../../¶ş²æÊ÷/¶ş²æÊ÷/binnode_macro_basic.h"

template<typename T>
static int removeAt(BinNodePosi(T) x)
{
	if (!x) return 0;

	int n = 1 + removeAt(x->lc) + removeAt(x->rc);

	//	release(x->data);
	//	release(x);

	return n;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)	//É¾³ı×ÓÊ÷
{
	FromParentTo( *x ) = nullptr;
	this->updateHeightAbove(x->parent);

	int n = removeAt(x);

	_size -= n;

	return n;

}