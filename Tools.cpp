#include "Tools.h"

void* _Malloc(size_t size)
{
	void* result = malloc(size);
	if (!result)
	{
		printf(" str number  %d\n function name  %s\n File name %s\n", __LINE__, __func__, __FILE__);
		//		todo короче надо какой нибудь парсер написать который будет (можно будет и в llvm это добавить)
		//		типо параметр в _Malloc добовляет автоматически и типо что вместо __func__ которая выводит _Malloc
		//		выводила функцию в которой _Malloc была вызванна
		return NULL;
	}
	return result;
}