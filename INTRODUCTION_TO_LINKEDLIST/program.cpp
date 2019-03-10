#include <iostream>
using namespace std;

#include "LinkedList.hpp"

#include "Tester.hpp"

int main()
{
    cout << "[1] RUN PROGRAM \t [2] RUN TESTS" << endl;
    int choice;
    cin >> choice;

    switch( choice )
    {
        case 1:
        break;

        case 2:
        {
            Tester tester;
            tester.RunTests();
            }
        break;
    }

    return 0;
}
