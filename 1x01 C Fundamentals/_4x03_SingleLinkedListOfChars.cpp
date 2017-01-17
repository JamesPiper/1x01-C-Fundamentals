//==============================================================================
// 2017.01.15 by James Piper, james@jamespiper.com
// 
// Taking code from _4x02_SingleLinkedListOfChar and modify
// to have an array of chars instead of a single char.
//
// Since this is a sorted list of strings, how to compare one string to another.
// Any characters that can be typed in with keyboard will be accepted.
// 'A' should compare as equal with 'a', 'B' with 'b' etc.
// Non-alpha characters shouldn't be a problem.
// Using a function to put all in upper or lower case won't affect non-alpha.
// Igore rules concerning leading 'the' or 'a' since it could be a list of names.
// Store inputs as is, but could create hidden sort field, but trading off storage
// cost with processing at RT.
//
// Collisions don't happen since add or insert will allow two nodes with the same value.
// Issue arises on removing one of the two nodes. Takes first one matched.
// Could adjust code to not allow add or insert for an existing node value.
//
//==============================================================================
// Struggling with this one.
// This code, ListHead = NewNode;, in AddNode 'works' except when it comes time
// to display the data it doesn't show correctly. I think it's storing and showing
// the address to the char array...yet NewNode->Value has the char array.
// Tried different things and they aren't working. Ugh.
//
//==============================================================================
// Figured out what is happening to the char arry in ListHead / NewNode.
// They value was pointing to a variable that gets distroyed when leaving calls.
// Need to malloc memory for the char* value to make it stick and use strcpy
// otherwise the Node->Value will point to junk.
//
// Using strlwr in my comparisons for inserting but it's calling the function and
// changing the underlying data. Not what I want. There's several options.
// 1. Don't bother with upper or lower. Not good.
// 2. Find a strcmp that does ignores case. Not sure where that is.
//    I could write a function.
// 3. Store a sort field in the struct.
// 4. Create temp variables.
// 
// C doesn't have a built-in case insensitive string compare function.
// There must be many online, but I should write one b/c that's how you learn.
//==============================================================================
// 
// TODO
// 1. Compares in remove functions.
// 2. Compare function - APPLES should come after APPLE
// 3. Call free for char* mallocs.
//
//==============================================================================

#include "stdafx.h"
#include "1x01 C Fundamentals.h"

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctype.h>

typedef enum Boolean { False, True };

// For Single Linked List
typedef struct SLListChars  
{
  char* Value;
  struct SLListChars* Next;
} SLListChars;

// Start of the list.
SLListChars* ListHead;

// Function prototypes.
static SLListChars* CreateNewNode(char* value);
static void GetNodeValueToAdd();
static void AddNode(char* value);

static void GetNodeValueToRemove();
static void RemoveNode(char* value);

static void GetNodeValueToInsert();
static void InsertNode(char* value);

static void DisplayNodes();
static void AtExitCleanup();

static int StringCompare(char* string1, char* string2);

void _4x03_SingleLinkedListOfChars() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;

	atexit(AtExitCleanup);

	// Initialize
	ListHead = NULL;
	
	do {

		/////////////////////////////////////////////////////////////////////////////////////
		// Need to learn the coding method for debug only code.
		/////////////////////////////////////////////////////////////////////////////////////
		//if (ListHead != NULL) {
		//	printf("[ListHead in _4x03_SingleLinkedListOfChars:\n");
		//	printf(" Memory Location: %X\n", ListHead);
		//	printf(" Value: %s at memory location %X\n", ListHead->Value, ListHead->Value);
		//	printf(" Next: %X]\n", ListHead->Next);
		//}
		/////////////////////////////////////////////////////////////////////////////////////

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
	scanf("%s", &Inputs);
	/////////////////////////////////////////////////////////////////////////////////////
	//printf("[Inputs in GetNodeValueToAdd '%s' at memory location %X]\n", Inputs, Inputs);
	//printf("[Value in GetNodeValueToAdd '%s' at memory location %X]\n", Value, Value);
	/////////////////////////////////////////////////////////////////////////////////////
	AddNode(Inputs);
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void AddNode(char* value) {
	
	/////////////////////////////////////////////////////////////////////////////////////
	//printf("[Value in AddNode '%s' at memory location %X]\n", value, value);
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a new node.
	SLListChars* NewNode = CreateNewNode(value);

	// Add node to the end of the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			// Add to the end.
			SLListChars* Traverser = ListHead;
			while (Traverser->Next != NULL) {
				Traverser = Traverser->Next;
			}
			Traverser->Next = NewNode;
		}
		else 
			// First node.
			ListHead = NewNode;
		printf("Node added to the list with value '%s' at location %X.\n", value, NewNode);
	}
	else 
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	//printf("[ListHead in AddNode:\n");
	//printf(" Memory Location: %X\n", ListHead);
	//printf(" Value: %s at memory location %X\n", ListHead->Value, ListHead->Value);
	//printf(" Next: %X]\n", ListHead->Next);
	//
	//printf("[NewNode in AddNode:\n");
	//printf(" Memory Location: %X\n", NewNode);
	//printf(" Value: %s at memory location %X\n", NewNode->Value, NewNode->Value);
	//printf(" Next: %X]\n", NewNode->Next);
	/////////////////////////////////////////////////////////////////////////////////////

}

