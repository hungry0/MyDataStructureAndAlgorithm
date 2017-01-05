#pragma once

#include "listnode.h"

/*
	List的.h，包含一些排序算法
*/

template<typename T>
class List
{
private:
	int _size;

	ListNodePosi(T) header;
	ListNodePosi(T) trailer;

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

	Rank size() const { return _size; }

	bool isEmpty() const { return _size <= 0; }

	T& operator[](Rank r) const;

	ListNodePosi(T) first() const{ return header->succ; }
	ListNodePosi(T) last() const{ return trailer->pred; }

	bool valid(ListNodePosi(T) p)
	{
		return p && p != trailer && p != header;
	}

	ListNodePosi(T) find(T const& e) const //列表无序查找
	{
		return find(e, _size, trailer);
	}

	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;	//无序区间查找

	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;	//有序区间查找

	ListNodePosi(T) insertAsFirst(T const& e);
	ListNodePosi(T) insertAsLast(T const& e);

	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);	//	p->succ = e
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);	//	p->pred = e

	T remove(ListNodePosi(T) p);

	void reverse() const;

	int deduplicate();	//无序去重
	int uniquify();		//有序去重

	void printAll() const;
};

#include "list_initialize.h"