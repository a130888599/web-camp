#include"qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//stack
typedef struct Node {
	int data;
	struct Node *next;
}Stack;

Stack *CreatStack()
{
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	if (!s)
		printf("error\n");
	s->next = 0;
	return s;
}

void pop(Stack *s)
{
	if (!s->next)
	{
		printf("入栈失败\n");
		return;
	}

	Stack *top = s->next;
	s->next = s->next->next;
	free(top);
}

void push(Stack *s, int n)
{
	Stack *top = (Stack*)malloc(sizeof(Stack));
	top->data = n;
	top->next = s->next;
	s->next = top;
}

void swap(int *l, int *r)
{
	int temp;
	temp = *l;
	*l = *r;
	*r = temp;
}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d	", a[i]);
}

void get(int x, int pos)
{
	int t = 1;
	for (int j = 0; j < pos - 1; j++)
		t *= 10;
	return (x / t) % 10;
}

int main()
{
	int flag = 0;
	while (1)
	{
		int size;
		printf("\n请输入数据范围：");
		scanf("%d", &size);
		int *a = (int*)malloc(sizeof(int)*size);
		int *w = (int*)malloc(sizeof(int)*size);
		memset(a, 0, sizeof(a) * size);
		memset(w, 0, sizeof(w) * size);
		int temp = size;
		int max, i = 0;
		printf("最大值为(32767以内)：");
		scanf("%d", &max);
		while (temp--)
		{
			int t = rand() % (max + 1);
			*(a + i++) = t;
		}

		printf("1.插入排序\n");
		printf("2.归并排序\n");
		printf("3.快速排序（递归）\n");
		printf("4.快速排序（迭代）\n");
		printf("5.计数排序\n");
		printf("6.基数排序\n");
		printf("7.颜色排序\n");
		printf("8.在一个无序序列中找到第K大/小的数\n");
		printf("9.清屏\n");
		printf("10.退出\n");
		printf("请选择排序方式:");
		int choose;
		scanf("%d", &choose);
		clock_t time_start = clock();
		switch (choose)
		{
		case 1:insertSort(a, size); break;
		case 2:MergeSort(a, 0, size - 1, w); break;
		case 3:QuickSort_Recursion(a, 0, size - 1); break;
		case 4:QuickSort(a, size - 1); break;
		case 5:CountSort(a, size - 1, max); break;
		case 6:RadixCountSort(a, size); break;
		case 7:ColorSort(a, size - 1); break;
		case 8:
		{
			printf("请输入k：");
			int k;
			scanf("%d", &k);
			printf("\n%d\n\n", search_k(a, size, k));
		} break;
		case 9:system("cls"); break;
		case 10:exit(0); break;
		default:
			break;
		}
		clock_t time_end = clock();
		double duration = (double)(time_end - time_start) / CLOCKS_PER_SEC;
		printf("所用时间:%lf\n", duration);
		//print(a, size);
		
		getchar();
		getchar();
		system("cls");
	}
	return 0;
}
