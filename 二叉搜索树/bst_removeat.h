#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"
#include "binnode_succ.h"
#include <utility>

template<typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x,BinNodePosi(T)& hot)
{
	BinNodePosi(T) w = x;			//实际被摘除节点
		
	BinNodePosi(T) succ = nullptr;	//后继

	if(!HasLChild(*x))
	{
		succ = x = x->rc;

	}else if(!HasRChild(*x))
	{
		succ = x = x->lc;
	}else
	{
		w = w->succ();

		std::swap(x->data, w->data);

		BinNodePosi(T) u = w->parent;

		((u == x) ? u->rc : u->lc) = succ = w->rc;
	}

	hot = w->parent;

	if (succ)
		succ->parent = hot;

//	relase(w->data);
//	relase(w);

	delete w;
	
	return succ;
}
