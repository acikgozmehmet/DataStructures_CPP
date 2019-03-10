// Lab - Standard Template Library - Part 3 - Queues
// MEHMET, ACIKGOZ

#include <iostream>
#include <string>
#include <queue>
#include<iomanip>
using namespace std;

void displayMenu(void);                     // displays the menu for choice
void inputTransaction(queue<double> & arr); // asks for the transactions
void printReport(queue<double> & arr);      // prints the final report


int main()
{
    queue<double> numbers;
    bool done = false;
    int choice;

    while (!done) {

		cout << "----------------------------" <<endl;
        cout <<"Transactions queued : " << numbers.size() << endl;

        do {
            displayMenu();
            cout <<">> ";
            cin >> choice;
        }while ( choice != 1 && choice != 2 );


        if (choice == 1)
            inputTransaction(numbers);
        else if (choice == 2)
        {
            printReport(numbers);
            done = true;
        }

        else
        {
            cout <<"Invalid number. Enter choice again" << endl;
        }


        cout << endl;


    }




    cin.ignore();
    cin.get();
    return 0;
}



// displays the menu
// @param NONE
// @return NONE, prints the dmenu on the screen

void displayMenu(void){
    cout << endl;
    cout <<"1. Enqueue transaction\t"
         <<"2. Continue" << endl << endl;
}


// asks for the amount and stores it in the queue
// @param  queue container to be updated which is passed by reference
// @return NONE, updated queue container will be return by reference


void inputTransaction(queue<double> & arr){
    double amount;
    cout <<"Enter amount ( positive or negative ) for next transaction : " ;
    cin >> amount;
    arr.push(amount);
}


// prints the transactions and reports the balance
// @param queue container passed by reference
// @return NONE

void printReport(queue<double> &arr)
{
    double finalBalance = 0;
    cout << setprecision(2) << fixed << showpoint; // formatting the output
    while (!arr.empty())
    {
        cout << setw(8) << arr.front() <<" pushed to account" << endl;
        finalBalance += arr.front();
        arr.pop();
    }

    cout << endl;
    cout <<"Final balance: $" << finalBalance << endl<< endl;
    cout <<"Goodbye"<< endl;
}
