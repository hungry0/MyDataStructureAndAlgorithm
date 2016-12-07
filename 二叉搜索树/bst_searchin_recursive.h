#pragma once
#include "binnode.h"

template<typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T)& v,const T& e,BinNodePosi(T)& hot)
{
	if (!v || e == v->data)
		return v;

	hot = v;

	return searchIn((e < v->data) ? v->lc : v->rc, e, hot);
}
