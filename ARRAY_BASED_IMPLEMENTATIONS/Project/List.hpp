#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>
using namespace std;


template <typename T>
class List
{
private:
    // private member variables

    int m_itemCount;
    static const int ARRAY_SIZE = 100;
    T items[ARRAY_SIZE];

    // functions for interal-workings
    bool ShiftRight( int atIndex )
    {
        if ( (atIndex < 0 || atIndex > m_itemCount-1) && m_itemCount > 0 ) {
            return false;
        }

        m_itemCount ++;
        for (int i= m_itemCount-1; i > atIndex; i--)
             items[i] = items[i-1];

        return true;
    }

    bool ShiftLeft( int atIndex )
    {

        if ( atIndex < 0 || atIndex > m_itemCount-1  ) {
            return false;
        }

        for (int i = atIndex+1; i < m_itemCount; i++)
             items[i-1] = items[i];

        m_itemCount --;
        return true;
    }

public:
    List() : m_itemCount(0)
    {
    }

    ~List()
    {
    }

    // Core functionality
    int     Size() const
    {
        return m_itemCount;
    }

    bool    IsEmpty() const
    {
        return (m_itemCount == 0);
    }

    bool    IsFull() const
    {
        return (m_itemCount == ARRAY_SIZE);
    }

    bool    PushFront( const T& newItem )
    {
        return ( Insert(0, newItem) );

    }


    bool    PushBack( const T& newItem )
    {
        if (m_itemCount < ARRAY_SIZE)
        {
            items[m_itemCount] = newItem;
            m_itemCount++;
            return true;
        }
        else
        {
            return false;

        }
    }


    bool    Insert( int atIndex, const T& item )
    {

        if ( IsFull() )
           return false;

        if ( atIndex < 0 || atIndex > m_itemCount  ) {
            return false;
        }

        ShiftRight(atIndex);
        items[atIndex] = item;
        return true;
    }



    bool    PopFront()
    {
        return( ShiftLeft(0) );
    }

    bool    PopBack()
    {
        bool done = false; //ans = Remove((m_itemCount-1) );
        if (m_itemCount > 0){
            m_itemCount --; // deleting the last index is the same as deleting the last element
            done = true;
        }

        return done;
    }

    bool RemoveWithValue( const T& value )
    {
        bool done = false;

        int i = m_itemCount-1;
        while ( i >= 0 ){
            if (items[i] == value)
            {
                RemoveAtIndex(i);
                done = true;
            }
            i--;
        }

        return done;
    }


    bool RemoveAtIndex( int index )
    {
        return ShiftLeft(index);
    }



    void    Clear()
    {
        m_itemCount = 0;
    }

    // Accessors
    T*      Get( int atIndex )
    {
        if (atIndex >= 0 && atIndex < m_itemCount) {
            T * temp = items;
            return (temp + atIndex);
        }
        else{
            return nullptr;
        }
    }

    T*      GetFront()
    {
        return ( Get(0) );

    }

    T*      GetBack()
    {
        return( Get(m_itemCount-1) );
    }

    // Additional functionality
    int     GetCountOf( const T& item ) const
    {
        int cnt = 0;
        for (int i = 0; i < m_itemCount; i++){
            if (items[i] == item)
                cnt++;
        }
        return cnt;
    }

    bool    Contains( const T& item ) const
    {
        return GetCountOf(item);
        //return false; // placeholder
    }


    // Helper function
    void Display()
    {
        cout << "\t List size: " << Size() << endl;
        for ( int i = 0; i < Size(); i++ )
        {
            T* item = Get(i);

            cout << "\t " << i << " = ";

            if ( item == nullptr )
            {
                cout << "nullptr" << endl;
            }
            else
            {
                cout << *item << endl;
            }
        }
    }

    friend class Tester;
};


#endif
