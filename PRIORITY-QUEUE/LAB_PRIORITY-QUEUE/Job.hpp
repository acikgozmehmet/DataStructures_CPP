#ifndef _JOB
#define _JOB

#include <iostream>
#include <vector>
using namespace std;

struct Job
{
    Job();
    void Work();
    void SetFinishDay( int day );
    void Update( int timestamp );

    int id;
    string assignment;
    bool done;
    bool overdue;

    int dueOnDay;
    int timeRemaining;
    int dayFinished;
};

Job::Job()
{
    done = false;
    overdue = false;
    dayFinished = -1;
}

void Job::Work()
{
    timeRemaining -= 1;

    if ( timeRemaining == 0 )
    {
        done = true;
    }
}

void Job::Update( int timestamp )
{
    if ( !done && timestamp > dueOnDay )
    {
        overdue = true;
    }
}

void Job::SetFinishDay( int day )
{
    dayFinished = day;
}


#endif

