#pragma once
#include "binnode.h"
#include <stack>

 /**************************************************************

 Author：hungry
 Date:2016.11.30
 Description:非递归中序遍历（一）

 Analysis:
 ① 沿着当前节点将左孩子都放入到stack中
 ② 弹出一个打印
 ③ 然后转向该节点的右孩子
 ④ 重复前面的过程

 **************************************************************/

template<typename T>
static void GoALongLeftBranch(BinNodePosi(T) x,std::stack<BinNodePosi(T)> &S)
{
	while(x)
	{
		S.push(x);
		x = x->lc;
	}
}

template<typename T>
void travIn_I1(BinNodePosi(T) x)
{
	std::stack<BinNodePosi(T)> S;
	
	while(true)
	{
		GoALongLeftBranch(x, S);

		if(S.empty())
			break;

		x = S.top(); S.pop();

		std::cout << x->data<<" ";

		x = x->rc;
	}
}
