#pragma once

#include "binnode.h"
#include <algorithm>
#include "binnode_travinorder_r.h"
#include "binnode_travinorder_i1.h"
#include "binnode_travinorder_i2.h"
#include "binnode_travinorder_i3.h"
#include "binnode_travinorder_i4.h"

template <typename T>
void BinNode<T>::travIn()
{
	switch (3)
	{
	case 1:
		travIn_I1(this);
		break;
	case 2:
		travIn_I2(this);
		break;
	case 3:
		travIn_I3(this);
		break;
	case 4:
		travIn_I4(this);
		break;
	default:
		//µ›πÈ∞Ê÷––Ú±È¿˙
		travIn_R(this);
		break;
	}
}
