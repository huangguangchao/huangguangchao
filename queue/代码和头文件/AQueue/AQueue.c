#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mainmenuface()
{
	 printf("您已进入菜单，请选择操作！\n");
    printf("                            功能系统                                    \n");
    printf("                                                                        \n");
    printf("           1.初始化队列           5. 查看队头元素 			    \n");
    printf("                                                                        \n");
    printf("           2.销毁队列              6.确定队列长度			    \n");
    printf("                                                                        \n");
    printf("           3.检查队列是否已满              7.入队操作                   \n");
    printf("                                                                        \n");
    printf("           4.检查队列是否为空              8.出队操作                   \n");
    printf("                                                                        \n");
    printf("	   9.清空队列		  10.遍历函数操作			     \n");
}
void Input (LQueue *Q){
	int amount;
	int t; //用户选择的入队数据类型
	printf("您想入队哪种数据类型？\n");
	printf("1. int整型   2. char字符型   3. double浮点型\n");
	printf("请输入数字序号：");
	scanf("%d",&t) ;
	//用户错误输入处理
	while(t<1 || t>3)
    {
     	printf("错误：您应输入1，2或3以选择！\n请重新输入：");
      	scanf("%d", &t);
    }
	printf("您要入队多少个数据：");   //链式存储的泛型队伍不判满
	scanf("%d",&amount);
	printf("\n注意：int和double类型输入以空格分隔，char类型输入空格也是字符。\n");
    printf("请输入入队数据：");
    switch(t)
    {
     	case 1:{  //int整形
			int a;
			for(int i = 0;i < amount;i++){
			scanf("%d", &a);
			Q->length = sizeof(int);
			EnLQueue(Q, &a);
			}
		break;
		}
		case 2: {   //字符型
			char a ;
			getchar();			//吸收上一步多出的一次回车，因为回车也是字符
			for(int i = 0;i < amount;i++){
			scanf("%c", &a);
			Q->length = sizeof(char);
			EnLQueue(Q, &a);
			}
			break;
		}
        case 3:{   //浮点型
			double a ;
			for(int i = 0;i < amount;i++){
			scanf("%lf", &a);
			Q->length = sizeof(double);
			EnLQueue(Q, &a);
			}
			break;
		}
	}
}
void InitAQueue(AQueue *Q)
{
		int i;
		for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void *)malloc(Q->length);
		Q->front = 0;
		Q->rear = 0;
		return;
}

void DestoryAQueue(AQueue *Q)
{

	int i;
	for( i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}

Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;
    if(Q->front == (Q->rear + 1) % MAXQUEUE)
	return TRUE;
    else
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{

	if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return (Q->front == Q->rear?TRUE: FALSE );

}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],Q->length);
	APrint(Q->data[Q->front],sizeof (Q->length));
    return TRUE;
}


int LengthAQueue(AQueue *Q)
{
	int count;
	count = (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
	return count;
}

Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列满了！不能再入队了！\n");
		return FALSE;
	}
		Q->rear = (Q->rear+1) % MAXQUEUE;
		memcpy(Q->data[Q->front], data, Q->length);
		return TRUE;

}




Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
    	{
    		printf("队列是空的！出不了队！\n");
    		return FALSE;
    	}
        Q->front = (Q->front+1)%MAXQUEUE;
        return TRUE;

}

void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
	return;
	}
    Q->front = Q->rear = 0;
	return;
}

void APrint(void *q,int size)
 {
 	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);


 }

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int size)) {
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		foo(Q->data[i], Q->length);
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;

}



































