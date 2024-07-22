#pragma once

template<typename Type>
Type** _Rect_Malloc_2d(size_t height, size_t widht);
template<typename Type>
Type*** _Rect_Malloc_3d(size_t height, size_t widht, size_t depth);


template<typename Type>
Type*** _Rect_Malloc_3d(size_t height, size_t widht, size_t depth)
{
	Type*** arr=(Type***)_Malloc(depth * sizeof(Type**));
	for(size_t i=0;i<depth;i++)
        arr[i]=(Type**)_Rect_Malloc_2d<Type*>(height,widht);
	return arr;
}

template<typename Type>
Type** _Rect_Malloc_2d(size_t height, size_t widht)
{
	Type** arr;
	arr = (Type**)_Malloc(height * sizeof(Type*));
	for (size_t i = 0; i < height; i++)
	{
		arr[i] = (Type*)_Malloc(widht * sizeof(Type));
	}
	return arr;
}
