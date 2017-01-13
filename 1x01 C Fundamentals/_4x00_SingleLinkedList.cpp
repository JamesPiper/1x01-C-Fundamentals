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
//
//
//
// MAJOR FLAW
// Node based on integer data type, but inputs of non-digits
// will result in corrupted data. This needs to be fixed.
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

static void GetNodeValueToAdd();
static void AddNode(int value);
static SLList* CreateNewNode(int value);
static void RemoveNode();
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
		printf("*   A. Add Node                                                              *\n");
		printf("*   B. Remove Node                                                           *\n");
		printf("*   C. Insert Node                                                           *\n");
		printf("*   D. Display Nodes                                                         *\n");
		printf("*                                                                            *\n");
		printf("*   Z. Return                                                                *\n");
		printf("*   X. Exit                                                                  *\n");
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
			RemoveNode();
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

static void RemoveNode() {

	printf("------------------------------------------------------------------------------\n");
	printf("Remove Node From The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
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
