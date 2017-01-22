/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.12
// File        : _3x09_DataStructures.cpp
// Description : Submenu for data structures.
// IDE         : Visual Studio 2012
// Compiler    : MS
// Language    : C
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "1x01 C Fundamentals.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
static void B();
static void C();
static void D();
static void E();
static void F();
static void G();
static void H();
static void I();
static void J();
static void K();

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _3x09_DataStructures() {

	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Data Structures                                                          *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Linked Lists                                                         *\n");
		printf("*                                                                            *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*   Z - Return to main menu.                                                 *\n");
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
			_4x00_LinkedLists();
		else if (Choice == 'b')
			Choice = 'b';
		else if (Choice == 'c')
			Choice = 'c';
		else if (Choice == 'd')
			Choice = 'd';
		else if (Choice == 'e')
			Choice = 'e';
		else if (Choice == 'f')
			Choice = 'f';
		else if (Choice == 'g')
			Choice = 'g';
		else if (Choice == 'h')
			Choice = 'h';
		else if (Choice == 'i')
			Choice = 'i';
		else if (Choice == 'j')
			Choice = 'j';
		else if (Choice == 'k')
			Choice = 'k';
		else if (Choice == 'x') 
			exit(0);
		else if (Choice == 'z') 
			return;
		else 
			printf("*** Select a choice from those listed. ****\n\n");

	} while (Choice != 'x'); 

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions.
/////////////////////////////////////////////////////////////////////////////////////
static void B() {

	printf("------------------------------------------------------------------------------\n");
	printf("B - <stdio.h>  Standard Input/Output functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void C() {

	printf("------------------------------------------------------------------------------\n");
	printf("C - <math.h>   Mathematics functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void D() {

	printf("------------------------------------------------------------------------------\n");
	printf("D - <string.h> String handling functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void E() {

	printf("------------------------------------------------------------------------------\n");
	printf("E - <time.h>  Date time functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void F() {

	printf("------------------------------------------------------------------------------\n");
	printf("F - <ctype.h>  Character type functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	system("pause");
	
}

static void G() {

	printf("------------------------------------------------------------------------------\n");
	printf("G - <stdarg.h> Variable arguments handling functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void H() {

	printf("------------------------------------------------------------------------------\n");
	printf("H - <assert.h> Program assertion functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void I() {

	printf("------------------------------------------------------------------------------\n");
	printf("I - <locale.h> Localization functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void J() {

	printf("------------------------------------------------------------------------------\n");
	printf("J - <setjmp.h> Jump functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void K() {

	printf("------------------------------------------------------------------------------\n");
	printf("K - <signal.h> Signal handling functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

