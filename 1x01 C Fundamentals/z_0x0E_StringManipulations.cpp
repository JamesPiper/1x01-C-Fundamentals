//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// An examination of the functions in "string.h"
// TO DO
// Move as submenu item of HeaderFiles
// 
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "stdlib.h"
#include <cstdlib>
#include "string.h"

// Function prototypes
static void A();
static void B();
static void C();
static void D();
static void E();
static void F();

void _0x0E_StringManipulations() {

	char Inputs[80];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   String Manipulations                                                     *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - strlen()                                                             *\n");
		printf("*   B - strcpy()                                                             *\n");
		printf("*   C - strcat()                                                             *\n");
		printf("*   D - strcmp()                                                             *\n");
		printf("*   E - strlwr()                                                             *\n");
		printf("*   F - strupr()                                                             *\n");
		printf("*                                                                            *\n");
		printf("*   X - Return to main menu.                                                 *\n");
		printf("*                                                                            *\n");
		printf("*   Need #include \"string.h\"                                                 *\n");
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
		else if (Choice == 'X' || Choice == 'x') 
			return;

		system("pause");

	} while (Choice != 'X' && Choice != 'x'); 

	printf("Type: char %d\n", CHAR_BIT);
}

static void A() {

	printf("------------------------------------------------------------------------------\n");
	printf("1. strlen() - Calculates the length of string\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	char aString1a[] = "0123456879";
	char aString1b[11] = "0123456879";
	printf("\n");
	printf("  char aString1a[] = \"%s\";\n", aString1a);
	printf("  char aString1b[11] = \"%s\";\n", aString1b);
	printf("  Since aString1a has 10 elements that's 11 b/c of \\0 at the end.\n");
	int length1 = strlen(aString1a);
	printf("  int length1 = strlen(aString1a);\n", length1);
	printf("  The length is %d\n", length1);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

static void B() {

	printf("------------------------------------------------------------------------------\n");
	printf("2. strcpy() - Copies a string to another string\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	char aString1a[] = "0123456879";
	char aString2[11];
	printf("   char aString2[11] = \"%s\";\n", aString2);
	printf("   Forced to declare a fixed size.\n");
	printf("   Since aString1a has 10 elements that's 11 b/c of \\0 at the end.\n");
	printf("   The destination string, aString2, has to be as long as source string.\n");
	printf("\n");
	strcpy(aString2, aString1a);
	printf("   Run function: strcpy(aString2, aString1a);\n");
	printf("   aString2 is now = \"%s\";\n", aString2);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

static void C() {

	printf("------------------------------------------------------------------------------\n");
	printf("3. strcat() - Concatenates(joins) two strings\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	char aString1a[] = "0123456879";
	char JoinedString[20] = "start: ";
	printf("   char JoinedString[20] = \"start: \";\n");
	strcat(JoinedString, aString1a);
	printf("   strcat(JoinedString, aString1a);\n");
	printf("   JoinedString is now: '%s'\n", JoinedString);
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

static void D() {

	printf("------------------------------------------------------------------------------\n");
	printf("4. strcmp() - Compares two string and return an integer\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("   int strcmp (const char* str1, const char* str2);\n");
	printf("\n");
	printf("   Returns:\n");
	printf("   0   - if both strings are identical (equal)\n");
	printf("   < 0 - if the ASCII value of first unmatched character is less than second\n");
	printf("   > 0 - if the ASCII value of first unmatched character is greater than second\n");
	printf("\n");
	printf("   Compare \"%s\" to \"%s\" results in %d\n", "a", "a", strcmp("a","a"));
	printf("   Compare \"%s\" to \"%s\" results in %d\n", "A", "A", strcmp("A","A"));
	printf("   Compare \"%s\" to \"%s\" results in %d\n", "a", "A", strcmp("a","A"));
	printf("   Compare \"%s\" to \"%s\" results in %d\n", "A", "a", strcmp("A","a"));
	char Str1[] = "abc";
	char Str2[] = "abC";
	char Str3[] = "ABc";
	int result;
	printf("\n");
	printf("   Strings to compare: Str1[] = \"%s\", Str2[] = \"%s\";, Str3[] = \"%s\"; \n", Str1, Str2, Str3);
	printf("\n");
	result = strcmp(Str1, Str1);
	printf("   Compare 1 to 1: result = strcmp(Str1, Str1); \"%s\" - \"%s\" returns; %d\n", Str1, Str1, result);
	result = strcmp(Str1, Str2);
	printf("   Compare 1 to 2: result = strcmp(Str1, Str2); \"%s\" - \"%s\" returns; %d\n", Str1, Str2, result);
	result = strcmp(Str1, Str3);
	printf("   Compare 1 to 3: result = strcmp(Str1, Str3); \"%s\" - \"%s\" returns; %d\n", Str1, Str3, result);
	result = strcmp(Str2, Str3);
	printf("   Compare 2 to 3: result = strcmp(Str2, Str3); \"%s\" - \"%s\" returns; %d\n", Str2, Str3, result);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

static void E() {

	printf("------------------------------------------------------------------------------\n");
	printf("5. strlwr() - Converts string to lowercase\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("   char *strlwr(char *s);\n");
	char ucString[] = "THIS IS IN CAPS.";
	printf("\n");
	printf("   start with char ucString[] = \"%s\"\n", ucString);
	strlwr(ucString);
	printf("   turn to lowercase with strlwr(ucString)\n");
	printf("   usString becomes \"%s\"\n", ucString);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

static void F() {

	printf("------------------------------------------------------------------------------\n");
	printf("6. strupr() - Converts string to uppercase\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("   char *strupr(char *s);\n");
	printf("\n");
	char ucString[] = "this is in caps.";
	printf("   start with char ucString[] = \"%s\"\n", ucString);
	strupr(ucString);
	printf("   back to upppercase with strupr(ucString)\n");
	printf("   usString becomes \"%s\"\n", ucString);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");

}
