/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.14
// File        : _3x0A_IOTests.cpp
// Description : Test code on various I/O functions of C.
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

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _3x0A_IOTests() {

	char Choice;

	do {
		
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Testing Standard I/O                                                     *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - File Exists                                                          *\n");
		printf("*   B - Rename                                                               *\n");
		printf("*   C - Remove                                                               *\n");
		printf("*   D - Temp File                                                            *\n");
		printf("*   E - Open, Close                                                          *\n");
		printf("*   F -                                                                      *\n");
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
			A();
		else if (Choice == 'b')
			B();
		else if (Choice == 'c') 
			C();
		else if (Choice == 'd') 
			D();
		else if (Choice == 'e') 
			E();
		else if (Choice == 'f') 
			F();
		else if (Choice == 'g') 
			Choice = 'g';
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
static void A() {

	printf("==============================================================================\n");
	printf("A - File Exists\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  There is no built-in function to test if a file exists.\n");
	printf("  There are several methods used to check.\n");
	printf("  The code here uses fopen in this user-defined function.\n");
	printf("\n");
	printf("  static Boolean FileExists(char* filename) {\n");
	printf("    FILE* pFile;\n");
	printf("    pFile = fopen(filename, \"r\");\n");
	printf("    if (pFile != NULL) {\n");
	printf("      fclose(pFile);\n");
	printf("      return True;\n");
	printf("    } else\n");
	printf("      return False;\n");
	printf("  }\n");
	printf("\n");
	
	printf("Enter a filename: ");
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", &Inputs);
	printf("\n");
	if (FileExists(Inputs))
		printf("The code says the file exists.\n");
	else 
		printf("The code says the file does not exist.\n");

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void B() {

	printf("==============================================================================\n");
	printf("B - Rename\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("int rename (const char* oldname, const char* newname);\n");
	printf("\n");
	printf("Returns: non-zero int for failure, zero for success\n");
	printf("\n");
	printf("\n");
	
	char Path[] = "C:\\Users\\Guest\\";
	printf("Using path: %s\n", Path);

	char OldFilename[MAX_FILENAME_CHARS];
	strcpy(OldFilename, Path);
	
	char Inputs[MAX_INPUT_CHARS];
	printf("Enter a filename to rename: ");
	scanf("%s", &Inputs);
	strcat(OldFilename, Inputs);
	printf("File to rename: %s\n", OldFilename);
	printf("\n");

	if (FileExists(OldFilename)) {
		char NewFilename[MAX_FILENAME_CHARS];
		strcpy(NewFilename, Path);
		printf("Enter new name: ");
		scanf("%s", &Inputs);
		strcat(NewFilename, Inputs);
		printf("New name: %s\n", NewFilename);
		printf("\n");

		// Can write as one line but not as readable (IMO).
		// if (rename(OldFilename, NewFilename) != 0) 
		int result = rename(OldFilename, NewFilename);
		if (result != 0) 
			printf("Problem renaming the file.");
		else
			printf("%s renamed to %s\n", OldFilename, NewFilename);
		printf("\n");
	} else
		printf("File not found. Cannot rename.\n");

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void C() {
	
	printf("==============================================================================\n");
	printf("C - Remove\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("int remove(const char* filename);\n");
	printf("\n");
	printf("Returns: non-zero int for failure, zero for success\n");
	printf("\n");

	printf("Enter name of file to delete: ");
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", &Inputs);
	char Filename[MAX_FILENAME_CHARS];
	strcpy(Filename, "C:\\Users\\Guest\\");
	strcat(Filename, Inputs);
	// No need to check if the file exists, the function remove deals with that.
	int result = remove(Filename);
	if (result !=0) 
		printf("Problem trying to delete the file.\n");
	else
		printf("The computer deleted the file: %s\n", Filename);
	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void D() {
		
	printf("==============================================================================\n");
	printf("D - Temporary Files\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("char* tmpnam(char* filename);\n");
	printf("\n");
	printf("Returns: \n");
	printf("1. A filename on success.\n");
	printf("2. Null on failure.\n");
	printf("\n");
	printf("Method 1 - Return filename to char array\n");
	printf("------------------------------------------------------------------------------\n");
	char* TempFile = tmpnam(NULL);
	printf("Using char* TempFile = tmpnam(NULL);\n");
	printf("\n");
	if (TempFile != NULL) 
		printf("TempFile is: %s\n", TempFile);
	else
		printf("Unable to create a temp filename.");
	printf("\n");

	printf("\n");
	printf("Method 2 - Pass char array to store filename\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Create char array with system max filename length of L_tmpnam\n");
	char TempFilename[L_tmpnam];
	printf("  char TempFilename[L_tmpnam];\n");
	printf("\n");
	printf("Call the function\n");
	printf("  tmpnam(TempFilename);\n");
	printf("\n");
	tmpnam(TempFilename);
	if (TempFilename!= NULL) 
		printf("TempFilename is: %s\n", TempFilename);
	else
		printf("Unable to create a temp filename.");
	printf("\n");

	printf("Method 3 - Open a temp file\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Create and open a temporary file in wb+ mode. The filename is unique\n");
	printf("and it is deleted when the file is closed.\n");
	printf("\n");
	printf("FILE* tmpfile()\n");
	printf("\n");
	FILE* pFile;
	printf("Create file pointer: FILE* pFile;\n");
	pFile = tmpfile();
	printf("Call the function to open temp file: pFile = tmpfile();\n");
	printf("\n");
	FILE* pFile2 = tmpfile();
	printf("Done in one line: FILE* pFile2 = tmpfile();\n");
	printf("\n");
	fclose(pFile);
	fclose(pFile2);

	printf("Close the file: pclose(pFile)\n");
	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}


static void E() {
			
	printf("==============================================================================\n");
	printf("E - Open and Close File\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Open\n");
	printf("------------------------------------------------------------------------------\n");
	printf("FILE * fopen(const char* filename, const char* mode)\n");
	printf("\n");
	printf("filename is a text string with full path and name\n");
	printf("\n");
	printf("returns pointer to file or null if open failed\n");
	printf("\n");
	printf("| Modes                                     | Existing File   | No File      |\n");
	printf("------------------------------------------------------------------------------\n");
	printf("| \"r\"  Open file for reading.               | Read from start | Null ptr     |\n");
	printf("| \"w\"  Create a file for writing.           | Overwrites      | Creates file | \n");
	printf("| \"a\"  Append to file.                      | Append          | Creates file | \n");
	printf("| \"r+\" Open for read and write.             | Read from start | Null ptr     |\n");
	printf("| \"w+\" Create for read and write.           | Overwrites      | Creates file | \n");
	printf("| \"a+\" Open for read and write.             | Append          | Creates file | \n");
	printf("------------------------------------------------------------------------------\n");
	printf("For windows, add 'b' to mode for binary files (e.g., \"rb\").\n");
	printf("\n");
	printf("Close\n");
	printf("------------------------------------------------------------------------------\n");
	printf("int fclose(FILE* stream)\n");
	printf("\n");
	printf("Example: fclose(ptrToFile);\n");
	printf("\n");
	printf("Returns 0 on success, EOF on failure.\n");
	printf("\n");
	printf("I haven't seen any testing on call to close function.\n");
	printf("\n");
	printf("Reopen\n");
	printf("------------------------------------------------------------------------------\n");
	printf("FILE* freopen(const char* filename, const char* mode, FILE* stream)\n");
	printf("\n");
	printf("See above on filename and mode. The stream argument is an existing pointer.\n");
	printf("\n");
	printf("It's possible to use this to printf output to file instead of stdout,\n");
	printf("but once set, I can't close it and get regular stdout. Not sure how to do that,\n");
	printf("yet you should be able to do so.\n");
	printf("\n");
	
	//char Path[] = "C:\\Users\\Guest\\stdout.txt";
	//if (freopen(Path, "w", stdout) == 0 ) {
	//	printf("Printing to file instead of stdout.");
	//	fclose(stdout);
	//} else
	//	printf("Problem reopening stdout as file.\n");

	printf("==============================================================================\n");
	system("pause");

}

static void F() {

}

static void G() {

}

static void H() {

}

static void I() {

}

static void J() {

}

static void K() {

}
