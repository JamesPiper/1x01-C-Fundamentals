//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Terminal style menu.
// Branchs to displaying information
// or will present a submenu.
// 
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#include <cstdio>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

void _2x00_MainMenu() {

	char Inputs[MAX_INPUT_CHARS];
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
		printf("*   A - Keywords                                B - Header Files             *\n");
		printf("*   C - Control Statements                      D - Operators                *\n");
		printf("*   E - Char Mapping Table                      F - Data Types               *\n");
		printf("*                                                                            *\n");
		printf("*   G - Dynamic Memory Allocation               H - String Manipulations     *\n");
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

		strupr(Inputs);
		Choice = Inputs[0];
		printf("\n");

		if (Choice == '0') 
			_3x00_Hello_World();
		if (Choice == 'A')
			_3x01_Keywords();
		else if (Choice == 'B')
			_3x02_HeaderFiles();
		else if (Choice == 'C')
			_3x03_ControlStatements();
		else if (Choice == 'D')
			_3x04_Operators();
		else if (Choice == 'E')
			_3x05_CharMapping();
		else if (Choice == 'F') 
			_3x06_DataTypes();
		else if (Choice == 'G') 
			_3x07_DynamicMemoryAllocation();
		else if (Choice == 'H') 
			_3x08_StringManipulations();
		else if (Choice == 'I')
			Choice = 'I';
		else if (Choice == 'J')
			Choice = 'j';
		else if (Choice == 'K')
			Choice = 'k';
		else if (Choice == 'L')
			Choice = 'l';
		else if (Choice == 'M') 
			Choice = 'm';
		else if (Choice == 'N')
			Choice = 'n';
		else if (Choice == 'O')
			Choice = 'o';
		else if (Choice == 'P') 
			Choice = 'p';
		else if (Choice == 'Q') 
			Choice = 'Q';
		else if (Choice == 'R')
			_0x11_DataStructures();
		else if (Choice == 'X') 
			return;

	} while (Choice != 'X'); 

}
