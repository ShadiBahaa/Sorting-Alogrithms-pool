#include <stdio.h>
#include "STD_TYPES.h"
void bubble(s32 *arr, const u32 *size)
{
    for (u32 rep =0; rep+1<*size; ++rep)
    {
        for (u32 ind = 0; ind+1+rep<*size; ++ind)
        {
            if (arr[ind]>arr[ind+1])
            {
                u32 tmp = arr[ind+1];
                arr[ind+1] = arr[ind];
                arr[ind] = tmp;
            }
        }
    }
    puts("Array after sorting : ");
    for (u32 ind = 0; ind<*size; ++ind){
        printf("%d ",arr[ind]);
    }
    puts("");
}
