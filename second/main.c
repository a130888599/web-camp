#include<stdio.h>
#include"LinkStack.h"

int main()
{
	welcome();
	int n;
	printf("请选择功能：");
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	while (scanf("%d", &n))
	{
		int flag = 1;
		switch (n) 
		{
		case 1:initLStack(s); break;
		case 2:clearLStack(s); break;
		case 3:destroyLStack(s); break;
		case 4:pow_4(s); break;
		case 5:pow_5(s); break;
		case 6:pow_6(s); break;
		case 7:system("cls"), welcome(); break;
		case 8:pow_8(s); break;
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
