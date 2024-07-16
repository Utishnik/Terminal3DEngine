#include "VisMap.h"
#include "Tools.h"

bool Init_Vis_Map(Vis_Map* vsm, size_t height, size_t widht, size_t depth, int init_sym)
{
	vsm->widht = widht;
	vsm->height = height;
	vsm->depth = depth;

	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < height; j++)
		{
			vsm->map[i][j] = (int*)_Malloc(sizeof(size_t) * widht);
			if (!vsm->map[i][j]) return false;//todo: add meneger errors!
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

void decart_Vsm_Set(Vis_Map* vsm, size_t height, size_t widht, size_t depth, int sym)
{
	vsm->map[vsm->depth - depth][vsm->height - height][widht] = sym;
}


bool Free_Vis_Map(Vis_Map* vsm, size_t height, size_t widht, size_t depth)
{
	//todo: add function is_empty
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < height; j++)
		{
			free(vsm->map[i][j]);
		}
	}
	return true;
}