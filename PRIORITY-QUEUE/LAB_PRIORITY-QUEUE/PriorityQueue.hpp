#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

#include "Menu.hpp"
#include "Job.hpp"

const int MAX_SIZE = 1000;

class PriorityQueue
{
    public:
    PriorityQueue();
    void Push( Job* task );
    void Pop();
    Job* Front();
    int Size();
    void Display();

    private:
    void ShiftRight( int atIndex );
    void ShiftLeft( int atIndex );

    Job* m_arr[MAX_SIZE];
    int m_itemCount;
};

PriorityQueue::PriorityQueue()
{
    m_itemCount = 0;
}

void PriorityQueue::Push( Job* task )
{
    //throw runtime_error( "Not yet implemented" );
    if (m_itemCount == MAX_SIZE)
        throw runtime_error("Additional items can not be added");

    int insertAt = m_itemCount; // if it does not have hihgh priority, goes to the end of the line

    for (int i = 0; i < m_itemCount; i++){
        if ( (m_arr[i]->dueOnDay) > (task->dueOnDay) )   {
            insertAt = i;
            break;
        }
    }

    ShiftRight(insertAt);
    m_arr[insertAt] = task;
    m_itemCount++;


}

void PriorityQueue::Pop()
{
    if (m_itemCount > 0){
        ShiftLeft(0);
        m_itemCount--;
    }
    //throw runtime_error( "Not yet implemented" );
}

Job* PriorityQueue::Front()
{
    return m_arr[0];
    //throw runtime_error( "Not yet implemented" );
}

void PriorityQueue::ShiftRight( int atIndex )
{
    for ( int i = m_itemCount; i > atIndex; i-- )
    {
        m_arr[i] = m_arr[i-1];
    }
}

void PriorityQueue::ShiftLeft( int atIndex )
{
    for ( int i = atIndex + 1; i < m_itemCount; i++ )
    {
        m_arr[i-1] = m_arr[i];
    }
}

int PriorityQueue::Size()
{
    return m_itemCount;
}

void PriorityQueue::Display()
{
    cout << endl;
    Menu::Header( "Priority Queue" );
    cout << left
        << setw( 10 ) << "INDEX"
        << setw( 10 ) << "DUE"
        << setw( 50 ) << "ASSIGNMENT" << endl;

    for ( int i = 0; i < m_itemCount; i++ )
    {
        cout << left
            << setw( 10 ) << i
            << setw( 10 ) << m_arr[i]->dueOnDay
            << setw( 50 ) << m_arr[i]->assignment << endl;
    }
}

#endif
