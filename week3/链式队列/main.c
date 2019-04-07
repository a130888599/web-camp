#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LQueue.h"
int size;   //size为判断数据类型

int main()
{
    int *I; float *F; char *C; void *data;
	int flag = 1;
	LQueue Q;
	while (flag)
	{
		system("cls");
		welcome();
		int choose = bool_choose();
		system("cls");
		switch(choose)
		{
		    case 1: InitLQueue(&Q);wait();break;
		    case 2: DestoryLQueue(&Q);wait();break;
		    case 3: ClearLQueue(&Q);printf("清除成功!\n");wait();break;
		    case 4: printf("%d", LengthLQueue(&Q));wait();break;
		    case 5: enter_queue(&Q, data);wait();break;
		    case 6: DeLQueue(&Q);wait();break;
		    case 7: TraverseLQueue(&Q, LPrint);wait();break;
		    case 8: exit(0);break;
		    default: printf("输入错误\n");
		}
	}
}

void welcome()
{
	printf("------------------------------------------\n");
	printf("------------\n");
	printf("---请选择功能:\n");
	printf("---1.初始化队列\n");
	printf("---2.销毁队列\n");
	printf("---3.清空队列\n");
	printf("---4.队列长度\n");
	printf("---5.入队\n");
	printf("---6.出队\n");
	printf("---7.打印队列\n");
	printf("---8.退出\n");
	printf("------------\n");
	printf("------------------------------------------\n\n");
}

int bool_choose()
{
    printf("请选择功能：");
    int k;
    while(1)
    {
        int flag = 1;
        scanf("%d", &k);
        if(k < 0 || k > 8)
            flag = 0;

        if(!flag)
        {
            printf("输入错误，请重新输入\n");
            continue;
        }
        break;
    }
}

int getType()
{
    int type, flag = 0;
    while(!flag)
    {
        system("cls");
        int choose;
        printf("请选择数据类型：\n");
        printf("1.int\n2.float\n");
        scanf("%d", &choose);
        switch(choose)
        {
            case 1: type = 1; flag = 1; break;
            case 2: type = 2; flag = 1; break;
            default : printf("请重新输入\n");
        }
    }
    size = type;
    return type;
}

int getSize(int type)
{
    int type_size;

    if(type == 1)
        type_size = sizeof(int);
    if(type == 2)
        type_size = sizeof(float);

    return type_size;
}

void *getKey(int type)
{
    void *key = NULL;
    int *I = (int*)malloc(sizeof(int));
    float *F = (float*)malloc(sizeof(float));

    printf("请输入数据\n");
    switch (type)
    {
        case 1:    scanf("%d", I);
                        key = (void *)I; break;

        case 2:    scanf("%f", F);
                        key = (void *)F; break;
        default:    printf("ERROR\n");
    }
    return key;
}

void enter_queue(LQueue *Q, void *data)     //入队
{
    printf("请问要输入多少个数据：");
    int times = 0;
    scanf("%d", &times);

    while(times--)
    {
        printf("剩余%d个数据\n", times + 1);
        data = getKey(size);
        if(!EnLQueue(Q, data))
                                break;
    }
}

void wait()
{
    getchar();
    getchar();
}
