#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    Node()
    {
        ptrNext = NULL;
        ptrPrev = NULL;
    }

    T data;
    Node* ptrNext;
    Node* ptrPrev;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList()
    {
        ptrFront = NULL;
        ptrEnd = NULL;
        m_size = 0;
    }

    ~LinkedList()
    {
        Clear();
    }

    void Clear()
    {
        while ( ptrFront != NULL )
        {
            PopBack();
        }
    }

    void PushBack( T data )
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if ( ptrFront == NULL && ptrEnd == NULL )
        {
            ptrFront = newNode;
            ptrEnd = newNode;
        }
        else
        {
            // New node goes at end of list
            newNode->ptrPrev = ptrEnd;
            ptrEnd->ptrNext = newNode;
            ptrEnd = newNode;
        }

        m_size++;
    }

    void PushFront( T data )
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        if ( ptrFront == NULL && ptrEnd == NULL )
        {
            ptrFront = newNode;
            ptrEnd = newNode;
        }
        else
        {
            // New node goes at the front of the list
            newNode->ptrNext = ptrFront;
            ptrFront->ptrPrev = newNode;
            ptrFront = newNode;
        }

        m_size++;
    }

    void PopBack()
    {
        if ( m_size == 0 )
        {
            return;
        }
        else if ( ptrFront == ptrEnd )
        {
            delete ptrFront;
            ptrFront = NULL;
            ptrEnd = NULL;
            m_size = 0;
        }
        else
        {
            // Remove the last element
            Node<T>* penultimate = ptrEnd->ptrPrev;
            delete ptrEnd;
            ptrEnd = penultimate;
            ptrEnd->ptrNext = NULL;
            m_size--;
        }
    }

    void PopFront()
    {
        if ( m_size == 0 )
        {
            return;
        }
        else if ( ptrFront == ptrEnd )
        {
            delete ptrFront;
            ptrFront = NULL;
            ptrEnd = NULL;
            m_size = 0;
        }
        else
        {
            // Remove the first element
            Node<T>* next = ptrFront->ptrNext;
            delete ptrFront;
            ptrFront = next;
            ptrFront->ptrPrev = NULL;
            m_size--;
        }
    }

    T& GetFirst()
    {
        return ptrFront->data;
    }

    T& GetLast()
    {
        return ptrEnd->data;
    }

    T& At( int index )
    {
        int counter = 0;
        Node<T>* ptrCurrent = ptrFront;

        while ( counter < index )
        {
            ptrCurrent = ptrCurrent->ptrNext;
            counter++;
        }

        return ptrCurrent->data;
    }

    bool Contains( T item )
    {
        Node<T>* ptrCurrent = ptrFront;

        while ( ptrCurrent != nullptr )
        {
            if ( ptrCurrent->data == item )
            {
                return true;
            }

            ptrCurrent = ptrCurrent->ptrNext;
        }

        return false;
    }

    int Size()
    {
        return m_size;
    }

    bool IsEmpty()
    {
        return ( m_size == 0 );
    }

    void Display()
    {
        Node<T>* ptrCurrent = ptrFront;
        int counter = 0;
        while ( ptrCurrent != NULL )
        {
            cout << counter++ << ": " << ptrCurrent->data << endl;
            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    private:
    Node<T>* ptrFront;
    Node<T>* ptrEnd;
    int m_size;
};

#endif




