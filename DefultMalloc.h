#ifndef DEFULTMALLOC_H_INCLUDED
#define DEFULTMALLOC_H_INCLUDED
#include "Tools.h"

template<typename Type>
Type** _Malloc_2d(size_t height, size_t widht)
{
    Type** arr2d=(Type**)_Malloc(height*sizeof(Type));
    for(size_t i=0;i<height;i++)
        arr2d[i]=(Type*)_Malloc(widht*sizeof(Type));
    return arr2d;
}


template<typename Type>
Type*** _Malloc_3d(size_t height, size_t widht, size_t depth)
{
    Type** arr3d=(Type***)_Malloc
}

#endif // DEFULTMALLOC_H_INCLUDED
