#include <stdio.h>
#include <stdlib.h>

struct Vis_Map {
	int*** map;
	size_t height;
	size_t widht;
	size_t depth;
};

void* _Malloc(size_t size)
{
	void* result = malloc(size);
	if (!result) 
	{
		printf(" str number  %d\n function name  %s\n File name %s\n",__LINE__,__func__,__FILE__);
		//		todo короче надо какой нибудь парсер написать который будет (можно будет и в llvm это добавить)
		//		типо параметр в _Malloc добовляет автоматически и типо что вместо __func__ которая выводит _Malloc
		//		выводила функцию в которой _Malloc была вызванна
		return NULL;
	}
	return result;
}

bool Init_Vis_Map(Vis_Map *vsm,size_t height,size_t widht,size_t depth,int init_sym)
{
	vsm->widht = widht;
	vsm->height = height;
	vsm->depth = depth;

	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < height; j++)
		{
			vsm->map[i][j] = (int*)_Malloc(sizeof(size_t) * widht);
			for (int k = 0; k < widht; k++)
			{
				vsm->map[j][i][k] = init_sym;
			}
		}
	}
}

int decart_Vsm_Get(Vis_Map* vsm, size_t height, size_t widht, size_t depth)
{
	return vsm->map[vsm->depth - depth][vsm->height - height][widht];
}

void decart_Vsm_Set(Vis_Map* vsm, size_t height, size_t widht, size_t depth,int sym)
{
	vsm->map[vsm->depth - depth][vsm->height - height][widht]=sym;
}


bool Free_Vis_Map(Vis_Map* vsm, size_t height, size_t widht, size_t depth)
{
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < height; j++)
		{
			free(vsm->map[i][j]);
		}
	}
}

int main()
{
	
}
