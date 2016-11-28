#pragma once
#include "list.h"
#include "list_insert.h"

template <typename T>
void List<T>::copyNodes(ListNode<T>* p, int n) 
{
	init();

	while (n--)
	{
		//逐个插入最后边，相当于复制
		insertAsLast(p->data);
		p = p->succ;
	}
}

