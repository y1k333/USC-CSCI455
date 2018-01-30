// Name:Kai Yang
// USC NetID:kaiyang
// CSCI 455 PA5
// Fall 2017


//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

using namespace std;

struct Node {
    string key;
    int value;

    Node *next;

    Node(const string &theKey, int theValue);

    Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

// inserts node at the front of list
void listInsert(ListType & list, string key, int value);

// appends node at the end of list
void listAppend(ListType & list, string key, int value);

//looks for a specific node
int * listLookup(ListType & list, string target);

//removes a node
bool listRemove(ListType & list, string target);

//print the list
void listPrint(ListType & list);

//return the size of the list
int listSize(ListType & list);




// keep the following line at the end of the file
#endif
