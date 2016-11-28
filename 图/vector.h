#pragma once

typedef int Rank;

#define DEFAULT_CAPACITY  10

template<typename T>
class Vector
{
protected:
	Rank _size;
	int _capacity;
	T* _elem;

	void copyFrom(T const* A, Rank io, Rank hi);
	void expand();
	void shrink();
	bool bubble(Rank io, Rank hi);
	void bubbleSort(Rank io,Rank hi);
	Rank max(Rank io, Rank hi);
	void selectionSort(Rank io, Rank hi);
	void merge(Rank io, Rank mi, Rank hi);
	void mergeSort(Rank io, Rank hi);
	Rank partition(Rank io,Rank hi);
	void quickSort(Rank io, Rank hi);
	void heapSort(Rank io, Rank hi);

public:
	Vector(int c = DEFAULT_CAPACITY,int s = 0,T v = 0)
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}

	Vector(T const* A,Rank n)
	{
		copyFrom(A, 0, n);
	}

	Vector(T const* A,Rank io,Rank hi)
	{
		copyFrom(A, io, hi);
	}

	Vector(Vector<T> const& V)
	{
		copyFrom(V._elem,0, V._size);
	}

	~Vector()
	{
		delete []_elem;
	}

	Rank size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return !_size;
	}

	int disordered() const;
	Rank find(T const& e) const
	{
		return find(e, 0, _size);
	}
	Rank find(T const& e, Rank io, Rank hi) const;

	Rank search(T const& e) const				//有序向量整体查找
	{
		return (_size <= 0) ? -1 : search(e, 0, _size);
	}
	Rank search(T const& e, Rank io, Rank hi);

	T& operator[](Rank i) const;

	Vector<T>& operator= (Vector<T> const&);

	T remove(Rank r);

	int remove(Rank lo, Rank hi);

	Rank insert(Rank r, T const& e);

	Rank insert(T const& e)
	{
		return insert(_size, e);
	}

	void sort(Rank lo, Rank hi);

	void sort()
	{
		sort(0, _size);
	}

	void unsort(Rank lo, Rank hi);

	void unsort()
	{
		unsort(0, _size);
	}

	int deduplicate();	//无序去重
	int uniquify();		//有序去重

	void printAll();
};
