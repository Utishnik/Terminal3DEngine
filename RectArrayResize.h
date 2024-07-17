#ifndef RECTARRAYRESIZE_H_INCLUDED
#define RECTARRAYRESIZE_H_INCLUDED
#include "Tools.h"

template<typename Type>
size_t _Rect_ResizeCol3d(size_t cnt_new_col,Rect_Array3d<Type>* arr3d,bool save_data)
{
        size_t ret_code=0;
        if(!arr3d->map) ret_code+=0x0000000000000001;
        if(cnt_new_col==arr3d->height) ret_code+=0x0000000000000010;
        if(!arr3d->depth || !arr3d->height || !arr3d->widht) ret_code+=0x0000000000000100;
        if(ret_code) return ret_code;

        for(size_t i=0;i<arr3d->depth;i++)
        {
            Type **save_slice_data=(Type**)_Rect_Malloc_2d<Type>(arr3d->height,arr3d->widht);
            if(save_data)
                for(size_t j=0;j<arr3d->height;j++)
                    for(size_t k=0;k<arr3d->widht;k++)
                        save_slice_data[j][k]=arr3d->map[i][j][k];
            _Free_2d(arr3d->map[i],arr3d->height);

            arr3d->map[i]=_Rect_Malloc_2d<Type>(cnt_new_col,arr3d->widht);
            if(save_data)
            {
                for(size_t j=0;j<arr3d->height;j++)
                {
                    for(size_t k=0;k<arr3d->widht;k++)
                    {
                        arr3d->map[i][j][k]=save_slice_data[j][k];
                    }
                }
            }

        }
    arr3d->widht=cnt_new_col;
    return 0;
}


#endif // RECTARRAYRESIZE_H_INCLUDED
