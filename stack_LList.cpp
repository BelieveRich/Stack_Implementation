// stack_LList.cpp for ANSI C and C++
// (C) 2019 Richard Chen <richardchenahs@hotmail.com>

#include "stack.h"

using namespace std;

// Constant Declaration
static bool bExit = false;
static char* sDottedLine = "========================================================\n";

// Type Define, Stack Link List Node
struct NodeType
{
    int16_t val;
    NodeType* prev;   // Point to previous node of stack
};

void RunLinkedListStack()
{
    NodeType* HEAD = new NodeType;
    memset(HEAD, 0, sizeof(NodeType));
    NodeType* ptrStackTop = NULL;
    int count = 0;

    do
    {
        uint16_t nAction = QueryForAction();
        StackOperationType eAction = (StackOperationType)nAction;

        if (0 == nAction)
        {
            cout << "\nExiting....\n";
            bExit = true;

            // Free all the allocated memories
            while (ptrStackTop != NULL)
            {
                NodeType* tmp = ptrStackTop->prev;
                delete ptrStackTop;
                ptrStackTop = tmp;
            }
        }
        else
        {
            if (eAction == Push)
            {
                // LinkedList has no size limitation as
                // it is dynamically allocated on runtime
                int16_t nInputVal;
                cout << "\nEnter value to push:";
                cin >> nInputVal;

                // Create a new node, and set new node's prev node as prev top
                // Then set new top to the new node
                NodeType* newNode = new NodeType;
                newNode->val = nInputVal;
                newNode->prev = ptrStackTop;
                ptrStackTop = newNode;
                count++;
            }
            else if (eAction == Pop)
            {
                // Kill top, then Set top as top->prev
                NodeType* tmp = ptrStackTop->prev;
                delete ptrStackTop;
                ptrStackTop = tmp;
                count--;
            } else if (eAction == ShowStack)
            {
                int tmp_count = count;
                NodeType* traverse_node = ptrStackTop;
                if (traverse_node == NULL)
                {
                    cout << "Empty stack. Nothing to show\n";
                }
                while (traverse_node != NULL)
                {
                    cout << "-------------------\n";
                    cout << "Level: " << tmp_count << " Value: " << traverse_node->val << endl;
                    traverse_node = traverse_node->prev;
                    tmp_count--;
                }
            }
        }
    } while (bExit != true);
    return;
}