#include "TesterBase.hpp"
#include "StringUtil.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "Menu.hpp"

TesterBase::TesterBase()
{
	m_totalTestCount = 0;
	m_totalTestPass = 0;

	cout << "* TEST LOG WILL BE WRITTEN OUT TO:" << endl;
	Menu::PrintPwd();

	m_output.open( "test_result.html" );

    OutputHeader();

    m_closed = false;
}

TesterBase::~TesterBase()
{
    Close();
}

void TesterBase::Close()
{
    if ( m_closed ) { return; }

    OutputFooter();
    m_output.close();

    m_closed = true;
}

void TesterBase::OutputHeader()
{
    m_output << "<!DOCTYPE html>" << endl;
    m_output << "<html>" << endl;
    m_output << "    <head>" << endl;
    m_output << "        <title> cuTEST Test Results </title>" << endl;

    m_output << "        <style type='text/css'>" << endl;
    m_output << "            body { font-family: sans-serif; font-size: 12pt; }" << endl;
    m_output << "            .warning { padding: 20px; background: #ffed24; font-size: 20px; text-align: center; }" << endl;
    m_output << "            .result-success { background: #24ff24; font-size: 20px; text-align: center; }" << endl;
    m_output << "            .result-failure { background: #ff7095; font-size: 20px; text-align: center; }" << endl;

    m_output << "            table { background: #ccccff; width: 100%; border: solid 1px #0000aa; }" << endl;
    m_output << "            table tr.pass { background: #ccffcc; }" << endl;
    m_output << "            table tr.fail { background: #ffcccc; }" << endl;

    m_output << "            table tr             { font-size: 12pt; border: solid 1px #000066; }" << endl;
    m_output << "            table tr td          { padding: 10px; border: solid 1px #000033; }" << endl;
    m_output << "            table tr td ul li, "
             << "            table tr td ol li    { margin: 10px 0; }" << endl;
    m_output << "            table tr td ol       { list-style-type: upper-latin; }" << endl;
    m_output << "            table tr .test-set   {  }" << endl;
    m_output << "            table tr .test       { font-size: 14pt; }" << endl;
    m_output << "            table tr .prereq     {  }" << endl;
    m_output << "            table tr .result     { text-align: center; font-size: 14pt; font-weight: bold; }" << endl;
    m_output << "            table tr .expected   { font-family: monospace; font-size: 14pt; }" << endl;
    m_output << "            table tr .actual     { font-family: monospace; font-size: 14pt; }" << endl;
    m_output << "            table tr .comments   {  }" << endl;

    m_output << "            table tr.summary { background: #000000; color: #ffffff; }" << endl;

    m_output << "            table tr.descriptions { font-size: 8pt; text-align: center; }" << endl;

//    m_output << "            table .col_set      { width: 5%; }" << endl;
//    m_output << "            table .col_test     { width: 15%; }" << endl;
//    m_output << "            table .col_prereq   { width: 10%; }" << endl;
//    m_output << "            table .col_result   { width: 5%; }" << endl;
//    m_output << "            table .col_expected { width: 15%; }" << endl;
//    m_output << "            table .col_actual   { width: 15%; }" << endl;
//    m_output << "            table .col_comments { width: 35%; }" << endl;
    m_output << "            table .spacer { height: 100px; }" << endl;
    m_output << "        </style>" << endl;
    m_output << "    </head>" << endl;

    m_output << "    <body>" << endl;
    m_output << "    <div class='warning'>Warning: Make sure to check if all tests finish (there will be a message at the end of the file) - <br>" << endl;
    m_output << "    It is possible for your program to crash early, but still show that tests have passed because it hasn't gone through everything.</div>" << endl;

    m_output << "    <table>" << endl;
    m_output << "        <tr>" << endl;
    m_output << "            <th class='col_set'> Test set </th>" << endl;
    m_output << "            <th class='col_test'> Test </th>" << endl;
    m_output << "            <th class='col_prereq'> Prerequisite <br> functions </th>" << endl;
    m_output << "            <th class='col_result'> Pass/fail </th>" << endl;
    m_output << "            <th class='col_expected'> Expected <br> output </th>" << endl;
    m_output << "            <th class='col_actual'> Actual <br> output </th>" << endl;
    m_output << "            <th class='col_comments'> Comments </th>" << endl;
    m_output << "        </tr>" << endl;

//    m_output << "        <tr class='descriptions'>" << endl;
//    m_output << "            <td>  </td>" << endl;
//    m_output << "            <td>  </td>" << endl;
//    m_output << "            <td> Functions that need to be implemented for these tests to work right </td>" << endl;
//    m_output << "            <td>  </td>" << endl;
//    m_output << "            <td> The output expected from the function's return </td>" << endl;
//    m_output << "            <td> What was actually returned from the function </td>" << endl;
//    m_output << "            <td> Additional notes from the test </td>" << endl;
//    m_output << "        </tr>" << endl;
}

void TesterBase::OutputFooter()
{
    m_output << "    </table>" << endl;

    if ( m_subtest_totalPasses == m_subtest_totalTests )
    {
        m_output << "    <div class='result-success'>" << m_totalTestCount << " testsets ran; " << m_totalTestPass << " testsets passed</div>" << endl;
    }
    else
    {
        m_output << "    <div class='result-failure '>" << m_totalTestCount << " testsets ran; " << m_totalTestPass << " testsets passed</div>" << endl;
    }

    m_output << "    </body>" << endl;
    m_output << "</html>" << endl;
}

