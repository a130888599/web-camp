#include"SqStack.h"
#include<stdio.h>
#include<stdlib.h>

void welcome()
{
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t-----1.��ʼ��                                                  ------\n");
	printf("\t\t-----2.���ջ                                                  ------\n");
	printf("\t\t-----3.����ջ                                                  ------\n");
	printf("\t\t-----4.��ջ                                                    ------\n");
	printf("\t\t-----5.��ջ                                                    ------\n");
	printf("\t\t-----6.ջ����                                                  ------\n");
	printf("\t\t-----7.����                                                    ------\n");
	printf("\t\t-----8.��ӡ                                                    ------\n");
	printf("\t\t-----0.���أ��˳���                                            ------\n");
	printf("\t\t---------------------------------------------------------------------\n");
	printf("\t\t---------------------------------------------------------------------\n\n");
}

void error(int i)
{
	if (i == 0)
		printf("δ��ʼ��ջ\n");
	if (i == 1)
		printf("ջΪ��\n");
	if (i == 2)
		printf("ջΪ��\n");
}

void pow_1(SqStack *s)
{
	int size;
	printf("���������鳤�ȣ�");
	scanf("%d", &size);
	initStack(s, size);
}

void pow_4(SqStack *s)
{
	int data, length = 0;
	stackLength(s, &length);
	printf("Ŀǰջ���ȣ�%d\n", length);
	printf("�������ջ�����ݣ�");
	scanf("%d", &data);
	pushStack(s, data);

	stackLength(s, &length);
	printf("Ŀǰջ���ȣ�%d\n", length);
}

void pow_5(SqStack *s)
{
	ElemType data = 0;
	int flag = popStack(s, &data);
	if (flag)
		printf("��ջ������Ϊ��%d\n", data);

	int length = 0;
	stackLength(s, &length);
	printf("Ŀǰջ����Ϊ��%d\n", length);
}

void pow_6(SqStack *s)
{
	if (!s) {
		error(0);
		return;
	}
	int length = 0;
	stackLength(s, &length);
	printf("Ŀǰջ����Ϊ��%d\n\n", length);
}