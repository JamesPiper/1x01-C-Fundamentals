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

typedef enum Boolean { False, True };

// For Single Linked List
typedef struct SLList  
{
  int Value;
  struct SLList* Next;
} SSList;

// Start of the list.
SLList* ListHead;

// Function prototypes.
static SLList* CreateNewNode(int value);
static void GetNodeValueToAdd();
static void AddNode(int value);

static void GetNodeValueToRemove();
static void RemoveNode(int value);

static void GetNodeValueToInsert();
static void InsertNode(int value);

static void DisplayNodes();

void _4x00_SingleLinkedList() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;

	// Initialize
	ListHead = NULL;
	
	do {
		
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Single Linked List                                                       *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Add Node                                                             *\n");
		printf("*   B - Remove Node                                                          *\n");
		printf("*   C - Insert Node                                                          *\n");
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
		else if (Choice == 'z') 
			return;
		else 
			printf("*** Select a choice from those listed. ****\n\n");
		
	} while (Choice != 'x');  
}

static void GetNodeValueToAdd() {

	printf("------------------------------------------------------------------------------\n");
	printf("Add Node To The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Value to add to node: ");

	// Better code needed for inputing numbers
	int Item;
	scanf("%d", &Item);
	AddNode(Item);
	
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void AddNode(int value) {

	// Create a new node.
	SLList* NewNode = CreateNewNode(value);

	// Add node to the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Add to the end.
			SLList* Traverser = ListHead;
			while (Traverser->Next != NULL) {
				Traverser = Traverser->Next;
			}
			Traverser->Next = NewNode;
		}
		else 
			// First node.
			ListHead = NewNode;
		printf("Node added to the list with value %d at location %X.\n", value, NewNode);
	}
	else 
		printf("Problem allocating memory for new node.\n");

}

static SLList* CreateNewNode(int value) {

	// Create a pointer for new node.
	SLList* NewNode = (SLList*) malloc(sizeof(SLList));

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
		printf("Value to remove from the list: ");
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
		ListHead = ListHead->Next;
		printf("Node with value %d removed from the list.\n", value);
	} else {
		// Search the list for node.
		SSList* Traverser = ListHead->Next;
		SSList* PrevNode = ListHead;
		Boolean LocationFound = False;
		Boolean NotEndOfList = True;
		while (LocationFound != True && NotEndOfList == True)  {
			if (Traverser->Next !=NULL) {
				if (value == Traverser->Value) {
					LocationFound = True;
					PrevNode->Next = Traverser->Next;
					printf("Node with value %d removed from the list.\n", value);
				} else {
					PrevNode = Traverser;
					Traverser = Traverser->Next;
				}
			} else {
				// At the end of the list.
				if (value == Traverser->Value) {
					LocationFound = True;
					PrevNode->Next = Traverser->Next;
					printf("Node with value %d removed from the list.\n", value);
				} else {
					NotEndOfList = False;
					printf("Value not found in the list. List unchanged.\n");
				}
			}
		}
	}
}

