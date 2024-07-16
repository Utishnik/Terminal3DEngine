#pragma once
#include <stdio.h>
#include <stdlib.h>

void* _Malloc(size_t size);

//todo: Add debug memory map

//Real multidimensional arrays

//Rect array
struct Rect_Array3d 
{
	void*** map;
	size_t height;
	size_t widht;
	size_t depth;
};

struct Rect_Array2d 
{
	void** map;
	size_t widht;
	size_t height;
};

//Safe Rect Memory Allocator
template<typename Type>
Type ***_Rect_Malloc_3d(size_t height, size_t widht, size_t depth);
template<typename Type>
Type** _Rect_Malloc_2d(size_t height, size_t widht);
#include "RectMalloc.hpp"

//bool _Rect_Free_3d(Rect_Array3d* arr3d);
//bool _Rect_Free_2d(Rect_Array2d* arr2d);
//
////Safe Resize Array
//int _Rect_ResizeCol3d(size_t cnt_new_col,Rect_Array3d *arr3d);
//int _Rect_ResizeLine3d(size_t cnt_new_line, Rect_Array3d* arr3d);
//int _Rect_ResizeDepth3d(size_t cnt_new_depth, Rect_Array3d* arr3d);
//int _Rect_Resize3d(size_t cnt_new_col, size_t cnt_new_line, size_t cnt_new_depth,Rect_Array3d* arr3d);
//
//int _Rect_ResizeCol2d(size_t cnt_new_col, Rect_Array2d* arr2d);
//int _Rect_ResizeLine2d(size_t cnt_new_line, Rect_Array2d* arr2d);
//int _Rect_Resize2d(size_t cnt_new_col, size_t cnt_new_line, Rect_Array2d* arr2d);

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