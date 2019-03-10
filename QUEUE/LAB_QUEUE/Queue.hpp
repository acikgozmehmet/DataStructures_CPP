#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "LinkedList.hpp"

template <typename T>
class Queue
{
    public:
    void Push( T data )
    {
        m_list.PushBack(data);
        //throw runtime_error( "not yet implemented" ); // placeholder
    }

    void Pop()
    {
        m_list.PopFront();
        //throw runtime_error( "not yet implemented" ); // placeholder
    }

    T& Front()
    {
        m_list.GetFirst();
        //throw runtime_error( "not yet implemented" ); // placeholder
    }

    int Size()
    {
        return m_list.Size();
        //throw runtime_error( "not yet implemented" ); // placeholder
    }

    private:
        LinkedList<T> m_list; // has a - composition
};

#endif
