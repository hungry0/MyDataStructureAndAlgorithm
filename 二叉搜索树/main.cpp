#include <iostream>
#include "bst.h"

using namespace std;

void main()
{
	BST<int> B;

	B.insert(20);

	cout << B.remove(20);

	system("pause");
}