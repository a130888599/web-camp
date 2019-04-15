#include"qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int data;
	struct Node *next;
}Stack;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i], j;
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > temp)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = temp;
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
	if (begin >= end)
		return;
	int i = begin, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	for (int t = begin, b = 0; t <= end; t++)
		a[t] = temp[b++];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a, int begin, int end, int *temp)
{
	if (begin >= end)
		return;
	int mid = begin + end >> 1;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid + 1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if (begin > end)
		return;
	int i = begin - 1, j = end + 1, x = a[begin + end >> 1];
	while (i < j)
	{
		do j--; while (a[j] > x);
		do i++; while (a[i] < x);
		if (i <= j)
			swap(&a[i], &a[j]);
		else
		{
			QuickSort_Recursion(a, begin, j);
			QuickSort_Recursion(a, j + 1, end);
		}
	}
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a, int size)
{
	Stack *s = CreatStack();
	push(s, 0);
	push(s, size - 1);
	int left, right, mid;
	while (s->next)
	{
		right = s->next->data;
		pop(s);
		left = s->next->data;
		pop(s);
		int mid = Partition(a, left, right);
		if (mid - 1 > left)
		{
			push(s, left);
			push(s, mid - 1);
		}
		if (mid + 1 < right)
		{
			push(s, mid + 1);
			push(s, right);
		}
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
	int t = a[begin];
	int i = begin - 1, j = end + 1;
	while (i < j)
	{
		do j--;  while (i < j && a[j] >= t);
		do i++;  while (i < j && a[i] <= t);
		if (i < j) swap(a + i, a + j);
	}
	a[begin] = a[i];
	a[i] = t;
	return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size, int max)
{
	int *cnt = (int*)malloc(sizeof(int)*(max + 1));
	memset(cnt, 0, sizeof(cnt) * max);
	for (int i = 1; i < size; i++)
		cnt[a[i]]++;
	for(int i = 1, k = 0; i<= max; i++)
		while (cnt[i] != 0 && k < size)
		{
			a[k++] = i;
			cnt[i]--;
		}
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a, int size)
{
	int *cnt[10];    //分别为0~9的序列空间
	for (int i = 0; i < 10; i++)
	{
		cnt[i] = (int *)malloc(sizeof(int) * (size + 1));
		cnt[i][0] = 0;    //index为0处记录这组数据的个数
	}

	for (int pos = 1; pos <= 10; pos++)    //从个位开始到31位
	{
		for (int i = 0; i < size; i++)    //分配过程
		{
			int num = get(a[i], pos);
			int index = ++cnt[num][0];
			cnt[num][index] = a[i];
		}

		for (int i = 0, j = 0; i < 10; i++)    //收集
		{
			for (int k = 1; k <= cnt[i][0]; k++)
				a[j++] = cnt[i][k];
			cnt[i][0] = 0;    //复位
		}
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a, int size)
{
	int p1 = 0, p2 = size - 1;
	for (int cur = 0; cur <= p2; cur++)
	{
		if (a[cur] == 0)
			swap(&a[cur], &a[p1++]);
		else if (a[cur] == 2)
			swap(&a[cur--], &a[p2--]); 
	}
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int search_k(int *a, int size, int k)
{
	int begin = 0, end = size - 1;
	QuickSort_Recursion(a, begin, end);
	return a[k - 1];
}