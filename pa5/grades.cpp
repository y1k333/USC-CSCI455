// Name: Kai Yang
// USC NetID: kaiyang
// CSCI 455 PA5
// Fall 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

#include <vector>

void printCmdSummary() {
    cout << "Valid commands are: " << endl; 
    cout << "insert(name score), change(name score), lookup(name), " << endl;    
    cout << "remove(name), print(all the name and score), size(number of entries), " << endl;
    cout << "stats(), help(brief command summary) , quit(exit the program)."<< endl;

}

int main(int argc, char * argv[]) {

    // gets the hash table size from the command line

    int hashSize = Table::HASH_SIZE;

    Table * grades;  // Table is dynamically allocated below, so we can call
                    // different constructors depending on input from the user.

    if (argc > 1) {
        hashSize = atoi(argv[1]);  // atoi converts c-string to int

        if (hashSize < 1) {
            cout << "Command line argument (hashSize) must be a positive number" << endl;
            return 1;
    }

    grades = new Table(hashSize);

    }
    else {   // no command line args given -- use default table size
        grades = new Table();
    }


    grades->hashStats(cout);

    // add more code here
    // Reminder: use -> when calling Table methods, since grades is type Table*

    string cmd;
    char c;
    string name;
    int score;
    bool keepgoing = true;
    bool inserted;
    int * scorep;
    bool removed;

    printCmdSummary();

    do {
        cout << "cmd> ";
        cin >> cmd;
        if (cmd == "stats") {
            c = 't';
        }else {
            c = cmd[0];
        }
        if (c == 'i' || c == 'c') {
            cin >> name;
            cin >> score;
        }else if (c == 'l' || c == 'r') {
            cin >> name;
        }
        if (cin.fail()) {
            cout << "ERROR: input stream failed." << endl;
            keepgoing = false;
        }else {
            switch(c) {
                case 'i':
                    inserted = grades->insert(name, score);
                    if (!inserted) cout << "name was already presented." << endl;
                    break;
                case 'c':
                    scorep = grades->lookup(name);
                    if (scorep == NULL) {
                        cout << "name is not present." << endl;
                    }else {
                        (*scorep) = score;
                    }
                    break;
                case 'l':
                    scorep = grades->lookup(name);
                    if (scorep == NULL) {
                        cout << "name is not present." << endl;
                    }else {
                        cout << "the score is: " << (*scorep) << endl;
                    }
                    break;
                case 'r':
                    removed = grades->remove(name);
                    if (!removed) {
                        cout << "name is not present." << endl;
                    }
                    break;
                case 'p':
                    grades->printAll();
                    break;
                case 's':
                    cout << "number of entries is: " << grades->numEntries() << endl;
                    break;
                case 't':
                    grades->hashStats(cout);
                    break;
                case 'h':
                    printCmdSummary();
                    break;
                case 'q':
                    keepgoing = false;
                    break;
                default:
                    cout << "ERROR: Invalid command." << endl;
                    printCmdSummary();
                    break;
            }
         }
    }while (keepgoing);
    

    return 0;
}




