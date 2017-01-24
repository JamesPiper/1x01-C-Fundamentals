/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.17
// File        : _3x0B_User_Defined_Functions.cpp
// Description : A lib of functions I've written to deal with certain common tasks.
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
static void Use_FileExists();
static void Use_StringCompare();
static char* StringCompareInText(int result);
static void Use_TrimWhitespace();
static void Test_GetUserInputs();

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _3x0B_User_Defined_Functions() {
	
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
		printf("*   D - String Input With Whitespace                                         *\n");
		printf("*                                                                            *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*   Z - Return to main menu.                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("Enter choice: ");

		char Inputs[MAX_INPUT_CHARS];
		GetUserInputs(Inputs, CHOICE_LENGTH);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			Use_FileExists();
		else if (Choice == 'b')
			Use_StringCompare();
		else if (Choice == 'c')
			Use_TrimWhitespace();
		else if (Choice == 'd')
			Test_GetUserInputs();
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
		else if (Choice != 'x') 
			printf("*** Select a choice from those listed. ****\n\n");

	} while (Choice != 'x'); 

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions.
/////////////////////////////////////////////////////////////////////////////////////
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

	strcpy(str1, "fdsa");
	strcpy(str2, "asdf");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "asdf");
	strcpy(str2, "fdsa");
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

	strcpy(str1, "fdsaaz");
	strcpy(str2, "fdsaz");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "fdsaza");
	strcpy(str2, "fdsaz");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "asdfzz");
	strcpy(str2, "asdf");
	result = StringCompare(str1, str2);
	printf("Compare '%s' to '%s' results in %d (%s)\n", str1, str2, result, StringCompareInText(result));

	strcpy(str1, "asdfaa");
	strcpy(str2, "asdf");
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
	int Length = (signed)strlen(string1);
	int LengthA = (signed)strlen(string1);
	int LengthB = (signed)strlen(string2);
	if (LengthB < LengthA) 
		Length = LengthB;

	char A, B;
	int result = 0;
	Boolean CompareEnded = False;
	int i = 0;

	while (CompareEnded != True) {
		A = tolower(string1[i]);
		B = tolower(string2[i]);
		if (A == B) 
			result = 0; // abs(result) * result;
		else if (A <= B) {
			CompareEnded = True;
			result = -1;
		} else if (A >= B) {
			CompareEnded = True;
			result = 1;
		}
		i++;
		if (i == Length) 
			CompareEnded = True;
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
	size_t End = strlen(str) - 1;
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

	strcpy(str, "  word    gap   ");
	printf("Text before: '%s'\n", str);
	printf("Text after:  '%s'\n", TrimWhitespace(str));
	printf("              012345678901234567890123456789\n");
	printf("\n");

	strcpy(str, "     ");
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
	// Overflow: reading past the end of the string array or before it.
	// String doesn't end with '\0'.
	// String is too long. What is the limit?
	// String is null.
	// String is only whitespace.
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
	int End = (signed)strlen(string) - 1;
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
	//printf("To:   %d \n", To);
	//printf("End:  %d \n", End);
	//printf("From: %d \n", From);
	/////////////////////////////////////////////////////////////////////////////////////

	// Backward search for trailing spaces.
	EndReached  = False;
	while ((EndReached != True) && (To > 0)) {
		 if (isspace(string[To - 1]) != 0) 
			To--;
		 else {
			EndReached = True;
		 }
	}

	string[To] = '\0';
	return string;
}

