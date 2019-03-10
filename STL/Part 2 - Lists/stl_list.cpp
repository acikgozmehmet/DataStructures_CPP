// Lab - Standard Template Library - Part 2 - Lists
// MEHMET, ACIKGOZ

#include <iostream>
#include <list>
#include <string>
using namespace std;

void addRecordToFront(list<string> & liste); // adds a record to the front
void addRecordToBack(list<string> &);        // adds a record to the back
void popRecordFromFront(list<string> &);     // removes a record from the front
void popRecordFromBack(list<string> &);      // removes a record from the front

void printRecords(list<string> liste);       // prints out the records on the screen

int main()
{
    list<string> states;
    bool done = false;

    while (!done) {

		cout << "----------------------------" <<endl;
		cout << "State list size: " << states.size() << endl << endl;
        cout << "1. Add a new state to front\t"
             << "2. Add a new state to back\n"
             << "3. Pop front state\t\t"
             << "4. Pop back state\n"
             << "5. Continue"<< endl;

        cout << endl;
        cout << ">> ";
        int choice;
        cin >> choice;

        switch (choice){
            case 1:
                cout << endl;
                addRecordToFront(states);
                break;
            case 2:
                cout << endl;
                addRecordToBack(states);
                break;
            case 3:
                cout << endl;
                popRecordFromFront(states);
                break;
            case 4:
                cout << endl;
                popRecordFromBack(states);
                break;
            case 5:
                cout << endl;
                cout <<"ORIGINAL LIST:" << endl;
                printRecords(states);
                cout << endl;

                cout <<"REVERSED LIST:" << endl;
                states.reverse();
                printRecords(states);
                cout << endl;

                cout <<"SORTED LIST:" << endl;
                states.sort();
                printRecords(states);
                cout << endl;

                cout <<"REVERSE-SORTED LIST:" << endl;
                states.reverse();
                printRecords(states);
                cout << endl;

                cout <<"Goodbye" << endl;
                done = true;
        }
    } // end of while loop

    cin.ignore();
    cin.get();
    return 0;
}

// adds a record to the front
// @param list container to be updated
// @return updated list container will be return by reference

void addRecordToFront(list<string> &liste)
{
    string stateName;
    cout <<"ADD STATE TO FRONT" << endl;
    cout <<"Enter new state name: " ;

    do {
        cin >> stateName;
    } while (stateName.empty()); // testing the stateName if it is empty...

    liste.push_front(stateName);
    cout << endl;

}


// adds a record to the back
// @param list container to be updated
// @return updated list container will be return by reference

void addRecordToBack(list<string> &liste)
{
    string stateName;
    cout <<"ADD STATE TO BACK" << endl;
    cout <<"Enter new state name : " ;

    do {
        cin >> stateName;
    } while (stateName.empty()); // testing the stateName if it is empty...

    liste.push_back(stateName);
    cout << endl;
}



// pops a record from the front
// @param list container to be updated
// @return updated list container will be return by reference

void popRecordFromFront(list<string> &liste)
{
    cout <<"REMOVE STATE FROM FRONT" << endl;
    cout << liste.front() <<  " removed" << endl;
    //cout << *(liste.begin()) << " removed" << endl;  // that also works ...
    liste.pop_front();
    cout << endl;
}



// pops a record from the back
// @param list container to be updated
// @return updated list container will be return by reference

void popRecordFromBack(list<string> &liste)
{
    cout <<"REMOVE STATE FROM BACK" << endl;
    cout << (liste.back()) << " removed" << endl;
    liste.pop_back();
    cout << endl;

}



// prints the records to the screen
// @param list container to be printed
// @return prints the records to the screen


void printRecords(list<string> liste)
{

    for (list<string>::iterator it = liste.begin(); it != liste.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
