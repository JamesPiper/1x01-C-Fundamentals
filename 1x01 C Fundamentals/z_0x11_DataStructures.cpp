//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// TO DO
// I want to code various examples of data scructures here.
// Linked Lists, Queues, Stacks, Trees...
// 
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>

// Function prototypes
static void A();
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

void _0x11_DataStructures() {

	char Inputs[80];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   Data Structures                                                          *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Single Linked List                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   X - Return to main menu.                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("\n");
		printf("Enter choice: ");

		scanf("%s", &Inputs);

		Choice = Inputs[0];
		printf("\n");

		if (Choice == 'A' || Choice == 'a')
			A();
		else if (Choice == 'B' || Choice == 'b')
			B();
		else if (Choice == 'C' || Choice == 'c')
			C();
		else if (Choice == 'D' || Choice == 'd')
			D();
		else if (Choice == 'E' || Choice == 'e')
			E();
		else if (Choice == 'F' || Choice == 'f')
			F();
		else if (Choice == 'G' || Choice == 'g')
			G();
		else if (Choice == 'H' || Choice == 'h')
			H();
		else if (Choice == 'I' || Choice == 'i')
			I();
		else if (Choice == 'J' || Choice == 'j')
			J();
		else if (Choice == 'K' || Choice == 'k')
			K();
		else if (Choice == 'X' || Choice == 'x') 
			return;

		system("pause");

	} while (Choice != 'X' && Choice != 'x'); 

	printf("Type: char %d\n", CHAR_BIT);
}

static void A() {

	printf("==============================================================================\n");
	printf("A - <stdlib.h> Standard Utility functions\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Dynamic memory management\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  calloc  - Allocate and zero-initialize array\n");
	printf("  free    - Deallocate memory block\n");
	printf("  malloc  - Allocate memory block\n");
	printf("  realloc - Reallocate memory block\n");
	printf("\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void B() {

	printf("------------------------------------------------------------------------------\n");
	printf("B - <stdio.h>  Standard Input/Output functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void C() {

	printf("------------------------------------------------------------------------------\n");
	printf("C - <math.h>   Mathematics functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void D() {

	printf("------------------------------------------------------------------------------\n");
	printf("D - <string.h> String handling functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void E() {

	printf("------------------------------------------------------------------------------\n");
	printf("E - <time.h>  Date time functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void F() {

	printf("------------------------------------------------------------------------------\n");
	printf("F - <ctype.h>  Character type functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  isalnum  - Check if character is alphanumeric\n");
	printf("  isalpha  - Check if character is alphabetic\n");
	printf("  isblank  - Check if character is blank\n");
	printf("  iscntrl  - Check if character is a control character\n");
	printf("  isdigit  - Check if character is decimal digit\n");
	printf("  isgraph  - Check if character has graphical representation\n");
	printf("  islower  - Check if character is lowercase letter\n");
	printf("  isprint  - Check if character is printable\n");
	printf("  ispunct  - Check if character is a punctuation character\n");
	printf("  isspace  - Check if character is a white-space\n");
	printf("  isupper  - Check if character is uppercase letter\n");
	printf("  isxdigit - Check if character is hexadecimal digit\n");
	printf("\n");
	printf("  tolower  - Convert uppercase letter to lowercase\n");
	printf("  toupper  - Convert lowercase letter to uppercase\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	
}

static void G() {

	printf("------------------------------------------------------------------------------\n");
	printf("G - <stdarg.h> Variable arguments handling functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void H() {

	printf("------------------------------------------------------------------------------\n");
	printf("H - <assert.h> Program assertion functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void I() {

	printf("------------------------------------------------------------------------------\n");
	printf("I - <locale.h> Localization functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void J() {

	printf("------------------------------------------------------------------------------\n");
	printf("J - <setjmp.h> Jump functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void K() {

	printf("------------------------------------------------------------------------------\n");
	printf("K - <signal.h> Signal handling functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

