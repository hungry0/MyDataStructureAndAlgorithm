#include <iostream>

using namespace std;

/**************************************************************

Author：hungry
Date:2016.11.30
Description:归并排序

Analysis:
① 先进行分解，递归地将一个数组均分为一个或者元素，然后进行合并
② 第一种情况的合并是，两个只有一个元素的数组合并或者一个元素和两个元素合并
③ 当大于两个元素合并时，是两个已经排好序的数组进行合并，例如（4,5,6）和（3,7,9）
④ 以上举例合并时，先把3合并，然后4,5,6，最后发现第一个数组空了，则把第二个数组剩余的直接合并
⑤ 经过递归与合并，最后是一个原位置上排好序的数组

**************************************************************/

static void merge(int* lists, int lo, int mi, int hi)
{
	int* A = lists + lo;			//指向第lo个元素
	
	int lb = mi - lo;				//前半部分元素的个数（不包括mi）

	int* B = new int[lb];			

	for (size_t i = 0; i < lb; B[i] = A[i++]);	//将前半部分的元素拷贝到B数组中

	int lc = hi - mi;							//后半部分元素的个数（不包括hi）

	int* C = lists + mi;						//指向第mi个元素

	for (int i = 0, j = 0, k = 0; j < lb || k < lc;)	//将[lo,hi)的元素进行归并
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))//如果B最前面的数小于C最前面的数，则将B的值赋值给A。
			A[i++] = B[j++];						  //或者C中的数值已经全部参与归并，则将B中的剩余数直接赋值给A

		if ((k < lc) && (!(j < lb) || C[k] < B[j]))	//如果C最前面的数小于B最前面的数，则将C的值赋值给A
			A[i++] = C[k++];						//或者B中的数值已经全部参与归并，则将C中的剩余数直接赋值给A
	}

	delete[] B;					
}

static void _mergeSort(int* lists, int lo, int hi)
{
	if (hi - lo < 2)			//如果只剩下一个或者两个元素，停止二分
		return;

	int mi = (lo + hi) / 2;

	_mergeSort(lists, lo, mi);	//[lo,mi)
	_mergeSort(lists, mi, hi);	//[mi,hi)

	merge(lists, lo, mi, hi);	//开始归并
}

static void mergeSort(int* lists, int length)
{
	_mergeSort(lists,0,length);
}

void main()
{
	int lists[] = {4,345,35,232,53,1,20,33,18,90};
	
	mergeSort(lists, sizeof(lists) / sizeof(lists[0]));
	
	for (size_t i = 0; i < sizeof(lists) / sizeof(lists[0]); i++)
		cout << lists[i] << " ";
	
	system("pause");
}