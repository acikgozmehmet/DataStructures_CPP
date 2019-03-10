// Done - you can add helper functions if you want.

#ifndef _COURSE_CATALOG_HPP
#define _COURSE_CATALOG_HPP

#include <iostream>
#include <fstream>
using namespace std;

#include "Course.hpp"

#include "DATA_STRUCTURES/LinkedList.hpp"

class CourseCatalog
{
public:
CourseCatalog();

void Run();

private:
void LoadCourses();
void ViewCourses();
void ViewPrereqs();

Course FindCourse( const string& code );

LinkedList<Course> m_courses;
};

#endif
