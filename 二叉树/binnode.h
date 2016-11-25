#pragma once

#define BinNodePosi(T) BinNode<T>*

#define stature(p) ((p) ? (p)->height : -1)

typedef enum
{
	RB_RED,
	RB_BLACK
} RBColor;


template <typename T>
struct BinNode
{
public:
	T data;

	BinNodePosi(T) parent;
	BinNodePosi(T) lc;
	BinNodePosi(T) rc;

	int height;

	int npl;

	RBColor color;

	BinNode() :
		parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED)
	{
	}

	BinNode(T e, BinNodePosi(T) p = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr, int h = 0, int npl = 1, RBColor c = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(npl), color(c)
	{
	}

//	int size();

	BinNodePosi(T) insertAsLC(T const&);
	BinNodePosi(T) insertAsRC(T const&);

	BinNodePosi(T) succ();

	void travLevel();
	void travPre();
	void travIn();
	void travPost();

	bool operator<(BinNode const& bn)
	{
		return data < bn.data;
	}

	bool operator==(BinNode const& bn)
	{
		return data == bn.data;
	}


//	BinNodePosi(T) zig(); //顺时针旋转
//	BinNodePosi(T) zag(); //逆时针旋转
};
