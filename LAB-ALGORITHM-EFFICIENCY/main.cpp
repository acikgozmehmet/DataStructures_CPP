#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

#include "Timer.hpp"
#include "Menu.hpp"
#include "Searcher.hpp"

int main()
{
    Menu::Header( "Initialize" );

    srand( time( NULL ) );

    int listSize;
    cout << "Enter a list size: ";
    cin >> listSize;

    Searcher searcher( listSize );

    cout << endl;

    while ( true )
    {
        cout << endl;
        Menu::Header( "Main Menu" );

        cout << " Which function do you want to time?" << endl;

        int choice = Menu::ShowIntMenuWithPrompt( {
            "Search 1",
            "Search 2",
            "Binary Search (for sorted lists)",
            "Sort",
            "Recursive Fibonacci",
            "Iterative Fibonacci"
            } );

        searcher.Run( choice );
    }

    return 0;
}