static void Test_GetUserInputs() {
	
	printf("==============================================================================\n");
	printf("D - String Input With Whitespace\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Scenario 1 on Arrays\n");
	printf("------------------------------------------------------------------------------\n");
	char str[] = "012345678";
	printf("Define a string array: char str[] = \"%s\";\n", str);
	printf("strlen(str) is %d \n", strlen(str));
	for (int i = 0; i < (signed)strlen(str); i++) {
		printf("Element [%d] is %c\n", i, str[i]);
	}
	printf("Element [%d] is ", strlen(str), str[strlen(str)]);
	if (str[strlen(str)] == '\0') 
		printf("null.\n");
	else
		printf("not null.\n");

	printf("\n");
	printf("Scenario 2 on Arrays\n");
	printf("------------------------------------------------------------------------------\n");
	char str2[10] = "012345678";
	printf("Define a string array: char str[%d] = \"%s\";\n", strlen(str2), str2);
	printf("strlen(str) is %d \n", strlen(str2));
	for (int i = 0; i < (signed)strlen(str2); i++) {
		printf("Element [%d] is %c\n", i, str2[i]);
	}
	printf("Element [%d] is ", strlen(str2), str2[strlen(str2)]);
	if (str2[strlen(str2)] == '\0') 
		printf("null.\n");
	else
		printf("not null.\n");
	printf("\n");
	
	printf("Test Function Call\n");
	printf("------------------------------------------------------------------------------\n");
	char UserInputs[10] = "";
	printf("Enter text: ");
	GetUserInputs(UserInputs, 10);
	printf("You entered: '%s'\n", UserInputs);

	char OneUserInputs[2] = "";
	printf("Enter one character: ");
	GetUserInputs(OneUserInputs, 2);
	printf("You entered: '%s'\n", OneUserInputs);

	printf("\n");
	printf("==============================================================================\n");

}

void GetUserInputs(char* input, int max_length) {

	/////////////////////////////////////////////////////////////////////////////////////
	// Take user typed-in data from terminal and stores the string of inputs in
	// a string array, input, of max_length.
	// 
	// Using scanf("%s", Inputs) doesn't work when there's whitespace.
	// It will only put first chunk of text into Inputs.
	//
	// There's many things said about overflows and how it can crash a program or worse.
	// Certainly if you try to store text with n chars into a char array defined with
	// m chars and m is less than n, you'll overwrite memory beyond the array or
	// you'll get a segmentation fault.
	//
	// Risks
	// 1. User inputs more text than max_length.
	//    Circumvent by ingoring text entereded after max_length and not storing data
	//    in array past max_length.
	//
	// 2. String doesn't end with '\0'.
	//
	// 3. scanf("%s", Inputs) on first entry.
	//    The computer will take a chunk of text until the whitespace is encountered
	//    and put it in Inputs. 
	//    Possible overflow in writing to Inputs array if this chunk is longer. 
	//    Use scanf("%ns", Inputs) to limit chars put into Inputs to n chars.
	//    Coding to vary this specifier based on max_length.
	//
	/////////////////////////////////////////////////////////////////////////////////////
	//
	// Example
	//
	// max_length: 10
	// Note: String defined in caller as str[10]
	//       10 = 9 chars + 1 of '\0'
	//
	// Enter text: 'here is some text' <enter>
	//              01234567890123456
	//
	// 1. input = "here" + \0
	// 2. i = 5
	// 3. get additional char until enter key hit
	// 4. add if not before max_length
	// 5. input = "here is s" + '\0'
	//             012345678     9
	//
	/////////////////////////////////////////////////////////////////////////////////////
	
	// First chunk of non-whitespace user input.
	// Using fixed length to simplify code.
	// Use more temp memory for less cycles.
	// If user enters more than 1024 chars, the code will likely cause problems.
	// Low risk of overflow.
	// Issue if piping in file as input.
	char UserInput[1024];
	scanf("%1023s", UserInput); 
	strncpy(input, UserInput, max_length - 1);
	//*(input + max_length - 1) = '\0';

	// Initial chunk of text--cut off from first whitespace.
	int i = (signed)strlen(input);
	char c;
	
	do {
		// Get additional text one character at a time.
        scanf("%c", &c);

		// Keep adding text as long before max_length.
        if (i < max_length)
            input[i++] = c;

		// Need to continue looping until '\n' is reached
		// because additional text input will be processed.
		// It would be good to stop the scan process but I
		// don't know how to do that.
	} while (c != '\n');

	// Terminate string array.
	if (i < max_length)
		input[i - 1] = '\0';
	else
		input[max_length - 1] = '\0';

}


