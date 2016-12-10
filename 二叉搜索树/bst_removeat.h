#pragma once
#include "binnode.h"
#include "binnode_macro_basic.h"
#include "binnode_succ.h"
#include <utility>

/**************************************************************

Author：hungry
Date:2016.12.10
Description:二叉搜索树的移除节点方法

Analysis:
① 

**************************************************************/

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

	delete w;
	
	return succ;
}
