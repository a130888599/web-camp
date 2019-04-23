#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

typedef struct Node {
	BiTree date;
	struct Node *next;
} Queue;

typedef struct SNode {
	BiTree date;
	struct SNode *next;
} Stack;

int flag = 0;	//�ж������Ƿ����

Status Traverse(TElemType a);	//��ӡ�ַ�

void error(void)	//��װ���Խ�flag����Tree.c��
{
	flag = 1;
}

int main()
{
	char a[100]; 
	double result;
	while (1)
	{
		printf("\n������ǰ׺���ʽ(��q�˳�):");
		gets(a);
		if (a[0] == 'q')
			break;
		BiTree T;
		InitBiTree(&T);
		reset();
		CreateBiTree(&T, a);
		result = Value(T);
		if (flag)
		{
			printf("�������\n");
			return;
		}
		else
			printf("����� %.2f\n\n", result);
		printf("����\n");
		PreOrderTraverse(T, Traverse);
		printf("\n����\n");
		InOrderTraverse(T, Traverse);
		printf("\n����\n");
		PostOrderTraverse(T, Traverse);
		printf("\n����\n");
		LevelOrderTraverse(T, Traverse);
		printf("\n�Զ���\n");
		InOrderTraverse_cycle(T, Traverse);
		DestroyBiTree(T);
	}
	return 0;
}

int isNum(char c)	//�ж��Ƿ�Ϊ����
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 0;
	return 1;
}

Status Traverse(TElemType a)
{
	printf("%c ", a);
	return SUCCESS;
}

double cal(double a, double b, char c)	//������
{
	double result = 0;
	switch (c)
	{
	case '+': result = a + b; break;
	case '-': result = a - b; break;
	case '*': result = a * b; break;
	case '/': result = a / b; break;
	default: error();
	}

	return result;
}

int make_num(char a)	//���ַ�ת�������
{
	int result = 0;
	switch (a)
	{
	case '9': result++;
	case '8': result++;
	case '7': result++;
	case '6': result++;
	case '5': result++;
	case '4': result++;
	case '3': result++;
	case '2': result++;
	case '1': result++;
	case '0': break;
	default: error();
	}
	return result;
}

int IsEmpty(Queue *Q)	//�ж϶����Ƿ�Ϊ��
{
	return Q->next == 0;
}

BiTree DeQueue(Queue *Q)
{
	Queue *Top;
	BiTree T;

	if (IsEmpty(Q))
		printf("\n����Ϊ��\n");
	else
	{
		Top = Q->next;
		T = Q->next->date;
		Q->next = Q->next->next;
		free(Top);
	}

	return T;
}

void EnQueue(Queue *Q, BiTree data)
{
	Queue *Rear = (Queue *)malloc(sizeof(Queue));

	if (Rear == 0)
		printf("\n���г���\n");
	else
	{
		while (Q->next)
			Q = Q->next;
		Rear->next = 0;
		Rear->date = data;
		Q->next = Rear;
	}

	return;
}

int StackIsEmpty(Stack *S)
{
	return S->next == 0;
}

void Pop(Stack *S)
{
	if (StackIsEmpty(S))
	{
		puts("���Ӵ���");
		return;
	}

	Stack *Top;
	Top = S->next;
	S->next = S->next->next;
	free(Top);
}

void Push(Stack *S, BiTree data)
{
	Stack *Top = (Stack *)malloc(sizeof(Stack));
	Top->date = data;
	Top->next = S->next;
	S->next = Top;
}

BiTree Top(Stack *S)
{
	if (StackIsEmpty(S))
	{
		puts("���Ӵ���");
		return 0;
	}

	return S->next->date;
}

Status InOrderTraverse_cycle(BiTree T, Status(*visit)(TElemType e))
{
	Stack S;
	S.next = 0;
	while (T || !StackIsEmpty(&S))
	{
		while (T)
		{
			Push(&S, T);
			T = T->lchild;
		}
		while (!StackIsEmpty(&S))
		{
			T = Top(&S);
			visit(T->data);
			Pop(&S);
			T = T->rchild;
		}
	}
}