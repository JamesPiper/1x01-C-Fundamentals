//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
// 
// Covering the various built in data types and derived types
// 
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>
#define MAX_0A 2

// Function prototypes
static void A();
static void B();
static void C();
static void D();
static void E();
static void F0();
static void F1();
static void F2();
static void F3();
static void F4();
static void F5();
static void F6();
static void Display_1(int age);
static void Display_2(int *age);
static float average(float *age);
static void G();
static void H();
static void I();
static void J();
static void K();
static void L();

void _3x06_DataTypes() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   DataTypes                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   Fundamental Types                                                        *\n");
		printf("*   A - Integer                                                              *\n");
		printf("*   B - Floating Point                                                       *\n");
		printf("*   C - Character                                                            *\n");
		printf("*                                                                            *\n");
		printf("*   Devrived Types                                                           *\n");
		printf("*   D - Arrays                                                               *\n");
		printf("*   E - Pointers                                                             *\n");
		printf("*   F - Structures                                                           *\n");
		printf("*   G - Enums                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   More                                                                     *\n");
		printf("*   H - Booleans                                                             *\n");
		printf("*   I - Sizeof                                                               *\n");
		printf("*   J - Pass Arrays To Functions                                             *\n");
		printf("*   K - Pointers & Arrays                                                    *\n");
		printf("*   L - Typedef and Structures                                               *\n");
		printf("*                                                                            *\n");
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
			F0();
		else if (Choice == 'G')
			G();
		else if (Choice == 'H')
			H();
		else if (Choice == 'I')
			I();
		else if (Choice == 'J')
			J();
		else if (Choice == 'K')
			K();
		else if (Choice == 'L')
			L();
		else if (Choice == 'X') 
			exit(0);
		else if (Choice == 'Z') 
			return;

		system("pause");

	} while (Choice != 'X'); 

}

