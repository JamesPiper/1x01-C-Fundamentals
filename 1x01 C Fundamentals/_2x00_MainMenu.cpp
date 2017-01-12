//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Terminal style menu.
// Branchs to displaying information
// or will present a submenu.
// 
//==============================================================================

#include "stdafx.h"
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS

#include "1x01 C Fundamentals.h"

void _2x00_MainMenu() {

	char Inputs[80];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Basic C/C++ Code                                                         *\n");
		printf("*   Main Menu                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   0 - Print Hello World                                                    *\n");
		printf("*   A - Keywords                                B - Header Files             *\n");
		printf("*   C - Control Statements                      D - Operators                *\n");
		printf("*   E - Char Mapping Table                      F - Data Types               *\n");

		printf("*   N - Dynamic Memory Allocation                                            *\n");
		printf("*   O - String Manipulations                                                 *\n");
		printf("*                                                                            *\n");
		printf("*   R - Data Structures                                                      *\n");
		printf("*                                                                            *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("\n");
		printf("Enter choice: ");

		// Input user action.
		// Because of buffering, getchar or getc processes hold more than one character.
		// Use scanf because less chance of problems.
		// Using "%c" causes the loop to process for each char enter, need "%s"
		// MS wants me to use scanf_s instead of scanf b/c of buffer overflow.
		scanf("%s", &Inputs);

		Choice = Inputs[0];
		printf("\n");

		if (Choice == '0') 
			_3x00_Hello_World();
		if (Choice == 'A' || Choice == 'a')
			_3x01_Keywords();
		else if (Choice == 'B' || Choice == 'b')
			_3x02_HeaderFiles();
		else if (Choice == 'C' || Choice == 'c')
			_3x03_ControlStatements();
		else if (Choice == 'D' || Choice == 'd')
			_3x04_Operators();
		else if (Choice == 'E' || Choice == 'e')
			_3x05_CharMapping();
		else if (Choice == 'F' || Choice == 'f') 
			_3x06_DataTypes();
		else if (Choice == 'G' || Choice == 'g') 
			Choice = 'g';
		else if (Choice == 'H' || Choice == 'h') 
			Choice = 'h';
		else if (Choice == 'I' || Choice == 'i')
			Choice = 'I';
		else if (Choice == 'J' || Choice == 'j')
			Choice = 'j';
		else if (Choice == 'K' || Choice == 'k')
			Choice = 'k';
		else if (Choice == 'L' || Choice == 'l')
			Choice = 'l';
		else if (Choice == 'M' || Choice == 'm') 
			Choice = 'm';
		else if (Choice == 'N' || Choice == 'n')
			_0x0D_DynamicMemoryAllocation();
		else if (Choice == 'O' || Choice == 'o')
			_0x0E_StringManipulations();
		else if (Choice == 'P' || Choice == 'p') 
			Choice = 'p';
		else if (Choice == 'Q' || Choice == 'q') 
			Choice = 'Q';
		else if (Choice == 'R' || Choice == 'r')
			_0x11_DataStructures();
		else if (Choice == 'X' || Choice == 'x') 
			return;

	} while (Choice != 'X' && Choice != 'x'); 

}
