// stack_array.cpp for ANSI C and C++
// (C) 2019 Richard Chen <richardchenahs@hotmail.com>

#include "stack.h"

using namespace std;

// Constant Declaration
static bool bExit = false;
static char* sDottedLine = "========================================================\n";

// This function allocates an array to build a stack
void RunArrayStack()
{
    uint16_t nAction = 0;
    StackOperationType eAction;
    // Initialize array for stack operation
    int16_t* ptrStack = new int16_t[STACK_SIZE];
    memset(ptrStack, 0, sizeof(int16_t)*STACK_SIZE);
    int stack_top = -1;

    do
    {
        nAction = QueryForAction();
        if (0 == nAction)
        {
            cout << "\nExiting....\n";
            bExit = true;
        }
        else
        {
            eAction = (StackOperationType)nAction;
            if (eAction == Push)
            {
                // Action: Push
                // First check if stack already hit the limit to push
                if (stack_top >= STACK_SIZE - 1)
                {
                    cout << "ERROR: Reach stack size limit. Cannot push.\n";
                }
                else
                {
                    // Stack can push the value
                    int16_t nInputVal;
                    cout << "\nEnter value to push:";
                    cin >> nInputVal;
                    ptrStack[++stack_top] = nInputVal;
                }
            }
            // Execute based on action request
            else if (eAction == Pop)
            {
                // Action: Pop the top
                if (stack_top <= -1)
                {
                    cout << "Stack is empty! Nothing to pop\n";
                }
                else
                {
                    // Reset the value to 0 and move the top down
                    ptrStack[stack_top--] = 0;
                }
            }
            else if (eAction == ShowStack)
            {
                // Action: Show stack values
                for (int i = stack_top; i >= 0; i--)
                {
                    if (i == stack_top)
                    {
                        cout << endl << endl << sDottedLine << "TOP OF STACK\n" << sDottedLine;
                    }
                    cout << "-------------------\n" << "Level: " << i << "  Value: " << ptrStack[i] << "\n";
                    if (i == 0)
                    {
                        cout << sDottedLine << "END OF STACK\n";
                    }
                }
            }
        }
    } while (bExit != true);

    // Free dynamic allocated memory
    delete ptrStack;
}