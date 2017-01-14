//==============================================================================
// 2017.01.14 by James Piper, james@jamespiper.com
// 
// Test code on various I/O functions of C.
// 
//
//
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"

#include <cstdio>
#include <cstdlib>
#include <string.h>

typedef enum Boolean { False, True };


void _3x0A_IOTests() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;

	do {
		
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   I/O Tests                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A -                                                                      *\n");
		printf("*   B -                                                                      *\n");
		printf("*   C -                                                                      *\n");
		printf("*   D -                                                                      *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return                                                               *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");
		printf("\n");

		printf("Enter choice: ");
		scanf("%s", &Inputs);
		strlwr(Inputs);
		Choice = Inputs[0];

		if (Choice == 'a')
			Choice = 'a';
		else if (Choice == 'b')
			Choice = 'b';
		else if (Choice == 'c') 
			Choice = 'c';
		else if (Choice == 'd') 
			Choice = 'd';
		else if (Choice == 'x') 
			exit(0);
		else if (Choice == 'z') 
			return;
		else 
			printf("*** Select a choice from those listed. ****\n\n");
		
	} while (Choice != 'x');  
}
