/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.12
// File        : _3x07_DynamicMemoryAllocation.cpp
// Description : Examples of Memory Allocation from stdlib.h
// IDE         : Visual Studio 2012
// Compiler    : MS
// Language    : C
/////////////////////////////////////////////////////////////////////////////////////
// 
// Consider adding mem functions in 'string.h'
// 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <cstdio>
#include <cstdlib>

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
static void UsePointer(int* pInt);

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _3x07_DynamicMemoryAllocation() {
	
	printf("==============================================================================\n");
	printf("Dynamic Memory Allocation\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Need to add: #include \"stdlib.h\" or #include <cstdlib>\n");
	printf("\n");
	printf("There's four functions in the lib:\n");
	printf("\n");
	printf("1. malloc\n");
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
	printf("2. calloc\n");
	printf("------------------------------------------------------------------------------\n");
	printf("calloc stands for 'contiguous allocation'\n");
	printf("\n");
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
	printf("3. free\n");
	printf("------------------------------------------------------------------------------\n");
	printf("A block of memory previously allocated by a call to malloc, calloc \n");
	printf("or realloc is deallocated, making it available again for further allocations.\n");
	printf("\n");
	free(ptr1);
	printf("  free(ptr1);\n");
	free(ptr2);
	printf("  free(ptr2);\n");
	printf("\n");
	printf("4. realloc\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Changes the size of the memory block pointed to by ptr.\n");
	printf("\n");
	printf("  (cast-type*) ptr = (cast-type*) realloc(ptr, byte-size)\n");
	printf("\n");
	printf("\n");
	printf("==============================================================================\n");
	system("Pause");
	printf("\n");
	printf("\n");

	printf("==============================================================================\n");
	printf("Test Malloc and Free\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Within the same function\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Allocate memory for an int: int* pInt = (int*) malloc(sizeof(int));\n");
	int* pInt = (int*) malloc(sizeof(int));
	*pInt = 10;
	printf("and set a value (%d) with: *pInt = %d; at memory location %X\n", *pInt, *pInt, pInt);
	printf("\n");
	free(pInt);
	printf("Now free this memory: free(pInt);\n");
	printf("The value is gone, now garbage: %d\n", pInt);
	printf("\n");
	printf("Calling another function\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Allocate memory for an int: int* pInt = (int*) malloc(sizeof(int));\n");
	pInt = (int*) malloc(sizeof(int));
	*pInt = 100;
	printf("and set a value (%d) with: *pInt = %d; at memory location %X\n", *pInt, *pInt, pInt);
	printf("\n");
	printf("Now go to function where pointer is passed.\n");
	printf("\n");
	printf("  static void UsePointer(int* pInt)\n");
	printf("\n");
	UsePointer(pInt);
	printf("Garbage back in the caller: %d\n", pInt);
	printf("\n");
	printf("==============================================================================\n");
	system("Pause");

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions.
/////////////////////////////////////////////////////////////////////////////////////
static void UsePointer(int* pInt) {

	printf("We're in the function and the value is %d at memory location %X\n", *pInt, pInt);
	printf("It's the same memory address.\n");
	printf("\n");
	free(pInt);
	printf("Free the memory in the function: free(pInt);\n");
	printf("Garbage in the function: %d\n", pInt);

}