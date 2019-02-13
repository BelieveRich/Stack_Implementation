// stack.h for ANSI C and C++
// (C) 2019 Richard Chen <richardchenahs@hotmail.com>

#include "stack.h"

using namespace std;

// Constant Declaration
static char* sDottedLine = "========================================================\n";

// Main Function
// This file implements data structure stack using 3 ways: array, linkedlist and vector
int main()
{
    cout << sDottedLine;
    cout << "  Stack Implementation  Arthur: Richard Chen 02/13/2019\n";
    cout << sDottedLine;
    cout << "Choose options:\n";
    cout << "1. Stack by Array\n2. Stack by Linked-List\n3. Stack by Vector\n:";
    uint16_t nOption;
    cin >> nOption;

    switch ((StackType)nOption)
    {
    case StackByArray:
    {
        // Stack by Array
        cout << "Okay. Executing stack by fixed array.\n";
        RunArrayStack();
        break;
    }
    case StackByLinkedList:
    {
        // Stack by Linked-List
        cout << "Okay. Executing stack by Linked-List.\n";
        RunLinkedListStack();
        break;
    }
    case StackByVector:
    {
        // Stack by Vector
        cout << "Okay. Executing stack by Vector.\n";
        RunVectorStack();
        break;
    }
    default:
        cout << "Invalid option!\n";
        break;
    }
    return 0;
}

// This function asks user what action they want to take
uint16_t QueryForAction()
{
    cout << sDottedLine;
    cout << "\nWhat action would you like to take?\n";
    cout << "1. Push value\n2. Pop value\n3. Show stack values\nOr......\n0. Exit\n";
    cout << sDottedLine << ":";
    uint16_t nInput = 0;
    cin >> nInput;
    return nInput;
}

void RunLinkedListStack()
{
    QueryForAction();
}

void RunVectorStack()
{
    QueryForAction();
}