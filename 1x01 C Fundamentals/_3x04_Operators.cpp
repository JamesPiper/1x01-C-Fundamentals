//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Summary of operators
// 
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>


// Function prototypes
static void A();
static void B();
static void C();
static void D();
static void E();
static void F();
static void G();
static void H();

void _3x04_Operators() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   Operators                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Mathematical Operators                                               *\n");
		printf("*   B - Unary Increment Operators                                            *\n");
		printf("*   C - Relational Operators                                                 *\n");
		printf("*   D - Logical Operators                                                    *\n");
		printf("*   E - Bitwise Operators                                                    *\n");
		printf("*   F - Other Assignment Operators                                           *\n");
		printf("*   G - Bitwise Operators Examples                                           *\n");
		printf("*   H - Other Assignment Operators Examples                                  *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return to main menu.                                                 *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("\n");
		printf("Enter choice: ");

		scanf("%s", &Inputs);

		strupr(Inputs);
		Choice = Inputs[0];
		printf("\n");

		if (Choice == 'A')
			A();
		else if (Choice == 'B')
			B();
		else if (Choice == 'C')
			C();
		else if (Choice == 'D')
			D();
		else if (Choice == 'E')
			E();
		else if (Choice == 'F')
			F();
		else if (Choice == 'G')
			G();
		else if (Choice == 'H')
			H();
		else if (Choice == 'X') 
			exit(0);
		else if (Choice == 'Z') 
			return;

		system("pause");

	} while (Choice != 'X'); 

}

static void A() {
		
	printf("==============================================================================\n");
	printf("Mathematical Operators\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  + addition\n");
	printf("  - subtraction\n");
	printf("  / division\n");
	printf("  * multiplication \n");
	printf("\n");
	printf("==============================================================================\n");

}

static void B() {
	
	printf("==============================================================================\n");
	printf("Unary Increment Operators\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  ++ or --\n");
	printf("  var++ postfix addition\n");
	printf("  ++var prefix addition\n");
	printf("  var-- postfix negation\n");
	printf("  --var prefix negation\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void C() {
	
	printf("==============================================================================\n");
	printf("Relational Operators\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  == equals   (avoid using single = )\n");
	printf("  != not equal\n");
	printf("  >  greater than\n");
	printf("  <  less than\n");
	printf("  >= greater than or equal\n");
	printf("  <= less than or equal \n");
	printf("\n");
	printf("==============================================================================\n");
}

static void D() {
	
	printf("==============================================================================\n");
	printf("Logical Operators\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  !  boolean not\n");
	printf("  && boolean and\n");
	printf("  || boolean or\n");
	printf("\n");
	printf("==============================================================================\n");
}

static void E() {
	
	printf("==============================================================================\n");
	printf("Bitwise Operators\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  ~ bitwise negation\n");
	printf("  & bitwise and\n");
	printf("  | bitwise or\n");
	printf("  ^ bitwise xor\n");
	printf("  >> Right Shift by right hand side (RHS) (divide by power of 2\n");
	printf("  << Left Shift by RHS (multiply by power of 2) \n");
	printf("\n");
	printf("==============================================================================\n");
}

static void F() {
	
	printf("==============================================================================\n");
	printf("Other Assignment Operators\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  +=, -= Increment or decrement by RHS\n");
	printf("  *=, /= Multiply or divide by RHS\n");
	printf("  %%= Mod by RHS\n");
	printf("  >>= Bitwise right shift by RHS (divide by power of 2)\n");
	printf("  <<= Bitwise left shift RHS (multiply by power of 2)\n");
	printf("  &=, |=, ^= Bitwise and, or, xor by RHS\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void G() {

	printf("==============================================================================\n");
	printf("Bitwise Operators Examples\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("~ bitwise negation\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	int example = 0xffff;
	printf("  int example = 0xffff = %X\n", example);
	example = ~example;
	printf("  example = ~example = %X\n", example);
	printf("\n");
	printf("\n");
	printf("& bitwise and\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0xF0F0;
	printf("  example = 0xF0F0 = %X\n", example);
	example = example & 0x0F0F;
	printf("  example = example & 0x0F0F = %X\n", example);
	printf("\n");
	printf("| bitwise or\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0x9999;
	printf("  example = 0x9999 = %X (0x9 = 1001)\n", example);
	example = example | 0x6666;
	printf("  example = example | 0x6666 = %X (0x6 = 0110)\n", example);
	printf("\n");
	printf("^ bitwise xor\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0xF;
	printf("  example = 0xF = %X\n", example);
	example = example ^ 0x9;
	printf("  example = example ^ 0x9 = %X  (0x9 = 1001) (0x6 = 0110)\n", example);
	printf("\n");
	printf("\n");
	printf(">> Right Shift by right hand side (RHS) (divide by power of 2)\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0x8;
	printf("  example = 0x8 = %X\n", example);
	example = example >> 1;
	printf("  example = example >> 1 = %X\n", example);
	example = example >> 1;
	printf("  example = example >> 1 = %X\n", example);
	example = example >> 1;
	printf("  example = example >> 1 = %X\n", example);
	example = example >> 1;
	printf("  example = example >> 1 = %X\n", example);
	printf("\n");
	printf("\n");
	printf("<< Left Shift by RHS (multiply by power of 2)\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0x1;
	printf("  example = 0x1 = %X\n", example);
	example = example << 1;
	printf("  example = example << 1 = %X\n", example);
	example = example << 1;
	printf("  example = example << 1 = %X\n", example);
	printf("\n");
	printf("==============================================================================\n");

}

static void H() {
	
	printf("==============================================================================\n");
	printf("Other Assignment Operator Examples\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("+=, -= Increment or decrement by RHS\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	int example = 10;
	printf("  int example = 10 = %d\n", example);
	example += 10;
	printf("  example += 10 = %d\n", example);
	printf("\n");
	printf("*=, /= Multiply or divide by RHS\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 10;
	printf("  example = 10 = %d\n", example);
	example *= 10;
	printf("  example *= 10 = %d\n", example);
	printf("\n");
	printf("%%= Mod by RHS\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 10;
	printf("  example = 10 = %d\n", example);
	example %= 3;
	printf("  example %%= 3 = %d\n", example);
	printf("\n");
	printf(">>= Bitwise right shift by RHS (divide by power of 2)\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0xF;
	printf("  example = 0xF = %X (F = 1111)\n", example);
	example >>= 1;
	printf("  example >>= 1 = %X (7 = 0111)\n", example);
	printf("\n");
	printf("<<= Bitwise left shift RHS (multiply by power of 2)\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	example = 0x7;
	printf("  example = 0x7 = %X (7 = 0111)\n", example);
	example <<= 1;
	printf("  example <<= 1 = %X (E = 1110)\n", example);
	printf("\n");
	printf("&=, |=, ^= Bitwise and, or, xor by RHS\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("==============================================================================\n");

}