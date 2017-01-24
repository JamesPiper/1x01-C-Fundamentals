/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.15
// File        : _4x03_SingleLinkedListOfChar.c
// Description : Single-linked list with data value of char.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 11.)
/////////////////////////////////////////////////////////////////////////////////////
//
// Taking code from _4x01_SingleLinkedListOfInts and modify
// to have a char value instead of int value.
//
// I'm doing this as a proof of concept and for use in creating one
// with array of chars.
//
/////////////////////////////////////////////////////////////////////////////////////
//
// What's the difference? Change int to char and use '%c' instead of '%d'
// Afterall a char is an n-bit int.
// That makes sense except after adding one node and calling DisplayNodes
// this line, Traverser = ListHead;, shows that ListHead is null
// yet the code works and it displays the data.
// I don't understand what's going on. Maybe too close to this.
// Perhaps tomorrow I'll see it better.
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "_1x01 C Fundamentals.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Typedefs
/////////////////////////////////////////////////////////////////////////////////////
typedef struct SLListChar
{
  char Value;
  struct SLListChar* Next;
} SLListChar;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
static SLListChar* CreateNewNode(char value);
static void GetNodeValueToAdd();
static void AddNode(char value);

static void GetNodeValueToRemove();
static void RemoveNode(char value);

static void GetNodeValueToInsert();
static void InsertNode(char value);

static void DisplayNodes();
static void ClearList();

static void AtExitCleanup();

