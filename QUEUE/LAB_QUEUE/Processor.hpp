#ifndef _PROCESSOR
#define _PROCESSOR

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "Job.hpp"
#include "Queue.hpp"

class Processor
{
    public:
    void FirstComeFirstServe( vector<Job>& allJobs, Queue<Job*>& jobQueue, const string& logFile );
    void RoundRobin( vector<Job>& allJobs, Queue<Job*>& jobQueue, int timePerProcess, const string& logFile );

};

void Processor::FirstComeFirstServe( vector<Job>& allJobs, Queue<Job*>& jobQueue, const string& logFile )
{
    // log file
    ofstream output(logFile);
    output <<"First Come First Served (FCFS)" << endl;

    int cycles = 0;
    // while the job queue is not empty

//     << endl; //0...
    output << "Processing job #" << jobQueue.Front()->id << endl;


    while (jobQueue.Size() > 0 )
    {

        output << "\tCYCLE: " << cycles <<"\t";

        // Process the front-most item
        jobQueue.Front()->Work(FCFS);

        output <<"  REMAINING: \t" << jobQueue.Front()->fcfs_timeRemaining << "  ..." << endl;

        // If the front- mots otem is done
        if (jobQueue.Front()->fcfs_done)
        {
            // set the front-most item's finish time
            jobQueue.Front()->SetFinishTime( cycles, FCFS );
            // pop the item off the JobQueue
            jobQueue.Pop();
            //cycles = 0;
            output <<"Done" << endl;
            output << endl<< endl;
            output <<"----------------------------------------------" << endl;
            if (jobQueue.Size() > 0 )
                        output << "Processing job #" << jobQueue.Front()->id << endl;
        }

        // increment the cycles
        cycles++;
    }

    // Write the summary to the output file
    output <<"----------------------------------------------" << endl;
    output << endl << endl;
    output <<"First come, first serve results:"<< endl<< endl;
    output <<"JOB ID    TIME TO COMPLETE    " << endl;
    double sumOf_fcfs_finishTime = 0;
    for (unsigned int i = 0; i < allJobs.size() ; i++){

            output << allJobs[i].id <<" \t  "<<allJobs[i].fcfs_finishTime << endl;
            sumOf_fcfs_finishTime += allJobs[i].fcfs_finishTime;
            // << endl;

       // output << jobQueue.At(i)->id;
       // >id <<"\t\t" <<jobQueue.Front()
    }
    //output << "Total time: ............. " << sumOf_fcfs_finishTime << endl;
    output << "Total time: ............. " << cycles << endl;

    output <<"\t(Time for all jobs to complete processing)" <<endl <<endl ;
    output <<"Average time: ........... " << (double)cycles/allJobs.size() << endl;
    output <<"\t\t(The average time to complete, including the wait time while items\n are ahead of it in the queue.)" << endl;






    output.close();
}

void Processor::RoundRobin( vector<Job>& allJobs, Queue<Job*>& jobQueue, int timePerProcess, const string& logFile )
{
    // log file
    ofstream output(logFile);
    output <<"Round Robin (RR)" << endl;

    int cycles = 0;
    // while the job queue is not empty

    int timer = 0;

    output << "Processing job #" << jobQueue.Front()->id << endl;

    while (jobQueue.Size() > 0){

        output << "\tCYCLE: " << cycles <<"\t";
        jobQueue.Front()->Work(RR);
        output <<"  REMAINING: \t" << jobQueue.Front()->rr_timeRemaining << "  ..." << endl;
        timer++;


        if ( timer == timePerProcess ){
            jobQueue.Front()->rr_timesInterrupted++;
            jobQueue.Push(jobQueue.Front());
            jobQueue.Pop();
            timer = 0;
            output<<endl;
            output <<"----------------------------------------------" << endl;
            output << "Processing job #" << jobQueue.Front()->id << endl;
        }

        if (jobQueue.Front()->rr_done){
            // set the front-most item's finish time
            jobQueue.Front()->SetFinishTime( cycles, RR);
            // pop the item off the JobQueue
            jobQueue.Pop();
        }

        cycles++;


    }

    output <<"----------------------------------------------" << endl;
    output <<"----------------------------------------------" << endl;
    output << endl << endl;
    output <<"Round Robin results:"<< endl<< endl;
    output <<"JOB ID    TIME TO COMPLETE    TIMES INTERRUPTED " << endl;
    //double totalTime = 0;
    for (unsigned int i = 0; i < allJobs.size(); i++){
        output << allJobs[i].id << "\t  " << allJobs[i].rr_finishTime<< "\t\t      " << allJobs[i].rr_timesInterrupted << endl;
        //totalTime += allJobs[i].rr_finishTime;
    }
    output << "Total time: ...........  " << cycles << endl ;
    output << "	(Time for all jobs to complete processing)" << endl << endl;
    output << "Average time: ........... " << (double)cycles/allJobs.size() << endl ;
    output <<"	(The average time to complete, including the wait time while items \n\t are ahead of it in the queue.)" << endl << endl;

    output << "Round robin interval: ... " << timePerProcess << endl;
    output <<"	(Every n units of time, move the current item being processed\n	to the back of the queue and start working on the next item)" << endl;
output.close();
}

#endif
