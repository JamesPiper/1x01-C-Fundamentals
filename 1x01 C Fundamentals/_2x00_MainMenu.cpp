/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.12
// File        : _2x00_MainMenu.cpp
// Description : Terminal style main menu for user.
//             : Starting point for the user.
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
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _2x00_MainMenu() {

	char Choice;

	do 
	{
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Basic C Code                                                             *\n");
		printf("*   Main Menu                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   0 - Print Hello World                                                    *\n");
		printf("*   A - Keywords                          H - Dynamic Memory Allocation      *\n");
		printf("*   B - Header Files                      I - String Manipulations           *\n");
		printf("*   C - Control Statements                J - Data Structures                *\n");
		printf("*   D - Operators                         K - User-defined Functions         *\n");
		printf("*   E - Char Mapping Table                                                   *\n");
		printf("*   F - Data Types                                                           *\n");
		printf("*   G - Standard I/O                                                         *\n");
		printf("*                                                                            *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("Enter choice: ");

		/////////////////////////////////////////////////////////////////////////////////////
		// Change to use GetUserInputs
		char Inputs[MAX_INPUT_CHARS];
		// 2 represents 1 char of input and null terminator.
		GetUserInputs(Inputs, CHOICE_LENGTH);
		//scanf("%s", &Inputs);
		Choice = tolower(Inputs[0]);
		/////////////////////////////////////////////////////////////////////////////////////
		printf("\n");

		if (Choice == '0') 
			_3x00_Hello_World();
		if (Choice == 'a')
			_3x01_Keywords();
		else if (Choice == 'b')
			_3x02_HeaderFiles();
		else if (Choice == 'c')
			_3x03_ControlStatements();
		else if (Choice == 'd')
			_3x04_Operators();
		else if (Choice == 'e')
			_3x05_CharMapping();
		else if (Choice == 'f') 
			_3x06_DataTypes();
		else if (Choice == 'g') 
			_3x0A_IOTests();
		else if (Choice == 'h') 
			_3x07_DynamicMemoryAllocation();
		else if (Choice == 'i')
			_3x08_StringManipulations();
		else if (Choice == 'j')
			_3x09_DataStructures();
		else if (Choice == 'k')
			_3x0B_User_Defined_Functions();
		else if (Choice == 'l')
			Choice = 'l';
		else if (Choice == 'm') 
			Choice = 'm';
		else if (Choice == 'n')
			Choice = 'n';
		else if (Choice == 'o')
			Choice = 'o';
		else if (Choice == 'p') 
			Choice = 'p';
		else if (Choice == 'q') 
			Choice = 'q';
		else if (Choice == 'r')
			Choice = 'r';
		//else if (Choice == 'x') 
		//	return;

	} while (Choice != 'x'); 

}
