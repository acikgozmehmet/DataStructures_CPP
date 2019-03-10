#ifndef _TESTS
#define _TESTS

#include "LinkedList.hpp"

#include <iostream>
using namespace std;

class Tester
{
    public:
    void RunTests();

    private:
    void DrawLine();
    void Test_Init();

    void Test_Size();
    void Test_IsEmpty();
    void Test_IsFull();
    void Test_GetCountOf();
    void Test_Contains();

    void Test_ShiftRight();
    void Test_ShiftLeft();

    void Test_PushFront();
    void Test_PushBack();
    void Test_Insert();

    void Test_PopFront();
    void Test_PopBack();
    void Test_Remove();
    void Test_Clear();

    void Test_Get();
    void Test_GetFront();
    void Test_GetBack();
};

#endif
