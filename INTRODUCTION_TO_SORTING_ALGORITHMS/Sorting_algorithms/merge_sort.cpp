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

void MergeSort_Recursive( vector<int>& numberList, int first, int last, int& iterations );
void Merge( vector<int>& numberList, int first, int mid, int last, int& iterations );
int MergeSort( vector<int>& numberList );

int main()
{
    srand( time( NULL ) );

    vector<int> numberList;
    AddRandomItems( numberList, 100 );

    cout << "UNSORTED:" << endl;
    Display( numberList );

    int iterations = MergeSort( numberList );

    cout << endl <<  "MERGE SORT:" << endl;
    Display( numberList );

    cout << endl << iterations << " iterations to sort" << endl;


    return 0;
}

// Implementation from Data Abstraction & Problem Solving with Walls and Mirrors, 7th ed
// Frank Carrano and Timothy Henry
void MergeSort_Recursive( vector<int>& numberList, int first, int last, int& iterations )
{
    iterations++;

    if ( first < last )
    {
        int mid = first + (last - first)/2;

        MergeSort_Recursive( numberList, first, mid, iterations );
        MergeSort_Recursive( numberList, mid+1, last, iterations );
        Merge( numberList, first, mid, last, iterations );
    }
}

void Merge( vector<int>& numberList, int first, int mid, int last, int& iterations )
{
    vector<int> temp = numberList;

    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;

    int index = first;
    while ( ( first1 <= last1 ) && ( first2 <= last2 ) )
    {
        if ( numberList[first1] <= numberList[first2] )
        {
            temp[index] = numberList[first1];
            first1++;
        }
        else
        {
            temp[index] = numberList[first2];
            first2++;
        }
        index++;
        iterations++;
    }

    while ( first1 <= last1 )
    {
        temp[index] = numberList[first1];
        first1++;
        index++;
        iterations++;
    }

    while ( first2 <= last2 )
    {
        temp[index] = numberList[first2];
        first2++;
        index++;
        iterations++;
    }

    numberList = temp;
}

int MergeSort( vector<int>& numberList )
{
    int iterations = 0;

    MergeSort_Recursive( numberList, 0, numberList.size()-1, iterations );

    return iterations;
}
