#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

#include "Timer.hpp"
#include "Menu.hpp"

struct DataEntry
{
    map<string, string> fields;

    void Output( ofstream& output )
    {
        for ( map<string, string>::iterator it = fields.begin();
                it != fields.end(); it++ )
        {
            output << left << setw( 30 ) << it->second;
        }
        output << endl;
    }
};

void ReadData( vector<DataEntry>& data, const string& filename );

/* ********************************************* */
/* TODO: Add prototypes for sort functions here. */
/* ********************************************* */
void SelectionSort( vector<DataEntry>& data, const string& onKey );


int main()
{
    Menu::Header( "U.S. Chronic Disease Indicators" );

    vector<string> filenames = {
        "100_US_Chronic_Disease_Indicators.csv",
        "1000_US_Chronic_Disease_Indicators.csv",
        "10000_US_Chronic_Disease_Indicators.csv",
        "523487_US_Chronic_Disease_Indicators.csv"
    };

    /* ********************************************* */
    /* TODO: Update this menu with your sorting algs */
    /* ********************************************* */
    vector<string> sorts = {
        "Selection Sort",
        "YOUR BASIC SORT",
        "YOUR FAST SORT"
    };

    vector<string> columns = {
        "YearStart", "YearEnd", "LocationAbbr", "LocationDesc", "Topic", "Question"
    };

    cout << "Which file do you want to load?" << endl;
    int fileChoice = Menu::ShowIntMenuWithPrompt( filenames );

    cout << "Which sort do you want to use?" << endl;
    int sortChoice = Menu::ShowIntMenuWithPrompt( sorts );

    cout << "Which column do you want to sort on?" << endl;
    int sortOnChoice = Menu::ShowIntMenuWithPrompt( columns );

    cout << fileChoice << ", " << sortChoice << ", " << sortOnChoice << endl;

    Timer timer;
    vector<DataEntry> data;

    string filename = filenames[ fileChoice - 1 ];


    // Read in the data from the file
    cout << left << setw( 15 ) << "BEGIN:" << "Loading data from file, \"" << filename << "\"..." << endl;
    timer.Start();
    ReadData( data, filename );
    cout << left << setw( 15 ) << "COMPLETED:" << "In " << timer.GetElapsedMilliseconds() << " milliseconds" << endl << endl;

    cout << data.size() << " items loaded" << endl;


    // Sort the data
    if ( sortChoice == 1 )
    {
        cout << left << setw( 15 ) << "BEGIN:" << "Sorting data with Selection Sort..." << endl;
        timer.Start();

        /* *************************************** */
        /* TODO: Call basic sorting algorithm here */
        /* *************************************** */
        // example: SelectionSort( data, columns[ sortOnChoice - 1 ] );
        cout << left << setw( 15 ) << "COMPLETED:" << "In " << timer.GetElapsedMilliseconds() << " milliseconds" << endl << endl;
    }
    else if ( sortChoice == 2 )
    {
        cout << left << setw( 15 ) << "BEGIN:" << "Sorting data with Merge Sort..." << endl;
        timer.Start();
        /* **************************************** */
        /* TODO: Call faster sorting algorithm here */
        /* **************************************** */
        // example: MergeSort( data, columns[ sortOnChoice - 1 ] );
        cout << left << setw( 15 ) << "COMPLETED:" << "In " << timer.GetElapsedMilliseconds() << " milliseconds" << endl << endl;
    }
    cout << endl << "Writing list out to \"output.txt\"..." << endl;


    // Output the sorted data
    ofstream output( "output.txt" );
    for ( map<string, string>::iterator it = data[0].fields.begin();
            it != data[0].fields.end(); it++ )
    {
        output << left << setw( 30 ) << it->first;
    }

    output << endl;

    for ( unsigned int i = 0; i < data.size(); i++ )
    {
        data[i].Output( output );
    }
    output.close();

    cout << endl;

    Menu::Header( "Hit ENTER to quit." );

    cin.ignore();
    cin.get();

    return 0;
}

void ReadData( vector<DataEntry>& data, const string& filename )
{
    ifstream input( filename );

    vector<string> headerItems;

    unsigned int field = 0;

    string line;
    bool header = true;
    bool skippedGeoComma = false;
    while ( getline( input, line ) )
    {
        DataEntry entry;

        int columnBegin = 0;
        field = 0;
        skippedGeoComma = false;

        for ( unsigned int i = 0; i < line.size(); i++ )
        {
            //cout << line[i];
            if ( line[i] == ',' )
            {
                int length = i - columnBegin;
                string substring = line.substr( columnBegin, length );

                if ( header )
                {
                    headerItems.push_back( substring );
                }
                else
                {
                    string fieldKey = "";
                    if (field >= headerItems.size())
                    {
                        fieldKey = "Unknown";
                    }
                    else
                    {
                        fieldKey = headerItems[field];
                    }
                    entry.fields[ fieldKey ] = substring;
                }

                columnBegin = i+1;

                if ( header == false && skippedGeoComma == false && headerItems[ field ] == "GeoLocation" )
                {
                    skippedGeoComma = true;
                    // Ignore this comma.
                    continue;
                }
                else
                {
                    field++;
                }
            }
        }

        if ( header )
        {
            header = false;
        }
        else
        {
            data.push_back( entry );
        }
    }

    input.close();
}

/* ******************************************** */
/* TODO: Implement sorting algorithsm down here */
/* ******************************************** */

void SelectionSort( vector<DataEntry>& data, const string& onKey )
{
    int n = data.size();

    for ( int j = 0; j < n-1; j++ )
    {
        int iMin = j;
        for ( int i = j+1; i < n; i++ )
        {
            if ( data[i].fields[ onKey ] < data[iMin].fields[ onKey ] )
            {
                iMin = i;
            }

            if ( iMin != j )
            {
                DataEntry temp = data[j];
                data[j] = data[iMin];
                data[iMin] = temp;
            }
        }
    }
}
