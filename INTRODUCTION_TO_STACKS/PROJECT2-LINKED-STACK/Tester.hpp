// Done - you can add additional tests if you want

#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
using namespace std;

#include "CUTEST/TesterBase.hpp"
#include "CUTEST/StringUtil.hpp"

#include "DATA_STRUCTURES/Stack.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem( "Test_Stack()",
                 bind(&Tester::Test_Stack, this)));
	}

	virtual ~Tester() { }

private:
	int Test_Stack();
};

int Tester::Test_Stack()
{
    StartTestSet( "Test_Stack", { "Size()", "Push()", "Top()", "Pop()" } );

    {   /********************************************** TEST BEGIN */
        /** Test constructor / Size() **/
        StartTest( "Create an empty Stack, make sure Size() is 0." );

        LinkedStack<int> testStack;

        int expectedSize = 0;
        int actualSize = testStack.Size();

        Set_ExpectedOutput  ( "Size", expectedSize );
        Set_ActualOutput    ( "Size", actualSize );

        if ( actualSize == expectedSize )   { TestPass(); }
        else
        {
            TestFail( "Bad Size value. Make sure you're setting the size in the constructor, and have written the Size() function." );
        }

        FinishTest();
    }   /********************************************** TEST END */

    {   /********************************************** TEST BEGIN */
        /** Test Push() / Size() / Top() **/
        StartTest( "Create a Stack. Push 5. Size() should be 1. Top() should be 5." );

        LinkedStack<int> testStack;
        testStack.Push( 5 );

        int expectedSize = 1;
        int actualSize = testStack.Size();

        int expectedTop = 5;
        int actualTop;

        try { actualTop = testStack.Top(); }
        catch( ... ) { actualTop = -100; Set_Comments( "Caught exception while getting Top()!" ); }

        Set_ExpectedOutput  ( "Size", expectedSize );
        Set_ActualOutput    ( "Size", actualSize );

        Set_ExpectedOutput  ( "Top", expectedTop );
        Set_ActualOutput    ( "Top", actualTop );

        if ( actualSize != expectedSize )
        {
            TestFail( "Bad Size value. Make sure you're setting the size in the constructor, and have written the Size() function, and are incrementing the size during Push()." );
        }
        else if ( actualTop != expectedTop )
        {
            TestFail( "Bad Top value. Make sure you've written the Top() function." );
        }
        else
        {
            TestPass();
        }

        FinishTest();
    }   /********************************************** TEST END */

    {   /********************************************** TEST BEGIN */
        /** Test Push() / Size() / Top() / Pop() **/
        StartTest( "Create a Stack. Push 'A' & 'B'. Size() should be 2. Check order." );

        LinkedStack<char> testStack;
        testStack.Push( 'A' );
        testStack.Push( 'B' );

        int expectedSize = 2;
        int actualSize = testStack.Size();

        char expectedTop = 'B';
        char expectedSecond = 'A';

        char actualTop;
        char actualSecond;

        try
        {
            actualTop = testStack.Top();
            testStack.Pop();
            actualSecond = testStack.Top();
        }
        catch( ... )
        {
            actualTop = ' ';
            actualSecond = ' ';
            Set_Comments( "Caught exception while getting Top()!" );
        }

        Set_ExpectedOutput  ( "Size", expectedSize );
        Set_ActualOutput    ( "Size", actualSize );

        Set_ExpectedOutput  ( "Top", expectedTop );
        Set_ActualOutput    ( "Top", actualTop );

        Set_ExpectedOutput  ( "2nd", expectedSecond );
        Set_ActualOutput    ( "2nd", actualSecond );

        if ( actualSize != expectedSize )
        {
            TestFail( "Bad Size value. Make sure you're setting the size in the constructor, and have written the Size() function." );
        }
        else if ( actualTop != expectedTop )
        {
            TestFail( "Bad Top value. Make sure you've written the Top() function." );
        }
        else if ( actualSecond != expectedSecond )
        {
            TestFail( "Bad Top after Pop. Make sure you've written the Pop() and Top() functions." );
        }
        else
        {
            TestPass();
        }

        FinishTest();
    }   /********************************************** TEST END */


    {   /********************************************** TEST BEGIN */
        /** Test Push() / Size() / Top() / Pop() **/
        StartTest( "Create a Stack. Push 3 items and Pop. Check Size(). Check Top()." );

        LinkedStack<char> testStack;
        testStack.Push( 'A' );
        testStack.Push( 'B' );
        testStack.Push( 'C' );

        int expectedSizeBeforePop = 3;
        int actualSizeBeforePop = testStack.Size();

        testStack.Pop();

        int expectedSizeAfterPop = 2;
        int actualSizeAfterPop = testStack.Size();

        testStack.Pop();

        int expectedSizeAfterPopPop = 1;
        int actualSizeAfterPopPop = testStack.Size();

        Set_ExpectedOutput  ( "Size before Pop", expectedSizeBeforePop );
        Set_ActualOutput    ( "Size before Pop", actualSizeBeforePop );

        Set_ExpectedOutput  ( "Size after Pop", expectedSizeAfterPop );
        Set_ActualOutput    ( "Size after Pop", actualSizeAfterPop );

        Set_ExpectedOutput  ( "Size after Pop Pop", expectedSizeAfterPopPop );
        Set_ActualOutput    ( "Size after Pop Pop", actualSizeAfterPopPop );

        if ( actualSizeBeforePop != expectedSizeBeforePop )
        {
            TestFail( "Bad Size value before Pop. Make sure your Push increments the size." );
        }
        else if ( actualSizeAfterPop != expectedSizeAfterPop )
        {
            TestFail( "Bad Top value after Pop. Make sure your Pop decrements the size." );
        }
        else
        {
            TestPass();
        }

        FinishTest();
    }   /********************************************** TEST END */

    FinishTestSet();
    return TestResult();
}

#endif
