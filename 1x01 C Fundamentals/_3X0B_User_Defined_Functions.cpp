//==============================================================================
// 2017.01.17 by James Piper, james@jamespiper.com
// 
// A repository of functions I've written to deal with certain common tasks.
// 
//==============================================================================


#include "stdafx.h"
#include "1x01 C Fundamentals.h"

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <ctype.h>

// Function prototypes
static void Use_FileExists();

static void Use_StringCompare();
static char* StringCompareInText(int result);

static void Use_TrimWhitespace();

void _3X0B_User_Defined_Functions() {
	
	char Inputs[MAX_INPUT_CHARS];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   User-defined Functions                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - FileExists                                                           *\n");
		printf("*   B - String Compare (Case insensitive)                                    *\n");
		printf("*   C - Trim Whitespace                                                      *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return to main menu.                                                 *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("\n");
		printf("Enter choice: ");

		scanf("%s", &Inputs);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			Use_FileExists();
		else if (Choice == 'b')
			Use_StringCompare();
		else if (Choice == 'c')
			Use_TrimWhitespace();
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

static void Use_FileExists() {
		
	printf("==============================================================================\n");
	printf("A - FileExists\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Boolean FileExists(const char* filename)\n");
	printf("\n");
	printf("Example filename: C:\\Users\\Guest\\new.txt\n");
	printf("\n");
	printf("Call the function: if (FileExists(\"C:\\Users\\Guest\\new.txt\"))\n");
	printf("\n");
	if (FileExists("C:\\Users\\Guest\\new.txt")) 
		printf("The code says the file exists.\n");
	else
		printf("Problem encountered. File likely doesn't exist.\n");
	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

Boolean FileExists(const char* filename) {

	// There seems to be several ways to do this, but using fopen seems the easiest.
	// One method uses access() yet I can't find any reference on this.
	// Another uses stat() function in <sys/stat.h>
	// Using const in argument so this function doesn't change the filename.

	FILE* pFile;
	pFile = fopen(filename, "r");
	if (pFile != NULL) { 
		fclose(pFile);
		return True;
	} else
		return False;

}

static void Use_StringCompare() {

	printf("==============================================================================\n");
	printf("B - String Compare (Case insensitive)\n");
	printf("==============================================================================\n");
	printf("\n");
	char str1[MAX_INPUT_CHARS];
	char str2[MAX_INPUT_CHARS];
	int result = 0;

	printf("Cases with same length.\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(str1, "ABC");
	strcpy(str2, "abc");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "abc");
	strcpy(str2, "ABC");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "Abc");
	strcpy(str2, "abc");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));
	printf("\n");

	strcpy(str1, "AAC");
	strcpy(str2, "abc");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "ABb");
	strcpy(str2, "abc");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "ABC");
	strcpy(str2, "abb");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	printf("\n");
	printf("Cases with different lengths.\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(str1, "app");
	strcpy(str2, "apps");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "apps");
	strcpy(str2, "app");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "App");
	strcpy(str2, "apps");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));
	printf("\n");

	strcpy(str1, "aPPle");
	strcpy(str2, "apples");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "aPPles");
	strcpy(str2, "Apple");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));
	printf("\n");

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}
int StringCompare(const char* string1, const char* string2) {

	/////////////////////////////////////////////////////////////////////////////////////
	// Compare string1 to string2 without regard to case.
	// Thus ABC is equal to abc or AbC and the other variations.
	// Also, apple comes before apples.
	//
	// Returns
	// 0 if string1 is the same as string2
	// < 0 if string1 comes before string2
	// > 0 if string1 comes after string2
	//
	// Risks or Concerns
	// Reading past array.
	// Doesn't deal with wide chars.
	// Leading or trailing whitespace - should be ignored.
	//
	/////////////////////////////////////////////////////////////////////////////////////
	//
	/////////////////////////////////////////////////////////////////////////////////////

	// To avoid reading past an array.
	int Length = strlen(string1);
	int LengthA = strlen(string1);
	int LengthB = strlen(string2);
	if (LengthB < LengthA) 
		Length = LengthB;

	char A, B;
	int result = 0;

	for (int i = 0; i < Length; i++) {
		A = tolower(string1[i]);
		B = tolower(string2[i]);
		// Want to keep result from previous compares.
		if (A == B) 
			result = abs(result) * result;
		else if (A <= B) 
			result = -1;
		else if (A >= B)
			result = 1;
	}

	// Handle cases with different length strings.
	if (LengthA < LengthB) {
		// Case of 'app' v 'apps'
		if (result == 0) 
			result = -1;
	} else if (LengthA > LengthB) {
		// Case of 'apps' v 'app'
		if (result == 0)
			result = 1;
	}

	return result;

}

