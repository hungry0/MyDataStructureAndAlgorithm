#include <iostream>
#include "bintree.h"
#include "bintree_insert.h"
#include "binnode_travinorder.h"
#include "bintree_remove.h"
#include "binnode_insert.h"
#include "binnode_succ.h"
#include "binnode_travlevel.h"

using namespace std;

int main(int argc,char* argv[])
{
	BinTree<int>* bin_tree = new BinTree<int>();

	bin_tree->insertAsRoot(20);

	bin_tree->insertAsLC(bin_tree->root(), 10);

	bin_tree->insertAsRC(bin_tree->root(), 30);

//	bin_tree->travIn();

	bin_tree->travLevel();

	system("pause");

	return 0;
}
