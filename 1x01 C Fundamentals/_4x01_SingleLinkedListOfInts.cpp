//==============================================================================
// 2017.01.12 by James Piper, james@jamespiper.com
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
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctype.h>

// For Single Linked List of Ints
typedef struct SLListInts  
{
  int Value;
  struct SLListInts* Next;
} SLListInts;

// Start of the list.
SLListInts* ListHead;

// Function prototypes.
static SLListInts* CreateNewNode(int value);
static void GetNodeValueToAdd();
static void AddNode(int value);

static void GetNodeValueToRemove();
static void RemoveNode(int value);

static void GetNodeValueToInsert();
static void InsertNode(int value);

static void DisplayNodes();
			
static void AtExitCleanup();

static void _4x01_SingleLinkedListOfInts_TestCode();

void _4x01_SingleLinkedListOfInts() {

	atexit(AtExitCleanup);

	// Initialize
	ListHead = NULL;
	
	char Choice;

	do {
		
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Single Linked List of Ints                                               *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Add Node  (Non-sorted list)                                          *\n");
		printf("*   B - Remove Node                                                          *\n");
		printf("*   C - Insert Node (Sorted list)                                            *\n");
		printf("*   D - Display Nodes                                                        *\n");
		printf("*                                                                            *\n");
		printf("*   T - Test Code                                                            *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return                                                               *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("Enter choice: ");

		char Inputs[MAX_INPUT_CHARS];
		// 2 represents 1 char of input and null terminator.
		GetUserInputs(Inputs, 2);
		//scanf("%s", &Inputs);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			GetNodeValueToAdd();
		else if (Choice == 'b')
			GetNodeValueToRemove();
		else if (Choice == 'c') 
			GetNodeValueToInsert();
		else if (Choice == 'd') 
			DisplayNodes();
		else if (Choice == 't')
			_4x01_SingleLinkedListOfInts_TestCode();
		else if (Choice == 'x')
			exit(0);
		else if (Choice == 'z') {
			AtExitCleanup();
			return;
		} else 
			printf("*** Select a choice from those listed. ****\n\n");
		
	} while (Choice != 'x');  
}

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
			//printf(">>>>>ListHead in AddNode<<<<<\n");
			//printf(">>>>>(Memory Location: %X | Value: '%d' | Next: %X)<<<<<\n",
			//	ListHead, ListHead->Value, ListHead->Next);
			/////////////////////////////////////////////////////////////////////////////////////
		}
		printf("Node added to the list with value %d at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	//printf(">>>>>NewNode in AddNode:<<<<<\n");
	//printf(">>>>>(Memory Location: %X | Value: '%d' | Next: %X)<<<<<\n",
	//	NewNode, NewNode->Value, NewNode->Next);
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

	if (ListHead != NULL) {
		printf("Enter value to remove from the list: ");
		int Item;
		scanf("%d", &Item);
		RemoveNode(Item);
	} else
		printf("This list is empty.\n");
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void RemoveNode(int value) {
	// Second attempt. Wokring.

	// Cases to consider.
	// 1. Found value in list, remove node.
	// 2. Value not found. List unchanged.

	// Possible states of list and node to remove.
	// 1. List is empty. ListHead points to null. Can't remove node.
	//    Handled by caller. Only get here if list isn't empty.
	// 2. Node is at the start. Adjust ListHead to point to second node.
	// 3. Node is at the end. Adjust second last to point to null.
	// 4. Node is not at start or end, point previous to next.
	
	// Using NotEndOfList for readability even though it adds to cycles.

	if (value == ListHead->Value) {
		// Remove at start.
		SLListInts* temp = ListHead;
		/////////////////////////////////////////////////////////////////////////////////////
		printf("Value before: '%d' at %X\n", temp->Value, temp);
		/////////////////////////////////////////////////////////////////////////////////////
		ListHead = ListHead->Next;
		free(temp);
		printf("Node with value %d removed from the list.\n", value);
		/////////////////////////////////////////////////////////////////////////////////////
		printf("Value after: '%d' at %X\n", temp->Value, temp);
		/////////////////////////////////////////////////////////////////////////////////////
	} else {
		// Search the list for node.
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
					printf("Node with value %d removed from the list.\n", value);
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
					printf("Node with value %d removed from the list.\n", value);
				} else {
					NotEndOfList = False;
					printf("Value (%d) not found in the list. List unchanged.\n", value);
				}
			}
		}
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

	// Using a previous pointer variable to keep track of where to insert.
	// I wonder if there's a way to do it without this variable.

	// Writing structured code, hence all the embedded if..else
	// Also needed to catch any null pointers.
	// Looking at ways to simplify but this seems to be it.

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
		printf("Node inserted into the list with value %d at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");
}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	//printf("\n");
	
	SLListInts* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("List item with value %d at memory location %X and next at %X\n",
				Traverser->Value, Traverser, Traverser->Next);
			Traverser = Traverser->Next;
		} while (Traverser !=NULL);
	}
	else 
		printf("The list empty.\n");

	//printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

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

static void _4x01_SingleLinkedListOfInts_TestCode() {

	/////////////////////////////////////////////////////////////////////////////////////
	// Run test code on the SLL data structure of ints.
	// 
	// Able to test valid inputs (ints) to show it works.
	// Not able to test junk input to see how it handles it.
	/////////////////////////////////////////////////////////////////////////////////////

	printf("==============================================================================\n");
	printf("Testing Code - Check Add, Insert, Remove and Display Nodes\n");
	printf("==============================================================================\n");
	printf("\n");

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

	printf("Remove Some Nodes\n");
	printf("------------------------------------------------------------------------------\n");
	RemoveNode(900);
	RemoveNode(20);
	RemoveNode(400);
	RemoveNode(0);
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	DisplayNodes();
	printf("\n");

	printf("Insert Some Nodes (Sorted list)\n");
	printf("------------------------------------------------------------------------------\n");
	InsertNode(400);
	InsertNode(4000);
	InsertNode(40);
	InsertNode(4);
	InsertNode(-4);
	InsertNode(-40);
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	DisplayNodes();
	printf("\n");

	printf("Remove Some Nodes (Sorted list)\n");
	printf("------------------------------------------------------------------------------\n");
	RemoveNode(400);
	RemoveNode(40000);
	RemoveNode(4000);
	RemoveNode(400);
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	DisplayNodes();
	printf("\n");

	printf("\n");
	printf("==============================================================================\n");

}
