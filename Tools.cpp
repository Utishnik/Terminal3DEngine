#include "Tools.h"

void* _Malloc(size_t size)
{
	void* result = malloc(size);
	if (!result)
	{
		printf(" str number  %d\n function name  %s\n File name %s\n", __LINE__, __func__, __FILE__);
		//		todo ������ ���� ����� ������ ������ �������� ������� ����� (����� ����� � � llvm ��� ��������)
		//		���� �������� � _Malloc ��������� ������������� � ���� ��� ������ __func__ ������� ������� _Malloc
		//		�������� ������� � ������� _Malloc ���� ��������
		return NULL;
	}
	return result;
}