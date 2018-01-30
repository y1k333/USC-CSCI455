// Name:Kai Yang
// USC NetID:kaiyang
// CSCI 455 PA5
// Fall 2017


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
    key = theKey;
    value = theValue;
    next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
    key = theKey;
    value = theValue;
    next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

// inserts node at the front of list
void listInsert(ListType & list, string key, int value) {

    list = new Node(key, value, list);

}

// appends node at the end of list
void listAppend(ListType & list, string key, int value) {

    ListType p = list;

    if (p == NULL) {
        listInsert(list, key, value);
        return;
    }

    while (p->next != NULL) {
        p = p->next;
    }
    ListType np = new Node(key, value);
    p->next = np;

}


//looks for a specific node
int * listLookup(ListType & list, string target) {

    ListType p = list;
    while (p != NULL) {
        if (p->key == target) {
            return &(p->value);
        }
        p = p->next;
    }
    return NULL;
}

//removes a node
bool listRemove(ListType & list, string target) {

    ListType p = list;
    if (p->key == target) {
        list = list->next;
        delete p;
        return true;
    }
    while (p->next != NULL) {
        if (p->next->key == target) {
            ListType np = p->next->next;
            delete p->next;
            p->next = np;
            return true;
        }
        p = p->next;
    }
    return false;
}

//print the list
void listPrint(ListType & list) {

    ListType p = list;
    while (p != NULL) {
        cout << p->key << " " << p->value << endl;
        p = p->next;
    }
}

//return the size of the list
int listSize(ListType & list) {

    ListType p = list;
    int size = 0;
    while (p != NULL) {
        size++;
        p = p->next;
    }
    return size;

}
