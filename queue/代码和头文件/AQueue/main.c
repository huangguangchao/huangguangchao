#include <stdio.h>
#include <stdlib.h>
#include"AQueue.h"

int main()
{
	AQueue Q;
	mainmenuface();
	int options;
	while (1) {
	loop:
		printf("-------------------��ѡ�����Ĳ�����ţ�----------------------\n");
		scanf("%d", &options);
		switch (options)
		{
		case 1:
			system("cls");			//�����Ļ
			mainmenuface();
			InitAQueue(&Q);
			printf("��ʼ���ɹ�");		//��ʼ������
			goto loop;
			break;

		case 2:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			DestoryAQueue(&Q);
			break;

		case 3:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			IsFullAQueue(&Q);
			break;

		case 4:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			IsEmptyAQueue(&Q);
			break;

		case 5:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			GetHeadAQueue(Q, Q->data);
			break;


		case 6:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			int count;
			count = LengthAQueue(&Q);
			printf("%d", count);
			break;

		case 7:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			Input (&Q);
			break;

		case 8:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			DeAQueue(&Q);
			break;

		case 9:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			ClearAQueue(&Q);
			break;

		case 10:
			system("cls");			//�����Ļ
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
			}
			TraverseAQueue(&Q, APrint);
			break;
			}
	}
    return 0;
}
