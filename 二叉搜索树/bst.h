#pragma once
#include "bintree.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:二叉搜索树

Analysis:

**************************************************************/

template<typename T>
class BST : public BinTree<T>
{
protected:
	BinNodePosi(T) _hot;

//	BinNodePosi(T) connect34
//	BinNodePosi(T) rotateAt(BinNodePosi(T) x);	//别的类型搜索树会用的api

public:
	virtual BinNodePosi(T)& search(const T& e);
	virtual BinNodePosi(T) insert(const T& e);
	virtual bool remove(const T& e);
};


#include "bst_insert.h"
#include "bst_remove.h"
#include "bst_search.h"
