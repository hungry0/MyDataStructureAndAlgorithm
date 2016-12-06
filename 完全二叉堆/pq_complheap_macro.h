#pragma once

#define InHeap(n,i)				(((-1) < n) && ((i) < (n)))
#define Parent(i)				((i - 1) >> 1)
#define LastInternal(n)			Parent(n-1)			//最后一个内部节点（末节点的父亲）
#define LChild(i)				(1 + (i) << 1)
#define RChild(i)				(2 + (i) << 1)
#define ParentValid(i)			(i > 0)				//PQ[i]是否有父亲
#define LChildValid(n,i)		InHeap(n,LChild(i))
#define RChildValid(n,i)		InHeap(n,RChild(i))
#define Bigger(PQ,i,j)			(lt(PQ[i],PQ[j]) ? j : i)
#define ProperParent(PQ,n,i)	(RChildValid(n,i) ? Bigger(PQ,Bigger((PQ,i,LChild(i)), RChild(i)) : \
								(LChildValid(n,i) ? Bigger(PQ,i,LChild(i)) : i \
								) \
								)