static void A() {

	printf("==============================================================================\n");
	printf("short data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("16 bit integer [-32768 to 32767] (2 ^ 16 = 65536)\n");
	printf("\n");
	short MyShort = (short)((pow(2, 16) / -2.0));
	printf("short MyShort = (short)((pow(2, 16) / -2.0) - 1.0) = %hi\n", MyShort);
	MyShort = (short)((pow(2, 16) / 2.0) - 1.0);
	printf("short MyShort = (short)((pow(2, 16) / 2.0) - 1.0) = %hi\n", MyShort);
	printf("\n");
	printf("also short int | signed short | signed short int\n");
	short int MyShort2 = 32767;
	signed short MyShort3 = 32767;
	signed short int MyShort4 = 32767;
	printf("also unsigned short | unsigned short int\n");
	unsigned short MyShort5 = 32767;
	unsigned short int MyShort6 = 32767;
	printf("\n");
	printf("Format Specifier: %%hi or %%hu\n");
	printf("MyShort: %hi\n", MyShort);
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");
	system("pause");

	printf("==============================================================================\n");
	printf("int data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("32 bit integer [-2,147,483,648, 2,147,483,647] (2 ^ 32 = 4,294,967,296)\n");
	printf("\n");
	int MyInt = (int)((pow(2, 32) / -2.0) - 1.0);
	printf("int MyInt = (int)((pow(2, 32) / -2.0) - 1.0) = %i\n", MyInt);
	MyInt = (int)((pow(2, 32) / 2.0) - 1.0);
	printf("int MyInt = (int)((pow(2, 32) / 2.0) - 1.0) = %i\n", MyInt);
	printf("\n");
	printf("also signed | signed int\n");
	signed MyInt2 = 2147483647;
	signed int MyInt3 = 2147483647;
	printf("also unsigned | unsigned int\n");
	unsigned MyInt4 = 2147483647;
	unsigned int MyInt5 = 2147483647;
	printf("\n");
	printf("Format Specifier: %%i or %%d, %%u\n");
	printf("MyInt: %i\n", MyInt);
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");
	system("pause");
	
	printf("==============================================================================\n");
	printf("long data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("32 bit integer [-2,147,483,648, 2,147,483,647] (2 ^ 32 = 4,294,967,296)\n");
	printf("\n");
	long MyLong = (long)((pow(2, 32) / -2.0) - 1.0);
	printf("long MyLong = (long)((pow(2, 32) / -2.0) - 1.0) = %li\n", MyLong);
	MyLong = (long)((pow(2, 32) / 2.0) - 1.0);
	printf("long MyLong = (long)((pow(2, 32) / 2.0) - 1.0) = %li\n", MyLong);
	printf("\n");
	printf("also long int | signed long | signed long int\n");
	long int MyLong2 = 2147483647;
	signed long MyLong3 = 2147483647;
	signed long int MyLong4 = 2147483647;
	printf("also unsigned long | unsigned long int\n");
	unsigned long MyLong5 = 2147483647;
	unsigned long int MyLong6 = 2147483647;
	printf("\n");
	printf("Format Specifier: %%li, %%lu\n");
	printf("MyLong2: %li\n", MyLong2);
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");
	system("pause");

	printf("==============================================================================\n");
	printf("long long data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("64 bit integer [-9,223,372,036,854,775,808, 9,223,372,036,854,775,807]\n");
	printf("(2 ^ 64 = 18,446,744,073,709,551,616)\n");
	printf("\n");
	long long MyLongLong= (long long)((pow(2, 64) / -2.0) - 1.0);
	printf("long long MyLongLong = (long long)((pow(2, 64) / -2.0) - 1.0)\n = %lli\n", MyLongLong);
	MyLongLong = (long long)((pow(2, 64) / 2.0) - 1.0);
	printf("long MyLong = (long long)((pow(2, 64) / 2.0) - 1.0)\n = %lli\n", MyLongLong);
	printf("**Not sure why it's wrapping around.**\n");
	printf("\n");
	printf("also long long int | signed long long | signed long long int\n");
	long long int MyLongLong2 = 9223372036854775807;
	signed long long MyLongLong3 = 9223372036854775807;
	signed long long int MyLongLong4 = 9223372036854775807;
	printf("also unsigned long long | unsigned long long int\n");
	unsigned long long MyLongLong5 = 9223372036854775807;
	unsigned long long int MyLongLong6 = 9223372036854775807;
	printf("\n");
	printf("Format Specifier: %%lli, %%llu\n");
	printf("MyLongLong2: %lli\n", MyLongLong2);
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");

}

static void B() {

	printf("==============================================================================\n");
	printf("float data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("4 byte (32 bit) single precision floating point\n");
	printf("\n");
	float MyFloat = 123465.789123F;
	printf("float MyFloat = 123465.789123F; or %f\n", MyFloat);
	printf("This is some loss of data.\n");
	printf("\n");
	printf("Format Specifier: %%f (case sensitive)\n");
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");

	system("pause");
	
	printf("==============================================================================\n");
	printf("double data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("8 byte (64 bit) double precision floating point\n");
	printf("\n");
	double MyDouble = 123465.789123;
	printf("double MyDouble = 123465.789123; or %f\n", MyDouble);
	printf("No data loss.\n");
	printf("\n");
	printf("Format Specifier: %%f, %%G, %%g, %%E, %%e  \n");
	printf("\n");
	printf("With %%F %F\n", MyDouble);
	printf("With %%f %f\n", MyDouble);
	printf("\n");
	printf("With %%G %G\n", MyDouble);
	printf("With %%g %g\n", MyDouble);
	printf("\n");
	printf("With %%E %E\n", MyDouble);
	printf("With %%e %e\n", MyDouble);
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");

}

static void C() {
	
	printf("==============================================================================\n");
	printf("char data type\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("min 8 bit, normally 16 bit\n");
	printf("\n");
	char MyChar1 = 'c';
	printf("char MyChar = 'c';\n");
	signed char MyChar2 = 'c';
	printf("signed char MyChar = 'c';\n");
	unsigned char MyChar3 = 'c';
	printf("unsigned char MyChar = 'c';\n");
	printf("\n");
	printf("Format Specifier: %%c\n");
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");

}

static void D() {

	int MyArray1[10];
	int MyArray2[10] = {1, 2, 3};
	int MyArray3[10];
	int MyArray4[] = {1, 2, 3};

	char MyString[] = "This is a test";
	
	int MyMultiRowArray1[10][10];
	int MultiRow[10][10] = {{0,1,2,3,4,5,6,7,8,9}, {10,11,12,13,14,15,16,17,18,19}};

	printf("==============================================================================\n");
	printf("Arrays\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Single Dimensional Arrays\n");
	printf("------------------------------------------------------------------------------\n");
	printf("These don't work.\n");
	printf("  int MyArray[];\n");
	printf("  int MyArray[] = (9, 2, 8);\n");
	printf("  char MyString[] = \"This is a test\";\n");
	printf("\n");
	printf("These work.\n");
	printf("  int MyArray[10];\n");
	printf("  int MyArray[] = {1, 2, 3};\n");
	printf("  int MyArray[10] = {1, 2, 3};\n");
	printf("\n");
	printf("Assign or access: MyArray[0]...MyArray[9]\n");
	printf("0 to 9 is 10 elements\n");
	printf("\n");
	printf("Multidimensional Arrays\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Create one\n");
	printf("  int MyMultiRowArray1[10][10];\n");
	printf("\n");
	printf("Assign or access: MyMultiRowArray1[0][0]...MyMultiRowArray1[9][9]\n");
	printf("Syntax: var[row][col]\n");
	printf("\n");
	printf("Create one\n");
	printf("  MultiRow[10][10] = {{0,1,2,3,4,5,6,7,8,9}, {10,11,12,13,14,15,16,17,18,19}};\n");
	printf("  {0..9} is row [0] of cols[0..9]\n");
	printf("  {10..19} is row [1] of cols[0..9]\n");
	printf("\n");
	printf("   MultiRow[1][5] = %d - that's row 1, column 5\n", MultiRow[1][5]);
	printf("\n");
	printf("Array of Structs\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  struct fraction numbers[1000];\n");
	printf("  numbers[0].numerator = 22;\n");
	printf("\n");	
	printf("==============================================================================\n");

}

static void E() {
	
	printf("==============================================================================\n");
	printf("Pointers\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Syntactically C uses the asterisk (*) to indicate a pointer.\n");
	printf("------------------------------------------------------------------------------\n");
	printf("A char* is type of pointer which refers to a single char.\n");
	printf(" char* charPtr; // declares a character pointer\n");
	printf("\n");
	printf("Same for int*\n");
	printf("------------------------------------------------------------------------------\n");
	printf(" int* intPtr; // declare an integer pointer variable intPtr\n");
	printf("\n");
	printf("These are all the same:\n");
	printf("------------------------------------------------------------------------------\n");
	printf(" char* charPtr1;\n");
	printf(" char * charPtr1;\n");
	printf(" char  *charPtr1;\n");
	printf("\n");
	printf("Pointer Dereferencing:\n");
	printf("------------------------------------------------------------------------------\n");
	printf(" The pointer points to memory of the appropriate type\n");
	printf(" In an expression, the unary * to the left of a pointer dereferences it\n");
	printf(" to retrieve the value it points to.\n");
	printf("\n");
	printf("Example 1: Using & to Get Address of Variable\n");
	printf("------------------------------------------------------------------------------\n");
	int MyInt = 10;
	printf(" int MyInt = 10;\n");
	printf(" Value: %d\n", MyInt);
	printf(" Address: %X\n", &MyInt);
	printf("\n");
	printf("Example 2: Dereference pointer\n");
	printf("------------------------------------------------------------------------------\n");
	int* pMyInt;
	printf(" int* pMyInt; value = random data at this point\n");
	pMyInt = &MyInt;
	printf(" pMyInt = &MyInt; value = %X - now address of MyInt\n", pMyInt);
	printf(" Dereference pointer to get value. Value = %d using *pMyInt\n", *pMyInt);
	printf("\n");
	MyInt += 100;
	printf(" MyInt += 100; - increase value of variable, now %d\n", MyInt);
	printf(" Now using the pointer, *pMyInt, points to new value, %d\n", *pMyInt);
	printf("\n");
	*pMyInt = *pMyInt * 2;
	printf(" *pMyInt = *pMyInt * 2; Directly change the value with pointer.\n");
	printf(" MyInt is now %d\n", MyInt);
	printf("\n");
	printf("==============================================================================\n");

}


struct fractionA {
	int numerator;
	int denominator;
};

struct fractionB { int numerator; int denominator; };

static void F0() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;
	
	do 
	{
		printf("******************************************************************************\n");
		printf("*   Structures                                                               *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Define a used-defined structure                                      *\n");
		printf("*   B - Declare                                                              *\n");
		printf("*   C - Set Values                                                           *\n");
		printf("*   D - Access Values                                                        *\n");
		printf("*   E - Define and Declare                                                   *\n");
		printf("*   F - Structures Within Structures                                         *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return to previous menu.                                             *\n");
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
			F1();
		else if (Choice == 'B')
			F2();
		else if (Choice == 'C')
			F3();
		else if (Choice == 'D')
			F4();
		else if (Choice == 'E')
			F5();
		else if (Choice == 'F')
			F6();
		else if (Choice == 'X') 
			exit(0);
		else if (Choice == 'Z') 
			return;

		system("pause");

	} while (Choice != 'X'); 

	}

static void F1() {

	struct fractionA f1;
	f1.numerator = 22;
	f1.denominator = 7;

	printf("==============================================================================\n");
	printf("Define a used-defined structure\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  struct fractionA {\n");
	printf("    int numerator;\n");
	printf("    int denominator;\n");
	printf("  };\n");
	printf("\n");
	printf("  This also works - one line.\n");
	printf("\n");
	printf("    struct fractionB { int numerator; int denominator; };\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void F2() {
	
	struct fractionA f1;
	f1.numerator = 22;
	f1.denominator = 7;

	printf("==============================================================================\n");
	printf("Declare\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Declaration introduces the type struct fractionA (both words are required)\n");
	printf("as a new type.\n");
	printf("\n");
	printf("   struct fractionA f1, f2;\n");
	printf("\n");
	printf("==============================================================================\n");

	}

static void F3() {
	
	printf("==============================================================================\n");
	printf("Set Values\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("C uses the period (.) to access the fields in a record.\n");
	printf("\n");
	printf("   structure_variable_name.member_name\n");
	printf("\n");
	printf("   f1.numerator = 22;\n");
	printf("   f1.denominator = 7;\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void F4() {
	
	struct fractionA f1;
	f1.numerator = 22;
	f1.denominator = 7;

	printf("==============================================================================\n");
	printf("Access Values\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("   printf(\"f1.numerator = %%d\\n\", f1.numerator\n");
	printf("   printf(\"f1.denominator = %%d\\n\", f1.denominator\n");
	printf("\n");
	printf("   f1.numerator =  %d\n", f1.numerator);
	printf("   f1.denominator = %d\n", f1.denominator);
	printf("\n");
	printf("==============================================================================\n");

}

static void F5() {
	
	static struct fractionC {
		int numerator;
		int denominator;
	} fC1, fC2;

	fC1.numerator = 0;
	fC2.numerator = 0;

	printf("==============================================================================\n");
	printf("Define and Declare\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("  struct fractionC { int numerator; int denominator; } fC1, fC2;\n");
	printf("\n");
	printf("  This results in two variables, fC1 and fC2 of fractionC\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void F6() {
	
	struct name { 
		char* fname; 
		char* mname; 
		char* lname; 
	};

	struct person {
		struct name name;
		int age;
	} person1;

	person1.age = 20;
	person1.name.fname = "James";

	printf("==============================================================================\n");
	printf("Structures Within Structures\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Declaration\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  struture name {\n");
	printf("    char* fname;\n");
	printf("    char* mname;\n");
	printf("    char* lname;\n");
	printf("  } name1;\n");
	printf("\n");
	printf("  struct person {\n");
	printf("    struct name name;\n");
	printf("    int age;\n");
	printf("  } person1;\n");
	printf("\n");
	printf("Assign values:\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  person1.age = 20\n");
	printf("  person1.name.fname = \"James\";\n");
	printf("\n");
	printf("Access items:\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  Age: %d\n", person1.age);
	printf("  Name: %s\n", person1.name.fname);
	printf("\n");
	printf("==============================================================================\n");

}

static void G() {

	printf("==============================================================================\n");
	printf("Enumeration\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Basics\n");
	printf("------------------------------------------------------------------------------\n");
	printf("An enumeration is a user-defined data type that consists of integral constants. \n");
	printf("\n");
	printf("  enum flag { const1, const2, ..., constN };\n");
	printf("\n");
	printf("enum is a keyword\n");
	printf("\n");
	printf("By default, const1 = 0, const2 = 1 etc. but you can override the values used.\n");
	printf("\n");
	printf("  enum flag { const1 = 10, const2 = 11, ..., constN };\n");
	printf("\n");
	printf("Creating an enumerated type declaration\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	enum boolean { False, True, Quantum };
	printf("  enum boolean { False, True, Quantum };\n");
	boolean IsRunning = Quantum;
	printf("  Set a value to variable: boolean IsRunning = Quantum;\n");
	printf("  Integer value is %d. Can't use %%s to get text version.\n", IsRunning);
	printf("\n");
	printf("Using As Flags\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	enum customer {
		Savings = 1,  // 0000 0001
		Chequing = 2, // 0000 0010
		LineOfCr = 4, // 0000 0100
		Mortage = 8   // 0000 1000
	} ;
	printf("  enum customer { \n");
	printf("	Savings  = 1,  // 0000 0001\n");
	printf("	Chequing = 2,  // 0000 0010\n");
	printf("	LineOfCr = 4,  // 0000 0100\n");
	printf("	Mortage  = 8   // 0000 1000\n");
	printf("  }\n");
	printf("\n");
	int FirstCustomer = Savings | Chequing;
	printf("  Declare and set value: int FirstCustomer = Savings | Chequing; = %d\n", FirstCustomer);
	printf("\n");
	printf("  Does the customer have a line of credit? %s\n", FirstCustomer & LineOfCr ? "Yes" : "No");
	printf("  Got this with FirstCustomer & LineOfCr ? \"Yes\" : \"No\"\n");
	printf("\n");
	printf("  Savings? %s\n", FirstCustomer & Savings ? "Yes" : "No");
	printf("  Chequing? %s\n", FirstCustomer & Chequing ? "Yes" : "No");
	printf("  Mortage? %s\n", FirstCustomer & Mortage ? "Yes" : "No");
	printf("\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void H() {

	typedef enum Boolean { False, True} Boolean;

	printf("==============================================================================\n");
	printf("boolean\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("not part of C, but used in C++\n");
	bool IsUsed = False;
	printf("bool IsUsed = False;\n");
	printf("\n");
	printf("Format Specifier: %%d (but displays as digit)\n");
	printf("boolean value %d\n", IsUsed);
	printf("\n");
	printf("Format Specifier: %%s then IsUsed ? true : false\n");
	printf("boolean value %s\n", IsUsed ? "true": "false");
	printf("\n");	
	printf("create typedef in c\n");	
	printf("typedef enum Boolean { False, True} Boolean;\n");
	Boolean IsWorking = True;
	printf("boolean value %s\n", IsWorking ? "true": "false");
	printf("\n");
	printf("==============================================================================\n");
	printf("\n");

}

static void I() {

	printf("==============================================================================\n");
	printf("Sizeof\n");
	printf("==============================================================================\n");
	printf("\n");
	bool t = true;
	printf(" bool t = true; - sizeof is %d\n", sizeof(t));
	char a = 'a';
	printf(" char a = 'a'; - sizeof is %d\n", sizeof(a));
	short b = 100;
	printf(" short b = 100; - sizeof is %d\n", sizeof(b));
	int c = 100;
	printf(" int c = 100; - sizeof is %d\n", sizeof(c));
	long d = 100;
	printf(" long d = 100; - sizeof is %d\n", sizeof(d));
	long long e = 100;
	printf(" long long e = 100; - sizeof is %d\n", sizeof(e));
	float f = 100.00;
	printf(" float f = 100.00; - sizeof is %d\n", sizeof(f));
	double g = 100.00;
	printf(" double g = 100.00; - sizeof is %d\n", sizeof(g));
	printf("\n");
	printf("\n");
	bool* pt = NULL;
	printf(" bool* pt = NULL; - sizeof is %d\n", sizeof(pt));
	char* pa = NULL;
	printf(" char *pa = NULL; - sizeof is %d\n", sizeof(pa));
	int* pc = NULL;
	printf(" int* pc = NULL; - sizeof is %d\n", sizeof(pc));
	double* pg = NULL;
	printf(" double* pg = NULL; - sizeof is %d\n", sizeof(pg));
	printf("\n");
	printf("==============================================================================\n");

}

static void J() {

	int ageArray[] = { 2, 3, 4 };
	float age[] = { 23.4, 55, 22.6, 3, 40.5, 18 };

	printf("==============================================================================\n");
	printf("Pass Arrays To Functions\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Passing Element of a One-dimensional Array In Function\n");
	printf("------------------------------------------------------------------------------\n");
	printf(" set array: int ageArray[] = { 2, 3, 4 };\n");
	printf(" define function\n");
	printf("   void Display_1(int age)\n");
	printf("   {\n");
	printf("     printf(\"%%d\", age);\n");
	printf("   }\n");
	printf("\n");
	printf(" call the function\n");
	printf("   Display_1(ageArray[2]); returns 4\n");
	printf("   It's passing the array element value.\n");
	printf("\n");
	printf(" new function\n");
	printf("   void Display_2(int *age)\n");
	printf("   {\n");
	printf("     printf(\"%%d\", *age);\n");
	printf("   }\n");
	printf("\n");
	printf("   Display_2(ageArray + 2); returns 4\n");
	printf("   It's passing address to the array and dereferences in the function\n");
	printf("\n");
	printf("Passing an entire one-dimensional array to a function\n");
	printf("------------------------------------------------------------------------------\n");
	printf("   float average(float age[]) OR float average(float *age)\n");
	printf("   {\n");
	printf("     int i;\n");
	printf("     float sum = 0.0;\n");
	printf("     for (i = 0; i < 6; ++i) {\n");
	printf("       sum += age[i];\n");
	printf("     return (sum / 6);\n");
	printf("   }\n");
	printf("\n");
	printf("   float age[] = { 23.4, 55, 22.6, 3, 40.5, 18 };\n");
	printf("\n");
	printf("   call it: avg = average(age); the average is %0.2f\n", average(age));
	printf("   Using the variable 'age' passes the address for the array, pass by ref\n");
	printf("\n");
	printf("==============================================================================\n");

}

static void Display_1(int age)
{
    printf("%d", age);
}

static void Display_2(int *age)
{
    printf("%d", *age);
}

//float average(float age[])
static float average(float *age)
{
    int i;
    float sum = 0.0;
    for (i = 0; i < 6; ++i) {
        sum += age[i];
    }
    return (sum / 6);
}

static void K() {


	printf("==============================================================================\n");
	printf("Pointers & Arrays\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Memory Addresses of Arrays\n");
	printf("------------------------------------------------------------------------------\n");
	int ThisArray[5];
	printf(" int ThisArray[4];\n");
	printf(" &ThisArray[0] is %X\n", &ThisArray[0]);
	printf(" &ThisArray[1] is %X\n", &ThisArray[1]);
	printf(" &ThisArray[4] is %X\n", &ThisArray[4]);
	printf("\n");
	printf(" &ThisArray[0] is %X is the same as ThisArray (%X)\n", &ThisArray[0], ThisArray);
	printf(" &ThisArray[0] is %X is the same as (ThisArray + 0) (%X)\n", &ThisArray[0], (ThisArray + 0));
	printf(" &ThisArray[4] is %X is the same as (ThisArray + 4) (%X)\n", &ThisArray[4], (ThisArray + 4));
	printf("\n");
	printf("Referencing Array\n");
	printf("------------------------------------------------------------------------------\n");
	ThisArray[0] = 123;
	printf(" ThisArray[0] = 123;\n");
	printf(" ThisArray[0] is %d is the same as *ThisArray which gives %d\n", ThisArray[0], *ThisArray);
	ThisArray[4] = 321;
	printf(" ThisArray[4] = 321;\n");
	printf(" ThisArray[4] is %d is the same as *(ThisArray + 4) which gives %d\n", ThisArray[4], *(ThisArray + 4));
	printf("\n");
	printf("Sum Numbers Example\n");
	printf("------------------------------------------------------------------------------\n");
	printf(" Declare input variable: int classes[MAX]\n");
	printf(" Store inputs: scanf(\"%%d\",(classes + i));\n");
	printf(" Calc sum: sum += *(classes + i);\n");
	printf("\n");
	int i, classes[MAX_0A], sum = 0;
	printf("Enter %d numbers:\n", MAX_0A);
	for(i = 0; i < MAX_0A; ++i)
	{
      // (classes + i) is equivalent to &classes[i]
      scanf("%d",(classes + i));

      // *(classes + i) is equivalent to classes[i]
      sum += *(classes + i);
	}
	printf("Sum = %d\n", sum);
	printf("\n");
	printf("==============================================================================\n");

}

static void L() {
	
	printf("==============================================================================\n");
	printf("Typedef and Structures\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("'typedef' is a keyword\n");
	printf("\n");
	printf("To get around writing struct struct_name variable_name; to declare a struct\n");
	printf("use typedef\n");
	printf("\n");
	printf("Create the struture\n");
	printf("\n");
	printf("  typedef struct complex\n");
	printf("  {\n");
	printf("    int imag;\n");
	printf("    float real;\n");
	printf("  } comp;\n");
	printf("\n");
	printf("Then use it\n");
	printf("\n");
	printf("  comp comp1, comp2;\n");
	printf("\n");
	printf("==============================================================================\n");

}