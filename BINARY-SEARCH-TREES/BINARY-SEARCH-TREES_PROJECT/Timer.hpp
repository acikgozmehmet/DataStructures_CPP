#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
using namespace std;

class Timer
{
    public:
    void Start()
    {
        m_startTime = chrono::system_clock::now();
    }

    unsigned int GetElapsedSeconds()
    {
        auto current_time = std::chrono::system_clock::now();
        return chrono::duration_cast<std::chrono::seconds>( current_time - m_startTime ).count();
    }

    unsigned int GetElapsedMilliseconds()
    {
        auto current_time = std::chrono::system_clock::now();
        return chrono::duration_cast<std::chrono::milliseconds>( current_time - m_startTime ).count();
    }

    private:    
    chrono::system_clock::time_point m_startTime;
};


#endif 
