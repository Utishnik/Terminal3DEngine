#pragma once
#include "Tools.h"

template<typename Type>
void _Rect_Free_2d(Rect_Array2d<Type> r_arr_2d)
{
	for (size_t i = 0; i < r_arr_2d.height; i++)
	{
		_Free(r_arr_2d.map[i]);
	}
	_Free(r_arr_2d.map);
}

template<typename Type>
void _Rect_Free_3d(Rect_Array3d<Type> r_arr_3d)
{
	for (size_t i = 0; i < r_arr_3d.depth; i++)
	{
		for (size_t j = 0; j < r_arr_3d.height; j++)
		{
			_Free(r_arr_3d.map[i][j]);
		}
		_Free(r_arr_3d.map[i]);
    }
	_Free(r_arr_3d.map);
}