void TesterBase::WriteoutSummary()
{
    m_output << "<tr class='summary'>" << endl;
    m_output << "<td colspan='7' class='summary'>" << endl;
    m_output << "<strong>SUMMARY FOR " << col_testSet << ":</strong>" << endl;
    m_output << m_subtest_totalPasses << " out of " << m_subtest_totalTests << " tests passed" << endl;
    m_output << "</td>" << endl;
    m_output << "</tr>" << endl;
    m_output << "<tr class='spacer'></tr>" << endl;
}


void TesterBase::WriteoutRow()
{
    if ( col_result == "passed" )
        m_output << "<tr class='pass'>" << endl;
    else
        m_output << "<tr class='fail'>" << endl;

    m_output << "<td class='test-set'>      " << col_testSet <<         "       </td>" << endl;
    m_output << "<td class='test'>          " << col_testName <<        "       </td>" << endl;
    m_output << "<td class='prereq'>   <ul> " << col_prerequisites <<   " </ul> </td>" << endl;
    m_output << "<td class='result'>        " << col_result <<          "       </td>" << endl;
    m_output << "<td class='expected'> <ol> " << col_expectedOutput <<  " </ol> </td>" << endl;
    m_output << "<td class='actual'>   <ol> " << col_actualOutput <<    " </ol> </td>" << endl;
    m_output << "<td class='comments'> <ul> " << col_comments <<        " </ul> </td>" << endl;
    m_output << "</tr>" << endl;
}

void TesterBase::Start()
{
//	MainMenu();
    TestAll();
}

void TesterBase::TestAll()
{
    int counter = 1;
    cout << endl;
    for ( list<TestListItem>::iterator it = m_tests.begin(); it != m_tests.end(); it++ )
    {
        if ( it->testAggregate == false )
        {
            cout << "Running testset " << counter << " out of " << m_totalTestCount << ": \t"
                << it->name << endl;
            int result = it->callFunction();
            if ( result == 1 )
            {
                m_totalTestPass++;
            }
        }
        counter++;
    }

    cout << endl << " NOTE: CHECK \"test_result.html\" FOR FULL DETAILS." << endl;
}

void TesterBase::AddTest( const TestListItem& test )
{
	m_tests.push_back( test );
	m_totalTestCount++;
}

void TesterBase::StartTestSet( const string& name, const vector<string>& prereqs )
{
    Set_TestSet( name );
    m_subtest_totalTests = 0;
    m_subtest_totalPasses = 0;
    Set_TestPrerequisites( prereqs );
}

void TesterBase::StartTest( const string& description )
{
    cout << left << setw( 1 ) << " * " << setw( 70 ) << description << setw( 10 ) << "... ";
    Set_TestName( description );
    m_subtest_totalTests++;
    col_actualOutput = "";
    col_expectedOutput = "";
    col_comments = "";
}

void TesterBase::TestFail()
{
    cout << "FAIL" << endl;
    Set_Result( false );
}

void TesterBase::TestFail( const string& message )
{
    cout << "FAIL" << endl;
    Set_Comments( message );
    Set_Result( false );
}

void TesterBase::TestPass()
{
    cout << "PASS" << endl;
    Set_Result( true );
    m_subtest_totalPasses++;
}

int TesterBase::TestResult()
{
    return ( m_subtest_totalPasses == m_subtest_totalTests );
}

void TesterBase::FinishTest()
{
    WriteoutRow();
}

void TesterBase::FinishTestSet()
{
    WriteoutSummary();
    cout << endl << endl;
}

void TesterBase::Set_TestSet( const string& value )
{
    col_testSet = value;
}

void TesterBase::Set_TestName( const string& value )
{
    col_testName = value;
}

void TesterBase::Set_TestPrerequisites( const vector<string>& prereqs )
{
    col_prerequisites = "";
    for ( unsigned int i = 0; i < prereqs.size(); i++ )
    {
        col_prerequisites += "<li>" + prereqs[i] + "</li>";
    }
}

void TesterBase::Set_Result( bool passed )
{
    col_result = ( passed ) ? "passed" : "FAILED";
}

void TesterBase::Set_ExpectedOutput( const string& variable )
{
    col_expectedOutput += "<li>" + variable + "</li>";
}

void TesterBase::Set_ExpectedOutput( const string& variable, const string& value )
{
    col_expectedOutput += "<li>" + variable + " = " + value + "</li>";
}

void TesterBase::Set_ExpectedOutput( const string& variable, int value )
{
    Set_ExpectedOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_ExpectedOutput( const string& variable, bool value )
{
    Set_ExpectedOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_ActualOutput( const string& variable )
{
    col_actualOutput += "<li>" + variable + "</li>";
}

void TesterBase::Set_ActualOutput( const string& variable, const string& value )
{
    col_actualOutput += "<li>" + variable + " = " + value + "</li>";
}

void TesterBase::Set_ActualOutput( const string& variable, int value )
{
    Set_ActualOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_ActualOutput( const string& variable, bool value )
{
    Set_ActualOutput( variable, StringUtil::ToString( value ) );
}

void TesterBase::Set_Comments( const string& value )
{
    col_comments += "<li>" + value + "</li>";
}

void TesterBase::TerminationMessage( const string& message )
{
    cout << "TEST TERMINATED: " << message << endl;
}
