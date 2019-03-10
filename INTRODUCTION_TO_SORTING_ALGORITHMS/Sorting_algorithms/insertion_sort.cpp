#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void Display( const vector<int>& numberList )
{
    for ( unsigned int i = 0; i < numberList.size(); i++ )
    {
        cout << setw( 5 ) << i << " = " << setw( 5 ) << numberList[i];

        if ( i != numberList.size() - 1 ) { cout << ","; }
        if ( i != 0 && (i+1) % 5 == 0 ) { cout << endl; }
    }
}

void AddRandomItems( vector<int>& numberList, int amount )
{
    for ( int i = 0; i < amount; i++ )
    {
        numberList.push_back( rand() % amount );
    }
}

// Implementation from GeeksForGeeks
// https://www.geeksforgeeks.org/insertion-sort/
int InsertionSort( vector<int>& numberList )
{
    int iterations = 0;

    int n = numberList.size();
    int key;

    for ( int i = 1; i < n; i++ )
    {
        key = numberList[i];
        int j = i-1;

        while ( j >= 0 && numberList[j] > key )
        {
            numberList[j+1] = numberList[j];
            j = j-1;

            iterations++;
        }

        numberList[j+1] = key;
    }

    return iterations;
}

int main()
{
    srand( time( NULL ) );

    vector<int> numberList;
    AddRandomItems( numberList, 100 );

    cout << "UNSORTED:" << endl;
    Display( numberList );

    int iterations = InsertionSort( numberList );

    cout << endl <<  "INSERTION SORT:" << endl;
    Display( numberList );

    cout << endl << iterations << " iterations to sort" << endl;


    return 0;
}
