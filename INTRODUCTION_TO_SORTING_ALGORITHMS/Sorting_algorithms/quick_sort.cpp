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

void QuickSort_Recursive( vector<int>& numberList, int low, int high, int& iterations );
int QuickSort( vector<int>& numberList );
int Partition( vector<int>& numberList, int low, int high, int& iterations );

int main()
{
    srand( time( NULL ) );

    vector<int> numberList;
    AddRandomItems( numberList, 100 );

    cout << "UNSORTED:" << endl;
    Display( numberList );

    int iterations = QuickSort( numberList );

    cout << endl <<  "QUICK SORT:" << endl;
    Display( numberList );

    cout << endl << iterations << " iterations to sort" << endl;


    return 0;
}

// Implementation from GeeksForGeeks
// https://www.geeksforgeeks.org/quick-sort/
void QuickSort_Recursive( vector<int>& numberList, int low, int high, int& iterations )
{
    iterations++;

    if ( low < high )
    {
        int partitionIndex = Partition( numberList, low, high, iterations );

        QuickSort_Recursive( numberList, low, partitionIndex - 1, iterations );
        QuickSort_Recursive( numberList, partitionIndex + 1, high, iterations );
    }
}

int QuickSort( vector<int>& numberList )
{
    int iterations = 0;

    QuickSort_Recursive( numberList, 0, numberList.size()-1, iterations );

    return iterations;
}

int Partition( vector<int>& numberList, int low, int high, int& iterations )
{
    int pivot = numberList[high];

    int i = (low - 1);

    for ( int j = low; j <= high - 1; j++ )
    {
        if ( numberList[j] <= pivot )
        {

            i++;

            int temp = numberList[i];
            numberList[i] = numberList[j];
            numberList[j] = temp;
        }
        iterations++;
    }

    int temp = numberList[i + 1];
    numberList[i + 1] = numberList[high];
    numberList[high] = temp;

    return ( i + 1 );
}
