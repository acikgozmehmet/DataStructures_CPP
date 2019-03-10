#ifndef _STUDENT_MANAGER
#define _STUDENT_MANAGER

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "HashTable.hpp"

struct Student
{
    string name;
    float gpa;
    int studentId;

    friend ostream & operator << (ostream & out, const Student & stu);
};

ostream & operator << (ostream & out, const Student & stu)
{
    out
        << setw( 10 ) << stu.gpa
        << setw( 30 ) << stu.name;

    return out;
}

class StudentManager
{
    public:
    void Run( CollisionMethod method );

    private:
    void ReadFile( const string& filename );
    void SaveFile();
    HashTable<int, Student> m_students;
};

void StudentManager::Run( CollisionMethod method )
{
    m_students.SetCollisionMethod( method );
    ReadFile( "students.txt" );
    SaveFile();
}

void StudentManager::SaveFile()
{
    string filename = "Output-";
    if ( m_students.GetCollisionMethod() == LINEAR )
    {
        filename += "Linear";
    }
    else if ( m_students.GetCollisionMethod() == QUADRATIC )
    {
        filename += "Quadratic";
    }
    else
    {
        filename += "Double";
    }
    filename += ".txt";

    m_students.Print( filename );

    cout << "\n\t Output saved to \"" << filename << "\" in the project directory" << endl;
}

void StudentManager::ReadFile( const string& filename )
{
    ifstream input( filename );
    if ( input.fail() || input.bad() )
    {
        cout << "ERROR OPENING FILE \"" << filename << "\"! \n Make sure file is in the project directory!" << endl;
    }

    Student student;
    string buffer;

    while ( input >> buffer )   // STUDENTID
    {
        input >> student.studentId;
        input >> buffer;        // NAME

        input >> buffer;
        student.name = buffer;
        input >> buffer;
        student.name += " " + buffer;

        input >> buffer;        // GPA
        input >> student.gpa;

        try
        {
            m_students.Insert( student.studentId, student );
        }
        catch( exception& ex )
        {
            cout << "Exception: " << ex.what()
                << "\n\t Table size: " << m_students.Size()
                << "\n\t ID:    " << student.studentId
                << "\n\t Name:  " << student.name
                << "\n\t GPA:   " << student.gpa << endl;
        }
    }

    input.close();

    cout << "\n\t " << m_students.Size() << " students loaded" << endl;
}

#endif
