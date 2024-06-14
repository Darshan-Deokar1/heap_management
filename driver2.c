#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    void *const_heap = malloc(10000);
    Node *hptr = createNode();
    setNodeValues(hptr, const_heap, NULL, NULL, 10000, 0); // Node*,address,prev,next,memorySize,isAllocatd

    char *cptr = (char *)Allocate(hptr, sizeof(char));
    int *iptr = (int *)Allocate(hptr, sizeof(int));
    float *fptr = (float *)Allocate(hptr, sizeof(float));
    char *cptr1 = (char *)Allocate(hptr, 10 * sizeof(char));
    float *fptr1 = (float *)Allocate(hptr, 20 * sizeof(float));

    for (int i = 0, j = 65; i < 8; i++, j++)
    {
        cptr1[i] = j;
    }

    printf("\n\n");
    for (int i = 0, j = 65; i < 8; i++, j++)
    {
        printf("%c ", cptr1[i]);
    }
    printf("\n\n");

    *iptr = 4;
    *cptr = '&';
    *fptr = 5;

    printf("%d ", *iptr);
    printf("%c ", *cptr);
    printf("%f ", *fptr);
    printf("%p ", cptr);
    printf("%p ", iptr);
    printf("%p ", fptr);
    printf("%p ", cptr1);
    printf("%p ", fptr1);

    for (int i = 0, j = 65; i < 8; i++, j++)
    {
        fptr1[i] = j;
    }

    printf("\n\n");
    for (int i = 0, j = 65; i < 8; i++, j++)
    {
        printf("%f ", fptr1[i]);
    }
    printf("\n\n");
    printf("%p ", iptr);
    Deallocate(hptr, &iptr);
    printf("%p ", iptr);
    printf("\n\n");
    printf("%p ", cptr1);
    Deallocate(hptr, &cptr1);
    printf("%p ", cptr1);
    printf("\n\n");
    printf("%p ", fptr);
    Deallocate(hptr, &fptr);
    printf("%p ", fptr);

    printf("\n\n");
}