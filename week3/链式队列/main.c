#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LQueue.h"
int size;   //sizeΪ�ж���������

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
		    case 3: ClearLQueue(&Q);printf("����ɹ�!\n");wait();break;
		    case 4: printf("%d", LengthLQueue(&Q));wait();break;
		    case 5: enter_queue(&Q, data);wait();break;
		    case 6: DeLQueue(&Q);wait();break;
		    case 7: TraverseLQueue(&Q, LPrint);wait();break;
		    case 8: exit(0);break;
		    default: printf("�������\n");
		}
	}
}

void welcome()
{
	printf("------------------------------------------\n");
	printf("------------\n");
	printf("---��ѡ����:\n");
	printf("---1.��ʼ������\n");
	printf("---2.���ٶ���\n");
	printf("---3.��ն���\n");
	printf("---4.���г���\n");
	printf("---5.���\n");
	printf("---6.����\n");
	printf("---7.��ӡ����\n");
	printf("---8.�˳�\n");
	printf("------------\n");
	printf("------------------------------------------\n\n");
}

int bool_choose()
{
    printf("��ѡ���ܣ�");
    int k;
    while(1)
    {
        int flag = 1;
        scanf("%d", &k);
        if(k < 0 || k > 8)
            flag = 0;

        if(!flag)
        {
            printf("�����������������\n");
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
        printf("��ѡ���������ͣ�\n");
        printf("1.int\n2.float\n");
        scanf("%d", &choose);
        switch(choose)
        {
            case 1: type = 1; flag = 1; break;
            case 2: type = 2; flag = 1; break;
            default : printf("����������\n");
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

    printf("����������\n");
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

void enter_queue(LQueue *Q, void *data)     //���
{
    printf("����Ҫ������ٸ����ݣ�");
    int times = 0;
    scanf("%d", &times);

    while(times--)
    {
        printf("ʣ��%d������\n", times + 1);
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
