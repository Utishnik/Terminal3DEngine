#include <stdio.h>
#include <stdlib.h>
#include "Tools.h"
#include <windows.h>
//todo : https://www.cyberforum.ru/cpp-beginners/thread2709026.html решить эту проблему добавить возможность разносить шаблоны на основе tpp(но это не точно)


int main()
{
	Rect_Array2d<float> test;
	Rect_Array3d<float> test1;
	test1.height = 3;
	test1.widht = 4;
	test1.depth = 5;

	test.height = 3;
	test.widht = 4;

	test.map = _Rect_Malloc_2d<float>(test.height, test.widht);
	test1.map = _Rect_Malloc_3d<float>(test1.height, test1.widht, test1.depth);

    //_Rect_Free_2d(test);
    //_Rect_Free_3d(test1);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			test.map[i][j] = (float)(i);
			printf("%g ", test.map[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");

	for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<4;k++)
            {
                test1.map[i][j][k]=(float)i;
                printf("%g ",test1.map[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    Sleep(1000);
    system("cls");

    printf("Code %lu\n",_Rect_ResizeCol3d(100,&test1,true));

	for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<25;k++)
            {
                test1.map[i][j][k]=(float)i;
                printf("%g ",test1.map[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }


	_Rect_Free_2d(test);
	_Rect_Free_3d(test1);

	/*
	int* gg = (int*)malloc(sizeof(int) * 10);
	free(gg);
	for (int i = 0; i < 10; i++)
	{
		gg[i] = i;
		printf("%d\n", gg[i]);
	}
	*Я хз че за херня я но вочему то даже тут не всегда выдает ошибку и выводятся данные*/


}
