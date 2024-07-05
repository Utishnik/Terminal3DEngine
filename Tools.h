#pragma once
#include <stdio.h>
#include <stdlib.h>

void* _Malloc(size_t size);

struct array3d {
	void*** map;
	size_t height;
	size_t widht;
	size_t depth;
};

