#include <iostream>

using namespace std;

/**************************************************************

Author：hungry
Date:2016.11.30
Description:插入排序

Analysis:
① 类似于扑克牌的整理牌的顺序，从第二个牌开始
② 从当前牌的前一个牌开始遍历，逆序找到不大于当前牌的位置，并将大于该牌的往后“挤”
③ 将该牌放置到该位置

**************************************************************/

static void insertSort(int* lists,int length)
{
	for (size_t i = 1; i < length; i++)
	{
		auto curr = lists[i];

		size_t j;

		for (j = i; j > 0 && lists[j - 1] > curr; j--)
			lists[j] = lists[j - 1];

		lists[j] = curr;
	}

	for (size_t i = 0; i < length; i++)
		cout << lists[i] << " ";
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	insertSort(lists, sizeof(lists) / sizeof(lists[0]));
	
	system("pause");
	
}