#pragma once
#include "binnode.h"

/**************************************************************

Author：hungry
Date:2016.12.10
Description:二叉搜索树查找

Analysis:
① 二叉搜索树的左孩子比父节点小，右孩子比父节点大
② 递归调用searchIn查找值e
③ 如果当前节点为空或者找到该值（e），则返回该节点对象
④ 否则查找左子数或者右子数
⑤ hot一直是查找节点的父节点

**************************************************************/

template<typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T)& v,const T& e,BinNodePosi(T)& hot)
{
	if (!v || e == v->data)
		return v;

	hot = v;

	return searchIn((e < v->data) ? v->lc : v->rc, e, hot);
}
