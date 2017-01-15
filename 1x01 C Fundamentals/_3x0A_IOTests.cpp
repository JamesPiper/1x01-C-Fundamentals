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

// Function prototypes.
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

static Boolean FileExists(const char* filename);


void _3x0A_IOTests() {

	char Inputs[MAX_INPUT_CHARS];
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
		printf("*   D - Temp Filename                                                        *\n");
		printf("*   E -                                                                      *\n");
		printf("*   F -                                                                      *\n");
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
			A();
		else if (Choice == 'b')
			B();
		else if (Choice == 'c') 
			C();
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
	printf("    }\n");
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
	printf("int rename ( const char * oldname, const char * newname );\n");
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
	printf("int remove ( const char * filename );\n");
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
	printf("D - Temp Filename\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("char * tmpnam ( char * str );\n");
	printf("\n");
	printf("Returns:  \n");
	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}


static void E() {

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

static Boolean FileExists(const char* filename) {

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
