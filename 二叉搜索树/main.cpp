#include <iostream>
#include "bst.h"
#include "binnode_travinorder.h"

using namespace std;

void main()
{
	BST<int> B;

	for (int i = 0; i < 10; i++)
	{
		B.insert(i + rand() % 10);
	}
	
	B.travIn();

	system("pause");
}