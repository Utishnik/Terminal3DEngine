#ifndef DEFULTMEMORYCLEAR_H_INCLUDED
#define DEFULTMEMORYCLEAR_H_INCLUDED
#include "Tools.h"

template<typename Type>
void _Free_2d(Type **arr2d,size_t height)
{
    for(size_t i=0;i<height;i++)
        _Free(arr2d[i]);
    _Free(arr2d);
}

template<typename Type>
void _Free_3d(Type ***arr3d,size_t depth,size_t height)
{
    for(size_t i=0;i<depth;i++)
    {
        for(size_t j=0;j<height;j++)
            _Free(arr3d[i][j]);
        _Free(arr3d[i]);
    }
    _Free(arr3d);
}

#endif // DEFULTMEMORYCLEAR_H_INCLUDED
