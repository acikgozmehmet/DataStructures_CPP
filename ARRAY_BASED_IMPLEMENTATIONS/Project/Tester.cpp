#include "Tester.hpp"

void Tester::RunTests()
{
    Test_IsEmpty();
    Test_IsFull();
    Test_Size();
    Test_GetCountOf();
    Test_Contains();

    Test_PushFront();
    Test_PushBack();

    Test_Get();
    Test_GetFront();
    Test_GetBack();

    Test_PopFront();
    Test_PopBack();
    Test_Clear();

    Test_ShiftRight();
    Test_ShiftLeft();

    //Test_Remove();
    Test_RemoveAtIndex();
    Test_RemoveWithValue();

    Test_Insert();
}

void Tester::DrawLine()
{
    cout << endl;
    for ( int i = 0; i < 80; i++ )
    {
        cout << "-";
    }
    cout << endl;
}

void Tester::Test_Init()
{
    DrawLine();
    cout << "TEST: Test_Init" << endl;

    // Put tests here
}

void Tester::Test_ShiftRight()
{
    DrawLine();
    cout << "TEST: Test_ShiftRight" << endl;

    { // Test begin
        cout << endl << "Test-1" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.ShiftRight(0);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue   << endl;

        (expectedValue == actualValue ? cout << "Pass\n" : cout << "Fail\n");
        cout << endl;

        ListLetters.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-2" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.ShiftRight(1);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue   << endl;

        (expectedValue == actualValue ? cout << "Pass\n" : cout << "Fail\n");
        cout << endl;


        ListLetters.Display();

    } // Test end


    { // Test begin
        cout << endl << "Test-3" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.ShiftRight(2);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue   << endl;

        (expectedValue == actualValue ? cout << "Pass\n" : cout << "Fail\n");
        cout << endl;


        ListLetters.Display();
    } // Test end

        { // Test begin
        cout << endl << "Test-4" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = false;
        bool actualValue = ListLetters.ShiftRight(3);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue   << endl;

        (expectedValue == actualValue ? cout << "Pass\n" : cout << "Fail\n");
        cout << endl;

        ListLetters.Display();

        } //Test end
}

void Tester::Test_ShiftLeft()
{
    DrawLine();
    cout << "TEST: Test_ShiftLeft" << endl;

    { // Test begin
        cout << endl << "Test-1" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.ShiftLeft(1);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;

        (expectedValue==actualValue ? cout << "Pass\n":cout <<"Fail\n");
        cout << endl;

        ListLetters.Display();

     } // Test end

     { // Test begin
        cout << endl << "Test-2" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.ShiftLeft(0);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;

        (expectedValue==actualValue ? cout << "Pass\n":cout <<"Fail\n");
        cout << endl;

        ListLetters.Display();
     } // Test end

     { // Test begin
        cout << endl << "Test-3" << endl;
        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = false;
        bool actualValue = ListLetters.ShiftLeft(3);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;

        (expectedValue==actualValue ? cout << "Pass\n":cout <<"Fail\n");
        cout << endl;

        ListLetters.Display();
     } // Test end
}

void Tester::Test_Size()
{
    DrawLine();
    cout << "TEST: Test_Size" << endl;

    {   // Test begin
        cout << endl << "Test 1" << endl;
        List<int> testList;
        int expectedSize = 0;
        int actualSize = testList.Size();

        cout << "Expected size: " << expectedSize << endl;
        cout << "Actual size:   " << actualSize << endl;

        if ( actualSize == expectedSize )
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }   // Test end

    {   // Test begin
        cout << endl << "Test 2" << endl;
        List<int> testList;

        testList.PushBack( 1 );

        int expectedSize = 1;
        int actualSize = testList.Size();

        cout << "Expected size: " << expectedSize << endl;
        cout << "Actual size:   " << actualSize << endl;

        if ( actualSize == expectedSize )
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }   // Test end

    { // Test begin
        cout << endl <<"Test-3" << endl;
        List<int> ListInt;

        for (int i = 0; i < 103; i++)
            ListInt.PushBack(i);

        int expectedValue = 100;
        int actualValue = ListInt.Size();

        cout <<"Expected Value : " << expectedValue << endl;
        cout <<"Acutal   Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass":cout <<"Fail");
        cout << endl;
    } // Test end


    { // Test begin

        cout << endl <<"Test-4" << endl;
        List<int> ListInt;

        ListInt.PushBack(1);
        ListInt.PushBack(2);
        ListInt.PushBack(3);
        ListInt.PushBack(4);
        ListInt.PushBack(5);

        ListInt.PopBack();
        ListInt.PopBack();


        int expectedValue = 3;
        int actualValue = ListInt.Size();

        cout <<"Expected Value : " << expectedValue << endl;
        cout <<"Acutal   Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass":cout <<"Fail");
        cout << endl;
    } // test end
}

