
   #include "LQueue.h"

int main()
{
	LQueue Q;
	Node *p = NULL;
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
			InitLQueue(&Q);
			printf("��ʼ���ɹ�");		//��ʼ������
			goto loop;
			break;

		case 2:
			system("cls");			//�����Ļ
			mainmenuface();
			DestoryLQueue(&Q);
			break;


		case 3:
			system("cls");			//�����Ļ
			mainmenuface();
			IsEmptyLQueue(&Q);
			break;

		case 4:
			system("cls");			//�����Ļ
			mainmenuface();
			void *e = NULL;
			GetHeadLQueue(&Q, e);
			break;


		case 5:
			system("cls");			//�����Ļ
			mainmenuface();
			int count;
			count = LengthLQueue(&Q);
			printf("%d", count);
			break;

		case 6:
			system("cls");			//�����Ļ
			mainmenuface();
			Input (&Q);
			break;

		case 7:
			system("cls");			//�����Ļ
			mainmenuface();
			DeLQueue(&Q);
			break;

		case 8:
			system("cls");			//�����Ļ
			mainmenuface();
			ClearLQueue(&Q);
			break;

		case 9:
			system("cls");			//�����Ļ
			mainmenuface();
			TraverseLQueue(&Q);
			break;
			}
	}
    return 0;
}
