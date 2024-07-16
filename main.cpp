#include <stdio.h>
#include <stdlib.h>
#include "Tools.h"
//todo : https://www.cyberforum.ru/cpp-beginners/thread2709026.html решить эту проблему добавить возможность разносить шаблоны на основе tpp(но это не точно) 

int main()
{
	Rect_Array2d test;
	test.height = 3;
	test.widht = 4;
	float** arr = _Rect_Malloc_2d<float>(test.height, test.widht);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = i / j;
			printf("%g ", arr[i][j]);
		}
		printf("\n");
	}
}
