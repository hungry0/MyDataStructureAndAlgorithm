#pragma once

#include "listnode.h"

template<typename T>
class List
{
private:
	int _size;

	ListNodePosi(T) header, trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);

	/*
	 * 一些排序算法
	 */

public:
	List() { init(); }
	List(List<T> const& L);
	List (List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	~List();

	Rank size() { return _size; }

	bool isEmpty() { return _size <= 0; }

	T& operator[](Rank r) const;

	ListNodePosi(T) first() const{ return header->succ; }
	ListNodePosi(T) last() const{ return trailer->pred; }

	bool valid(ListNodePosi(T) p)
	{
		return p && p != trailer && p != header;
	}

	int disordered() const;  //判断是否有序

	ListNodePosi(T) find(T const& e) const //列表无序查找
	{
		return find(e, _size, trailer);			//?
	}

	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;	//	区间查找

	ListNodePosi(T) insertAsFirst(T const& e);
	ListNodePosi(T) insertAsLast(T const& e);

	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);	//	p->succ = e
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);	//	p->pred = e

	T remove(ListNodePosi(T) p);
};
