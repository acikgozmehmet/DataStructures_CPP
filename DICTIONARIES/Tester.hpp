/*
DON'T MODIFY THIS FILE

If this file doesn't compile for you in Code::Blocks,
go to the Build Options (Project > Build options...)
and select the flag for
"Have g++ follow the C++11 ISO C++ language standard"
*/

#ifndef _TESTER_HPP	// Don't allow duplicates
#define _TESTER_HPP	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "HashTable.hpp"

//! Unit tests for the Hash Table
class Tester : public TesterBase
{
public:
    Tester()
    {
        AddTest(TestListItem("IsEmpty()",           bind(&Tester::Test_IsEmpty, this)));
        AddTest(TestListItem("Size()",              bind(&Tester::Test_Size, this)));
        AddTest(TestListItem("HashFunction()",      bind(&Tester::Test_HashFunction, this)));
        AddTest(TestListItem("HashFunction2()",     bind(&Tester::Test_HashFunction2, this)));
        AddTest(TestListItem("LinearProbe()",       bind(&Tester::Test_LinearProbe, this)));
        AddTest(TestListItem("QuadraticProbe()",    bind(&Tester::Test_QuadraticProbe, this)));
        AddTest(TestListItem("DoubleHash()",        bind(&Tester::Test_DoubleHash, this)));
        AddTest(TestListItem("GetItemIndex()",      bind(&Tester::Test_GetItemIndex, this)));
        AddTest(TestListItem("GetUnusedIndex()",    bind(&Tester::Test_GetUnusedIndex, this)));
        AddTest(TestListItem("Contains()",          bind(&Tester::Test_Contains, this)));
        AddTest(TestListItem("Insert()",            bind(&Tester::Test_Insert, this)));
        AddTest(TestListItem("Remove()",            bind(&Tester::Test_Remove, this)));
        AddTest(TestListItem("GetItem()",           bind(&Tester::Test_GetItem, this)));
    }

private:
    int Test_HashFunction();
    int Test_HashFunction2();
    int Test_LinearProbe();
    int Test_QuadraticProbe();
    int Test_DoubleHash();
    int Test_Insert();
    int Test_Remove();
    int Test_GetItem();
    int Test_GetItemIndex();
    int Test_GetUnusedIndex();
    int Test_Contains();
    int Test_IsEmpty();
    int Test_Size();
};

