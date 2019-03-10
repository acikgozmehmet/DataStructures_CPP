#ifndef _STACK_HPP
#define _STACK_HPP

#include "Node.hpp"

template <typename T>
class LinkedStack
{
    public:
    LinkedStack()
    {
    }

    void Push( const T& newData )
    {
    }

    T& Top()
    {
        throw runtime_error( "Not yet implemented" );   // placeholder
    }

    void Pop()
    {
    }

    int Size()
    {
        return -1;    // placeholder
    }

    private:
    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif
