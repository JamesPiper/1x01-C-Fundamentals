/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.12
// File        : 1x01 C Fundamentals.h
// Description : Single-linked list with data value of int.
// IDE         : Visual Studio 2012
// Compiler    : MS
// Language    : C
/////////////////////////////////////////////////////////////////////////////////////
// 
// Demonstration of a dynamic single-linked list.
// 
// The list is based on a user-defined struct SSList with two members:
// (1) int data value (2) pointer to another struct.
//
// It is a dynamic list because nodes are added using malloc.
// Testing for null pointers to avoid problems.
//
// ListHead points to the start of the list.
// The value is null until the first node is added.
// There is no pointer to the tail of the list.
//
// Nature of SLL
// 1. Dynamic storage of data. Limited by memory of computer.
//    Size of list can grow and shrink as needed.
// 2. Easy to insert or remove node to keep a sorted list. 
// 3. Homogenous data types.
// 4. Sequential access. Must traverse from start to node to find node.
//    Must go through entire list to get to the end.
// 5. Linear data structure.
// 6. Uses dynamic memory allocation which can be trapped if
//    the program hangs or crashes.
//
// MAJOR FLAW
// Node based on integer data type, but inputs of non-digits
// results in junk data. This needs to be fixed.
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "1x01 C Fundamentals.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Typedefs
/////////////////////////////////////////////////////////////////////////////////////
typedef struct SLListInts  
{
  int Value;
  struct SLListInts* Next;
} SLListInts;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
static SLListInts* CreateNewNode(int value);
static void GetNodeValueToAdd();
static void AddNode(int value);

static void GetNodeValueToRemove();
static void RemoveNode(int value);

static void GetNodeValueToInsert();
static void InsertNode(int value);

static void DisplayNodes();
static void ClearList();

static void AtExitCleanup();

static void TestCode_F_SingleLinkedListOfInt();
static void TestCode_G_SingleLinkedListOfInt();
static void TestCode_H_SingleLinkedListOfInt();
static void TestCode_I_SingleLinkedListOfInt();
static void TestCode_J_SingleLinkedListOfInt();
static void TestCode_K_SingleLinkedListOfInt();
static void TestCode_L_SingleLinkedListOfInt();
static void TestCode_M_SingleLinkedListOfInt();
static void TestCode_N_SingleLinkedListOfInt();
static void TestCode_O_SingleLinkedListOfInt();
static void TestCode_P_SingleLinkedListOfInt();
static void TestCode_Q_SingleLinkedListOfInt();

