#include <iostream>
using namespace std;

#include "Tester.hpp"
#include "CarProgram.hpp"
#include "cuTEST/Menu.hpp"

int main()
{
    while ( true )
    {
        Menu::Header( "MAIN MENU" );
        int choice = Menu::ShowIntMenuWithPrompt( { "Tests", "Program", "Exit" } );

        if ( choice == 1 )
        {
            Tester test;
            test.Start();
        }
        else if ( choice == 2 )
        {
            CarProgram program;
            program.Start();
        }
        else if ( choice == 3 )
        {
            break;
        }

        cout << endl;
    }

    return 0;
}
