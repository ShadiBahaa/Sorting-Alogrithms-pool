#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>
static void run(s32 *, const u32*);
void bubble(s32 *,const u32 *);
void select(s32 *,const u32 *);
void merge(s32 *,const u32 *);
void insert(s32 *,const u32 *);
void (*sortAlgos[4])(s32*,const u32*) = {merge,insert,select,bubble};
s32 main(void)
{
    u32 size;
    s32 *arr = NULL;
    puts("This program is designed for sorting arrays.");
    printf("Enter the size of array: ");
    scanf("%d",&size);
    arr = (s32*)malloc(size*sizeof(s32));
    if (arr==NULL)
    {
        puts("Sorry we cannot create this array for you");
        return 0;
    }
    for (u32 ind = 0; ind<size; ++ind)
    {
        printf("Enter the element number %d :",ind+1);
        scanf("%d",arr+ind);
    }
    run(arr,&size);
}
static void run(s32* arr, const u32* size)
{
    u8 choice;
    printf("Enter a choice between 1 and 4 to sort your array:\n");
    printf("\t1- Merge sort\n");
    printf("\t2- Insertion sort\n");
    printf("\t3- Selection sort\n");
    printf("\t4- Bubble sort\n");
    printf("Your choice: ");
    scanf("%d",&choice);
    while (choice<1 || choice>4)
    {
        printf("Wrong choice. Enter a choice between 1 and 4: ");
        scanf("%d",&choice);
    }
    (*sortAlgos[choice-1])(arr,size);
}
