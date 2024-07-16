#pragma once

template<typename Type>
Type*** _Rect_Malloc_3d(size_t height, size_t widht, size_t depth)
{
	Type*** arr=(Type***)_Malloc(depth * sizeof(Type));
	for (size_t i = 0; i < depth; i++)
	{
		arr[i] = (Type**)_Malloc(height * sizeof(Type));

		for (size_t j = 0; j < height; j++)
		{
			arr[i][j] = (Type*)_Malloc(widht * sizeof(Type));
		}
	}
	return arr;
}

template<typename Type>
Type** _Rect_Malloc_2d(size_t height, size_t widht)
{
	Type** arr;
	arr = (Type**)_Malloc(height * sizeof(Type));
	for (size_t i = 0; i < height; i++)
	{
		arr[i] = (Type*)_Malloc(widht * sizeof(Type));
	}
	return arr;
}