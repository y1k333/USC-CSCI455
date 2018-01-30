// Name:Kai Yang
// USC NetID:kaiyang
// CSCI 455 PA5
// Fall 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {

    numOfEntries = 0;
    hashSize = HASH_SIZE;
    datap = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) {
        datap[i] = NULL;
    }
}


Table::Table(unsigned int hSize) {

    numOfEntries = 0;
    hashSize = hSize;
    datap = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) {
        datap[i] = NULL;
    }
}


int * Table::lookup(const string &key) {

    return listLookup(datap[hashCode(key)], key);

}

bool Table::remove(const string &key) {

    bool removed = listRemove(datap[hashCode(key)], key);
    if (removed) {
        numOfEntries--;
    }
    return removed;

}

bool Table::insert(const string &key, int value) {

    if (listLookup(datap[hashCode(key)], key) != NULL) {
        return false;
    }
    listInsert(datap[hashCode(key)], key, value);
    numOfEntries++;
    return true;
}

int Table::numEntries() const {

    return numOfEntries;

}


void Table::printAll() const {

    for (int i = 0; i < hashSize; i++) {
        ListType list = datap[i];
        listPrint(list);
    }

}

void Table::hashStats(ostream &out) const {

    out << "Number of buckets: " << hashSize << endl;
    out << "Number of entries: " << numOfEntries << endl;
    int numOfNEB = 0;
    int longestChain = 0;
    for (int i = 0; i < hashSize; i++) {
        if (datap[i] != NULL) {
            numOfNEB++;
            longestChain = max(listSize(datap[i]), longestChain);
        }
    }
    out << "Number of non-empty buckets: " << numOfNEB << endl;
    out << "Longest Chain: " << longestChain << endl;

}


// add definitions for your private methods here
