//==============================================================================
// 2017.01.15 by James Piper, james@jamespiper.com
// 
// Taking code from _4x01_SingleLinkedListOfInts and modify
// to have a char value instead of int value.
//
// I'm doing this as a proof of concept and for use in creating one
// with array of chars.
//
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"

#include <cstdio>
#include <cstdlib>
#include <string.h>

typedef enum Boolean { False, True };

// For Single Linked List
typedef struct SLListChar  
{
  char Value;
  struct SLListChar* Next;
} SLListChar;

// Start of the list.
SLListChar* ListHead;

// Function prototypes.
static SLListChar* CreateNewNode(char value);
static void GetNodeValueToAdd();
static void AddNode(char value);

static void GetNodeValueToRemove();
static void RemoveNode(char value);

static void GetNodeValueToInsert();
static void InsertNode(char value);

static void DisplayNodes();
static void AtExitCleanup();

void _4x02_SingleLinkedListOfChar() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;

	atexit(AtExitCleanup);

	// Initialize
	ListHead = NULL;
	
	do {
		
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Single Linked List of Chars                                              *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Add Node  (Non-sorted list)                                          *\n");
		printf("*   B - Remove Node                                                          *\n");
		printf("*   C - Insert Node (Sorted list)                                            *\n");
		printf("*   D - Display Nodes                                                        *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return                                                               *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");
		printf("\n");

		printf("Enter choice: ");
		scanf("%s", &Inputs);
		strlwr(Inputs);
		Choice = Inputs[0];

		if (Choice == 'a')
			GetNodeValueToAdd();
		else if (Choice == 'b')
			GetNodeValueToRemove();
		else if (Choice == 'c') 
			GetNodeValueToInsert();
		else if (Choice == 'd') 
			DisplayNodes();
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
	char Inputs[MAX_INPUT_CHARS];
	char Item;
	scanf("%s", &Inputs);
	Item = Inputs[0];
	AddNode(Item);
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void AddNode(char value) {

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
		}
		else 
			// First node.
			ListHead = NewNode;
		printf("Node added to the list with value '%c' at location %X.\n", value, NewNode);
	}
	else 
		printf("Problem allocating memory for new node.\n");

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

	if (ListHead != NULL) {
		printf("Enter value to remove from the list: ");
		char Item;
		char Inputs[MAX_INPUT_CHARS];
		scanf("%s", &Inputs);
		Item = Inputs[0];
		RemoveNode(Item);
	} else
		printf("This list is empty.\n");
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void RemoveNode(char value) {

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
		ListHead = ListHead->Next;
		printf("Node with value '%c' removed from the list.\n", value);
	} else {
		// Search the list for node.
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
					printf("Node with value '%c' removed from the list.\n", value);
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
					printf("Node with value '%c' removed from the list.\n", value);
				} else {
					NotEndOfList = False;
					printf("Value not found in the list. List unchanged.\n");
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
	char Item;
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", &Inputs);
	Item = Inputs[0];
	InsertNode(Item);
	
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void InsertNode(char value) {

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
		printf("Node inserted into the list with value '%c' at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");
}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	
	SLListChar* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("List item with value '%c' at memory location %X and next at %X\n",
				Traverser->Value, Traverser, Traverser->Next);
			Traverser = Traverser->Next;
		} while (Traverser !=NULL);
	}
	else 
		printf("The list empty.\n");

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

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