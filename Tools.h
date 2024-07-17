#pragma once
#include <stdio.h>
#include <stdlib.h>

void* _Malloc(size_t size);
void _Free(void* arr);

//todo: Add debug memory map

//Real multidimensional arrays

//Rect array
template<typename Type>
struct Rect_Array3d
{
	Type*** map;
	size_t height;
	size_t widht;
	size_t depth;
};

template<typename Type>
struct Rect_Array2d
{
	Type** map;
	size_t widht;
	size_t height;
};

//Safe Rect Memory Allocator
template<typename Type>
Type*** _Rect_Malloc_3d(size_t height, size_t widht, size_t depth);
template<typename Type>
Type** _Rect_Malloc_2d(size_t height, size_t widht);
#include "RectMalloc.hpp"

//Safe Rect Memory Clear
template<typename Type>
void _Rect_Free_3d(Rect_Array3d<Type> r_arr_3d);
template<typename Type>
void _Rect_Free_2d(Rect_Array2d<Type> r_arr_2d);
#include "RectMemoryClear.hpp"

//Safe Memory Clear In Defult Array
template<typename Type>
void _Free_2d(Type **arr2d,size_t height);
template<typename Type>
void _Free_3d(Type ***arr2d,size_t depth,size_t height);
#include "DefultMemoryClear.h"

//Safe Resize Array
template<typename Type>
size_t _Rect_ResizeCol3d(size_t cnt_new_col,Rect_Array3d<Type>* arr3d,bool save_data);
template<typename Type>
size_t _Rect_ResizeLine3d(size_t cnt_new_line, Rect_Array3d<Type>* arr3d,bool save_data);
template<typename Type>
size_t _Rect_ResizeDepth3d(size_t cnt_new_depth, Rect_Array3d<Type>* arr3d,bool save_data);
template<typename Type>
size_t _Rect_Resize3d(size_t cnt_new_col, size_t cnt_new_line, size_t cnt_new_depth,Rect_Array3d<Type>* arr3d,bool save_data);

template<typename Type>
size_t _Rect_ResizeCol2d(size_t cnt_new_col, Rect_Array2d<Type>* arr2d,bool save_data);
template<typename Type>
size_t _Rect_ResizeLine2d(size_t cnt_new_line, Rect_Array2d<Type>* arr2d,bool save_data);
template<typename Type>
size_t _Rect_Resize2d(size_t cnt_new_col, size_t cnt_new_line, Rect_Array2d<Type>* arr2d,bool save_data);
#include "RectArrayResize.h"

//Step Array
struct Step_Array3d
{
	void*** map;
	size_t height;
	size_t widht;
	size_t depth;
};

struct Step_Array2d
{
	void** map;
	size_t widht;
	size_t height;
};

struct Step_Map_2d
{//map edit 2d step array
	size_t *widht;
	size_t len;
};

struct Step_Map_3d
{//map edit 2d step array
	Step_Map_2d *sections;
	size_t len;
};

//void*** _Step_ResizeStep3d(Step_Map_3d SMR3d,Step_Array3d step_array3d);
//void** _Step_ResizeStep2d(Step_Map_3d SMR2d, Step_Array3d step_array2d);
//
////Safe Resize Array
//int _Step_Malloc3d(Step_Map_3d SMR3d, Step_Array3d* arr3d);
//int _Step_Malloc2d(Step_Map_3d SMR2d, Step_Array3d* arr2d);

//todo: Psevdo multidimensional arrays
