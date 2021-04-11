
   #include "LQueue.h"

int main()
{
	LQueue Q;
	Node *p = NULL;
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
			InitLQueue(&Q);
			printf("初始化成功");		//初始化链表
			goto loop;
			break;

		case 2:
			system("cls");			//清空屏幕
			mainmenuface();
			DestoryLQueue(&Q);
			break;


		case 3:
			system("cls");			//清空屏幕
			mainmenuface();
			IsEmptyLQueue(&Q);
			break;

		case 4:
			system("cls");			//清空屏幕
			mainmenuface();
			void *e = NULL;
			GetHeadLQueue(&Q, e);
			break;


		case 5:
			system("cls");			//清空屏幕
			mainmenuface();
			int count;
			count = LengthLQueue(&Q);
			printf("%d", count);
			break;

		case 6:
			system("cls");			//清空屏幕
			mainmenuface();
			Input (&Q);
			break;

		case 7:
			system("cls");			//清空屏幕
			mainmenuface();
			DeLQueue(&Q);
			break;

		case 8:
			system("cls");			//清空屏幕
			mainmenuface();
			ClearLQueue(&Q);
			break;

		case 9:
			system("cls");			//清空屏幕
			mainmenuface();
			TraverseLQueue(&Q);
			break;
			}
	}
    return 0;
}
