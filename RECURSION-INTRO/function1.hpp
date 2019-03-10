#ifndef _function1
#define _function1

/*
CountUp functions
@param int start    The starting value (inclusive) to begin at
@param int end      The end value (inclusive) to run until

Display the numbers between [start] and [end], incrementing by 1 each time.
*/

void CountUp_Iter( int start, int end )
{
    for (int i = start; i <= end; i++)
        cout << i << "\t" ;
}

void CountUp_Rec( int start, int end )
{
    if ( start == end )
        return;

    cout << start << "\t";

    CountUp_Iter(start+1, end);

}

#endif
