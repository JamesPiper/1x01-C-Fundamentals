/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x01 C Fundamentals
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.15
// File        : _4x03_SingleLinkedListOfChars.c
// Description : Single-linked list of char array as the data value.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 11.)
/////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////
// Struggling with this one.
// This code, ListHead = NewNode;, in AddNode 'works' except when it comes time
// to display the data it doesn't show correctly. I think it's storing and showing
// the address to the char array...yet NewNode->Value has the char array.
// Tried different things and they aren't working. Ugh.
//
/////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////
//
// TODO
// 1. Compares in remove functions.
// 2. Compare function - APPLES should come after APPLE
// 3. Call free for char* mallocs.
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
typedef struct SLListChars
{
  char* Value;
  struct SLListChars* Next;
} SLListChars;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
static SLListChars* CreateNewNode(char* value);
static void GetNodeValueToAdd();
static void AddNode(char* value);

static void GetNodeValueToRemove();
static void RemoveNode(char* value);

static void GetNodeValueToInsert();
static void InsertNode(char* value);

static void DisplayNodes();
static void ClearList();

static void AtExitCleanup();

static void TestCode_F_SingleLinkedListOfChars();
static void TestCode_G_SingleLinkedListOfChars();
static void TestCode_H_SingleLinkedListOfChars();
static void TestCode_I_SingleLinkedListOfChars();
static void TestCode_J_SingleLinkedListOfChars();
static void TestCode_K_SingleLinkedListOfChars();
static void TestCode_L_SingleLinkedListOfChars();
static void TestCode_M_SingleLinkedListOfChars();
static void TestCode_N_SingleLinkedListOfChars();
static void TestCode_O_SingleLinkedListOfChars();
static void TestCode_P_SingleLinkedListOfChars();
static void TestCode_Q_SingleLinkedListOfChars();
/////////////////////////////////////////////////////////////////////////////////////
// Start of the list.
/////////////////////////////////////////////////////////////////////////////////////
SLListChars* ListHead;

/////////////////////////////////////////////////////////////////////////////////////
// Main function.
/////////////////////////////////////////////////////////////////////////////////////
void _4x03_SingleLinkedListOfChars() {

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
#define DEBUG_403
#ifdef DEBUG_403
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
#undef DEBUG_403
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
			TestCode_F_SingleLinkedListOfChars();
		else if (Choice == 'g')
			TestCode_G_SingleLinkedListOfChars();
		else if (Choice == 'h')
			TestCode_H_SingleLinkedListOfChars();
		else if (Choice == 'i')
			TestCode_I_SingleLinkedListOfChars();
		else if (Choice == 'j')
			TestCode_J_SingleLinkedListOfChars();
		else if (Choice == 'k')
			TestCode_K_SingleLinkedListOfChars();
		else if (Choice == 'l')
			TestCode_L_SingleLinkedListOfChars();
		else if (Choice == 'm')
			TestCode_M_SingleLinkedListOfChars();
		else if (Choice == 'n')
			TestCode_N_SingleLinkedListOfChars();
		else if (Choice == 'o')
			TestCode_O_SingleLinkedListOfChars();
		else if (Choice == 'p')
			TestCode_P_SingleLinkedListOfChars();
		else if (Choice == 'q')
			TestCode_Q_SingleLinkedListOfChars();
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
	scanf("%s", Inputs);
	AddNode(Inputs);

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void AddNode(char* value) {

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_403
	#ifdef DEBUG_403
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Value in AddNode '%s' at memory location %X\n", value, &value);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	/////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	TrimWhitespace(value);
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
		} else {
			// First node.
			ListHead = NewNode;
			/////////////////////////////////////////////////////////////////////////////////////
			// Assigning NewNode to ListHead, when the first node is created, works for ints.
			// Yet something odd is happening with char or char*.
			// In debug mode, ListHead has null value after the assign, yet
			// printing out the values works. Makes no sense.
			// And, it doesn't seem to matter if assignment is done for each member.
			/////////////////////////////////////////////////////////////////////////////////////
			//ListHead->Value = NewNode->Value;
			//ListHead->Next = NewNode->Next;
			/////////////////////////////////////////////////////////////////////////////////////
			#ifdef DEBUG_403
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("ListHead in AddNode\n");
			printf("Memory Location: %X | Value: '%s' | Next: %X\n",
				ListHead, ListHead->Value, ListHead->Next);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			/////////////////////////////////////////////////////////////////////////////////////
		}
		printf("Node added to the list at location %X with value '%s'\n", NewNode, value);
	} else
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG_403
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("NewNode in AddNode:\n");
	printf("Memory Location: %X | Value: '%s' | Next: %X\n",
		NewNode, NewNode->Value, NewNode->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_403
	/////////////////////////////////////////////////////////////////////////////////////

}

