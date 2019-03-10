// @author Mehmet ACIKGOZ

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>

using namespace std;

char displayMenu(void);                         // displays the menu
bool isValid(string text);                      // checks for the illegal character in the the string
void saveToFile(ofstream & w, string text);     // saves the record to the file
void addRecord(void);                           // asks for the entry for input
void loadRecords(vector<string> & fnames);      // loads the record from the file to the vector
void printRecords(vector<string> fnames);       // prints out the records to the screen


int main()
{
    bool done = false;
    vector<string> records;
    while (! done)
    {

        loadRecords(records);
        printRecords(records);
        cout << endl;

        char choice = displayMenu();

        switch (choice)
        {
        case '1':
            addRecord();
            break;

        case '2':
            cout <<"Goodbye" << endl;
            return 0;

        default:
            cout <<"Invalid input" << endl;

        }

    } // end of while statement

    cin.ignore();
    cin.get();
    return 0;
}

// validates  if a string has no illegal character for the desired input
// @param, a string to be validated.
// @return true if it is alpha, otherwise false
bool isValid(string text){
    for (int i = 0; i < text.size(); i++){
//       cout << text[i] << "" ;
       if (text[i] == ' ')
                continue;

       if ( !isalpha(text[i]) )
           return false;
    }
    return true;
}

// displays the menu
// @param , none
// @result  char value chosen by the user for the menu choice
char displayMenu(void){
    cout << "============================================" << endl;
    cout << "1. Enter a name\t\t\t"
         << "2. Quit\n" <<endl;

    cout << ">> ";
    char ch;
    cin.get(ch);
    return ch;
}

// saves the text in to a file
// @param ofstream file
// @param string text
// @return NONE- a record saved in the file.
void saveToFile(ofstream & w, string text){
   w << text << endl;
}


// This asks for the full name and saves it in a file after validating.
// @param NONE
// @result - a record added to the file.
void addRecord(void){
     string fullName;
     ofstream outFile;

     //outFile.open("records.dat", std::ofstream::out | std::ofstream::app);
     outFile.open("records.dat", ios::app);

     // testing the file exits
     if (!outFile){
        cout << "Error in creating file" << endl;
        exit(1);
     }

     do {
        cout <<"Please enter the full name [Name Surname] : ";
        cin.ignore();
        getline(cin,fullName);
     } while( !isValid(fullName) );

     saveToFile(outFile, fullName);
     outFile.close();

}


// loads the entries from  the file to the vector.
// @param vector to be loaded
// @result NONE, loaded vectors

void loadRecords(vector<string> & fnames){

    fnames.clear();  // clears out the vector each time before it reads from the file.

    ifstream inFile;

    // This will create the file even if it doesn't exit at all and later will open it in append mode.
    inFile.open("records.dat", ios::out | ios::app);

    // The following will never execute because the file is already created when it comes to here.
    // However, just keep it to be on the safe side
    if (!inFile){
        cout <<"Error in opening the master input file " << endl;
        exit(1);
    }

    //cout << endl;
    string temp;
    while( !inFile.eof() ){
        getline(inFile, temp);
        if (temp.size() > 0)         // any entry which has fewer than one character will NOT be stored in the container.
            fnames.push_back(temp);  // It is mainly for eof character which is the last line of the file
    }
    inFile.close();
}

// prints out the entries to the screen.
// @param vector to be printed
// @result NONE, printing elements in the vector

void printRecords(vector<string> fnames){
    cout << endl;
    for (unsigned int i = 0; i < fnames.size()   ; i++)
        cout << i+1 << "  " <<fnames[i] << endl;

}
