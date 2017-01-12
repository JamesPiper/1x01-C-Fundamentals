//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Simple ASCII table
// 
//==============================================================================

// http://pastebin.com/rkNZCKDJ

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>

void _3x05_CharMapping() {

	printf("******************************************************************************\n");
	printf("*                         Character Mapping                                  *\n");
	printf("*                                                                            *\n");
	printf("******************************************************************************\n");

	for (int i = 0; i < 256; i++) {
		printf("%i - %c\t", i, i);
		if (i % 8 == 0) 
			printf("\n");
	}
	printf("\n\n");
	printf("******************************************************************************\n");
	system("Pause");

}