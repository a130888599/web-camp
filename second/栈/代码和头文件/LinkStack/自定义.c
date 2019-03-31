#include"LinkStack.h"
#include<stdio.h>

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
		printf("δ��ʼ��\n\n");
}

void pow_4(LinkStack *s)	//��ջ
{
	
	int data, length;
	LStackLength(s, &length);
	printf("Ŀǰջ���ȣ�%d\n",length);
	printf("�������ջ�����ݣ�");
	scanf("%d", &data);
	pushLStack(s, data);

	LStackLength(s, &length);
	printf("Ŀǰջ���ȣ�%d\n", length);
}

void pow_5(LinkStack *s)	//��ջ
{
	if (!s) {
		error(0);
		return;
	}
	ElemType data = 0;
	int flag = popLStack(s, &data);
	if(flag)
		printf("��ջ������Ϊ��%d\n", data);
	
	int length = 0;
	LStackLength(s, &length);
	printf("Ŀǰջ����Ϊ��%d\n", length);
}

void pow_6(LinkStack *s)
{
	if (!s) {
		error(0);
		return;
	}
	int length = 0;
	LStackLength(s, &length);
	printf("Ŀǰջ����Ϊ��%d\n\n", length); 
}

void pow_8(LinkStack *s)	//��ӡջ
{
	if (!s) {
		error(0);
		return;
	}
	if (!s->top) {
		printf("ջΪ��\n");
		return;
	}
	LinkStackPtr p = s->top;
	while (p) {
		printf("%d  ", p->data);
		p = p->next;
	}
}