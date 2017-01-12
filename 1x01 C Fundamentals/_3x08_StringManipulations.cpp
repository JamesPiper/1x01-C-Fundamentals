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
#include <cstdlib>
#include <string.h>

// Function prototypes
static void A();
static void B();
static void C();
static void D();
static void E();
static void F();

void _3x08_StringManipulations() {

	char Inputs[80];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   String Manipulations                                                     *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - strlen                               B - strcpy, strncpy             *\n");
		printf("*   C - strcat, strncat                      D - strcmp, strncmp             *\n");
		printf("*   E - strlwr, strupr                       F - strchr, strrchr             *\n");
		printf("*   G - strspn                               H - strcspn                     *\n");
		printf("*   I - strpbrk                              J - strtok                      *\n");
		printf("*   K - strstr                               L - strerror                    *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return to main menu.                                                 *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("*   Need #include \"string.h\" or #include <string.h>                          *\n");
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
			exit(0);
		else if (Choice == 'Z' || Choice == 'z') 
			return;

		system("pause");

	} while (Choice != 'X' && Choice != 'x'); 

	printf("Type: char %d\n", CHAR_BIT);
}

static void A() {

	printf("==============================================================================\n");
	printf("A - strlen(string) - Calculates the length of string\n");
	printf("==============================================================================\n");
	//printf("\n");  // for some reason two blank lines appearing, comment out to get one, weird.
	char String1[]   = "0123456879";
	char String2[11] = "0123456879";
	//char String1c[10] = "0123456879";
	printf("\n");
	printf("  char String1[]   = \"%s\";\n", String1);
	printf("  char String2[11] = \"%s\";\n", String2);
	printf("  char String3[10] = \"%s\"; *** won't run ***\n", String2);
	printf("\n");
	printf("  Since String1a has 10 elements, need 11 b/c of \\0 at the end.\n");
	int length1 = strlen(String1);
	printf("\n");
	printf("  int length1 = strlen(String1);\n");
	printf("  The length is %d\n", length1);
	printf("\n");
	printf("==============================================================================\n");

}

