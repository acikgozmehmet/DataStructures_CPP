// Lab - Standard Template Library - Part 1 - Vectors
// MEHMET, ACIKGOZ

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> courses;

int main()
{
	bool done = false;

	while (!done)
	{
		cout << endl << endl;
		cout << "----------------------------" <<endl;
		cout << "Current list size: " << courses.size() << endl;
		cout << endl;
		cout << "1. Add a new course\t\t\t"
			 << "2. Remove last course\n"
             << "3. Display the course list\t\t"
			 << "4. Quit" << endl << endl;

		int choice;
		cout << ">> ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
		{
			string courseName;
			cout << "NEW COURSE" << endl;
			cout << "Enter new course name: ";

			do {
			cin.ignore();
			getline(cin, courseName);
			}while (courseName.empty()); // to prevent empty string.

			courses.push_back(courseName); // if courseName is not empty, push it...
		}
		else if (choice  == 2)
		{
			cout << "REMOVE COURSE" << endl;
			cout << courses[courses.size()-1] << " removed" << endl;
			courses.pop_back();
		}
		else if (choice == 3)
		{
		    cout <<"VIEW COURSE LIST" << endl;
			for (unsigned int i = 0; i < courses.size(); i++)
			{
				cout << "course[" << i << "]" << " =  " << courses[i] << endl;
			}
		}
		else if (choice == 4)
		{
		    cout << "Goodbye" << endl;
			done = true;
		}
	}

    cin.ignore();
    cin.get();
    return 0;
}
