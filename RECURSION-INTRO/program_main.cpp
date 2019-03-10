#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

#include "function1.hpp"
#include "function2.hpp"
#include "function3.hpp"
#include "function4.hpp"
#include "function5.hpp"

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
        cout << "**             RECURSION             **" << endl;
        cout << "***************************************" << endl;
        cout << " 1. CountUp" << endl;
        cout << " 2. MultiplyUp" << endl;
        cout << " 3. Factorial" << endl;
        cout << " 4. GetConsonants" << endl;
        cout << " 5. GetFirstUppercase" << endl;
        cout << " 6. Quit" << endl << endl;

        int choice;
        cout << "Run which function? ";
        cin >> choice;

        cout << endl << endl;

        switch( choice )
        {
            case 1:
            {
                cout << "CountUp, Iterative:" << endl;
                CountUp_Iter( 1, 10 );

                cout << endl << endl;
                cout << "CountUp, Recursive:" << endl;
                CountUp_Rec( 1, 10 );
            }
            break;

            case 2:
            {
                cout << "MultiplyUp, Iterative:" << endl;
                MultiplyUp_Iter( 2, 300 );

                cout << endl << endl;
                cout << "MultiplyUp, Recursive:" << endl;
                MultiplyUp_Rec( 2, 300 );
            }
            break;

            case 3:
            {
                cout << "Factorial, Iterative:" << endl;
                for ( int i = 2; i < 10; i++ )
                {
                    if ( i % 2 == 0 ) { cout << endl; }
                    cout << i << "! = " << Factorial_Iter( i ) << "\t\t";
                }

                cout << endl << endl;
                cout << "Factorial, Recursive:" << endl;
                for ( int i = 2; i < 10; i++ )
                {
                    if ( i % 2 == 0 ) { cout << endl; }
                    cout << i << "! = " << Factorial_Rec( i ) << "\t\t";
                }
            }
            break;

            case 4:
            {
                string text[] = { "aeiou", "kittens", "development" };

                cout << "GetConsonants, Iterative:" << endl;
                for ( int i = 0; i < 3; i++ )
                {
                    cout << " * Consonants in " << text[i] << ": " << CountConsonants_Iter( text[i] ) << endl;
                }

                cout << endl << endl;
                cout << "GetConsonants, Recursive:" << endl;
                for ( int i = 0; i < 3; i++ )
                {
                    cout << " * Consonants in " << text[i] << ": " << CountConsonants_Rec( text[i], 0 ) << endl;
                }
            }
            break;

            case 5:
            {
                string text[] = { "how are YOU?", "What?", "where am I?", "no caps" };

                cout << "GetFirstUppercase, Iterative:" << endl;
                for ( int i = 0; i < 4; i++ )
                {
                    cout << " * First upper-case in " << text[i] << ": '" << GetFirstUppercase_Iter( text[i] ) << "'" << endl;
                }

                cout << endl << endl;
                cout << "GetConsonants, Recursive:" << endl;
                for ( int i = 0; i < 4; i++ )
                {
                    cout << " * First upper-case in " << text[i] << ": '" << GetFirstUppercase_Rec( text[i], 0 ) << "'" << endl;
                }
            }
            break;

            case 6:
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
