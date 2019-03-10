#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "StudentManager.hpp"
#include "Tester.hpp"
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
            cout << "Which collision style?" << endl;
            int collisionType = Menu::ShowIntMenuWithPrompt( { "Linear Probing", "Quadratic Probing", "Double Hashing" } );
            CollisionMethod method;
            if      ( collisionType == 1 ) { method = LINEAR; }
            else if ( collisionType == 2 ) { method = QUADRATIC; }
            else if ( collisionType == 3 ) { method = DOUBLE; }

            StudentManager stum;
            stum.Run( method );
        }
        else if ( choice == 3 )
        {
            break;
        }

        cout << endl;
    }

    return 0;
}
