#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

void visit(int a);
int main()
{
	welcome();		//功能界面
	int n;
	LinkedList L = (LinkedList)malloc(sizeof(LNode));
	L->next = NULL;
	printf("请选择功能：\n");
	while (scanf("%d", &n))
	{
		int flag = 1;
		switch (n)
		{
		case 0:flag = 0; break;
		case 1:InitList(&L); break;
		case 2:DestroyList(&L); break;
		case 3:pow_3(&L); break;
		case 4:pow_4(&L); break;
		case 5:TraverseList(L, visit); break;
		case 6:pow_6(&L); break;
		case 7:ReverseList(&L); break;
		case 8:IsLoopList(L); break;
		case 9:ReverseEvenList(&L); break;
		case 10:FindMidNode(&L); break;
		case 11:system("cls"), welcome();break;
		default:
			break;
		}
		if (!flag)
			break;
		printf("请选择功能：\n");
	}
	
	return 0;
}

