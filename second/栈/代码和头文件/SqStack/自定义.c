#include"SqStack.h"
#include<stdio.h>
#include<stdlib.h>

void welcome()
{
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t-----1.初始化                                                  ------\n");
	printf("\t\t-----2.清空栈                                                  ------\n");
	printf("\t\t-----3.销毁栈                                                  ------\n");
	printf("\t\t-----4.入栈                                                    ------\n");
	printf("\t\t-----5.出栈                                                    ------\n");
	printf("\t\t-----6.栈长度                                                  ------\n");
	printf("\t\t-----7.清屏                                                    ------\n");
	printf("\t\t-----8.打印                                                    ------\n");
	printf("\t\t-----0.返回（退出）                                            ------\n");
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t---------------------------------------------------------------------\n\n");
}

void error(int i)
{
	if (i == 0)
		printf("未初始化栈\n");
	if (i == 1)
		printf("栈为空\n");
	if (i == 2)
		printf("栈为满\n");
}

void pow_1(SqStack *s)
{
	int size;
	printf("请输入数组长度：");
	scanf("%d", &size);
	initStack(s, size);
}

void pow_4(SqStack *s)
{
	int data, length = 0;
	stackLength(s, &length);
	printf("目前栈长度：%d\n", length);
	printf("请输出入栈的数据：");
	scanf("%d", &data);
	pushStack(s, data);

	stackLength(s, &length);
	printf("目前栈长度：%d\n", length);
}

void pow_5(SqStack *s)
{
	ElemType data = 0;
	int flag = popStack(s, &data);
	if (flag)
		printf("出栈的数据为：%d\n", data);

	int length = 0;
	stackLength(s, &length);
	printf("目前栈长度为：%d\n", length);
}

void pow_6(SqStack *s)
{
	if (!s) {
		error(0);
		return;
	}
	int length = 0;
	stackLength(s, &length);
	printf("目前栈长度为：%d\n\n", length);
}