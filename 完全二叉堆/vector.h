#pragma once

typedef int Rank;

#define DEFAULT_CAPACITY  3

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

	Rank find(T const& e) const
	{
		return find(e, 0, _size);
	}

	Rank find(T const& e, Rank io, Rank hi) const;

	T& operator[](Rank i) const;

	Vector<T>& operator= (Vector<T> const&);

	T remove(Rank r);

	T remove(Rank lo, Rank hi);

	Rank insert(Rank r, T const& e);

	Rank insert(T const& e)
	{
		return insert(_size, e);
	}
};



