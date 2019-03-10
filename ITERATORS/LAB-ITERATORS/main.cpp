#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

#include "Menu.hpp"

list<string> LoadBook( const string& filename );
void ReadBook( list<string> bookText );

int main()
{
    vector<string> books = { "aesop.txt", "fairytales.txt" };

    bool done = false;
    while ( !done )
    {
        Menu::Header( "LIBRARY" );

        cout << "Which book do you want to read?" << endl;
        int choice = Menu::ShowIntMenuWithPrompt( books );

        list<string> bookText = LoadBook( books[choice-1] );
        ReadBook( bookText );
    }

    return 0;
}


list<string> LoadBook( const string& filename )
{
    list<string> bookText;

    cout << "Loading " << filename << "..." << endl;

    ifstream input( filename );

    if ( !input.good() )
    {
        cout << "Error opening file" << endl;
    }

    string line;
    while ( getline( input, line ) )
    {
        bookText.push_back( line );
    }

    cout << endl << bookText.size() << " lines loaded" << endl << endl;

    input.close();

    return bookText;
}


void ReadBook( list<string> bookText )
{
    int counter = 0 ;
    int lines = 0 ;
    int pageLength = 28;

    list<string>::iterator it;
    for (it = bookText.begin(); it!= bookText.end(); )
    {

    cout << *it << endl;

        if (counter == pageLength){
            cout << endl;
            cout <<"Line " << lines <<" of " << bookText.size()<< endl << endl;

            int choice = Menu :: ShowIntMenuWithPrompt ( {" BACKWARD ", " FORWARD " , "BACK TO LIBRARY", "EXIT" }, false );

            if (choice  == 1)
            {
                    for (int i = 0 ; i < pageLength*2; i++)
                    {
                        if (it != bookText.begin())
                        {
                            it--;
                            lines--;
                        }

                    }
            }

            else if(choice == 3)
                break;
            else if (choice == 4)
            {
                cout << "Bye..." << endl;
                exit(0);
            }


        counter = 0;
        }
    counter++;
    lines++;
    it++;

    }

}
