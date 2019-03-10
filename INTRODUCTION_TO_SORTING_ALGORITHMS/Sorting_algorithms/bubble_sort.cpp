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
// https://www.geeksforgeeks.org/bubble-sort/
int BubbleSort( vector<int>& numberList )
{
    int iterations = 0;

    int n = numberList.size();

    for ( int i = 0; i < n-1; i++ )
    {
        for ( int j = 0; j < n-i-1; j++ )
        {
            if ( numberList[j] >numberList[j+1] )
            {
                int temp = numberList[j];
                numberList[j] = numberList[j+1];
                numberList[j+1] = temp;
            }
            iterations++;
        }
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

    int iterations = BubbleSort( numberList );

    cout << endl << "BUBBLE SORT:" << endl;
    Display( numberList );

    cout << endl << iterations << " iterations to sort" << endl;


    return 0;
}
