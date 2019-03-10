#include<iostream>
#include "ArrayStack.hpp"
#include <cstdlib>


using namespace std;

void ClearScreen()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "cls" );
        #else
            system( "clear" );
        #endif
    }


int displayMenu(){
    int choice;
    do {
        cout << "-----------------------------------" << endl;
        cout << "\tTest for ArrayStack " << endl;
        cout << "-----------------------------------\n" << endl;
        cout << "1. Push          \n" << endl;
        cout << "2. Pop           \n" << endl;
        cout << "3. Top           \n" << endl;
        cout << "-----------------------------------" << endl;
        cout << "0. Exit          " << endl;
        cout << "-----------------------------------" << endl;


        cout << ">> " ;
        cin >> choice;
    } while (choice < 1 && choice > 3);
    return choice;
}



int main(){

ArrayStack<int> Test;

int choice = displayMenu();

while (choice != 0){
    if (choice == 1){
            int x;
            cout << "Please enter an element (integer number) to push : ";
            cin >> x;
            Test.Push(x);
            cout << x << " was pushed " << endl;
            cout << endl;
    }
    else if (choice == 2) {
            try {
                cout << endl;
                cout << Test.Top() << "  was removed" << endl;
                Test.Pop();
                cout << endl;
            }
            catch( runtime_error& ex )
            {
                cout << "Error: " << ex.what() << endl << endl;
            }
    }
    else if (choice == 3){
            try {
               cout << endl;
               cout << "Top of the Stack is " << Test.Top();
               cout << endl << endl;;

            }
            catch (runtime_error& ex)
            {
                cout <<"Error: " << ex.what() << endl << endl;;
            }
    }
    else
        cout <<"Invalid input !" << endl;

  choice = displayMenu();

}
cout << endl << "Good Bye ! " << endl;
return 0;
}
