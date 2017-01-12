//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Examples of Memory Allocation from stdlib.h
// 
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "stdlib.h"
#include <cstdlib>

void _0x0D_DynamicMemoryAllocation() {
	
	printf("==============================================================================\n");
	printf("Dynamic Memory Allocation\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Need to add: #include \"stdlib.h\"\n");
	printf("\n");
	printf("There's four functions in the lib:\n");
	printf("\n");
	printf("1. malloc()\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Allocates a block of size bytes of memory, returning a pointer to \n");
	printf("the beginning of the block.\n");
	printf("\n");
	printf("The content of the newly allocated block of memory is not initialized,\n");
	printf("remaining with indeterminate values.\n");
	printf("\n");
	printf(" (cast-type*) ptr = (cast-type*) malloc(byte-size)\n");
	printf(" int* ptr1 = (int*) malloc (100 * sizeof(int));\n");
	int* ptr1 = (int*) malloc (100 * sizeof(int));
	printf("\n");
	if (ptr1 == NULL) 
		printf(" *** Problem allocating memory ***\n");
	else
		printf(" Good news. Memory allocated.\n");
	printf("\n");
	printf("2. calloc()\n");
	printf("------------------------------------------------------------------------------\n");
	printf("calloc stands for 'contiguous allocation'\n");
	printf("Allocates a block of memory for an array of num elements, each of them \n");
	printf("size bytes long, and initializes all its bits to zero.\n");
	printf("\n");
	printf("The effective result is the allocation of a zero-initialized memory \n");
	printf("block of (num*size) bytes.\n");
	printf("\n");
	printf(" ptr = (cast-type*) calloc (n, element-size);\n");
	printf(" float *ptr2 = (float*) calloc (25, sizeof(float));\n");
	float* ptr2 = (float*) calloc (25, sizeof(float));
	printf("\n");
	if (ptr2 == NULL) 
		printf(" *** Problem allocating memory ***\n");
	else
		printf(" Good news. Memory allocated.\n");
	printf("\n");
	printf("Both return NULL to the pointer is there's a problem allocating memory.\n");
	printf("\n");
	printf("3. free()\n");
	printf("------------------------------------------------------------------------------\n");
	printf("A block of memory previously allocated by a call to malloc, calloc \n");
	printf("or realloc is deallocated, making it available again for further allocations.\n");
	printf("\n");
	free(ptr1);
	printf("free(ptr1);\n");
	free(ptr2);
	printf("free(ptr2);\n");
	printf("\n");
	printf("==============================================================================\n");
	system("Pause");


}