#pragma once

#include "binnode.h"


template <typename T>
class BinTree
{
protected:
	int _size;

	BinNodePosi(T) _root;

	int updateHeight(BinNodePosi(T) x);

	void updateHeightAbove(BinNodePosi(T) x); //更新此节点及祖先的高度

public:
	BinTree() : _size(0), _root(nullptr)
	{
	}

	~BinTree()
	{
		//		if (_size > 0)
		//			remove(_root);
	}

	int size() const { return _size; }

	bool isEmpty() { return !_root; }

	BinNodePosi(T) root() const { return _root; }

	BinNodePosi(T) insertAsRoot(T const& e);

	void insert(T const& e);

	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);

	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* & S);
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* & S);

	int remove(BinNodePosi(T) x);
//
//	BinTree<T>* secede(BinNodePosi(T) x); //将子树拆离开
//
	void travLevel() { if (_root) _root->travLevel(); }
//
//	template <typename VST>
//	void travPre(VST& visit) { if (_root) _root->travPre(visit); }
//
	void travIn() { if (_root) _root->travIn(); }
//
//	template <typename VST>
//	void TravPost(VST& visit) { if (_root) _root->travPost(visit); }

	//	bool operator< (BinTree<T> const& t){reutrn _root && t->_root && lt}
	//	bool operator==()
};
