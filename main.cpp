#include <stdio.h>
#include <stdlib.h>
#include "Tools.h"
//todo : https://www.cyberforum.ru/cpp-beginners/thread2709026.html ������ ��� �������� �������� ����������� ��������� ������� �� ������ tpp(�� ��� �� �����) 

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
	test1.map = _Rect_Malloc_3d<float>(test1.height, test1.widht, test1.depth);//������ ������ ���

	//������ ��������� ����
	printf("d  %p\n",test.map);
	for (int i = 0; i < 2; i++) free(test.map[i]);
	//free(arr1);
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		arr1[i][j] = (float)(i);
	//		printf("%g ", arr1[i][j]);
	//	}
	//	printf("\n");
	//}
	//_Rect_Free_2d(test);

	/*
	int* gg = (int*)malloc(sizeof(int) * 10);
	free(gg);
	for (int i = 0; i < 10; i++)
	{
		gg[i] = i;
		printf("%d\n", gg[i]);
	}
	*� �� �� �� ����� � �� ������ �� ���� ��� �� ������ ������ ������ � ��������� ������*/


}
