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

vector<Job> CreateJobs( int jobCount )
{
    vector<Job> jobList;

    for ( int i = 0; i < jobCount; i++ )
    {
        Job job;

        job.fcfs_timeRemaining = rand() % 100 + 50;
        job.rr_timeRemaining = job.fcfs_timeRemaining;

        job.id = i;
        jobList.push_back( job );

        cout << "Job " << i << ", fcfs: " << job.fcfs_timeRemaining << ", rr: " << job.rr_timeRemaining << endl;
    }

    return jobList;
}

void FillJobQueues( Queue<Job*>& fcfsQueue, Queue<Job*>& rrQueue, vector<Job>& allJobs )
{
    for ( unsigned int i = 0; i < allJobs.size(); i++ )
    {
        fcfsQueue.Push( &allJobs[i] );
        rrQueue.Push( &allJobs[i] );
    }
}

int main()
{
    srand( time( NULL ) );

    // Get config info
    Menu::Header( "Job Processor" );
    int totalJobs = Menu::GetValidChoice( 10, 9999, "How many jobs? (More than 10)" );
    int roundRobin = Menu::GetValidChoice( 1, 10, "Round Robin time interval? " );


    // Create jobs and copy these jobs into each queue
    // FCFS = First Come, First Served      RR = Round Robbin
    cout << endl << "Creating jobs..." << endl;
    vector<Job> allJobs = CreateJobs( totalJobs );
    Queue<Job*> fcfs, rr;                           // MA-neden <Job*>

    cout << endl << "Filling queues..." << endl;
    FillJobQueues( fcfs, rr, allJobs );


    // Process each queue with the different types of scheduling
    Processor cpu;
    cout << endl << "Processing with FCFS..." << endl;
    cpu.FirstComeFirstServe( allJobs, fcfs, "result-fcfs.txt" );

    cout << endl << "Processing with RR..." << endl;
    cpu.RoundRobin( allJobs, rr, roundRobin, "result-rr.txt" );

    cout << endl << "DONE" << endl;

    cin.ignore();
    cin.get();

    return 0;
}
