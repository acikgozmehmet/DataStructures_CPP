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

int GetMax( vector<int>& numberList );
int RadixSort( vector<int>& numberList );
void CountSort( vector<int>& numberList, int exp, int& iterations );

int main()
{
    srand( time( NULL ) );

    vector<int> numberList;
    AddRandomItems( numberList, 100 );

    cout << "UNSORTED:" << endl;
    Display( numberList );

    int iterations = RadixSort( numberList );

    cout << endl <<  "RADIX SORT:" << endl;
    Display( numberList );

    cout << endl << iterations << " iterations to sort" << endl;


    return 0;
}

// Implementation from GeeksForGeeks
// https://www.geeksforgeeks.org/radix-sort/
int RadixSort( vector<int>& numberList )
{
    int iterations = 0;

    int m = GetMax( numberList );

    for ( int exp = 1; m/exp > 0; exp *= 10 )
    {
        CountSort( numberList, exp, iterations );
    }

    return iterations;
}

void CountSort( vector<int>& numberList, int exp, int& iterations )
{
    vector<int> output = numberList;
    int count[10] = { 0 };

    for ( unsigned int i = 0; i < numberList.size(); i++ )
    {
        count[ (numberList[i]/exp) % 10 ]++;
        iterations++;
    }

    for ( int i = 1; i < 10; i++ )
    {
        count[i] += count[i - 1];
        iterations++;
    }

    for ( int i = numberList.size()-1; i >= 0; i-- )
    {
        output[ count[ (numberList[i]/exp) % 10 ] - 1 ] = numberList[i];
        count[ (numberList[i]/exp)%10 ]--;
        iterations++;
    }

    numberList = output;
}

int GetMax( vector<int>& numberList )
{
    int maxval = numberList[0];
    for ( unsigned int i = 1; i < numberList.size(); i++ )
    {
        if ( numberList[i] > maxval )
        {
            maxval = numberList[i];
        }
    }

    return maxval;
}
