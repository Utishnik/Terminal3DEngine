#include "Tools.h"

void* _Malloc(size_t size)
{
	void* result = malloc(size);
	if (!result)
	{
		printf("Not Alloce Memory str number  %d\n function name  %s\n File name %s\n", __LINE__, __func__, __FILE__);
		//		todo ������ ���� ����� ������ ������ �������� ������� ����� (����� ����� � � llvm ��� ��������)
		//		���� �������� � _Malloc ��������� ������������� � ���� ��� ������ __func__ ������� ������� _Malloc
		//		�������� ������� � ������� _Malloc ���� ��������
		return NULL;
	}
	return result;
}

void _Free(void* arr)
{
	if (!arr)
	{
		printf("Free:arr is empty str number  %d\n function name  %s\n File name %s\n", __LINE__, __func__, __FILE__);
		return;
	}
	free(arr);
}