static SLListChars* CreateNewNode(char* value) {

	// Create a pointer for new node.
	SLListChars* NewNode = (SLListChars*) malloc(sizeof(SLListChars));

	// Test if not null
	if (NewNode != NULL) {
		/////////////////////////////////////////////////////////////////////////////////////
		// Major difference here from the other SLL implementations
		NewNode->Value = (char*) malloc(sizeof(strlen(value) + 1));
		if (NewNode->Value != NULL)
			strcpy(NewNode->Value, value);
		/////////////////////////////////////////////////////////////////////////////////////
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
	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", Inputs);
	RemoveNode(Inputs);

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

static void RemoveNode(char* value) {

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
		/////////////////////////////////////////////////////////////////////////////////////
		if (StringCompare(value, ListHead->Value) == 0) {
		/////////////////////////////////////////////////////////////////////////////////////
			// Remove at start.
			SLListChars* temp = ListHead;
			/////////////////////////////////////////////////////////////////////////////////////
			//#define DEBUG_403
			#ifdef DEBUG_403
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Value before: '%c' at %X\n", temp->Value, temp);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			/////////////////////////////////////////////////////////////////////////////////////
			ListHead = ListHead->Next;
			free(temp);
			printf("Node removed from the list with value '%s'\n", value);
			/////////////////////////////////////////////////////////////////////////////////////
			#ifdef DEBUG_403
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Value after: '%c' at %X\n", temp->Value, temp);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			#endif
			#undef DEBUG_403
			/////////////////////////////////////////////////////////////////////////////////////
		} else {
			// Search the list for node.
			if (ListHead->Next != NULL) {
				SLListChars* Traverser = ListHead->Next;
				SLListChars* PrevNode = ListHead;
				Boolean LocationFound = False;
				Boolean NotEndOfList = True;
				while (LocationFound != True && NotEndOfList == True)  {
					if (Traverser->Next !=NULL) {
						/////////////////////////////////////////////////////////////////////////////////////
						if (StringCompare(value, Traverser->Value) == 0) {
						/////////////////////////////////////////////////////////////////////////////////////
							LocationFound = True;
							PrevNode->Next = Traverser->Next;
							free(Traverser);
							printf("Node removed from the list with value '%s'\n", value);
						} else {
							PrevNode = Traverser;
							Traverser = Traverser->Next;
						}
					} else {
						// At the end of the list.
						/////////////////////////////////////////////////////////////////////////////////////
						if (StringCompare(value, Traverser->Value) == 0) {
						/////////////////////////////////////////////////////////////////////////////////////
							LocationFound = True;
							PrevNode->Next = NULL;
							free(Traverser);
							printf("Node removed from the list with value '%s'\n", value);
						} else {
							NotEndOfList = False;
							printf("***** Value '%s' not found in the list. List unchanged. *****\n", value);
						}
					}
				}
			} else {
				// Only one item in the list and not a match.
				if (value != ListHead->Value)
					printf("***** Value '%s' not found in the list. List unchanged. *****\n", value);
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

	char Inputs[MAX_INPUT_CHARS];
	scanf("%s", Inputs);
	InsertNode(Inputs);

	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");
}

static void InsertNode(char* value) {

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
	TrimWhitespace(value);
	/////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_403
	#ifdef DEBUG_403
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Value in InsertNode '%s' at memory location %X\n", value, &value);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	/////////////////////////////////////////////////////////////////////////////////////

	// Create a new node.
	SLListChars* NewNode = CreateNewNode(value);

	// Insert new node into the list.
	if (NewNode != NULL) {
		if (ListHead != NULL) {
			/////////////////////////////////////////////////////////////////////////////////////
			if (StringCompare(value, ListHead->Value) <= 0) {
			/////////////////////////////////////////////////////////////////////////////////////
				// Insert at start.
				NewNode->Next = ListHead;
				ListHead = NewNode;
				/////////////////////////////////////////////////////////////////////////////////////
				//ListHead->Value = NewNode->Value;
				//ListHead->Next = NewNode->Next;
				/////////////////////////////////////////////////////////////////////////////////////
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
						/////////////////////////////////////////////////////////////////////////////////////
						if (StringCompare(value, Traverser->Value) <= 0) {
						/////////////////////////////////////////////////////////////////////////////////////
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
						/////////////////////////////////////////////////////////////////////////////////////
						if (StringCompare(value, Traverser->Value) <= 0) {
						/////////////////////////////////////////////////////////////////////////////////////
							PrevNode->Next = NewNode;
							NewNode->Next = Traverser;
						} else
							Traverser->Next = NewNode;
					}
				}
			}
		} else {
			// First node on the list.
			ListHead = NewNode;
			/////////////////////////////////////////////////////////////////////////////////////
			//ListHead->Value = NewNode->Value;
			//ListHead->Next = NewNode->Next;
			/////////////////////////////////////////////////////////////////////////////////////
		}
		printf("Node inserted into the list at location %X with value '%s'\n", NewNode, value);
	} else
		printf("Problem allocating memory for new node.\n");

	/////////////////////////////////////////////////////////////////////////////////////
	#ifdef DEBUG_403
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("ListHead in InsertNode\n");
	printf("Memory Location: %X | Value: '%s' | Next: %X\n",
		ListHead, ListHead->Value, ListHead->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_403
	/////////////////////////////////////////////////////////////////////////////////////

}

static void DisplayNodes() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	/////////////////////////////////////////////////////////////////////////////////////
	//#define DEBUG_403
	#ifdef DEBUG_403
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("ListHead in DisplayNodes\n");
	printf("Memory Location: %X | Value: '%s' | Next: %X\n",
		ListHead, ListHead->Value, ListHead->Next);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	#endif
	#undef DEBUG_403
	/////////////////////////////////////////////////////////////////////////////////////

	SLListChars* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("Item at memory location %X next at %6X with value '%s'\n",
				Traverser, Traverser->Next, Traverser->Value);
			Traverser = Traverser->Next;
		} while (Traverser !=NULL);
	}
	else
		printf("The list empty.\n");

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

static void ClearList() {

	printf("------------------------------------------------------------------------------\n");
	printf("Clearing The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Traverse the list and free nodes.\n");

	SLListChars* Traverser;
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
	SLListChars* Traverser;
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
static void TestCode_F_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("F - Unit Testing - Clear List\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Create list with add.\n");
	char str[MAX_INPUT_CHARS] = "abc";
	AddNode(str);
	strcpy(str, "def");
	AddNode(str);
	strcpy(str, "ghi");
	AddNode(str);
	strcpy(str, "jkl");
	AddNode(str);
	printf("\n");
	DisplayNodes();

	printf("Call clear list function.\n");
	printf("\n");
	ClearList();
	DisplayNodes();
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_G_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("G - Unit Testing - Add Nodes To List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Add Some Nodes (Not a sorted list)\n");
	printf("------------------------------------------------------------------------------\n");
	char str[MAX_INPUT_CHARS] = "lemon";
	AddNode(str);
	strcpy(str, "lime");
	AddNode(str);
	strcpy(str, "orange");
	AddNode(str);
	strcpy(str, "clemintine");
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_H_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("H - Unit Testing - Insert Node To Empty List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	char str[MAX_INPUT_CHARS] = "orange";
	InsertNode(str);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_I_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("I - Unit Testing - Insert Node To The Start Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Create list with add.\n");
	char str[MAX_INPUT_CHARS] = "lemon";
	AddNode(str);
	strcpy(str, "lime");
	AddNode(str);
	strcpy(str, "orange");
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	printf("\n");

	strcpy(str, "clemintine");
	InsertNode(str);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_J_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("J - Unit Testing - Insert Node To The Middle Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	printf("Create list with add.\n");
	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	strcpy(str, "lemon");
	AddNode(str);
	strcpy(str, "orange");
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	printf("\n");
	printf("\n");

	strcpy(str, "lime");
	InsertNode(str);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_K_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("K - Unit Testing - Insert Node To The End Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();

	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	strcpy(str, "lemon");
	AddNode(str);
	strcpy(str, "lime");
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	printf("\n");

	strcpy(str, "orange");
	InsertNode(str);
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_L_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("L - Unit Testing - Remove Node From Empty List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Attempt to remove item from empty list.\n");
	printf("\n");
	RemoveNode("lime");

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_M_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("M - Unit Testing - Remove Node Not In The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with an add.\n");
	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	printf("\n");

	printf("Attempt to remove an item.\n");
	RemoveNode("lemon");
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_N_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("N - Unit Testing - Remove Node From One-item List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with an add.\n");
	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	printf("\n");

	printf("Attempt to remove an item.\n");
	RemoveNode("clemintine");
	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_O_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("O - Unit Testing - Remove Node From The Start Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	strcpy(str, "lemon");
	AddNode(str);
	strcpy(str, "lime");
	AddNode(str);
	strcpy(str, "orange");
	AddNode(str);
	printf("\n");

	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode("clemintine");

	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_P_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("P - Unit Testing - Remove Node From The Middle Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	strcpy(str, "lemon");
	AddNode(str);
	strcpy(str, "lime");
	AddNode(str);
	strcpy(str, "orange");
	AddNode(str);
	printf("\n");

	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode("lime");

	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}

static void TestCode_Q_SingleLinkedListOfChars() {

	printf("==============================================================================\n");
	printf("Q - Unit Testing - Remove Node From The End Of The List\n");
	printf("==============================================================================\n");
	printf("\n");

	ClearList();
	printf("Create list with add.\n");
	char str[MAX_INPUT_CHARS] = "clemintine";
	AddNode(str);
	strcpy(str, "grapefruit");
	AddNode(str);
	strcpy(str, "lemon");
	AddNode(str);
	strcpy(str, "lime");
	AddNode(str);
	strcpy(str, "orange");
	AddNode(str);
	printf("\n");

	printf("\n");
	printf("Attempt to remove an item.\n");
	RemoveNode("orange");

	printf("\n");
	DisplayNodes();

	printf("\n");
	printf("==============================================================================\n");
	system("pause");

}
