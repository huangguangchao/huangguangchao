#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mainmenuface()
{
	 printf("���ѽ���˵�����ѡ�������\n");
    printf("                            ����ϵͳ                                    \n");
    printf("                                                                        \n");
    printf("           1.��ʼ������           5. �鿴��ͷԪ�� 			    \n");
    printf("                                                                        \n");
    printf("           2.���ٶ���              6.ȷ�����г���			    \n");
    printf("                                                                        \n");
    printf("           3.�������Ƿ�����              7.��Ӳ���                   \n");
    printf("                                                                        \n");
    printf("           4.�������Ƿ�Ϊ��              8.���Ӳ���                   \n");
    printf("                                                                        \n");
    printf("	   9.��ն���		  10.������������			     \n");
}
void Input (LQueue *Q){
	int amount;
	int t; //�û�ѡ��������������
	printf("������������������ͣ�\n");
	printf("1. int����   2. char�ַ���   3. double������\n");
	printf("������������ţ�");
	scanf("%d",&t) ;
	//�û��������봦��
	while(t<1 || t>3)
    {
     	printf("������Ӧ����1��2��3��ѡ��\n���������룺");
      	scanf("%d", &t);
    }
	printf("��Ҫ��Ӷ��ٸ����ݣ�");   //��ʽ�洢�ķ��Ͷ��鲻����
	scanf("%d",&amount);
	printf("\nע�⣺int��double���������Կո�ָ���char��������ո�Ҳ���ַ���\n");
    printf("������������ݣ�");
    switch(t)
    {
     	case 1:{  //int����
			int a;
			for(int i = 0;i < amount;i++){
			scanf("%d", &a);
			Q->length = sizeof(int);
			EnLQueue(Q, &a);
			}
		break;
		}
		case 2: {   //�ַ���
			char a ;
			getchar();			//������һ�������һ�λس�����Ϊ�س�Ҳ���ַ�
			for(int i = 0;i < amount;i++){
			scanf("%c", &a);
			Q->length = sizeof(char);
			EnLQueue(Q, &a);
			}
			break;
		}
        case 3:{   //������
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
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
	return (Q->front == Q->rear?TRUE: FALSE );

}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�û�ж�ͷ��\n");
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
		printf("�������ˣ�����������ˣ�\n");
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
    		printf("�����ǿյģ������˶ӣ�\n");
    		return FALSE;
    	}
        Q->front = (Q->front+1)%MAXQUEUE;
        return TRUE;

}

void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("�����Ѿ��ǿյ��ˣ�\n");
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



