static char* StringCompareInText(int result) {

	if (result < 0) 
		return "before";
	else if (result > 0)
		return "after";
	else
		return "same";

}

static void Use_TrimWhitespace() {

	printf("==============================================================================\n");
	printf("C - Trim Whitespace\n");
	printf("==============================================================================\n");
	printf("\n");
	char str[MAX_INPUT_CHARS];

	printf("Use of 'isspace'\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(str, "Some text.");
	int End = strlen(str) - 1;
	int StartWS = isspace(str[0]);
	int EndWS = isspace(str[End]);
	printf("Sample string: '%s'\n", str);
	printf("Start: '%c', IsWhitespace: %s (%d)\n", str[0], StartWS ? "True" : "False", StartWS);
	printf("End: '%c', IsWhitespace: %s (%d)\n", str[End], EndWS ? "True" : "False", EndWS);
	printf("\n");

	strcpy(str, " Some text . ");
	End = strlen(str) - 1;
	StartWS = isspace(str[0]);
	EndWS = isspace(str[End]);
	printf("Sample string: '%s'\n", str);
	printf("Start: '%c', IsWhitespace: %s (%d)\n", str[0], StartWS ? "True" : "False", StartWS);
	printf("End: '%c', IsWhitespace: %s (%d)\n", str[End], EndWS ? "True" : "False", EndWS);
	printf("\n");
	printf("zero when not whitespace\n");
	printf("non-zero when not whitespace\n");
	printf("\n");

	printf("No Whitespace Example\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(str, "Some text.");
	printf("Text before: '%s'\n", str);
	// TrimWhitespace(str); This works as well.
	printf("Text after:  '%s'\n", TrimWhitespace(str));
	printf("\n");

	printf("Whitespace Examples\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(str, "    Some text.");
	printf("Text before: '%s'\n", str);
	printf("Text after:  '%s'\n", TrimWhitespace(str));
	printf("              012345678901234567890123456789\n");
	printf("\n");

	strcpy(str, "Some text.   ");
	printf("Text before: '%s'\n", str);
	printf("Text after:  '%s'\n", TrimWhitespace(str));
	printf("              012345678901234567890123456789\n");
	printf("\n");

	strcpy(str, "     Some  (gap)  text.     ");
	printf("Text before: '%s'\n", str);
	printf("Text after:  '%s'\n", TrimWhitespace(str));
	printf("              012345678901234567890123456789\n");
	printf("\n");

	strcpy(str, "");
	printf("Text before: '%s'\n", str);
	printf("Text after:  '%s'\n", TrimWhitespace(str));
	printf("              012345678901234567890123456789\n");
	printf("\n");

	printf("\n");
	printf("==============================================================================\n");
	system("pause");
}

char* TrimWhitespace(char* string) {

	/////////////////////////////////////////////////////////////////////////////////////
	// Take a string and remove leading and trailing spaces.
	// 
	// The arguement string is changed if needed.
	//
	// Risks
	// Overflow: reading past the end of the string array.
	// Forgetting to end string with '\0'.
	// String is too long. What is the limit?
	// String is null.
	//
	/////////////////////////////////////////////////////////////////////////////////////
	//
	// From: " some (gap) text " + '\0'
	//        01234567890123456     7
	// To:   "some (gap) text"   + '\0'
	//        012345678901234       5   67
	// End:                   6 
	//
	/////////////////////////////////////////////////////////////////////////////////////

	Boolean EndReached = False;
	int From = 0;
	int To = 0;
	int End = strlen(string) - 1;
	Boolean InText = False;

	// Deal with leading spaces.
	while (EndReached != True) {
		if (From < End) {
			if (isspace(string[From]) != 0) {
				if (InText) 
					string[To++] = string[From++];
				else
					From++;			
			} else {
				InText = True;
				string[To++] = string[From++];
			}
		} else {
			string[To++] = string[From++];
			EndReached = True;
		}
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	//printf("To: %d \n", To);
	//printf("End: %d \n", End);
	//printf("From: %d \n", From);
	/////////////////////////////////////////////////////////////////////////////////////

	// Backward search for trailing spaces.
	EndReached  = False;
	while (EndReached != True) {
		 if (isspace(string[To - 1]) != 0) 
			To--;
		 else {
			EndReached = True;
		 }
	}

	string[To] = '\0';
	return string;
}