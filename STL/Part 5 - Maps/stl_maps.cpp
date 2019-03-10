// Lab - Standard Template Library - Part 5 - Maps
// FIRSTNAME, LASTNAME

#include <iostream>
#include <string>
#include <map>
using namespace std;

void fillTable(map<char, string> & table);                  //fills the map container with the user inputs
string searchTable(map<char, string> & table, char color);  //looks for the desired key and value pair.

int main()
{
    map<char, string> colorToHexTable;
    char letter;

    fillTable(colorToHexTable);

    cout <<"Enter a color letter , or 'q' to stop : ";
    cin >> letter;

    while ( (letter != 'q') && (letter !='Q') ){

        cout <<"Hex:  " <<searchTable(colorToHexTable, letter)<< endl << endl;

        cout <<"Enter a color letter , or 'q' to stop : ";
        cin >> letter;

    }
    cout <<"Goodbye" <<endl;



    cin.ignore();
    cin.get();
    return 0;
}


// asks for the inputs to the container
// @param  map container to be updated which is passed by reference
// @return NONE, updated map container will be return by reference

void fillTable(map<char, string> & table){
    table['r'] = "FF0000";
    table['g'] = "00FF00";
    table['b'] = "0000FF";
    table['c'] = "00FFFF";
    table['m'] = "FF00FF";
    table['y'] = "FFFF00";
}


// searches for the key and value pair in the container
// @param  map container to be searched for
// @return string value pair of the key keyed by the user

string searchTable(map<char, string> & table, char color){
    return table[color];

}
