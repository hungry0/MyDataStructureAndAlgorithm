#pragma once
#include "bintree.h"

/**************************************************************

Author��hungry
Date:2016.12.10
Description:����������

Analysis:���������������������а���һЩ���������õ��Ľӿ�

**************************************************************/

template<typename T>
class BST : public BinTree<T>
{
protected:
	BinNodePosi(T) _hot;

//	BinNodePosi(T) connect34
//	BinNodePosi(T) rotateAt(BinNodePosi(T) x);	//����������������õ�api

public:
	virtual BinNodePosi(T)& search(const T& e);
	virtual BinNodePosi(T) insert(const T& e);
	virtual bool remove(const T& e);
};


#include "bst_insert.h"
#include "bst_remove.h"
#include "bst_search.h"