static void B() {

	printf("==============================================================================\n");
	printf("B - Copies a string, or part, to another string\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("strcpy(destination string, source string) - copy entire string\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	char String1[] = "0123456879";
	char String2[11];
	printf("  char String1[] = \"%s\";\n", String1);
	printf("\n");
	printf("  char String2[]; *** doesn't work ***\n");
	printf("  Forced to declare a fixed size array.\n");
	printf("  char String2[11];\n", String2);
	printf("  *** It's filled with garbage: \"%s\" ***;\n", String2);
	printf("  Since String1 has 10 elements, it's 11 b/c of \\0 at the end.\n");
	printf("\n");
	strcpy(String2, String1);
	printf("  Run function: strcpy(String2, String1);\n");
	printf("  String2 is now = \"%s\";\n", String2);
	printf("\n");
	printf("  The destination string (String2) has to be as long as source string.\n");
	printf("  Run-time check that destingation array won't be overwritten.\n");
	printf("\n");
	printf("strncpy(destination string, source string, num) - copy num chars of string\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	// Running into a problem assigning a string literal 
	// a to char array after it's been declared.
	// Not sure what I'm missing here.

	char String3[] = "In the beginning...";
	char String4[10];
	printf("  char String3[] = \"%s\";\n", String3);
	printf("  char String4[10];\n", String4);
	printf("  *** It's filled with garbage: \"%s\" ***;\n", String4);
	printf("\n");
	strncpy(String4, String3, 8);
	String4[8] = '\0';
	printf("  strncpy(String4, String3, 8);\n");
	printf("  String4[8] = '\\0' - add null to mark the end\n");
	printf("\n");
	printf("  String4 is now \"%s\"\n", String4);
	printf("\n");
	printf("  Because String4 has 22 elements and only 8 chars copied, need to set end.\n");
	printf("\n");
	printf("==============================================================================\n");
}

static void C() {

	printf("==============================================================================\n");
	printf("C - Concatenate two strings\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("strcat(target string A, string to add B) - A = A + B\n");
	printf("------------------------------------------------------------------------------\n");
	char String1[] = "0123456879";
	char JoinedString[20] = "start: ";
	printf("  char String1[] = \"%s\";\n", String1);
	printf("  char JoinedString[20] = \"%s\";\n", JoinedString);
	strcat(JoinedString, String1);
	printf("  strcat(JoinedString, String1);\n");
	printf("  JoinedString is now: '%s'\n", JoinedString);
	printf("\n");
	printf("strncat(target string A, string to add B, num n) - A = A + n of B\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Only adds n chars of the second string.\n");
	printf("\n");
	char JoinedString2[20] = "start: ";
	printf("  char String1[] = \"%s\";\n", String1);
	printf("  char JoinedString2[20] = \"%s\";\n", JoinedString2);
	printf("\n");
	strncat(JoinedString2, String1, 5);
	printf("  strncat(JoinedString2, String1, 5);\n");
	printf("  JoinedString2 is now: '%s'\n", JoinedString2);
	printf("\n");
	printf("==============================================================================\n");
}

static void D() {

	printf("==============================================================================\n");
	printf("D - Compare two strings and return an integer\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("int strcmp (first string, second string);\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  Returns:\n");
	printf("  0  - if both strings are identical (equal)\n");
	printf("  < 0 - if the ASCII value of first unmatched character is less than second\n");
	printf("  > 0 - if the ASCII value of first unmatched character is greater than second\n");
	printf("\n");
	printf("  Compare \"%s\" to \"%s\" results in %d\n", "a", "a", strcmp("a","a"));
	printf("  Compare \"%s\" to \"%s\" results in %d\n", "A", "A", strcmp("A","A"));
	printf("  Compare \"%s\" to \"%s\" results in %d\n", "a", "A", strcmp("a","A"));
	printf("  Compare \"%s\" to \"%s\" results in %d\n", "A", "a", strcmp("A","a"));
	char Str1[] = "abc";
	char Str2[] = "abC";
	char Str3[] = "ABc";
	int result;
	printf("\n");
	printf("  Strings to compare: Str1[] = \"%s\", Str2[] = \"%s\";, Str3[] = \"%s\"; \n", Str1, Str2, Str3);
	printf("\n");
	result = strcmp(Str1, Str1);
	printf("  Compare 1 to 1: result = strcmp(Str1, Str1); \"%s\" - \"%s\" returns; %d\n", Str1, Str1, result);
	result = strcmp(Str1, Str2);
	printf("  Compare 1 to 2: result = strcmp(Str1, Str2); \"%s\" - \"%s\" returns; %d\n", Str1, Str2, result);
	result = strcmp(Str1, Str3);
	printf("  Compare 1 to 3: result = strcmp(Str1, Str3); \"%s\" - \"%s\" returns; %d\n", Str1, Str3, result);
	result = strcmp(Str2, Str3);
	printf("  Compare 2 to 3: result = strcmp(Str2, Str3); \"%s\" - \"%s\" returns; %d\n", Str2, Str3, result);
	printf("\n");
	printf("int strncmp (first string, second string, num);\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Compare n chars of each string\n");
	printf("\n");
	printf("strcoll - Compare two strings using locale\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Allows for local varitions for language, culture.\n");
	printf("\n");
	printf("==============================================================================\n");
}

static void E() {

	printf("==============================================================================\n");
	printf("E - Case conversion\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("strlwr(string) - Converts string to lowercase\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	char ucString[] = "THIS IS IN CAPS.";
	printf("  start with char ucString[] = \"%s\"\n", ucString);
	printf("\n");
	strlwr(ucString);
	printf("  turn to lowercase with strlwr(ucString)\n");
	printf("\n");
	printf("  usString becomes \"%s\"\n", ucString);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("strupr(string) - Converts string to uppercase\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  start with char ucString[] = \"%s\"\n", ucString);
	printf("\n");
	strupr(ucString);
	printf("  back to upppercase with strupr(ucString)\n");
	printf("\n");
	printf("  usString becomes \"%s\"\n", ucString);
	printf("\n");
	printf("==============================================================================\n");

}

static void F() {

	printf("==============================================================================\n");
	printf("E - Search for char in string\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("char* strchr(string, search char) - Left to Right\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  Finds first occurence of char in the search string from the beginning.\n");
	printf("  Returns a pointer to the location or null pointer if not found.\n");
	printf("\n");
	char String1[5] = "ABBA";
	char* location = strchr(String1, 'B');
	printf("  char String1[] = \"%s\";\n", String1);
	printf("  char* location = strchr(String1, 'B');\n");
	if (location != NULL) 
		printf ("  'B' found at %d\n", location - String1 + 1);
	else
		printf("  Couldn't find 'B' in String1");
	printf("\n");
	printf("  The return value is a memory location of %X\n", location);
	printf("\n");
	printf("  Use in two ways: \n");
	printf("    1. Covert to element index: location - String1 + 1 = %d\n", location - String1 + 1);
	printf("    2. Deference the pointer with *location - result: %c\n", *location);
	printf("\n");
	printf("\n");
	printf("char* strrchr(string, search char) - Right to Left\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("  Finds first occurence of char in the search string from the end.\n");
	printf("  Returns a pointer to the location or null pointer if not found.\n");
	printf("\n");
	printf("  char String1[] = \"%s\";\n", String1);
	location = strrchr(String1, 'B');
	printf("  char* location = strrchr(String1, 'B');\n");
	if (location != NULL) 
		printf ("  'B' found at %d\n", location - String1 + 1);
	else
		printf("  Couldn't find 'B' in String1");
	printf("\n");
	printf("  The return value is a memory location of %X\n", location);
	printf("\n");
	printf("\n");
	printf("==============================================================================\n");
}
