#include <stdio.h>
#include "STD_TYPES.h"
void insert(s32 *arr, const u32* size)
{
    for (u32 ind = 1; ind<*size; ++ind)
    {
        u32 val = arr[ind];
        s32 prev = ind-1;
        while (prev>=0 && arr[prev]>val){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = val;
    }
    puts("After sorting the array: ");
    for (u32 ind = 0; ind<*size; ++ind){
        printf("%d ",arr[ind]);
    }
    puts("");
}