static void TestCode_F_SingleLinkedListOfChar();
static void TestCode_G_SingleLinkedListOfChar();
static void TestCode_H_SingleLinkedListOfChar();
static void TestCode_I_SingleLinkedListOfChar();
static void TestCode_J_SingleLinkedListOfChar();
static void TestCode_K_SingleLinkedListOfChar();
static void TestCode_L_SingleLinkedListOfChar();
static void TestCode_M_SingleLinkedListOfChar();
static void TestCode_N_SingleLinkedListOfChar();
static void TestCode_O_SingleLinkedListOfChar();
static void TestCode_P_SingleLinkedListOfChar();
static void TestCode_Q_SingleLinkedListOfChar();
/////////////////////////////////////////////////////////////////////////////////////
// Start of the list.
/////////////////////////////////////////////////////////////////////////////////////
SLListChar* ListHead;

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _4x02_SingleLinkedListOfChar() {

	atexit(AtExitCleanup);

	// Initialize
	ListHead = NULL;

	char Choice;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Single-linked List of Chars                                              *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Add Node  (Non-sorted list)                                          *\n");
		printf("*   B - Remove Node                                                          *\n");
		printf("*   C - Insert Node (Sorted list)                                            *\n");
		printf("*   D - Display Nodes                                                        *\n");
		printf("*   E - Clear List                                                           *\n");
		printf("*                                                                            *\n");
#define DEBUG_402
#ifdef DEBUG_402
		printf("*   F - Unit Testing - Clear List                                            *\n");
		printf("*   G - Unit Testing - Add Nodes To List                                     *\n");
		printf("*   H - Unit Testing - Insert Node To Empty List                             *\n");
		printf("*   I - Unit Testing - Insert Node To The Start Of The List                  *\n");
		printf("*   J - Unit Testing - Insert Node To The Middle Of The List                 *\n");
		printf("*   K - Unit Testing - Insert Node To The End Of The List                    *\n");
		printf("*                                                                            *\n");
		printf("*   L - Unit Testing - Remove Node From Empty List                           *\n");
		printf("*   M - Unit Testing - Remove Node Not In The List                           *\n");
		printf("*   N - Unit Testing - Remove Node From One-item List                        *\n");
		printf("*   O - Unit Testing - Remove Node From The Start Of The List                *\n");
		printf("*   P - Unit Testing - Remove Node From The Middle Of The List               *\n");
		printf("*   Q - Unit Testing - Remove Node From The End Of The List                  *\n");
#endif
#undef DEBUG_402
		printf("*                                                                            *\n");
		printf("*   Z - Return                                                               *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("Enter choice: ");

		char Inputs[MAX_INPUT_CHARS];
		GetUserInputs(Inputs, CHOICE_LENGTH);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			GetNodeValueToAdd();
		else if (Choice == 'b')
			GetNodeValueToRemove();
		else if (Choice == 'c')
			GetNodeValueToInsert();
		else if (Choice == 'd') {
			DisplayNodes();
			system("pause");
		} else if (Choice == 'e') {
			ClearList();
			system("pause");
		} else if (Choice == 'f')
			TestCode_F_SingleLinkedListOfChar();
		else if (Choice == 'g')
			TestCode_G_SingleLinkedListOfChar();
		else if (Choice == 'h')
			TestCode_H_SingleLinkedListOfChar();
		else if (Choice == 'i')
			TestCode_I_SingleLinkedListOfChar();
		else if (Choice == 'j')
			TestCode_J_SingleLinkedListOfChar();
		else if (Choice == 'k')
			TestCode_K_SingleLinkedListOfChar();
		else if (Choice == 'l')
			TestCode_L_SingleLinkedListOfChar();
		else if (Choice == 'm')
			TestCode_M_SingleLinkedListOfChar();
		else if (Choice == 'n')
			TestCode_N_SingleLinkedListOfChar();
		else if (Choice == 'o')
			TestCode_O_SingleLinkedListOfChar();
		else if (Choice == 'p')
			TestCode_P_SingleLinkedListOfChar();
		else if (Choice == 'q')
			TestCode_Q_SingleLinkedListOfChar();
		else if (Choice == 'x')
			exit(0);
		else if (Choice == 'z') {
			AtExitCleanup();
			return;
		} else if (Choice != 'x')
			printf("*** Select a choice from those listed. ****\n\n");

	} while (Choice != 'x');
}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions.
/////////////////////////////////////////////////////////////////////////////////////
static void GetNodeValueToAdd() {

	printf("------------------------------------------------------------------------------\n");
	printf("Add Node To The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Enter value to add to the list: ");

	char Inputs[MAX_INPUT_CHARS];
	char Item;
	scanf("%s", Inputs);
	Item = Inputs[0];
	AddNode(Item);

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void AddNode(char value) {

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_402
	#ifdef DEBUG_402
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Value in AddNode '%c' at memory location %X\n", value, &value);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a new node.
	SLListChar* NewNode = CreateNewNode(value);

	// Add node to the end of the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Add to the end.
			SLListChar* Traverser = ListHead;
			while (Traverser->Next != NULL) {
				Traverser = Traverser->Next;
			}
			Traverser->Next = NewNode;
		} else {
			// First node.
			ListHead = NewNode;
			/////////////////////////////////////////////////////////////////////////////////////
			// Different here than the case with int value.
			// The ListHead is null after the assignment here, but not with ints.
			// I don't understand why this isn't working in debug mode, yet works.
			/////////////////////////////////////////////////////////////////////////////////////
			//ListHead->Value = NewNode->Value;
			//ListHead->Next = NewNode->Next;
			/////////////////////////////////////////////////////////////////////////////////////
			#ifdef DEBUG_402
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("ListHead in AddNode\n");
			printf("Memory Location: %X | Value: '%c' | Next: %X\n",
				ListHead, ListHead->Value, ListHead->Next);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			/////////////////////////////////////////////////////////////////////////////////////
		}
		printf("Node added to the list at location %X with value '%c'\n", NewNode, value);
	} else
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG_402
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("NewNode in AddNode:\n");
	printf("Memory Location: %X | Value: '%c' | Next: %X\n",
		NewNode, NewNode->Value, NewNode->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_402
	/////////////////////////////////////////////////////////////////////////////////////

}

static SLListChar* CreateNewNode(char value) {

	// Create a pointer for new node.
	SLListChar* NewNode = (SLListChar*) malloc(sizeof(SLListChar));

	// Test if not null
	if (NewNode != NULL) {
		NewNode->Value = value;
		NewNode->Next = NULL;
		return NewNode;
	}
	else
		return NULL;

}

