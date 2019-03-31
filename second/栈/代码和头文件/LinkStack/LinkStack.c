#include"LinkStack.h"
#include<stdio.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = NULL;
	s->count = 0;
	printf("初始化成功\n\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if (!s->count)
	{
		printf("链表为空\n\n");
		return SUCCESS;
	}
	else {
		printf("链表不为空\n\n");
		return ERROR;
	}
}
Status getTopLStack(LinkStack *s, ElemType *e)  //得到栈顶元素
{
	if (!s)
		return ERROR;
	e = s->top->data;
}
Status clearLStack(LinkStack *s)   //清空栈
{
	if (!s->top)
		return ERROR;
	LinkStackPtr p;
	while (s->top)
	{
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count--;
	}
	printf("清空成功\n\n");
	return SUCCESS;

}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	if (!s) {
		error(0);
		return;
	}
	if (!s->top)
		clearLStack(s);
	free(s);
	s = (LinkStack *)malloc(sizeof(LinkStack));
	printf("销毁成功\n\n");
	return SUCCESS;
}
Status LStackLength(LinkStack *s, int *length)    //检测栈长度
{
	*length = s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack *s, ElemType data)   //入栈
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	printf("入栈成功\n\n");
	return SUCCESS;
}
Status popLStack(LinkStack *s, ElemType *data)   //出栈
{
	LinkStackPtr p;
	if (isEmptyLStack(s))
		return ERROR;
	*data = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	printf("出栈成功\n\n");
	return SUCCESS;
}