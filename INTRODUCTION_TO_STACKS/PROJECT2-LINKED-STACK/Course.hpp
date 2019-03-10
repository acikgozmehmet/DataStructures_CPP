// Done - you can add helper functions if you want.

#ifndef _COURSE_HPP
#define _COURSE_HPP

#include <string>
using namespace std;

struct Course
{
    Course() { Clear(); }

    void Clear()
    {
        name = code = prereq = "";
    }

    string name;
    string code;
    string prereq;
};

#endif
