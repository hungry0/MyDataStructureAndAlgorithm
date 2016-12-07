#pragma once
#include "bintree.h"

template<typename T>
class BST : public BinTree<T>
{
protected:
	BinNodePosi(T) _hot;
//	BinNodePosi(T) connect34

	BinNodePosi(T) rotateAt(BinNodePosi(T) x);

public:
	virtual BinNodePosi(T)& search(const T& e);
	virtual BinNodePosi(T) insert(const T& e);
	virtual bool remove(const T& e);
};


#include "bst_insert.h"
#include "bst_remove.h"
#include "bst_search.h"