//! Tests the output index of the HashFunction given some input key
int Tester::Test_HashFunction()
{
    // Table size 131
    StartTestSet( "Test_HashFunction", {  } );

    StartTest( "Try to hash 1024, check the result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 107;
        int actualOutput = employees.HashFunction( 1024 );

        Set_ExpectedOutput( "Hash result", expectedOutput );
        Set_ActualOutput( "Hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Try to hash 2000, check the result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 35;
        int actualOutput = employees.HashFunction( 2000 );

        Set_ExpectedOutput( "Hash result", expectedOutput );
        Set_ActualOutput( "Hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Try to hash 131, check the result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 0;
        int actualOutput = employees.HashFunction( 131 );

        Set_ExpectedOutput( "Hash result", expectedOutput );
        Set_ActualOutput( "Hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests the output index of the HashFunction2 given some input key
int Tester::Test_HashFunction2()
{
    StartTestSet( "Test_HashFunction2", { } );

    StartTest( "Try to hash 1024, check the result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 5;
        int actualOutput = employees.HashFunction2( 1024 );

        Set_ExpectedOutput( "Hash result", expectedOutput );
        Set_ActualOutput( "Hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Try to hash 2000, check the result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 2;
        int actualOutput = employees.HashFunction2( 2000 );

        Set_ExpectedOutput( "Hash result", expectedOutput );
        Set_ActualOutput( "Hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Try to hash 131, check the result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 2;
        int actualOutput = employees.HashFunction2( 131 );

        Set_ExpectedOutput( "Hash result", expectedOutput );
        Set_ActualOutput( "Hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests the output of the LinearProbe given some input
int Tester::Test_LinearProbe()
{
    StartTestSet( "Test_LinearProbe", { } );

    StartTest( "Check linear probe value." ); {
        HashTable<int,string> employees;

        int expectedOutput = 132;
        int actualOutput = employees.LinearProbe( 131 );

        Set_ExpectedOutput( "Linear probe result", expectedOutput );
        Set_ActualOutput( "Linear probe result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Check linear probe value." ); {
        HashTable<int,string> employees;

        int expectedOutput = 51;
        int actualOutput = employees.LinearProbe( 50 );

        Set_ExpectedOutput( "Linear probe result", expectedOutput );
        Set_ActualOutput( "Linear probe result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests the output of the QuadraticProbe given some input
int Tester::Test_QuadraticProbe()
{
    StartTestSet( "Test_QuadraticProbe", {  } );

    StartTest( "Check quadratic probe value for 1st collision." ); {
        HashTable<int,string> employees;
        int input = 1;

        int expectedOutput = 3;
        int actualOutput = employees.QuadraticProbe( 2, input );

        Set_ExpectedOutput( "Quadratic probe result", expectedOutput );
        Set_ActualOutput( "Quadratic probe result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Check quadratic probe value for 2nd collision." ); {
        HashTable<int,string> employees;
        int input = 2;

        int expectedOutput = 6;
        int actualOutput = employees.QuadraticProbe( 2, input );

        Set_ExpectedOutput( "Quadratic probe result", expectedOutput );
        Set_ActualOutput( "Quadratic probe result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Check quadratic probe value for 3rd collision." ); {
        HashTable<int,string> employees;
        int input = 3;

        int expectedOutput = 11;
        int actualOutput = employees.QuadraticProbe( 2, input );

        Set_ExpectedOutput( "Quadratic probe result", expectedOutput );
        Set_ActualOutput( "Quadratic probe result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests the output of the DoubleHash given some input
int Tester::Test_DoubleHash()
{
    StartTestSet( "Test_DoubleHash", { } );

    StartTest( "Check double hash result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 5;
        int actualOutput = employees.HashFunction2( 100 );

        Set_ExpectedOutput( "2nd hash result", expectedOutput );
        Set_ActualOutput( "2nd hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Check double hash result." ); {
        HashTable<int,string> employees;

        int expectedOutput = 2;
        int actualOutput = employees.HashFunction2( 131 );

        Set_ExpectedOutput( "2nd hash result", expectedOutput );
        Set_ActualOutput( "2nd hash result", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests the Insert function using the various probing methods; Prerequisites: GetUnusedindex, HashFunction, LinearProbe, QuadraticProbe, HashFunction2
int Tester::Test_Insert()
{
    StartTestSet( "Test_Insert", { "SetCollisionMethod", "GetUnusedIndex", "HashFunction", "LinearProbe", "QuadraticProbe", "HashFunction2" } );

    StartTest( "Insert \"50, Kabe\" into empty table." ); {
        HashTable<int,string> employees;
        employees.Insert( 50, "Kabe" );

        int expectedIndex = 50;
        int actualIndex = -1;

        string expectedValue = "Kabe";
        string actualValue = employees.m_data[ expectedIndex ].data;

        for ( int i = 0; i < TABLE_SIZE; i++ )
        {
            if ( employees.m_data[i].data == "Kabe" )
            {
                actualIndex = i;
                break;
            }
        }

        Set_ExpectedOutput( "Item at index 50", expectedValue );
        Set_ActualOutput( "Item at index 50", actualValue );

        Set_ExpectedOutput( "Index of inserted item", expectedIndex );
        Set_ActualOutput( "Index of inserted item", actualIndex );

        if ( actualValue != expectedValue || actualIndex != expectedIndex )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Insert \"200, Kabe\" into empty table." ); {
        HashTable<int,string> employees;
        employees.Insert( 201, "Kabe" );

        int expectedIndex = 70;
        int actualIndex = -1;

        string expectedValue = "Kabe";
        string actualValue = employees.m_data[ expectedIndex ].data;

        for ( int i = 0; i < TABLE_SIZE; i++ )
        {
            if ( employees.m_data[i].data == "Kabe" )
            {
                actualIndex = i;
                break;
            }
        }

        Set_ExpectedOutput( "Item at index 70", expectedValue );
        Set_ActualOutput( "Item at index 70", actualValue );

        Set_ExpectedOutput( "Index of inserted item", expectedIndex );
        Set_ActualOutput( "Index of inserted item", actualIndex );

        if ( actualValue != expectedValue || actualIndex != expectedIndex )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* WITH LINEAR PROBING */
    StartTest( "Create collision, check linear probing." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.Insert( 0,   "Kabe" );
        employees.Insert( 131, "Luna" );
        employees.Insert( 262, "Mugs" );

        int expectedIndexOfKabe = 0, actualIndexOfKabe = -1;
        int expectedIndexOfLuna = 1, actualIndexOfLuna = -1;
        int expectedIndexOfMugs = 2, actualIndexOfMugs = -1;

        string expectedValueAt0 = "Kabe", actualValueAt0 = employees.m_data[ expectedIndexOfKabe ].data;
        string expectedValueAt1 = "Luna", actualValueAt1 = employees.m_data[ expectedIndexOfLuna ].data;
        string expectedValueAt2 = "Mugs", actualValueAt2 = employees.m_data[ expectedIndexOfMugs ].data;

        int expectedSize = 3, actualSize = employees.m_size;

        for ( int i = 0; i < TABLE_SIZE; i++ )
        {
            if ( employees.m_data[i].data == "Kabe" )       { actualIndexOfKabe = i; }
            else if ( employees.m_data[i].data == "Luna" )  { actualIndexOfLuna = i; }
            else if ( employees.m_data[i].data == "Mugs" )  { actualIndexOfMugs = i; }
        }

        Set_ExpectedOutput( "Item at index 0", expectedValueAt0 );
        Set_ActualOutput(   "Item at index 0", actualValueAt0 );

        Set_ExpectedOutput( "Item at index 1", expectedValueAt1 );
        Set_ActualOutput(   "Item at index 1", actualValueAt1 );

        Set_ExpectedOutput( "Item at index 2", expectedValueAt2 );
        Set_ActualOutput(   "Item at index 2", actualValueAt2 );

        Set_ExpectedOutput( "Index of Kabe", expectedIndexOfKabe );
        Set_ActualOutput(   "Index of Kabe", actualIndexOfKabe );

        Set_ExpectedOutput( "Index of Luna", expectedIndexOfLuna );
        Set_ActualOutput(   "Index of Luna", actualIndexOfLuna );

        Set_ExpectedOutput( "Index of Mugs", expectedIndexOfMugs );
        Set_ActualOutput(   "Index of Mugs", actualIndexOfMugs );

        Set_ExpectedOutput( "Size", expectedSize );
        Set_ActualOutput(   "Size", actualSize );

        if (    actualValueAt0 != expectedValueAt0
            ||  actualValueAt1 != expectedValueAt1
            ||  actualValueAt2 != expectedValueAt2
            ||  actualIndexOfKabe != expectedIndexOfKabe
            ||  actualIndexOfLuna != expectedIndexOfLuna
            ||  actualIndexOfMugs != expectedIndexOfMugs
            ||  actualSize != expectedSize
            )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* WITH QUADRATIC PROBING */
    StartTest( "Create collision, check quadratic probing." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( QUADRATIC );
        employees.Insert( 0,   "Kabe" );
        employees.Insert( 131, "Luna" ); // Collision 1, moves by 1^2
        employees.Insert( 262, "Mugs" ); // Collision 2, moves by 2^2

        int expectedIndexOfKabe = 0,        actualIndexOfKabe = -1;
        int expectedIndexOfLuna = 1,    actualIndexOfLuna = -1;
        int expectedIndexOfMugs = 4,    actualIndexOfMugs = -1;

        string expectedValueAt0 = "Kabe", actualValueAt0 = employees.m_data[ expectedIndexOfKabe ].data;
        string expectedValueAt1 = "Luna", actualValueAt1 = employees.m_data[ expectedIndexOfLuna ].data;
        string expectedValueAt2 = "Mugs", actualValueAt2 = employees.m_data[ expectedIndexOfMugs ].data;

        for ( int i = 0; i < TABLE_SIZE; i++ )
        {
            if ( employees.m_data[i].data == "Kabe" )       { actualIndexOfKabe = i; }
            else if ( employees.m_data[i].data == "Luna" )  { actualIndexOfLuna = i; }
            else if ( employees.m_data[i].data == "Mugs" )  { actualIndexOfMugs = i; }
        }

        Set_ExpectedOutput( "Item at index 0", expectedValueAt0 );
        Set_ActualOutput(   "Item at index 0", actualValueAt0 );

        Set_ExpectedOutput( "Item at index 1", expectedValueAt1 );
        Set_ActualOutput(   "Item at index 1", actualValueAt1 );

        Set_ExpectedOutput( "Item at index 2", expectedValueAt2 );
        Set_ActualOutput(   "Item at index 2", actualValueAt2 );

        Set_ExpectedOutput( "Index of Kabe", expectedIndexOfKabe );
        Set_ActualOutput(   "Index of Kabe", actualIndexOfKabe );

        Set_ExpectedOutput( "Index of Luna", expectedIndexOfLuna );
        Set_ActualOutput(   "Index of Luna", actualIndexOfLuna );

        Set_ExpectedOutput( "Index of Mugs", expectedIndexOfMugs );
        Set_ActualOutput(   "Index of Mugs", actualIndexOfMugs );

        if (    actualValueAt0 != expectedValueAt0
            ||  actualValueAt1 != expectedValueAt1
            ||  actualValueAt2 != expectedValueAt2
            ||  actualIndexOfKabe != expectedIndexOfKabe
            ||  actualIndexOfLuna != expectedIndexOfLuna
            ||  actualIndexOfMugs != expectedIndexOfMugs
            )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* WITH DOUBLE HASHING */
    StartTest( "Create collision, check double hashing." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( DOUBLE );
        employees.Insert( 0,   "Kabe" );
        employees.Insert( 131, "Luna" );
        employees.Insert( 262, "Mugs" );

        // Hash 2: 7 - ( key % 7 );
        // index    = Hash(key) + collisions * Hash2(key) % TABLE_SIZE;
        //          = 0         + 1 * 2
        //          = 0         + 2 * 2
        int expectedIndexOfKabe = 0,    actualIndexOfKabe = -1;
        int expectedIndexOfLuna = 2,    actualIndexOfLuna = -1;
        int expectedIndexOfMugs = 4,   actualIndexOfMugs = -1;

        string expectedValueAt0 = "Kabe", actualValueAt0 = employees.m_data[ expectedIndexOfKabe ].data;
        string expectedValueAt1 = "Luna", actualValueAt1 = employees.m_data[ expectedIndexOfLuna ].data;
        string expectedValueAt2 = "Mugs", actualValueAt2 = employees.m_data[ expectedIndexOfMugs ].data;

        for ( int i = 0; i < TABLE_SIZE; i++ )
        {
            if ( employees.m_data[i].data == "Kabe" )       { actualIndexOfKabe = i; }
            else if ( employees.m_data[i].data == "Luna" )  { actualIndexOfLuna = i; }
            else if ( employees.m_data[i].data == "Mugs" )  { actualIndexOfMugs = i; }
        }

        Set_ExpectedOutput( "Item at index 0", expectedValueAt0 );
        Set_ActualOutput(   "Item at index 0", actualValueAt0 );

        Set_ExpectedOutput( "Item at index 1", expectedValueAt1 );
        Set_ActualOutput(   "Item at index 1", actualValueAt1 );

        Set_ExpectedOutput( "Item at index 2", expectedValueAt2 );
        Set_ActualOutput(   "Item at index 2", actualValueAt2 );

        Set_ExpectedOutput( "Index of Kabe", expectedIndexOfKabe );
        Set_ActualOutput(   "Index of Kabe", actualIndexOfKabe );

        Set_ExpectedOutput( "Index of Luna", expectedIndexOfLuna );
        Set_ActualOutput(   "Index of Luna", actualIndexOfLuna );

        Set_ExpectedOutput( "Index of Mugs", expectedIndexOfMugs );
        Set_ActualOutput(   "Index of Mugs", actualIndexOfMugs );

        if (    actualValueAt0 != expectedValueAt0
            ||  actualValueAt1 != expectedValueAt1
            ||  actualValueAt2 != expectedValueAt2
            ||  actualIndexOfKabe != expectedIndexOfKabe
            ||  actualIndexOfLuna != expectedIndexOfLuna
            ||  actualIndexOfMugs != expectedIndexOfMugs
            )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests getting an item given some key using various probing methods; Prerequisites: SetCollisionMethod, Insert
int Tester::Test_GetItem()
{
    StartTestSet( "Test_GetItem", { "SetCollisionMethod", "Insert" } );

    StartTest( "Add item, check if it's returned when searching for the key." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.Insert( 0, "Mei" );
        employees.Insert( 131, "Orisa" );
        employees.Insert( 262, "Lucio" );

        string expectedValue = "Orisa";
        string actualValue = employees.GetItem( 131 );

        Set_ExpectedOutput( "value", expectedValue );
        Set_ActualOutput( "value", actualValue );

        if ( actualValue != expectedValue )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Try to get item that doesn't exist." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.Insert( 0, "Mei" );
        employees.Insert( 1, "Orisa" );
        employees.Insert( 2, "Lucio" );

        bool expectedException = true;
        bool actualException = false;

        string item;

        try
        {
            item = employees.GetItem( 3 );
        }
        catch( exception ex )
        {
            actualException = true;
        }

        Set_ExpectedOutput( "Threw an exception", expectedException );
        Set_ActualOutput( "Threw an exception", actualException );

        Set_ExpectedOutput( "Found item", "NOTHING" );
        if ( actualException == true )
            Set_ActualOutput( "Found item", "NOTHING" );
        else
            Set_ActualOutput( "Found item", item );

        if ( actualException != expectedException )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Tests the removal of an item; Prerequisites: Insert, SetCollisionMethod
int Tester::Test_Remove()
{
    StartTestSet( "Test_Remove", { "Insert", "SetCollisionMethod" } );

    StartTest( "Add item, then remove. Check size." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.Insert( 0, "Mei" );
        employees.Insert( 131, "Orisa" );
        employees.Insert( 262, "Lucio" );

        employees.Remove( 131 );

        bool expectedHasData = false;
        bool actualHasData = employees.m_data[1].hasData;

        int expectedSize = 2;
        int actualSize = employees.m_size;

        Set_ExpectedOutput( "hasData", expectedHasData );
        Set_ActualOutput( "hasData", actualHasData );

        Set_ExpectedOutput( "size", expectedSize );
        Set_ActualOutput( "size", actualSize );

        if ( actualHasData != expectedHasData )
        {
            TestFail();
        }
        else if ( actualSize != expectedSize )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    StartTest( "Try to remove item that doesn't exist. Check size." ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.Insert( 0, "Mei" );
        employees.Insert( 1, "Orisa" );
        employees.Insert( 2, "Lucio" );

        try
        {
            employees.Remove( 3 );
        }
        catch( exception ex )
        {
        }

        int expectedSize = 3;
        int actualSize = employees.m_size;

        Set_ExpectedOutput( "size", expectedSize );
        Set_ActualOutput( "size", actualSize );

        if ( actualSize != expectedSize )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Gets an item's index given some key; Prerequisite: SetCollisionMethod
int Tester::Test_GetItemIndex()
{
    StartTestSet( "Test_GetItemIndex", { "SetCollisionMethod" } );
    cout <<"BASLIYOR!" << endl;
    /* Linear */
    StartTest( "Get item index / Linear probing" ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.m_data[0].hasData = true;
        employees.m_data[1].hasData = true;
        employees.m_data[2].hasData = true;
        employees.m_data[2].key = 131;

        int expectedOutput = 2;
        int actualOutput = employees.GetIndex( 131, false );

        Set_ExpectedOutput( "Generated index", expectedOutput );
        Set_ActualOutput( "Generated index", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* Quadratic */
    StartTest( "Get item index / Quadratic probing" ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( QUADRATIC );
        employees.m_data[0].hasData = true;
        employees.m_data[1].hasData = true;
        employees.m_data[4].hasData = true;
        employees.m_data[4].key = 131;

        int expectedOutput = 4;
        int actualOutput;

        try
        {
            actualOutput = employees.GetIndex( 131, false );
        } catch( exception& ex )
        {
            cout << endl << ex.what() << endl;
        }

        Set_ExpectedOutput( "Generated index", expectedOutput );
        Set_ActualOutput( "Generated index", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* Double */
    StartTest( "Get item index / Double hashing" ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( DOUBLE );
        employees.m_data[0].hasData = true;

        // Fixed version
        int expectedOutputNew = 2;
        employees.m_data[expectedOutputNew].hasData = true;
        employees.m_data[expectedOutputNew].key = 131;

        // Hash( key ) + collisions * Hash2( key )
        int actualOutput = employees.GetIndex( 131, false );

        Set_ExpectedOutput( "Generated index", expectedOutputNew );
        Set_ActualOutput( "Generated index", actualOutput );

        if ( actualOutput != expectedOutputNew )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Gets an index of an unused space in the array given some key; Prerequisite: SetCollisionMethod
int Tester::Test_GetUnusedIndex()
{
    StartTestSet( "Test_GetUnusedIndex", { "SetCollisionMethod" } );

    /* Linear */
    StartTest( "Get unused index / Linear probing" ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( LINEAR );
        employees.m_data[0].hasData = true;
        employees.m_data[1].hasData = true;
        employees.m_data[2].hasData = true;

        int expectedOutput = 3;
        int actualOutput = employees.GetIndex( 131, true );

        bool expectedIsUsed = false;
        bool actualIsUsed = employees.m_data[expectedOutput].hasData;

        Set_ExpectedOutput( "Generated index", expectedOutput );
        Set_ActualOutput( "Generated index", actualOutput );

        Set_ExpectedOutput( "Item has data", expectedIsUsed );
        Set_ActualOutput( "Item has data", actualIsUsed );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else if ( actualIsUsed != expectedIsUsed )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* Quadratic */
    StartTest( "Get unused index / Quadratic probing" ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( QUADRATIC );
        employees.m_data[0].hasData = true;
        employees.m_data[1].hasData = true;
        employees.m_data[4].hasData = true;

        int expectedOutput = 9;
        int actualOutput = employees.GetIndex( 131, true );

        bool expectedIsUsed = false;
        bool actualIsUsed = employees.m_data[expectedOutput].hasData;

        Set_ExpectedOutput( "Generated index", expectedOutput );
        Set_ActualOutput( "Generated index", actualOutput );

        Set_ExpectedOutput( "Item has data", expectedIsUsed );
        Set_ActualOutput( "Item has data", actualIsUsed );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else if ( actualIsUsed != expectedIsUsed )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    /* Double */
    StartTest( "Get unused index / Double hashing" ); {
        HashTable<int,string> employees;
        employees.SetCollisionMethod( DOUBLE );
        employees.m_data[0].hasData = true;

        int expectedOutput = 2;
        int actualOutput = employees.GetIndex( 131, true );

        bool expectedIsUsed = false;
        bool actualIsUsed = employees.m_data[expectedOutput].hasData;

        Set_ExpectedOutput( "Generated index", expectedOutput );
        Set_ActualOutput( "Generated index", actualOutput );

        Set_ExpectedOutput( "Item has data", expectedIsUsed );
        Set_ActualOutput( "Item has data", actualIsUsed );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else if ( actualIsUsed != expectedIsUsed )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Checks whether Contains finds or doesn't find an item; Prerequisite function: Insert()
int Tester::Test_Contains()
{
    StartTestSet( "Test_Contains", {  } );

    StartTest( "Create empty table, add one item, check Contains" ); {
        HashTable<int,string> employees;
        employees.m_data[10].hasData = true;
        employees.m_data[10].key = 10;

        bool expectedOutput = true;
        bool actualOutput = employees.Contains( 10 );

        Set_ExpectedOutput( "Contains()", expectedOutput );
        Set_ActualOutput( "Contains()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    StartTest( "Create empty table, check Contains" ); {
        HashTable<int,string> employees;
        employees.m_data[10].hasData = false;
        employees.m_data[10].key = 10;

        Set_Comments( "Store data at key but set hasData to false. Contains should be false." );

        bool expectedOutput = false;
        bool actualOutput = employees.Contains( 10 );

        Set_ExpectedOutput( "Contains()", expectedOutput );
        Set_ActualOutput( "Contains()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    StartTest( "Create empty table, check Contains" ); {
        HashTable<int,string> employees;

        bool expectedOutput = false;
        bool actualOutput = employees.Contains( 20 );

        Set_ExpectedOutput( "Contains()", expectedOutput );
        Set_ActualOutput( "Contains()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Checks whether table is empty; Prerequisite function: Insert()
int Tester::Test_IsEmpty()
{
    StartTestSet( "Test_IsEmpty", { "Insert" } );

    StartTest( "Create empty Hash Table, check if IsEmpty() returns true." ); {
        HashTable<int,string> employees;

        bool expectedOutput = true;
        bool actualOutput = employees.IsEmpty();

        Set_ExpectedOutput( "IsEmpty()", expectedOutput );
        Set_ActualOutput( "IsEmpty()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    StartTest( "Create empty Hash Table, add items, check if IsEmpty() returns false." ); {
        HashTable<int,string> employees;
        employees.Insert( 123, "Bobbert" );
        employees.Insert( 456, "Kabe the Cat" );

        bool expectedOutput = false;
        bool actualOutput = employees.IsEmpty();

        Set_ExpectedOutput( "IsEmpty()", expectedOutput );
        Set_ActualOutput( "IsEmpty()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    FinishTestSet();
    return TestResult();
}

//! Checks whether size is correct after inserts; Prerequisite function: Insert()
int Tester::Test_Size()
{
    StartTestSet( "Test_Size", { "Insert" } );

    StartTest( "Create empty Hash Table, check Size()." ); {
        HashTable<int,string> employees;

        int expectedOutput = 0;
        int actualOutput = employees.Size();

        Set_ExpectedOutput( "Size()", expectedOutput );
        Set_ActualOutput( "Size()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    StartTest( "Create empty Hash Table, add 2 items, check Size()." ); {
        HashTable<int,string> employees;
        employees.Insert( 123, "Bobbert" );
        employees.Insert( 456, "Kabe the Cat" );

        int expectedOutput = 2;
        int actualOutput = employees.Size();

        Set_ExpectedOutput( "Size()", expectedOutput );
        Set_ActualOutput( "Size()", actualOutput );

        if ( actualOutput != expectedOutput )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }

    } FinishTest();

    FinishTestSet();
    return TestResult();
}


#endif
