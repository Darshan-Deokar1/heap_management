#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "heap.h"

void main()
{
    void *const_heap = malloc(10000);
    Node *hptr = createNode();
    setNodeValues(hptr, const_heap, NULL, NULL, 10000, 0); // Node*,address,prev,next,memorySize,isAllocatd

    printf("\nCheck Allocate() for integer\n\n");
    int *intptr = (int *)Allocate(hptr, sizeof(int));
    *intptr = 5;
    printf("*intptr = %d\n", *intptr);
    printf("sizeof intptr = %d\n", sizeof(intptr));
    printf("sizeof *intptr = %d\n", sizeof(*intptr));
    printf("\nFinished Check Allocate() for integer\n\n");

    printf("\nCheck Allocate() for integer array\n\n");
    int *int_arr_ptr = (int *)Allocate(hptr, 5 * sizeof(int));
    *int_arr_ptr = 1;
    *(int_arr_ptr + 1) = 2;
    *(int_arr_ptr + 2) = 3;
    *(int_arr_ptr + 3) = 4;
    *(int_arr_ptr + 4) = 5;
    int_arr_ptr[2] = 333;
    // int_arr_ptr[5] = (1, 2, 3, 4, 5)
    printf("int_arr_ptr[2] = %d\n", int_arr_ptr[2]);
    printf("sizeof int_arr_ptr[] = %d\n", sizeof(int_arr_ptr));
    printf("sizeof *int_arr_ptr = %d\n", sizeof(*int_arr_ptr));
    printf("\nFinished Check Allocate() for integer array\n\n");

    printf("\n\nintptr = %p\n", intptr);
    Deallocate(hptr, &intptr);
    printf("\n\nintptr = %p\n", intptr);
    printf("*intptr = %d\n", *intptr);
}