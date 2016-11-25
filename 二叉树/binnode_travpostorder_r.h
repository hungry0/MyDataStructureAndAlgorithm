#pragma once
#include "binnode.h"

template<typename T>
void travPost_R(BinNodePosi(T) x)
{
	if (!x) return;

	travPost_R(x->lc);
	travPost_R(x->rc);

	cout << x->data << " ";
}
