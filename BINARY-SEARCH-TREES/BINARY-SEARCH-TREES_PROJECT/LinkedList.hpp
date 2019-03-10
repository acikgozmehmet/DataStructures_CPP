#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

#include "Node.hpp"

template <typename TK, typename TD>
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

    void PushBack( const TK& newKey, const TD& newData )
    {
        Node<TK, TD>* newNode = new Node<TK, TD>;
        newNode->data = newData;
        newNode->key = newKey;
        newNode->IsNotTree();

        if ( ptrFront == NULL && ptrEnd == NULL )
        {
            ptrFront = newNode;
            ptrEnd = newNode;
        }
        else
        {
            // New node goes at end of list
            newNode->ptrLeft = ptrEnd;
            ptrEnd->ptrRight = newNode;
            ptrEnd = newNode;
        }

        m_size++;
    }

    void PushFront( const TK& newKey, const TD& newData )
    {
        Node<TK, TD>* newNode = new Node<TK, TD>;
        newNode->data = newData;
        newNode->key = newKey;
        newNode->IsNotTree();

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
            Node<TK, TD>* penultimate = ptrEnd->ptrLeft;
            delete ptrEnd;
            ptrEnd = penultimate;
            ptrEnd->ptrRight = NULL;
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
            Node<TK, TD>* next = ptrFront->ptrNext;
            delete ptrFront;
            ptrFront = next;
            ptrFront->ptrPrev = NULL;
            m_size--;
        }
    }

    void Remove( TK& key )
    {
        int counter = 0;
        Node<TK, TD>* ptrCurrent = ptrFront;

        while ( ptrCurrent != nullptr )
        {
            if ( ptrCurrent->key == key )
            {
                break;
            }
            ptrCurrent = ptrCurrent->ptrRight;
            counter++;
        }

        if ( ptrCurrent != nullptr )
        {
            Node<TK,TD>* ptrPrev = ptrCurrent->ptrLeft;
            Node<TK,TD>* ptrNext = ptrCurrent->ptrRight;

            if ( ptrFront == ptrEnd )
            {
                // Only one node
                ptrFront = nullptr;
                ptrEnd = nullptr;
            }

            delete ptrCurrent;

            if ( ptrPrev != nullptr )
            {
                ptrPrev->ptrRight = ptrNext;
            }

            if ( ptrNext != nullptr )
            {
                ptrNext->ptrLeft = ptrPrev;
            }

            m_size--;
        }
    }

    TD& GetFirst()
    {
        return ptrFront->data;
    }

    TD& GetLast()
    {
        return ptrEnd->data;
    }

    TD& GetItemAtPosition( int index )
    {
        int counter = 0;
        Node<TK, TD>* ptrCurrent = ptrFront;

        while ( counter < index )
        {
            ptrCurrent = ptrCurrent->ptrRight;
            counter++;
        }

        return ptrCurrent->data;
    }

    TD* GetItemWithKey( const TK& key )
    {
        int counter = 0;
        Node<TK, TD>* ptrCurrent = ptrFront;

        while ( counter < Size() )
        {
            if ( ptrCurrent->key == key )
            {
                break;
            }
            ptrCurrent = ptrCurrent->ptrRight;
            counter++;
        }

        if ( ptrCurrent == nullptr )
        {
            return nullptr;
        }

        return &ptrCurrent->data;
    }

    bool Contains( TD item )
    {
        Node<TK, TD>* ptrCurrent = ptrFront;

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
        Node<TK, TD>* ptrCurrent = ptrFront;
        int counter = 0;
        while ( ptrCurrent != NULL )
        {
            cout << counter++ << ": " << ptrCurrent->data << endl;
            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    private:
    Node<TK, TD>* ptrFront;
    Node<TK, TD>* ptrEnd;
    int m_size;
};

#endif