void Tester::Test_IsEmpty()
{
    DrawLine();
    cout << "TEST: Test_IsEmpty" << endl;

    {   // Test begin
        cout << endl << "Test 1" << endl;
        List<int> testList;
        bool expectedValue= true;
        bool actualValue = testList.IsEmpty();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass" : cout << "Fail" );
        cout << endl;

        testList.Display();
    }   // Test end

    { // Test begin
        cout << endl << "Test 2" << endl;
        List<int> testList;
        testList.PushBack(1);
        bool expectedValue = false;
        bool actualValue = testList.IsEmpty();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass" : cout << "Fail" );
        cout << endl;
        testList.Display();
    }

    {  // Test begin
        cout << endl << "Test 3" << endl;
        List<int> testList;

        for (int i = 0; i < 101 ; i++)
            testList.PushBack(i);

        bool expectedValue = false;
        bool actualValue = testList.IsEmpty();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;
        cout << "Number of elements : " << testList.Size()<< endl;


        ( (expectedValue == actualValue && testList.Size() == 100 )? cout << "Pass": cout << "Fail");
        cout << endl;

        testList.Display();

    }  // test end

    { //Test begin
        cout << endl << "Test 4" << endl;
        List<int> testList;

        testList.PushBack(1);
        testList.PushBack(2);
        testList.PushBack(3);
        testList.PushBack(4);
        testList.PushBack(5);

        testList.PopBack();
        testList.PopBack();
        testList.PopBack();
        testList.PopBack();
        testList.PopBack();

        bool expectedValue = true;
        bool actualValue = testList.IsEmpty();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;
        cout << "Number of elements : " << testList.Size()<< endl;

        ( (expectedValue == actualValue && testList.Size() == 0 )? cout << "Pass": cout << "Fail");
        cout << endl;

        testList.Display();
    } // test end
    // Put tests here
}

void Tester::Test_IsFull()
{
    DrawLine();
    cout << "TEST: Test_IsFull" << endl;

    {// Test begin
        cout << endl << "Test-1" << endl;
        List<char> ListChar;

        bool expectedValue = false;
        bool actualValue = ListChar.IsFull();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        ( (expectedValue == actualValue) ? cout<<"Pass":cout<<"Fail");
        cout << endl;

        ListChar.Display();
    }


    {// Test begin
        cout << endl <<"Test-2" << endl;
        List<char> ListChar;

        ListChar.PushBack('A');
        ListChar.PushBack('B');

        bool expectedValue = false;
        bool actualValue = ListChar.IsFull();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;
        cout <<"Number of elements is " << ListChar.Size()<< endl;

        ( (expectedValue == actualValue && ListChar.Size() == 2) ? cout<<"Pass":cout<<"Fail");

        cout << endl;

        ListChar.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-3" << endl;
        List<int> ListNum;

        for (int i=0; i < 100; i++)
            ListNum.PushBack(i);

        bool expectedValue = true;
        bool actualValue = ListNum.IsFull();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;
        cout <<"Number of elements is " << ListNum.Size()<< endl;

        ( (expectedValue == actualValue && ListNum.Size() == 100) ? cout<<"Pass":cout<<"Fail");

        cout << endl;

        ListNum.Display();

    }// Test end

    { // Test begin
        cout << endl << "Test-4" << endl;
        List<int> ListNum;

        for (int i=0; i < 105; i++)
            ListNum.PushBack(i*2);

        bool expectedValue = true;
        bool actualValue = ListNum.IsFull();

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        cout <<"Number of elements is " << ListNum.Size()<< endl;

        ( (expectedValue == actualValue && ListNum.Size() == 100) ? cout<<"Pass":cout<<"Fail");

        cout << endl;
        ListNum.Display();

    }// Test end
    // Put tests here
}

