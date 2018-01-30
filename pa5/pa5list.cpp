// Name:Kai Yang
// USC NetID:kaiyang
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {

    ListType theList = NULL;

    listInsert(theList, "d", 4);
    listPrint(theList);
    listInsert(theList, "c", 3);
    listPrint(theList);
    listInsert(theList, "b", 2);
    listPrint(theList);
    listInsert(theList, "a", 1);
    listPrint(theList);
    listAppend(theList, "e", 5);
    listPrint(theList);

    int * x = listLookup(theList, "a");
    cout << *x << endl;

    bool y = listRemove(theList, "d");

    listPrint(theList);




    return 0;
}
