#pragma once
#include "binnode.h"
#include <cstdlib>
#include "binnode_travpostorder_r.h"
#include "binnode_travpostorder_i.h"

template <typename T>
void BinNode<T>::travPost()
{
	switch (rand() % 2)
	{
	case 1:
		travPost_I(this);
		break;
	default:
		travPost_R(this);
		break;
	}
}

