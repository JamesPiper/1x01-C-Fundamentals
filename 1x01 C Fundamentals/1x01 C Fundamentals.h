//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
//==============================================================================

#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

//==============================================================================
// Common typedefs
//==============================================================================
typedef enum Boolean { False, True };

//==============================================================================
// Function prototypes.
//==============================================================================
void _2x00_MainMenu();
void _3x00_Hello_World();
void _3x01_Keywords();
void _3x02_HeaderFiles();
void _3x03_ControlStatements();
void _3x04_Operators();
void _3x05_CharMapping();
void _3x06_DataTypes();
void _3x07_DynamicMemoryAllocation();
void _3x08_StringManipulations();
void _3x09_DataStructures();
void _3x0A_IOTests();

void _3x0B_User_Defined_Functions();
Boolean FileExists(const char* filename);
int StringCompare(const char* string1, const char* string2);
char* TrimWhitespace(char* string);
void GetUserInputs(char* inputs, int);

void _4x00_LinkedLists();
void _4x01_SingleLinkedListOfInts();
void _4x02_SingleLinkedListOfChar();
void _4x03_SingleLinkedListOfChars();

void _0x09_PointersStructures();


//==============================================================================
// Set defines for constants (aka macros)
//==============================================================================
#define MAX_INPUT_CHARS 255
#define MAX_FILENAME_CHARS 255
#define _CRT_SECURE_NO_WARNINGS

#endif 