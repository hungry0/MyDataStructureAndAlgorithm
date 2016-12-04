#pragma once
#include "Graphmatrix.h"

template <typename Tv, typename Te>
std::stack<Tv>* Graph<Tv, Te>::tSort(int s)
{
	reset();

	std::stack<Tv>* S = new std::stack<Tv>();

	int clock = 0;

	int v = s;

	do
	{
		if (status(v) == UNDISCOVERED)
		{
			if (!TSort(v, clock, S))
			{
				while (!S->empty())
					S->pop();

				break;
			}
		}

	} while (s != (v = (++v % n)));

	return S;
}

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int& clock, std::stack<Tv>* S)
{
	dTime(v) = ++clock;
	status(v) = DISCOVERED;

	for (int u = firstNbr(v); u > -1; u = nextNbr(v, u))
	{
		switch (status(u))
		{
		case UNDISCOVERED:
			parent(u) = v;
			type(v, u) = TREE;
			if (!TSort(v, clock, S))
				return false;

			break;
		case DISCOVERED:
			type(v, u) = BACKWARD;
			return false;

		default:	//visited
			type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;

			break;
		}
	}

	status(v) = VISITED;
	S->push(vertex(v));

	return true;
}