static void GetNodeValueToRemove() {

	printf("------------------------------------------------------------------------------\n");
	printf("Remove Node From The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	printf("Enter value to remove from the list: ");
	char Item;
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", Inputs);
	Item = Inputs[0];
	RemoveNode(Item);

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void RemoveNode(char value) {

	/////////////////////////////////////////////////////////////////////////////////////
	// Cases to consider.
	// 1. Found value in list, remove node.
	// 2. Value not found. List unchanged.
	//
	// Possible states of list and node to remove.
	// 1. List is empty. ListHead points to null. Can't remove node.
	//    Handled by caller. Only get here if list isn't empty.
	// 2. Node is at the start. Adjust ListHead to point to second node.
	// 3. Node is at the end. Adjust second last to point to null.
	// 4. Node is not at start or end, point previous to next.
	//
	// Using NotEndOfList for readability even though it adds to cycles.
	/////////////////////////////////////////////////////////////////////////////////////

	if (ListHead != NULL) {
		if (value == ListHead->Value) {
			// Remove at start.
			SLListChar* temp = ListHead;
			/////////////////////////////////////////////////////////////////////////////////////
			//#define DEBUG_402
			#ifdef DEBUG_402
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Value before: '%c' at %X\n", temp->Value, temp);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			/////////////////////////////////////////////////////////////////////////////////////
			ListHead = ListHead->Next;
			free(temp);
			printf("Node removed from the list with value '%c'\n", value);
			/////////////////////////////////////////////////////////////////////////////////////
			#ifdef DEBUG_402
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Value after: '%c' at %X\n", temp->Value, temp);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			#undef DEBUG_402
			/////////////////////////////////////////////////////////////////////////////////////
		} else {
			// Search the list for node.
			if (ListHead->Next != NULL) {
				SLListChar* Traverser = ListHead->Next;
				SLListChar* PrevNode = ListHead;
				Boolean LocationFound = False;
				Boolean NotEndOfList = True;
				while (LocationFound != True && NotEndOfList == True)  {
					if (Traverser->Next !=NULL) {
						if (value == Traverser->Value) {
							LocationFound = True;
							PrevNode->Next = Traverser->Next;
							free(Traverser);
							printf("Node removed from the list with value '%c'\n", value);
						} else {
							PrevNode = Traverser;
							Traverser = Traverser->Next;
						}
					} else {
						// At the end of the list.
						if (value == Traverser->Value) {
							LocationFound = True;
							PrevNode->Next = NULL;
							free(Traverser);
							printf("Node removed from the list with value '%c'\n", value);
						} else {
							NotEndOfList = False;
							printf("***** Value '%c' not found in the list. List unchanged. *****\n", value);
						}
					}
				}
			} else {
				// Only one item in the list and not a match.
				if (value != ListHead->Value)
					printf("***** Value '%c' not found in the list. List unchanged. *****\n", value);
			}
		}
	} else
		printf("This list is empty.\n");
}

static void GetNodeValueToInsert() {

	printf("------------------------------------------------------------------------------\n");
	printf("Insert Node Into The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Value to insert into the list: ");

	char Item;
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", Inputs);
	Item = Inputs[0];
	InsertNode(Item);

	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void InsertNode(char value) {

	/////////////////////////////////////////////////////////////////////////////////////
	// Cases to consider.
	//
	// A. Affecting ListHead
	//----------------------
	// 1. No nodes in this list, insert as first node.
	// 2. All values in the list are larger than the insert value, insert as first node.
	//
	// B. Not affecting ListHead
	//--------------------------
	// 1. Insert value falls within two existing nodes.
	// 2. All values in the list are smaller than in the insert value, insert at the end.
	//
	// Using a previous pointer variable to keep track of where to insert.
	// I wonder if there's a way to do it without this variable.
	//
	// Writing structured code, hence all the embedded if..else
	// Also needed to catch any null pointers.
	// Looking at ways to simplify but this seems to be it.
	/////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_402
	#ifdef DEBUG_402
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Value in InsertNode '%c' at memory location %X\n", value, &value);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a new node.
	SLListChar* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			if (value <= ListHead->Value) {
				// Insert at start.
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLListChar* Traverser = ListHead;
				SLListChar* PrevNode = Traverser;
				Boolean LocationFound = False;
				while (LocationFound != True) {
					// There's two possible scenarios.
					// 1. We've reached the end of the list, or,
					// 2. The insert value is less than or equal to the node value.
					if (Traverser->Next != NULL) {
						if (value <= Traverser->Value) {
							// Insert between two nodes.
							LocationFound = True;
							PrevNode->Next = NewNode;
							NewNode->Next = Traverser;
						} else {
							// Get next node.
							PrevNode = Traverser;
							Traverser = Traverser->Next;
						}
					} else {
						// At the end.
						LocationFound = True;
						if (value <= Traverser->Value) {
							PrevNode->Next = NewNode;
							NewNode->Next = Traverser;
						} else
							Traverser->Next = NewNode;
					}
				}
			}
		} else
			// First node on the list.
			ListHead = NewNode;
		printf("Node inserted into the list at location %X with value '%c'\n", NewNode, value);
	} else
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG_402
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("ListHead in InsertNode\n");
	printf("Memory Location: %X | Value: '%c' | Next: %X\n",
		ListHead, ListHead->Value, ListHead->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_402
	/////////////////////////////////////////////////////////////////////////////////////

}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_402
	#ifdef DEBUG_402
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("ListHead in DisplayNodes\n");
	printf("Memory Location: %X | Value: '%c' | Next: %X\n",
		ListHead, ListHead->Value, ListHead->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_402
	/////////////////////////////////////////////////////////////////////////////////////

	SLListChar* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("Item at memory location %X next at %6X with value '%c'\n",
				Traverser, Traverser->Next, Traverser->Value);
			Traverser = Traverser->Next;
		} while (Traverser !=NULL);
	}
	else
		printf("The list empty.\n");

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void ClearList() {

	printf("------------------------------------------------------------------------------\n");
	printf("Clearing The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Traverse the list and free nodes.\n");

	SLListChar* Traverser;
	while (ListHead != NULL) {
		Traverser = ListHead;
		ListHead = ListHead->Next;
		printf("Node memory freed at %X.\n", Traverser);
		free(Traverser);
	}

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void AtExitCleanup() {

	printf("Cleaning up memory on exit...\n");

	// Free memory allocated for the list.
	SLListChar* Traverser;
	while (ListHead != NULL) {
		Traverser = ListHead;
		ListHead = ListHead->Next;
		printf("Node memory freed at %X.\n", Traverser);
		free(Traverser);
	}
}

/////////////////////////////////////////////////////////////////////////////////////
// Run test code on the SLL data structure of chars.
//
// Able to test valid inputs (ints) to show it works.
// Not able to test junk input to see how it handles it.
/////////////////////////////////////////////////////////////////////////////////////
static void TestCode_F_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("F - Unit Testing - Clear List\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Create list with add.\n");
	AddNode('a');
	AddNode('c');
	AddNode('e');
	AddNode('g');
	printf("\n");
	DisplayNodes();

	printf("Call clear list function.\n");
	printf("\n");
	ClearList();
	DisplayNodes();
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_G_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("G - Unit Testing - Add Nodes To List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Add Some Nodes (Not a sorted list)\n");
	printf("------------------------------------------------------------------------------\n");
	AddNode('f');
	AddNode('a');
	AddNode('c');
	AddNode(0);
	AddNode('>');
	AddNode(']');
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_H_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("H - Unit Testing - Insert Node To Empty List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	InsertNode('p');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_I_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("I - Unit Testing - Insert Node To The Start Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Create list with add.\n");
	AddNode('c');
	AddNode('e');
	AddNode('g');
	AddNode('h');
	printf("\n");

	InsertNode('a');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_J_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("J - Unit Testing - Insert Node To The Middle Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Create list with add.\n");
	AddNode('c');
	AddNode('e');
	AddNode('g');
	AddNode('h');
	printf("\n");

	InsertNode('f');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_K_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("K - Unit Testing - Insert Node To The End Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Create list with add.\n");
	AddNode('c');
	AddNode('e');
	AddNode('g');
	AddNode('h');
	printf("\n");

	InsertNode('i');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_L_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("L - Unit Testing - Remove Node From Empty List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Attempt to remove item from empty list.\n");
	printf("\n");
	RemoveNode('z');

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_M_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("M - Unit Testing - Remove Node Not In The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with an add.\n");
	AddNode('a');
	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode('z');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_N_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("N - Unit Testing - Remove Node From One-item List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with an add.\n");
	AddNode('a');
	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode('a');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_O_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("O - Unit Testing - Remove Node From The Start Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	AddNode('c');
	AddNode('e');
	AddNode('g');
	AddNode('h');
	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode('c');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_P_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("P - Unit Testing - Remove Node From The Middle Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	AddNode('c');
	AddNode('e');
	AddNode('g');
	AddNode('h');
	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode('g');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_Q_SingleLinkedListOfChar() {

	printf("==============================================================================\n");
	printf("Q - Unit Testing - Remove Node From The End Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	AddNode('c');
	AddNode('e');
	AddNode('g');
	AddNode('h');
	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode('h');
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}
