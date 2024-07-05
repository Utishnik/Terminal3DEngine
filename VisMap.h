#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Vis_Map {
	int*** map;
	size_t height;
	size_t widht;
	size_t depth;
};


bool Init_Vis_Map(Vis_Map* vsm, size_t height, size_t widht, size_t depth, int init_sym);

int decart_Vsm_Get(Vis_Map* vsm, size_t height, size_t widht, size_t depth);

void decart_Vsm_Set(Vis_Map* vsm, size_t height, size_t widht, size_t depth, int sym);

bool Free_Vis_Map(Vis_Map* vsm, size_t height, size_t widht, size_t depth);