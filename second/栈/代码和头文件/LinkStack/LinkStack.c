#include"LinkStack.h"
#include<stdio.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top = NULL;
	s->count = 0;
	printf("��ʼ���ɹ�\n\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if (!s->count)
	{
		printf("����Ϊ��\n\n");
		return SUCCESS;
	}
	else {
		printf("����Ϊ��\n\n");
		return ERROR;
	}
}
Status getTopLStack(LinkStack *s, ElemType *e)  //�õ�ջ��Ԫ��
{
	if (!s)
		return ERROR;
	e = s->top->data;
}
Status clearLStack(LinkStack *s)   //���ջ
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
	printf("��ճɹ�\n\n");
	return SUCCESS;

}
Status destroyLStack(LinkStack *s)   //����ջ
{
	if (!s) {
		error(0);
		return;
	}
	if (!s->top)
		clearLStack(s);
	free(s);
	s = (LinkStack *)malloc(sizeof(LinkStack));
	printf("���ٳɹ�\n\n");
	return SUCCESS;
}
Status LStackLength(LinkStack *s, int *length)    //���ջ����
{
	*length = s->count;
	return SUCCESS;
}
Status pushLStack(LinkStack *s, ElemType data)   //��ջ
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	printf("��ջ�ɹ�\n\n");
	return SUCCESS;
}
Status popLStack(LinkStack *s, ElemType *data)   //��ջ
{
	LinkStackPtr p;
	if (isEmptyLStack(s))
		return ERROR;
	*data = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	printf("��ջ�ɹ�\n\n");
	return SUCCESS;
}