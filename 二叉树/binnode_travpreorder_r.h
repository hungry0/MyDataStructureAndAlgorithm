#pragma once
#include "binnode.h"
#include <cstdio>

template<typename T>
void travPre_R(BinNodePosi(T) x)
{
	if (!x) return;

	std::cout << x->data<<" ";

	travPre_R(x->lc);
	travPre_R(x->rc);
}
