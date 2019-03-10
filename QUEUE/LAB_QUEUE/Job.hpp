#ifndef _JOB
#define _JOB

#include <iostream>
#include <vector>
using namespace std;

#include "Queue.hpp"

enum JobType { FCFS, RR };

struct Job
{
    Job();
    void Work( JobType type );
    void SetFinishTime( int time, JobType type );

    int id;

    int fcfs_timeRemaining;
    int fcfs_finishTime;
    bool fcfs_done;

    int rr_timeRemaining;
    int rr_finishTime;
    bool rr_done;
    int rr_timesInterrupted;
};

Job::Job()
{
    fcfs_done = false;
    rr_done = false;
    rr_timesInterrupted = 0;
}

void Job::Work( JobType type )
{
    if ( type == FCFS )
    {
        fcfs_timeRemaining -= 1;
        if ( fcfs_timeRemaining == 0 )
        {
            fcfs_done = true;
        }
    }
    else
    {
        rr_timeRemaining -= 1;
        if ( rr_timeRemaining == 0 )
        {
            rr_done = true;
        }
    }
}

void Job::SetFinishTime( int time, JobType type )
{
    if ( type == FCFS )
    {
        fcfs_finishTime = time;
    }
    else
    {
        rr_finishTime = time;
    }
}


#endif

