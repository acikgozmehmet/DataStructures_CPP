#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

#include "function1.hpp"
#include "function2.hpp"
#include "function3.hpp"
#include "function4.hpp"

void ClearScreen();
void Pause();

/*** DO NOT MODIFY MAIN *******************/

int main()
{
    bool quit = false;
    while ( quit == false )
    {
        ClearScreen();
        cout << "***************************************" << endl;
        cout << "**              TESTER               **" << endl;
        cout << "***************************************" << endl;
        cout << " 1. Test SumThree" << endl;
        cout << " 2. Test SumArr" << endl;
        cout << " 3. Test IsOverdrawn" << endl;
        cout << " 4. Test GetLength" << endl;
        cout << " 5. Quit" << endl << endl;

        int choice;
        cout << "Test which function? ";
        cin >> choice;

        cout << endl << endl;

        switch( choice )
        {
            case 1:
                Test_SumThree();
            break;

            case 2:
                Test_SumArr();
            break;

            case 3:
                Test_IsOverdrawn();
            break;

            case 4:
                Test_GetLength();
            break;

            case 5:
                quit = true;
            break;
        }

        cout << endl << endl;

        Pause();
    }
    return 0;
}

void ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    system( "cls" );
    #else
    system( "clear" );
    #endif
}

void Pause()
{
    cout << "Press enter to continue..." << endl;
    cin.ignore();
    cin.get();
}
