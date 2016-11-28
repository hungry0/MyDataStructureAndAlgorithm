#pragma once
#include "listnode.h"

template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this);

	//将前节点的后续节点指向新建节点
	pred->succ = x;

	//将当前节点的前驱节点指向新建节点
	this->pred = x;

	return x;
}

