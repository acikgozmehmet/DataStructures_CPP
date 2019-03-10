#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


template <typename T>

class ArrayStack{
public:
    ArrayStack(){
        m_itemCount = 0;
        m_array = nullptr;
    }


    ~ArrayStack(){
        if (m_array != nullptr ){
            delete [] m_array;
        }

    }

    void Push(const T& newData) noexcept {
        if (m_array == nullptr){
            Allocate(10);
        }
        else if (m_itemCount == m_arraySize)
        {
            Resize();
        }

        m_array[m_itemCount] = newData;
        m_itemCount++;
    }

    T& Top(){

        if ( (m_itemCount == 0) || (m_array == nullptr) ){
           throw runtime_error( "ArrayStack is empty!" );
        }

        return m_array[m_itemCount-1];
    }

    void Pop(){

        if (m_itemCount == 0 || m_array == nullptr){
            throw runtime_error("Array is empty and Nothing to pop! ");
        }

        if (m_itemCount > 0){
            m_itemCount--;
        }

    }

    int Size(){
        return m_itemCount;
    }

private:
    int m_itemCount;
    T * m_array;
    int m_arraySize;

    void Resize(){

        T *new_array = new T[ m_itemCount * 2 ];

        for (int i =0; i < m_itemCount; i++){
            new_array[i] = m_array[i];
        }

        delete [] m_array;

        m_array = new_array;

        m_arraySize = m_itemCount * 2;

    }

    void Allocate(int size){
        m_array = new T[size];
        m_arraySize = size;
    }
};




#endif // ARRAYSTACK_H