void Tester::Test_PushFront()
{
    DrawLine();
    cout << "TEST: Test_PushFront" << endl;

    { //Test begin
        cout << endl <<"Test-1" << endl;
        List<char> ListAnum;

        bool expectedValue = true;
        bool actualValue = ListAnum.PushFront('A');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass" : cout << "Fail" );
        cout << endl;

        ListAnum.Display();
    } // Test end


    { //Test begin
        cout << endl <<"Test-2" << endl;
        List<char> ListAnum;

        ListAnum.PushFront('A');
        ListAnum.PushFront('B');
        ListAnum.PushFront('C');
        bool expectedValue = true;
        bool actualValue = ListAnum.PushFront('Z');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass" : cout << "Fail" );
        cout << endl;

        ListAnum.Display();

    } // Test end


    { // Test begin
        cout << endl << "Test-3 " << endl;
        List<int> ListNum;

        //bool actualValue;
        for (int i = 0 ; i < 100; i++ )
            ListNum.PushFront(i);

        bool expectedValue = false;
        bool actualValue = ListNum.PushFront(100);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue  << endl;

        (expectedValue == actualValue ? cout <<"Pass\n":cout <<"Fail\n");
        cout << endl;

        ListNum.Display();
    } // Test  end

    // Put tests here
}

void Tester::Test_PushBack()
{
    DrawLine();
    cout << "TEST: Test_PushBack" << endl;

    { //Test begin
        cout << endl <<"Test-1" << endl;

        List<char> ListChar;

        bool expectedValue = true;
        bool actualValue = ListChar.PushBack('A');

        cout <<"Expected Value: " << expectedValue << endl;
        cout <<"Actual   Value: " << actualValue << endl;
        (expectedValue == actualValue ? cout <<"Pass": cout<<"Fail") ;
        cout << endl;

        ListChar.Display();
    } // Test end

    { //Test begin
        cout << endl <<"Test-2" << endl;

        List<int> ListInt;

        for (int i=0; i < 90; i++)
            ListInt.PushBack(i);

        bool expectedValue = true;
        bool actualValue = ListInt.PushBack(99);

        cout <<"Expected Value: " << expectedValue << endl;
        cout <<"Actual   Value: " << actualValue << endl;
        (expectedValue == actualValue ? cout <<"Pass": cout<<"Fail") ;
        cout << endl;

        ListInt.Display();
    } // Test end

    { //Test begin
        cout << endl <<"Test-3" << endl;

        List<int> ListInt;

        for (int i=0; i < 100; i++)
            ListInt.PushBack(i);

        bool expectedValue = false;
        bool actualValue = ListInt.PushBack(101);

        cout <<"Expected Value: " << expectedValue << endl;
        cout <<"Actual   Value: " << actualValue << endl;
        (expectedValue == actualValue ? cout <<"Pass": cout<<"Fail") ;
        cout << endl;

        ListInt.Display();
    } // Test end


    { //Test begin
        cout << endl <<"Test-4" << endl;

        List<char> ListChar;
        ListChar.PushBack('A');
        ListChar.PushBack('B');
        ListChar.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListChar.PushBack('D');

        cout <<"Expected Value: " << expectedValue << endl;
        cout <<"Actual   Value: " << actualValue << endl;
       (expectedValue == actualValue ? cout <<"Pass": cout<<"Fail") ;
        cout << endl;

        ListChar.Display();

    } // Test end

    // Put tests here
}

void Tester::Test_PopFront()
{
    DrawLine();
    cout << "TEST: Test_PopFront" << endl;

    { // Test begin
        cout << endl << "Test-1" << endl;
        List<char> ListLet;

        bool expectedValue = false;
        bool actualValue = ListLet.PopFront();

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;

        ( expectedValue == actualValue ? cout <<"Pass\n":cout << "Fail\n");
        cout << endl;

        ListLet.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-2" << endl;
        List<char> ListLet;

        ListLet.PushBack('A');
        ListLet.PushBack('B');
        ListLet.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLet.PopFront();

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;

        ( expectedValue == actualValue ? cout <<"Pass\n":cout << "Fail\n");
        cout << endl;

        ListLet.Display();

    } // Test end

    // Put tests here
}

