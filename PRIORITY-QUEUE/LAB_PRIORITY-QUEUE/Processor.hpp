#ifndef _PROCESSOR
#define _PROCESSOR

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Job.hpp"
#include "PriorityQueue.hpp"

class Processor
{
    public:
    void Work( vector<Job>& allJobs, PriorityQueue jobQueue, const string& logFile );

    private:
    void TimeUpdate( vector<Job>& allJobs, int timestamp, Job* processing );
    ofstream output;
};

void Processor::Work( vector<Job>& allJobs, PriorityQueue jobQueue, const string& logFile )
{
    output.open( logFile );
    output << "Doing my homework!" << endl;

    int days = 0;
    while ( jobQueue.Size() > 0 )
    {
        output << endl << "---------------------------------------------------------" << endl;
        output << "DAY: " << days << endl << endl;

        // Process the next task
        output << "Processing task " << jobQueue.Front()->id << "... ";
        jobQueue.Front()->Work();
        if ( jobQueue.Front()->done )
        {
            output << "done!";
            jobQueue.Front()->SetFinishDay( days );
            jobQueue.Pop();
        }
        output << endl << endl;

        TimeUpdate( allJobs, days, jobQueue.Front() );
        days++;
    }

    output.close();
}

void Processor::TimeUpdate( vector<Job>& allJobs, int timestamp, Job* processing )
{
    output << left
        << setw( 5 ) << "ID"
        << setw( 10 ) << "DUE ON"
        << setw( 15 ) << "REMAINING"
        << setw( 20 ) << "FINISHED DAY"
        << setw( 10 ) << "OVERDUE"
        << endl;

    for ( vector<Job>::iterator it = allJobs.begin(); it != allJobs.end(); it++ )
    {
        it->Update( timestamp );

        output << left
            << setw( 5 ) << it->id
            << setw( 10 ) << it->dueOnDay
            << setw( 15 ) << it->timeRemaining;

        if ( it->dayFinished != -1 )
        {
            output << setw( 20 ) << it->dayFinished;
        }
        else
        {
            output << setw( 20 ) << " ";
        }

        if ( it->overdue )
        {
            output << setw( 10 ) << "overdue";
        }
        else
        {
            output << setw( 10 ) << " ";
        }

        if ( &(*it) == processing )
        {
            output << setw( 10 ) << " <<";
        }
        output << endl;
    }

    output << endl;
}

#endif
