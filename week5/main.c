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

int flag = 0;	//判断输入是否错误

Status Traverse(TElemType a);	//打印字符

void error(void)	//封装可以将flag传到Tree.c中
{
	flag = 1;
}

int main()
{
	char a[100]; 
	double result;
	while (1)
	{
		printf("\n请输入前缀表达式(按q退出):");
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
			printf("结果错误\n");
			return;
		}
		else
			printf("结果： %.2f\n\n", result);
		printf("先序\n");
		PreOrderTraverse(T, Traverse);
		printf("\n中序\n");
		InOrderTraverse(T, Traverse);
		printf("\n后序\n");
		PostOrderTraverse(T, Traverse);
		printf("\n层序\n");
		LevelOrderTraverse(T, Traverse);
		printf("\n自定义\n");
		InOrderTraverse_cycle(T, Traverse);
		DestroyBiTree(T);
	}
	return 0;
}

int isNum(char c)	//判断是否为数字
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

double cal(double a, double b, char c)	//计算结果
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

int make_num(char a)	//将字符转变成数字
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

int IsEmpty(Queue *Q)	//判断队列是否为空
{
	return Q->next == 0;
}

BiTree DeQueue(Queue *Q)
{
	Queue *Top;
	BiTree T;

	if (IsEmpty(Q))
		printf("\n对列为空\n");
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
		printf("\n队列出错\n");
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
		puts("出队错误");
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
		puts("出队错误");
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