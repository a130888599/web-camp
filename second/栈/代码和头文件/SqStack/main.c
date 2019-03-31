#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"

int main()
{
	welcome();
	int n;
	printf("请选择功能：");
	SqStack *s = (SqStack*)malloc(sizeof(SqStack));
	while (scanf("%d", &n))
	{
		int flag = 1;
		switch (n)
		{
		case 1:pow_1(s); break;
		case 2:clearStack(s); break;
		case 3:destroyStack(s); break;
		case 4:pow_4(s); break;
		case 5:pow_5(s); break;
		case 6:pow_6(s); break;
		case 7:system("cls"), welcome(); break;
		//case 8:pow_8(s); break;
		case 0:flag = 0; break;
		default:
			break;
		}
		if (!flag)
			break;
		printf("请选择功能：");
	}
	return 0;
}