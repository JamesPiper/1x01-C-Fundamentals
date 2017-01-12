//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Summary of various header files
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

void _3x02_HeaderFiles() {

	char Inputs[80];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   Header Files                                                             *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - <stdlib.h> Standard Utility functions                                *\n");
		printf("*   B - <stdio.h>  Standard Input/Output functions                           *\n");
		printf("*   C - <math.h>   Mathematics functions                                     *\n");
		printf("*   D - <string.h> String handling functions                                 *\n");
		printf("*   E - <time.h>  Date time functions                                        *\n");
		printf("*   F - <ctype.h>  Character type functions                                  *\n");
		printf("*   G - <stdarg.h> Variable arguments handling functions                     *\n");
		printf("*   H - <assert.h> Program assertion functions                               *\n");
		printf("*   I - <locale.h> Localization functions                                    *\n");
		printf("*   J - <setjmp.h> Jump functions                                            *\n");
		printf("*   K - <signal.h> Signal handling functions                                 *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return to main menu.                                                 *\n");
		printf("*   X - Exit the program.                                                    *\n");
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
			exit(0);
		else if (Choice == 'Z' || Choice == 'z') 
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
	printf("String Functions\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  atof, strtod, strtof, strtold - string to floating point\n");
	printf("  atoi, atol, atoll, strtol, strtoll, strtoul, strtoull - for integers\n");
	printf("\n");
	printf("Dynamic memory management\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  calloc  - Allocate and zero-initialize array\n");
	printf("  free    - Deallocate memory block\n");
	printf("  malloc  - Allocate memory block\n");
	printf("  realloc - Reallocate memory block\n");
	printf("\n");
	printf("Pseudo-random sequence generation\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  rand   - Generate random number\n");
	printf("  srand  - Initialize random number generator\n");
	printf("\n");
	printf("Environment\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  abort  - Abort current process\n");
	printf("  atexit - Set function to be executed on exit (also at_quick_exit, quick_exit)\n");
	printf("  exit   - Terminate calling process (see also _Exit)\n");
	printf("  getenv - Get environment string\n");
	printf("  system - Execute system command\n");
	printf("\n");
	printf("Searching and sorting\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  bsearch - Binary search in array\n");
	printf("  qsort   - Sort elements of array\n");
	printf("\n");
	printf("Integer arithmetics\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  abs, labs, llabs - absolute value of integers\n");
	printf("  div, ldiv, lldib - integral division\n");
	printf("\n");
	printf("Multibyte characters (wide characters), strings\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  mblen, mbtowc, wctomb - mbstowcs, wcstombs\n");
	printf("\n");
	printf("Macro constants: EXIT_FAILURE, EXIT_SUCCESS, MB_CUR_MAX, NULL, RAND_MAX\n");
	printf("Types: div_t, ldiv_t, lldiv_t, size_t\n");
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