/////////////////////////////////////////////////////////////////////////////////////
// Start of the list.
/////////////////////////////////////////////////////////////////////////////////////
SLListInts* ListHead;

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _4x01_SingleLinkedListOfInts() {

	atexit(AtExitCleanup);

	// Initialize
	ListHead = NULL;
	
	char Choice;

	do {
		
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Single-linked List of Ints                                               *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Add Node  (Non-sorted list)                                          *\n");
		printf("*   B - Remove Node                                                          *\n");
		printf("*   C - Insert Node (Sorted list)                                            *\n");
		printf("*   D - Display Nodes                                                        *\n");
		printf("*   E - Clear List                                                           *\n");
		printf("*                                                                            *\n");
#define DEBUG_401
#ifdef DEBUG_401
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
#undef DEBUG_401
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
			TestCode_F_SingleLinkedListOfInt();
		else if (Choice == 'g')
			TestCode_G_SingleLinkedListOfInt();
		else if (Choice == 'h')
			TestCode_H_SingleLinkedListOfInt();
		else if (Choice == 'i')
			TestCode_I_SingleLinkedListOfInt();
		else if (Choice == 'j')
			TestCode_J_SingleLinkedListOfInt();
		else if (Choice == 'k')
			TestCode_K_SingleLinkedListOfInt();
		else if (Choice == 'l')
			TestCode_L_SingleLinkedListOfInt();
		else if (Choice == 'm')
			TestCode_M_SingleLinkedListOfInt();
		else if (Choice == 'n')
			TestCode_N_SingleLinkedListOfInt();
		else if (Choice == 'o')
			TestCode_O_SingleLinkedListOfInt();
		else if (Choice == 'p')
			TestCode_P_SingleLinkedListOfInt();
		else if (Choice == 'q')
			TestCode_Q_SingleLinkedListOfInt();
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

	// Better code needed for inputing numbers
	int Item;
	scanf("%d", &Item);
	AddNode(Item);
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void AddNode(int value) {

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_401
	#ifdef DEBUG_401
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Value in AddNode '%d' at memory location %X\n", value, &value);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a new node.
	SLListInts* NewNode = CreateNewNode(value);

	// Add node to the end of the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Add to the end.
			SLListInts* Traverser = ListHead;
			while (Traverser->Next != NULL) {
				Traverser = Traverser->Next;
			}
			Traverser->Next = NewNode;
		} else {
			// First node.
			ListHead = NewNode;
			/////////////////////////////////////////////////////////////////////////////////////
			#ifdef DEBUG_401
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("ListHead in AddNode\n");
			printf("Memory Location: %X | Value: '%d' | Next: %X\n",
				ListHead, ListHead->Value, ListHead->Next);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			/////////////////////////////////////////////////////////////////////////////////////
		}
		printf("Node added to the list at location %X with value %d\n", NewNode, value);
	} else 
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG_401
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("NewNode in AddNode:\n");
	printf("Memory Location: %X | Value: '%d' | Next: %X\n",
		NewNode, NewNode->Value, NewNode->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_401
	/////////////////////////////////////////////////////////////////////////////////////

}

static SLListInts* CreateNewNode(int value) {

	// Create a pointer for new node.
	SLListInts* NewNode = (SLListInts*) malloc(sizeof(SLListInts));
	// When freed? (1) at exit (2) remove function
	// All bets off if program crashes, not sure what windows does with stack / heap.

	// Test if not null
	if (NewNode != NULL) {
		NewNode->Value = value;
		NewNode->Next = NULL;
		return NewNode;
	} else 
		return NULL;

}

static void GetNodeValueToRemove() {

	printf("------------------------------------------------------------------------------\n");
	printf("Remove Node From The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	printf("Enter value to remove from the list: ");
	int Item;
	scanf("%d", &Item);
	RemoveNode(Item);
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void RemoveNode(int value) {

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
			SLListInts* temp = ListHead;
			/////////////////////////////////////////////////////////////////////////////////////
			//#define DEBUG_401
			#ifdef DEBUG_401
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Value before: '%d' at %X\n", temp->Value, temp);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			/////////////////////////////////////////////////////////////////////////////////////
			ListHead = ListHead->Next;
			free(temp);
			printf("Node removed from the list with value %d\n", value);
			/////////////////////////////////////////////////////////////////////////////////////
			#ifdef DEBUG_401
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Value after: '%d' at %X\n", temp->Value, temp);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			#undef DEBUG_401
			/////////////////////////////////////////////////////////////////////////////////////
		} else {
			// Search the list for node.
			if (ListHead->Next != NULL) {
				SLListInts* Traverser = ListHead->Next;
				SLListInts* PrevNode = ListHead;
				Boolean LocationFound = False;
				Boolean NotEndOfList = True;
				while (LocationFound != True && NotEndOfList == True)  {
					if (Traverser->Next !=NULL) {
						if (value == Traverser->Value) {
							LocationFound = True;
							PrevNode->Next = Traverser->Next;
							free(Traverser);
							printf("Node removed from the list with value %d\n", value);
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
							printf("Node removed from the list with value %d\n", value);
						} else {
							NotEndOfList = False;
							printf("***** Value '%d' not found in the list. List unchanged. *****\n", value);
						}
					}
				}
			} else {
				// Only one item in the list and not a match.
				if (value != ListHead->Value)
					printf("***** Value '%d' not found in the list. List unchanged. *****\n", value);
			}
		}
	} else {
		printf("This list is empty.\n");
	}
}

static void GetNodeValueToInsert() {

	printf("------------------------------------------------------------------------------\n");
	printf("Insert Node Into The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Value to insert into the list: ");

	// Better code needed for inputing numbers
	int Item;
	scanf("%d", &Item);
	InsertNode(Item);
	
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void InsertNode(int value) {

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
	//#define DEBUG_401
	#ifdef DEBUG_401
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Value in InsertNode '%d' at memory location %X\n", value, &value);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a new node.
	SLListInts* NewNode = CreateNewNode(value);
	
	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			if (value <= ListHead->Value) {
				// Insert at start.
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLListInts* Traverser = ListHead;
				SLListInts* PrevNode = Traverser;
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
		printf("Node inserted into the list at location %X with value %d\n", NewNode, value);
	} else 
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG_401
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("ListHead in InsertNode\n");
	printf("Memory Location: %X | Value: '%d' | Next: %X\n",
		ListHead, ListHead->Value, ListHead->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_401
	/////////////////////////////////////////////////////////////////////////////////////

}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	
	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_401
	#ifdef DEBUG_401
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("ListHead in DisplayNodes\n");
	printf("Memory Location: %X | Value: '%d' | Next: %X\n",
		ListHead, ListHead->Value, ListHead->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_401
	/////////////////////////////////////////////////////////////////////////////////////

	SLListInts* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("Item at memory location %X next at %6X with value %d\n",
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
	printf("\n");
	printf("Traverse the list and free nodes.\n");

	SLListInts* Traverser = NULL;
	if (ListHead != NULL) {
		Traverser = ListHead->Next;

		while (Traverser != NULL) {
			free(ListHead);
			ListHead = Traverser;
			Traverser = ListHead->Next;
		}
		ListHead = NULL;
	}
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void AtExitCleanup() {

	printf("Cleaning up memory on exit...\n");

	// Free memory allocated for the list.
	SLListInts* Traverser;
	while (ListHead != NULL) {
		Traverser = ListHead;
		ListHead = ListHead->Next;
		printf("Node memory freed at %X.\n", Traverser);
		free(Traverser);
	}
}

/////////////////////////////////////////////////////////////////////////////////////
// Run test code on the SLL data structure of ints.
// 
// Able to test valid inputs (ints) to show it works.
// Not able to test junk input to see how it handles it.
/////////////////////////////////////////////////////////////////////////////////////
static void TestCode_F_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("F - Unit Testing - Clear List\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");
	DisplayNodes();

	printf("Call clear list function.\n");
	printf("\n");
	ClearList();
	DisplayNodes();
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_G_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("G - Unit Testing - Add Nodes To List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Add Some Nodes (Not a sorted list)\n");
	printf("------------------------------------------------------------------------------\n");
	AddNode(400);
	AddNode(100);
	AddNode(200);
	AddNode(0);
	AddNode(20);
	AddNode(2000);
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_H_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("H - Unit Testing - Insert Node To Empty List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();

	InsertNode(1000);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_I_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("I - Unit Testing - Insert Node To The Start Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");

	InsertNode(10);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_J_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("J - Unit Testing - Insert Node To The Middle Of The List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();
	
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");

	InsertNode(250);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_K_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("K - Unit Testing - Insert Node To The End Of The List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();
	
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");

	InsertNode(500);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_L_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("L - Unit Testing - Remove Node From Empty List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();
	printf("Attempt to remove item from empty list.\n");
	printf("\n");
	RemoveNode(900);

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_M_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("M - Unit Testing - Remove Node Not In The List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();
	printf("Create list with an add.\n");
	AddNode(100);
	printf("\n");
	printf("Attempt removal of item.\n");
	RemoveNode(900);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_N_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("N - Unit Testing - Remove Node From One-item List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();
	printf("Create list with an add.\n");
	AddNode(100);
	printf("\n");
	printf("Attempt removal of item.\n");
	RemoveNode(100);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_O_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("O - Unit Testing - Remove Node From The Start Of The List\n");
	printf("==============================================================================\n");
	printf("\n");
	
	ClearList();
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");
	printf("Attempt removal of item.\n");
	RemoveNode(100);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_P_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("P - Unit Testing - Remove Node From The Middle Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");
	printf("Attempt removal of item.\n");
	RemoveNode(200);
	printf("\n");
	DisplayNodes();
	
	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_Q_SingleLinkedListOfInt() {

	printf("==============================================================================\n");
	printf("Q - Unit Testing - Remove Node From The End Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	AddNode(100);
	AddNode(200);
	AddNode(300);
	AddNode(400);
	printf("\n");
	printf("Attempt removal of item.\n");
	RemoveNode(400);
	printf("\n");
	DisplayNodes();
	
	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}