static SLListChars* CreateNewNode(char* value) {

	/////////////////////////////////////////////////////////////////////////////////////
	//printf("[Value in CreateNewNode '%s' at memory location %X]\n", value, value);
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a pointer for new node.
	SLListChars* NewNode = (SLListChars*) malloc(sizeof(SLListChars));

	// Test if not null
	if (NewNode != NULL) {
		/////////////////////////////////////////////////////////////////////////////////////
		// Major difference here from the other SLL implementations
		/////////////////////////////////////////////////////////////////////////////////////
		NewNode->Value = (char*) malloc(sizeof(strlen(value) + 1));
		strcpy(NewNode->Value, value);
		/////////////////////////////////////////////////////////////////////////////////////
		//NewNode->Value = Value;
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
		char Inputs[MAX_INPUT_CHARS];
		scanf("%s", &Inputs);
		RemoveNode(Inputs);
	} else
		printf("This list is empty.\n");
	
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void RemoveNode(char* value) {

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

	//if (value == ListHead->Value) {
	//if (strcmp(value, ListHead->Value) == 0) {
	//if (strcmp(strlwr(value), strlwr(ListHead->Value)) == 0) {
	if (StringCompare(value, ListHead->Value) == 0) {
		// Remove at start.
		ListHead = ListHead->Next;
		printf("Node with value '%s' removed from the list.\n", value);
	} else {
		// Search the list for node.
		SLListChars* Traverser = ListHead->Next;
		SLListChars* PrevNode = ListHead;
		Boolean LocationFound = False;
		Boolean NotEndOfList = True;
		while (LocationFound != True && NotEndOfList == True)  {
			if (Traverser->Next !=NULL) {
				//if (value == Traverser->Value) {
				//if (strcmp(value, Traverser->Value) == 0) {
				if (strcmp(strlwr(value), strlwr(Traverser->Value)) == 0) {
					LocationFound = True;
					PrevNode->Next = Traverser->Next;
					free(Traverser);
					printf("Node with value '%s' removed from the list.\n", value);
				} else {
					PrevNode = Traverser;
					Traverser = Traverser->Next;
				}
			} else {
				// At the end of the list.
				//if (value == Traverser->Value) {
				//if (strcmp(value, Traverser->Value) == 0) {
				if (strcmp(strlwr(value), strlwr(Traverser->Value)) == 0) {
					LocationFound = True;
					PrevNode->Next = NULL;
					free(Traverser);
					printf("Node with value '%s' removed from the list.\n", value);
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
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", &Inputs);
	InsertNode(Inputs);
	
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void InsertNode(char* value) {

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
	SLListChars* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			//if (value <= ListHead->Value) {
			//if (strcmp(strlwr(value), strlwr(ListHead->Value)) <= 0) {
			if (StringCompare(value, ListHead->Value) <= 0) {
				// Insert at start.
				NewNode->Next = ListHead;
				ListHead = NewNode;
			} else {
				// Search for insertion point.
				SLListChars* Traverser = ListHead;
				SLListChars* PrevNode = Traverser;
				Boolean LocationFound = False; 
				while (LocationFound != True) {
					// There's two possible scenarios.
					// 1. We've reached the end of the list, or,
					// 2. The insert value is less than or equal to the node value.
					if (Traverser->Next != NULL) {
						//if (value <= Traverser->Value) {
						//if (strcmp(strlwr(value), strlwr(Traverser->Value)) <= 0) {
						if (StringCompare(value, Traverser->Value) <= 0) {
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
						//if (value <= Traverser->Value) {
						//if (strcmp(strlwr(value), strlwr(Traverser->Value)) <= 0) {
						if (StringCompare(value, Traverser->Value) <= 0) {
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
		printf("Node inserted into the list with value '%s' at location %X.\n", value, NewNode);
	} else 
		printf("Problem allocating memory for new node.\n");
}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	
	/////////////////////////////////////////////////////////////////////////////////////
	//printf("[ListHead in DisplayNodes:\n");
	//printf(" Memory Location: %X\n", ListHead);
	//printf(" Value: %s\n", ListHead->Value);
	//printf(" Next: %X]\n", ListHead->Next);
	/////////////////////////////////////////////////////////////////////////////////////

	SLListChars* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("List item with value '%s' at memory location %X and next at %X\n",
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
	SLListChars* Traverser;
	while (ListHead != NULL) {
		Traverser = ListHead;
		ListHead = ListHead->Next;
		printf("Node memory freed at %X.\n", Traverser);
		free(Traverser);
	}
}

static int StringCompare(char* string1, char* string2) {

	// Compare string1 to string2 without regard to case.
	// Thus ABC is equal to abc or AbC and the other variations.

	// Returns
	// 0 if string1 is the same as string2
	// < 0 if string1 comes before string2
	// > 0 if string1 comes after string2

	/////////////////////////////////////////////////////////////////////////////////////
	// Ugh. I discovered that strlwr and strupr are not standard C,
	// yet it was presented as such on a C reference web site.
	// To use them or not? 
	// It would be possible to covert each char to ASCII 65 ('A') to 90 ('Z')
	// but that makes for longer code.
	// There are functions in ctype.h for lower or upper.
	//
	// Another issue. Calling strlwr changes the value of the argument.
	// Using 'const char*' in the function definition doesn't solve the problem.
	//
	// Easy to use int result = stricmp(string1, string2); but it's not std.
	//
	/////////////////////////////////////////////////////////////////////////////////////

	// To avoid reading past an array.
	int Length = strlen(string1);
	int LengthA = strlen(string1);
	int LengthB = strlen(string1);
	if (LengthB < LengthA) 
		Length = LengthB;

	char A, B;
	int result = 0;

	for (int i = 0; i < Length; i++) {
		A = tolower(string1[i]);
		B = tolower(string2[i]);
		// Want to keep result from previous compares.
		if (A == B) 
			result = result * result;
		else if (A <= B) 
			result = -1;
		else if (A >= B)
			result = 1;
	}

	return result;

}