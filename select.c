#include <stdio.h>
#include "STD_TYPES.h"
void select(s32 *arr, const u32 *size){
    for (u32 ind = 0; ind<*size; ++ind){
        u32 mini = ind;
        for (u32 after = ind+1; after<*size; ++after){
            if (arr[after]<arr[mini])mini = after;
        }
        u32 tmp = arr[mini];
        arr[mini] = arr[ind];
        arr[ind] = tmp;
    }
    puts("Array after sorting : ");
    for (u32 ind = 0; ind<*size; ++ind){
        printf("%d ",arr[ind]);
    }
    puts("");
}