static void RemoveNode_L(int value) {
	// First attempt.

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
		printf("Node with value %d removed from the list.\n", value);
	} else {
		// Search the list for node.
		SSList* Traverser = ListHead->Next;
		SSList* PrevNode = ListHead;
		Boolean LocationFound = False;
		Boolean NotEndOfList = True;
		while (LocationFound != True && NotEndOfList == True)  {
			if (value == Traverser->Value) {
				LocationFound = True;
				PrevNode->Next = Traverser->Next;
				printf("Node with value %d removed from the list.\n", value);
			} else {
				if (Traverser->Next != NULL) {
					PrevNode = Traverser;
					Traverser = Traverser->Next;
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
	SLList* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			if (value <= ListHead->Value) {
				// Insert at start.
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLList* Traverser = ListHead;
				SLList* PrevNode = Traverser;
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

static void InsertNode_O(int value) {
	// Fouth attempt.
	// Cases to consider.
	//
	// A. Affecting ListHead
	// 1. No nodes in this list, so add as first node. 
	// 2. All values in the list are larger than in the insert value, insert as first node.
	//
	// B. Not affecting ListHead
	// 1. Insert value falls within two existing nodes.
	// 2. All values in the list are smaller than in the insert value.

	// Create a new node.
	SLList* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Insert at start?
			if (value < ListHead->Value) {
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLList* Traverser = ListHead;
				SLList* PrevTraverser = Traverser;
				Boolean LocationFound = False; 
				while (LocationFound != True) {
					// There's two possible scenarios.
					// 1. We've reached the end of the list, or,
					// 2. The insert value is greater than or equal to node value.
					if (Traverser->Next != NULL) {
						if (value <= Traverser->Value) {
							LocationFound = True;
							PrevTraverser->Next = NewNode;
							NewNode->Next = Traverser;
						} else {
							PrevTraverser = Traverser;
							Traverser = Traverser->Next;
						}
					} else {
						// At at the end.
						LocationFound = True;
						Traverser->Next = NewNode;
					}
				}
			}
		} else 
			// First node.
			ListHead = NewNode;
		printf("Node inserted into the list with value %d at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");
}

static void InsertNode_N(int value) {
	// Third attempt.
	// Cases to consider.
	//
	// A. Affecting ListHead
	// 1. No nodes in this list, so add as first node. 
	// 2. All values in the list are larger than in the insert value, insert as first node.
	//
	// B. Not affecting ListHead
	// 1. Insert value falls within two existing nodes.
	// 2. All values in the list are smaller than in the insert value.

	// Create a new node.
	SLList* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Insert at start?
			if (value < ListHead->Value) {
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLList* Traverser = ListHead;
				Boolean LocationFound = False; 
				while (LocationFound != True) {
					// There's two possible scenarios.
					// 1. Reached the end of the list.
					// 2. The insert value is greater than or equal to node value.
					if (value > Traverser->Value) {
						LocationFound = True;
						NewNode->Next = Traverser->Next;
						Traverser->Next = NewNode;
					} else {
						if (Traverser->Next != NULL) {
							Traverser = Traverser->Next;
						} else {
							// At at the end.
							LocationFound = True;
							Traverser->Next = NewNode;
						}
					}
				}
			}
		} else 
			// First node.
			ListHead = NewNode;
		printf("Node inserted into the list with value %d at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");
}

static void InsertNode_M(int value) {
	// Second attempt
	// Cases to consider.
	//
	// A. Affecting ListHead
	// 1. No nodes in this list, so add as first node. 
	// 2. All values in the list are larger than in the insert value, insert as first node.
	//
	// B. Not affecting ListHead
	// 1. Insert value falls within two existing nodes.
	// 2. All values in the list are smaller than in the insert value.

	// As of 2017.01.13 code not complete.

	// Create a new node.
	SLList* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Insert at start?
			if (value < ListHead->Value) {
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLList* Traverser = ListHead;
				Boolean LocationFound = False; 
				while (LocationFound != True) {
					if (Traverser->Next = NULL) {
						// Adding at the end.
						LocationFound = True;
						Traverser->Next = NewNode;
					} else {
						if (value > Traverser->Value) {
							Traverser = Traverser->Next;
						} else {
							// Insert node.
							LocationFound = True;
							NewNode->Next = Traverser;
							Traverser= NewNode;
						}
					}
				}
			}

		} else 
			// First node.
			ListHead = NewNode;
		printf("Node inserted into the list with value %d at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");
}

static void InsertNode_L(int value) {
	// First attempt.
	// Cases to consider.
	//
	// A. Affecting ListHead
	// 1. No nodes in this list, so add as first node. 
	// 2. All values in the list are larger than in the insert value, insert as first node.
	//
	// B. Not affecting ListHead
	// 1. Insert value falls within two existing nodes.
	// 2. All values in the list are smaller than in the insert value.

	// As of 2017.01.13 code not complete.

	// Create a new node.
	SLList* NewNode = CreateNewNode(value);

	// Add node to the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Search for insertion point.
			SLList* Traverser = ListHead;
			Boolean LocationFound = False; 

			while (LocationFound == False) {
				if (Traverser->Value < value) {
					Traverser = Traverser->Next;
				}
				else {
			 		LocationFound = True;
					if (Traverser->Next != NULL) {
						// Insert node.
						if (Traverser = ListHead)
							ListHead = NewNode;
						NewNode->Next = Traverser->Next;
				 		Traverser->Next = NewNode;
					}
					else
						// Reached the end, add to the end.
						Traverser->Next = NewNode;
				}
			}
		}
		else 
			// First node.
			ListHead = NewNode;
		printf("Node added to the list with value %d at location %X.\n", value, NewNode);
	}
	else 
		printf("Problem allocating memory for new node.\n");
}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	
	SLList* Traverser;
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

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}
