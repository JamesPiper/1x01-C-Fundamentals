/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.15
// File        : _4x00_LinkedLists.cpp
// Description : Menu to various types of linked lists.
// IDE         : Visual Studio 2012
// Compiler    : MS
// Language    : C
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
//#include "stdafx.h"
#include "_1x01 C Fundamentals.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _4x00_LinkedLists() {

	char Choice;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Linked Lists                                                             *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Single Linked List of Ints                                           *\n");
		printf("*   B - Single Linked List of Char                                           *\n");
		printf("*   C - Single Linked List of Chars                                          *\n");
		printf("*   D - Single Linked List of Structs                                        *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return                                                               *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("Enter choice: ");

		char Inputs[MAX_INPUT_CHARS];
		// 2 represents 1 char of input and null terminator.
		GetUserInputs(Inputs, CHOICE_LENGTH);
		//scanf("%s", &Inputs);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			_4x01_SingleLinkedListOfInts();
		else if (Choice == 'b')
			_4x02_SingleLinkedListOfChar();
		else if (Choice == 'c')
			_4x03_SingleLinkedListOfChars();
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
