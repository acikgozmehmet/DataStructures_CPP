#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Job.hpp"
#include "Processor.hpp"
#include "Menu.hpp"
#include "HomeworkGenerator.hpp"

void FillJobQueues( PriorityQueue& pq, vector<Job>& allJobs )
{
    for ( unsigned int i = 0; i < allJobs.size(); i++ )
    {
        pq.Push( &allJobs[i] );
    }
}

int main()
{
    srand( time( NULL ) );

    // Get config info
    Menu::Header( "Homework Prioritizer" );
    int totalJobs = Menu::GetValidChoice( 10, 9999, "How many tasks? (More than 10)" );


    // Create homework and into priority queue
    cout << endl << "Creating homework..." << endl;
    HomeworkGenerator generator;
    vector<Job> allJobs = generator.GetHomework( totalJobs );

    PriorityQueue pq;

    cout << endl << "Filling queues..." << endl;
    FillJobQueues( pq, allJobs );


    // Process each queue with the different types of scheduling
    Processor cpu;
    cout << endl << "Processing with FCFS..." << endl;
    cpu.Work( allJobs, pq, "result.txt" );

    cout << endl << "DONE" << endl;

    cin.ignore();
    cin.get();

    return 0;
}
