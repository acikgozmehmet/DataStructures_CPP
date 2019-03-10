// Lab - Standard Template Library - Part 4 - Stacks
// MEHMET, ACIKGOZ

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void printStack(stack<char> & arr);     // prints the stack

int main()
{
    stack<char> letters;
    string text;



    cout << "Enter the next letter of the word , or UNDO to undo , or DONE to stop ." << endl;
    cout <<">> ";
    cin >> text;

    while  ( (text != "DONE") && (text != "done") ) {

        if (text != "UNDO" && text != "undo")
            letters.push(text[0]);

        cout <<">> ";
        cin >> text;

        if (text == "UNDO" || text == "undo")
        {
            cout << "\tRemoved " << letters.top() << endl;
            letters.pop();
        }

    }

    // printing the stack ...
    cout << endl << endl;
    printStack(letters);


    cin.ignore();
    cin.get();
    return 0;
}

// prints out the stack container which is passed by reference (in reverse order)
// @param stack container passed by reference
// @return NONE

void printStack(stack<char> & arr){
    cout <<"Finished word : " ;

    while (!arr.empty()) {
        cout << arr.top();
        arr.pop();
    }
    cout << endl;
}
