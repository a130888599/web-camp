#include"LinkStack.h"
#include<stdio.h>

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
		printf("未初始化\n\n");
}

void pow_4(LinkStack *s)	//入栈
{
	
	int data, length;
	LStackLength(s, &length);
	printf("目前栈长度：%d\n",length);
	printf("请输出入栈的数据：");
	scanf("%d", &data);
	pushLStack(s, data);

	LStackLength(s, &length);
	printf("目前栈长度：%d\n", length);
}

void pow_5(LinkStack *s)	//出栈
{
	if (!s) {
		error(0);
		return;
	}
	ElemType data = 0;
	int flag = popLStack(s, &data);
	if(flag)
		printf("出栈的数据为：%d\n", data);
	
	int length = 0;
	LStackLength(s, &length);
	printf("目前栈长度为：%d\n", length);
}

void pow_6(LinkStack *s)
{
	if (!s) {
		error(0);
		return;
	}
	int length = 0;
	LStackLength(s, &length);
	printf("目前栈长度为：%d\n\n", length); 
}

void pow_8(LinkStack *s)	//打印栈
{
	if (!s) {
		error(0);
		return;
	}
	if (!s->top) {
		printf("栈为空\n");
		return;
	}
	LinkStackPtr p = s->top;
	while (p) {
		printf("%d  ", p->data);
		p = p->next;
	}
}