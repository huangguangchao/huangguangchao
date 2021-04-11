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
		printf("-------------------请选择您的操作编号：----------------------\n");
		scanf("%d", &options);
		switch (options)
		{
		case 1:
			system("cls");			//清空屏幕
			mainmenuface();
			InitAQueue(&Q);
			printf("初始化成功");		//初始化链表
			goto loop;
			break;

		case 2:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			DestoryAQueue(&Q);
			break;

		case 3:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			IsFullAQueue(&Q);
			break;

		case 4:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			IsEmptyAQueue(&Q);
			break;

		case 5:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			GetHeadAQueue(Q, Q->data);
			break;


		case 6:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			int count;
			count = LengthAQueue(&Q);
			printf("%d", count);
			break;

		case 7:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			Input (&Q);
			break;

		case 8:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			DeAQueue(&Q);
			break;

		case 9:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			ClearAQueue(&Q);
			break;

		case 10:
			system("cls");			//清空屏幕
			mainmenuface();
			if (Q->data[0] == NULL)
			{
				printf("队列目前未初始化！请先初始化队列！\n");
			}
			TraverseAQueue(&Q, APrint);
			break;
			}
	}
    return 0;
}
