#include<stdio.h>
#include"SqStack.h"

//˳��ջ(���������)
Status initStack(SqStack *s, int sizes)  //��ʼ��ջ
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));
	if (!s->elem) {
		printf("����ռ�ʧ��!\n");
		return ERROR;
	}
	s->size = sizes;
	s->top = -1;
	printf("��ʼ���ɹ�\n");
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == -1)
	{
		printf("ջΪ��\n\n");
		return SUCCESS;
	}
	else
		return ERROR;
}
Status getTopStack(SqStack *s, ElemType *e)   //�õ�ջ��Ԫ��
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
Status clearStack(SqStack *s)   //���ջ
{
	s->top = -1;
	printf("���ջ�ɹ�\n");
	return SUCCESS;
}
Status destroyStack(SqStack *s)  //����ջ
{
	free(s->elem);
	return SUCCESS;
}
Status stackLength(SqStack *s, int *length)   //���ջ����
{
	if (isEmptyStack(s))
		return ERROR;
	int i = 0;
	while (i < s->top)
		i++;
	*length = i + 1;
	printf("ջ�ĳ���Ϊ:%d\n", *length);
	return SUCCESS;
}
Status pushStack(SqStack *s, ElemType data)  //��ջ
{
	if (s->top == s->size - 1) {
		error(2);
		return ERROR;
	}
	s->top++;
	s->elem[s->top]= data;
	return SUCCESS;

}
Status popStack(SqStack *s, ElemType *data)   //��ջ
{
	if (isEmptyStack(s))
		return ERROR;
	*data = s->elem[s->top];	//��Ҫɾ����ջ��Ԫ�ظ���data
	s->top--;
	return SUCCESS;
}

