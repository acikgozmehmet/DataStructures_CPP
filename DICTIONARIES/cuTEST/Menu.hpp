#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

class Menu
{
    public:
    // OUTPUT
    static void Header( const string& header )
    {
        DrawHorizontalBar( 80 );
        string head = "| " + header + " |";
        cout << " " << head << endl << " ";
        DrawHorizontalBar( head.size() );
        cout << endl;
    }

    static void DrawHorizontalBar( int width, char symbol = '-' )
    {
        for ( int i = 0; i < width; i++ )
        {
            cout << symbol;
        }
        cout << endl;
    }

    // MENUS and INPUT/OUTPUT
    static void ShowMenu( const vector<string> options, bool vertical = true )
    {
        if ( vertical )
        {
            for ( unsigned int i = 0; i < options.size(); i++ )
            {
                cout << " " << (i+1) << ".\t" << options[i] << endl;
            }
        }
        else
        {
            for ( unsigned int i = 0; i < options.size(); i++ )
            {
                cout << " " << (i+1) << ". " << options[i] << "\t";
            }
            cout << endl;
        }
    }

    static int ShowIntMenuWithPrompt( const vector<string> options, bool vertical = true )
    {
        ShowMenu( options, vertical );
        int choice = GetValidChoice( 1, options.size() );
        return choice;
    }

    static string ShowStringMenuWithPrompt( const vector<string> options, bool vertical = true )
    {
        ShowMenu( options, vertical );
        int choice = GetValidChoice( 1, options.size() );
        string value = options[ choice-1 ];
        return value;
    }

    static int GetValidChoice( int min, int max, const string& message = "" )
    {
        if ( message != "" )
        {
            cout << endl;
            DrawHorizontalBar( message.size() + 2 );
            cout << " " << message << endl;
        }

        int choice = GetIntChoice();

        while ( choice < min || choice > max )
        {
            cout << "Invalid selection. Try again." << endl;
            choice = GetIntChoice();
        }

        return choice;
    }

    static string GetStringChoice( const string& message = "" )
    {
        if ( message != "" )
        {
            cout << " " << message << endl;
        }

        cout << endl << " >> ";
        string choice;
        cin >> choice;
        cin.ignore();
        cout << endl;
        return choice;
    }

    static string GetStringLine( const string& message = "" )
    {
        if ( message != "" )
        {
            cout << " " << message << endl;
        }
        string choice;
        cout << endl << " >> ";
        getline( cin, choice );
        cout << endl;
        return choice;
    }

    static int GetIntChoice( const string& message = "" )
    {
        if ( message != "" )
        {
            cout << " " << message << endl;
        }
        cout << endl << " >> ";
        int choice;
        cin >> choice;
        cin.ignore();
        cout << endl;
        return choice;
    }

    // HANDY TRICKS
    static void ClearScreen()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "cls" );
        #else
            system( "clear" );
        #endif
    }

    static void Pause()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "pause" );
        #else
            cout << endl << " Press ENTER to continue..." << endl;
            cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
        #endif
    }

    static void PrintPwd()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "echo %cd%" );
        #else
            system( "pwd" );
        #endif
    }
};



#endif

