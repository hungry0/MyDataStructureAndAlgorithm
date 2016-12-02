#pragma once
#include "binnode.h"
#include <iostream>

template<typename T>
void travPost_R(BinNodePosi(T) x)
{
	if (!x) return;

	travPost_R(x->lc);
	travPost_R(x->rc);

	std::cout << x->data << " ";
}
