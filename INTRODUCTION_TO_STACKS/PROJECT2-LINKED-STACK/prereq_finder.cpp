// Done - do not edit

#include <iostream>
using namespace std;

#include "UTILITIES/Menu.hpp"

#include "Tester.hpp"
#include "CourseCatalog.hpp"

int main()
{
    Menu::Header( "Running tests..." );

    Tester tester;
    tester.Start();
    tester.Close();

    cout << endl;

    CourseCatalog courseProgram;
    courseProgram.Run();

    return 0;
}
