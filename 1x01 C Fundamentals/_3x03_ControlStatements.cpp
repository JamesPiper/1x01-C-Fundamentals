/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.12
// File        : _3x03_ControlStatements.cpp
// Description : Summary of control statements used in C.
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
void _3x03_ControlStatements() {

	printf("==============================================================================\n");
	printf("Control Statements\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("1. If Statement\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   (a) one line following if and optional else, {} not used\n");
	printf("   (b) multi-line following if and optional else, {} used\n");
	printf("\n");
	printf("2. Conditional Expression OR The Ternary Operator\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   <expression1> ? <expression2> : <expression3>\n");
	printf("\n");
	printf("3. Switch Statement\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   switch (<expression>) {\n");
	printf("     case <const-expression-1>:\n");
	printf("        <statement>\n");
	printf("        break; \n");
	printf("     default: \n");
	printf("   }\n");
	printf("\n");
	printf("4. While Loop\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   while (<expression>) {\n");
	printf("     <statement>\n");
	printf("   }\n");
	printf("\n");
	printf("5. Do-While Loop\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   Do {\n");
	printf("     <statement>\n");
	printf("   } while (<expression>); {\n");
	printf("\n");
	printf("6. For Loop\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   for (<initialization>; <continuation>; <action>) {\n");
	printf("     <statement>\n");
	printf("   }\n");
	printf("\n");
	printf("7. Break\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   The break statement will move control outside a loop or switch statement.\n");
	printf("\n");
	printf("8. Continue\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   The continue statement causes control to jump to the bottom of the loop,\n");
	printf("   effectively skipping over any code below the continue.\n");
	printf("\n");
	printf("\n");
	printf("==============================================================================\n");
	system("Pause");

}