void Tester::Test_PopBack()
{
    DrawLine();
    cout << "TEST: Test_PopBack" << endl;

    { // test begin
        cout << endl << "Test-1" << endl;
        List<int> ListInt;

        bool expectedValue = false;
        bool actualValue = ListInt.PopBack();

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout <<"Fail\n");
        cout << endl;

        ListInt.Display();

    } // test end

    { // test begin
        cout << endl << "Test-2" << endl;
        List<int> ListInt;
        ListInt.PushBack(1);
        ListInt.PushBack(2);
        ListInt.PushBack(3);

        bool expectedValue = true;
        bool actualValue = ListInt.PopBack();

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout <<"Fail\n");
        cout << endl;

        ListInt.Display();

    } // test end

    // Put tests here
}

void Tester::Test_Clear()
{
    DrawLine();
    cout << "TEST: Test_Clear" << endl;

    {// Test begin
        cout << endl << "Test-1" << endl;

        List<char> ListLettters;
        ListLettters.PushBack('A');
        ListLettters.PushBack('B');
        ListLettters.PushBack('C');

        int expectedValue = 0;
        ListLettters.Clear();
        int actualValue = ListLettters.Size();

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout << "Fail\n");
        cout << endl;


    } // Test end
    // Put tests here
}

void Tester::Test_Get()
{
    DrawLine();
    cout << "TEST: Test_Get" << endl;

    { //Test begin
        cout << endl << "Test-1" << endl;

        List<char> ListC;

        for (char i = 'A' ; i < 'F' ; i++)
            ListC.PushBack(i);

        char expectedValue = 'C';
        char actualValue = *(ListC.Get(2));

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail") << endl ;

        cout <<"The content : " << endl;
        for (int i =0; i < ListC.Size(); i++)
            cout <<*ListC.Get(i);
        cout << endl;



    } //test end


    { //Test begin

        cout << endl << "Test-2" << endl;

        List<int> ListC;

        for (int i = 1 ; i < 5 ; i++)
            ListC.PushBack(i);

        int *expectedValue = nullptr;
        int *actualValue = ListC.Get(10);

        cout <<"Expected Value : " << expectedValue << endl;
        cout <<"Actual   Value : " << actualValue << endl;

       (expectedValue == actualValue? cout << "Pass": cout << "Fail");

        cout << endl;
    } //test end

    // Put tests here
}

void Tester::Test_GetFront()
{
    DrawLine();
    cout << "TEST: Test_GetFront" << endl;

    {    // Test Begin
        cout << endl << "Test-1" << endl;

        List<int> ListNumbers;



        int *expectedValue = nullptr;
        int *actualValue = ListNumbers.GetFront();

        cout <<"Expected Value : " << expectedValue << endl;
        cout <<"Actual   Value : " << actualValue << endl;

       (expectedValue == actualValue? cout << "Pass": cout << "Fail");

        cout << endl;

        ListNumbers.Display();


    }  // Test end

    {  // Test begin
        cout << endl << "Test-2" << endl;
        List<int> ListNumbers;

        ListNumbers.PushBack(5);

        int expectedValue = 5;
        int actualValue = *( ListNumbers.GetFront() );

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual Value  : " << actualValue << endl;
        cout << "Address of Actual Value  : " << ListNumbers.GetFront() << endl;


        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");

        cout << endl;
        ListNumbers.Display();

    } // Test end
    // Put tests here
}

void Tester::Test_GetBack()
{
    DrawLine();
    cout << "TEST: Test_GetBack" << endl;

    { // Test begin
        cout << endl << "Test-1" << endl;
        List<int> ListNumbers;

        int *expectedValue = nullptr;
        int *actualValue = ListNumbers.GetBack();

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout <<"Fail");
        cout << endl;

        ListNumbers.Display();

    } // Test end

    { //Test begin
        cout << endl << "Test-2" << endl;
        List<int> ListNumbers;

        ListNumbers.PushBack(1);
        ListNumbers.PushBack(2);

        int expectedValue = 2;
        int actualValue = *( ListNumbers.GetBack() );

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value   : " << actualValue << endl;
        cout << "Address of Actual Value   : " << ListNumbers.GetBack() << endl;

        (expectedValue == actualValue ? cout << "Pass" :  cout << "Fail");
        cout << endl;

        ListNumbers.Display();

    } // Test end
    // Put tests here
}

