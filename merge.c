#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
void divide(s32 *, u32, u32);
void merging(s32 *, u32, u32, u32);
void merge(s32 *arr, const u32* size)
{
    divide(arr,0,*size-1);
    puts("After sorting the array: ");
    for (u32 ind = 0; ind<*size; ++ind)
    {
        printf("%d ", arr[ind]);
    }
    puts("");
}
void divide(s32 *arr, u32 start, u32 end)
{
    if (start<end)
    {
        u32 mid = start+(end-start)/2;
        divide(arr,start,mid);
        divide(arr,mid+1,end);
        merging(arr,start,mid,end);
    }
    else
    {
        // do nothing
    }
}
void merging(s32 *arr, u32 start, u32 mid, u32 end)
{
    u32 firstSize = mid-start+1;
    u32 secondSize = end-mid;
    s32 *arr1 = (s32*)malloc(firstSize*sizeof(s32));
    s32 *arr2 = (s32*)malloc(secondSize*sizeof(s32));
    for (u32 ind = 0; ind<firstSize; ++ind)
    {
        arr1[ind] = arr[ind+start];
    }
    for (u32 ind = 0; ind<secondSize; ++ind)
    {
        arr2[ind] = arr[ind+mid+1];
    }
    u32 firstInd = 0,secondInd = 0, mergeInd = start;
    while (firstInd<firstSize && secondInd<secondSize)
    {
        if (arr1[firstInd]<=arr2[secondInd])
        {
            arr[mergeInd] = arr1[firstInd];
            firstInd++;
        }
        else
        {
            arr[mergeInd] = arr2[secondInd];
            secondInd++;
        }
        mergeInd++;
    }
    while (firstInd<firstSize)
    {
        arr[mergeInd] = arr1[firstInd];
        mergeInd++;
        firstInd++;
    }
    while (secondInd<secondSize)
    {
        arr[mergeInd] = arr2[secondInd];
        mergeInd++;
        secondInd++;
    }
}
