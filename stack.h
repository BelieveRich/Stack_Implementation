#pragma once
// stack.h for ANSI C and C++
// (C) 2019 Richard Chen <richardchenahs@hotmail.com>

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <limits.h>
#include <math.h>
#include <cstring>
#include <cstdint>

static int STACK_SIZE = 100;

// Type Declaration
enum StackType
{
    StackByArray = 1,
    StackByLinkedList,
    StackByVector
};

enum StackOperationType
{
    Push = 1,
    Pop,
    ShowStack
};

// Function Declaration 
void RunArrayStack();

void RunLinkedListStack();

void RunVectorStack();

uint16_t QueryForAction();

#endif