void Tester::Test_GetCountOf()
{
    DrawLine();
    cout << "TEST: Test_GetCountOf" << endl;

    {//Test begin
        cout << endl << "Test-1" << endl;
        List<char> ListK;

        int expectedValue = 0;
        int actualValue = ListK.GetCountOf('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");

        cout << endl;
    }// test end


    { // Test begin
        cout << endl << "Test-2" << endl;
        List<char> ListK;

        ListK.PushBack('A');
        ListK.PushBack('B');
        ListK.PushBack('C');

        int expectedValue = 1;
        int actualValue = ListK.GetCountOf('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");

        cout << endl;

    }// test end


    { //Test begin
        cout << endl << "Test-3" << endl;
        List<char> ListK;

        ListK.PushBack('A');
        ListK.PushBack('B');
        ListK.PushBack('C');


        int expectedValue = 0;
        int actualValue = ListK.GetCountOf('D');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
        cout << endl;
    } //test end

    { //Test begin
        cout << endl << "Test-4" << endl;
        List<char> ListK;

        ListK.PushBack('A');
        ListK.PushBack('B');
        ListK.PushBack('C');
        ListK.PushBack('A');

        int expectedValue = 2;
        int actualValue = ListK.GetCountOf('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    } //test end

    { //Test begin
        cout << endl << "Test-5" << endl;
        List<char> ListK;

        for (int i = 0; i < 105;  i++)
            ListK.PushBack('A');

        int expectedValue = 100;
        int actualValue = ListK.GetCountOf('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    } //test end

    { //Test begin
        cout << endl << "Test-6" << endl;
        List<char> ListK;

        for (int i = 0; i < 75;  i++)
            ListK.PushBack('T');

        for (int i = 0; i < 25 ; i++)
            ListK.PushBack('Z');

        int expectedValue = 75;
        int actualValue = ListK.GetCountOf('T');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    } //test end
    // Put tests here
}

void Tester::Test_Contains()
{
    DrawLine();
    cout << "TEST: Test_Contains" << endl;

    { //Test begin
        cout << endl << "Test-1" << endl;
        List<char> ListC;

        bool expectedValue = false;
        bool actualValue = ListC.Contains('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    } // test end

    { //Test begin
        cout << endl << "Test-2" << endl;
        List<char> ListK;

        for (int i = 0; i < 75;  i++)
            ListK.PushBack('T');

        for (int i = 0; i < 25 ; i++)
            ListK.PushBack('Z');

        bool expectedValue = true;
        bool actualValue = ListK.Contains('T');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;
        cout << "Number of elements searched for : " << ListK.GetCountOf('T');
        cout << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    } //test end



    {// Test begin
        cout << endl << "Test-3" << endl;

        List<char> ListC;

        for (char i='A'; i < 'E' ; i++)
            ListC.PushBack(i);

        bool expectedValue = true;
        bool actualValue = ListC.Contains('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    }// test end

    { //Test begin
        cout << endl << "Test-4" << endl;
        List<char> ListK;

        for (int i = 0; i < 105;  i++)
            ListK.PushBack('A');

        bool expectedValue = true;
        bool actualValue = ListK.Contains('A');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;
        cout << "Number of elements searched for : " << ListK.GetCountOf('A');
        cout << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
         cout << endl;
    } //test end

    { //Test begin
        cout << endl << "Test-5" << endl;

        List<char> ListC;

        for (char i='A'; i <= 'C'; i++)
            ListC.PushBack(i);

        ListC.PushBack('A');
        ListC.PushBack('E');

        bool expectedValue = false;
        bool actualValue = ListC.Contains('Z');

        cout << "Expected Value: " << expectedValue << endl;
        cout << "Actual   Value: " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass": cout << "Fail");
        cout << endl;

    } //test end
    // Put tests here
}

//void Tester::Test_Remove()
void Tester::Test_RemoveWithValue() // RemoveWithValue( const T& value )
{
    DrawLine();
    cout << "TEST: Test_RemoveWithValue" << endl;

    { // Test begin
        cout << endl << "Test-1" << endl;

        List<char> ListLetters;

        bool expectedValue = false;
        bool actualValue = ListLetters.RemoveWithValue('A');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        cout << endl;

        ListLetters.Display();


    } // Test end


    { // Test begin
        cout << endl << "Test-2" << endl;

        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.RemoveWithValue('A');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        cout << endl;

        ListLetters.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-3 " << endl;

        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');
        ListLetters.PushBack('A');

        bool expectedValue = true;
        bool actualValue = ListLetters.RemoveWithValue('A');


        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        ListLetters.Display();


    } // Test end


    { // Test begin
        cout << endl << "Test-4" << endl;

        List<int> ListInt;

        ListInt.PushBack(1);
        ListInt.PushBack(2);
        ListInt.PushBack(3);
        ListInt.PushBack(4);

        cout <<"The content : " << endl;
        for (int i = 0; i < ListInt.Size(); i++ )
            cout <<*(ListInt.Get(i));
        cout << endl;

        bool expectedValue = true;
        bool actualValue = ListInt.RemoveWithValue(4);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");


        ListInt.Display();
    } // Test end
}


void Tester::Test_RemoveAtIndex() // RemoveAtIndex( int index )
{
    DrawLine();
    cout << "TEST: Test_RemoveAtIndex" << endl;

    { // Test begin
        cout << endl << "Test-1" << endl;

        List<char> ListLetters;

        bool expectedValue = false;
        bool actualValue = ListLetters.RemoveAtIndex(1);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        cout << endl;
        ListLetters.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-2 " << endl;

        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');


        bool expectedValue = true;
        bool actualValue = ListLetters.RemoveAtIndex(0);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");


        ListLetters.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-3 " << endl;

        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.RemoveAtIndex(2);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        cout << endl;


        ListLetters.Display();

    } // Test end


    { // Test begin
        cout << endl << "Test-4 " << endl;

        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = true;
        bool actualValue = ListLetters.RemoveAtIndex(1);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        cout << endl;


        ListLetters.Display();

    } // Test end

    { // Test begin
        cout << endl << "Test-5 " << endl;

        List<char> ListLetters;

        ListLetters.PushBack('A');
        ListLetters.PushBack('B');
        ListLetters.PushBack('C');

        bool expectedValue = false;
        bool actualValue = ListLetters.RemoveAtIndex(5);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout << "Pass\n": cout <<"Fail\n");

        cout << endl;


        ListLetters.Display();

    } // Test end
    // Put tests here
}

void Tester::Test_Insert()
{
    DrawLine();
    cout << "TEST: Test_Insert" << endl;

    {// Test begin
        cout << endl << "Test-1" << endl;

        List<char> ListInt;


        bool expectedValue = true;
        bool actualValue = ListInt.Insert(0,'A');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout <<"Fail\n");
        cout << endl;

        ListInt.Display();
    }// Test end

    {// Test begin
        cout << endl << "Test-2" << endl;

        List<char> ListZ;
        for (char i = 'A'; i < 'F'; i++)
            ListZ.PushBack(i);


        bool expectedValue = true;
        bool actualValue = ListZ.Insert(3,'Z');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout <<"Fail\n");
        cout << endl;
        ListZ.Display();

    }// Test end

        {// Test begin
        cout << endl << "Test-3" << endl;

        List<int> ListInt;

        for (int i = 0; i < 100 ; i++)
            ListInt.PushBack(i);//Insert(i);

        bool expectedValue = false;
        bool actualValue = ListInt.Insert(101,999);

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout <<"Fail\n");
        cout << endl;

        ListInt.Display();
    }// Test end

    {// Test begin
        cout << endl << "Test-4" << endl;

        List<char> ListZ;
        for (char i = 'A'; i <= 'C'; i++)
            ListZ.PushBack(i);


        bool expectedValue = false;
        bool actualValue = ListZ.Insert(5,'Z');

        cout << "Expected Value : " << expectedValue << endl;
        cout << "Actual Value : " << actualValue << endl;

        (expectedValue == actualValue ? cout <<"Pass\n": cout <<"Fail\n");
        cout << endl;

        ListZ.Display();

    }// Test end
    // Put tests here
}
