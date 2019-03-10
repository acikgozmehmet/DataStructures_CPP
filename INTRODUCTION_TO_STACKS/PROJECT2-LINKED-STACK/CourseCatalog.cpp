#include "CourseCatalog.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
using namespace std;

#include "UTILITIES/Menu.hpp"
#include "EXCEPTIONS/CourseNotFoundException.hpp"

CourseCatalog::CourseCatalog()
{
    LoadCourses();
}

void CourseCatalog::LoadCourses() // done
{
    Menu::Header( "LOADING COURSES" );

    ifstream input( "courses.txt" );

    if ( !input.is_open() )
    {
        cout << "Error opening input text file, courses.txt" << endl;
        return;
    }

    string label, courseCode, courseName, prerequisite;
    Course newCourse;

    while ( input >> label )
    {
        if ( label == "COURSE" )
        {
            if ( newCourse.name != "" )
            {
                m_courses.PushBack( newCourse );
                newCourse.Clear();
            }

            input >> newCourse.code >> newCourse.name;
        }
        else if ( label == "PREREQ" )
        {
            input >> newCourse.prereq;
        }
    }

    input.close();

    cout << " * " << m_courses.Size() << " courses loaded" << endl << endl;
}

void CourseCatalog::ViewCourses()
{
    Menu::Header( "VIEW COURSES" );
}

Course CourseCatalog::FindCourse( const string& code )
{
    throw runtime_error( "Not yet implemented!" );
}

void CourseCatalog::ViewPrereqs()
{
    Menu::Header( "GET PREREQS" );
}

void CourseCatalog::Run()
{
    bool done = false;
    while ( !done )
    {
        Menu::Header( "MAIN MENU" );

        int choice = Menu::ShowIntMenuWithPrompt( { "View all courses", "Get course prerequisites", "Exit" } );

        switch( choice )
        {
            case 1:
                ViewCourses();
            break;

            case 2:
                ViewPrereqs();
            break;

            case 3:
                done = true;
            break;
        }
    }
}
