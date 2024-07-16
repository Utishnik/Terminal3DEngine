#include <stdio.h>
#include <stdlib.h>
#include "Tools.h"
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

	_Rect_Free_2d(test);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			test.map[i][j] = (float)(i);
			printf("%g ", test.map[i][j]);
		}
		printf("\n");
	}
	


}
