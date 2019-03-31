#include<stdio.h>
#include"SqStack.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s, int sizes)  //初始化栈
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (!s->elem) {
		printf("申请空间失败!\n");
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	printf("初始化成功\n");
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if (s->top == -1)
	{
		printf("栈为空\n\n");
		return SUCCESS;
	}
	else
		return ERROR;
}
Status getTopStack(SqStack *s, ElemType *e)   //得到栈顶元素
{
	if (isEmptyStack(s))
	{
		error(1);
		return ERROR;
	}
	else
	{
		*e = s->elem[s->top];
		return SUCCESS;
	}
}
Status clearStack(SqStack *s)   //清空栈
{
	s->top = -1;
	printf("清空栈成功\n");
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //销毁栈
{
	free(s->elem);
	return SUCCESS;
}
Status stackLength(SqStack *s, int *length)   //检测栈长度
{
	if (isEmptyStack(s))
		return ERROR;
	int i = 0;
	while (i < s->top)
		i++;
	*length = i + 1;
	printf("栈的长度为:%d\n", *length);
	return SUCCESS;
}
Status pushStack(SqStack *s, ElemType data)  //入栈
{
	if (s->top == s->size - 1) {
		error(2);
		return ERROR;
	}
	s->top++;
	s->elem[s->top]= data;
	return SUCCESS;

}
Status popStack(SqStack *s, ElemType *data)   //出栈
{
	if (isEmptyStack(s))
		return ERROR;
	*data = s->elem[s->top];	//将要删除的栈顶元素赋给data
	s->top--;
	return SUCCESS;
}

