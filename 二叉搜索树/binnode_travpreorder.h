#pragma once
#include "binnode.h"
#include <cstdlib>
#include "binnode_travpreorder_i1.h"
#include "binnode_travpreorder_i2.h"
#include "binnode_travpreorder_r.h"

template <typename T>
void BinNode<T>::travPre()
{
	switch (0)
	{
	case 0:
		travPre_I1(this);
		break;
	case 1:
		travPre_I2(this);
		break;
	default:
		travPre_R(this);
		break;
	}
}

