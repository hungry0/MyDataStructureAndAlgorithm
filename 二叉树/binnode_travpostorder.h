#pragma once
#include "binnode.h"
#include <cstdlib>
#include "travPost_I.h"
#include "binnode_travpostorder_r.h"

template <typename T>
void BinNode<T>::travPost()
{
	switch (rand() % 1)
	{
	case 1:
		travPost_I(this);
		break;
	default:
		travPost_R(this);
		break;
	}
}

