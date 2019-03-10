#include "CarProgram.hpp"

#include <fstream>
#include <iomanip>
using namespace std;

#include "cuTEST/StringUtil.hpp"
#include "Timer.hpp"

void CarProgram::Start()
{
    string dataFile;

    cout << "Enter filename of data (including .txt): ";
    cin >> dataFile;
    cout << endl;

    LoadData( dataFile );
    PrintStats( "car-stats.txt", "traversal.txt" );
    MainLoop();


    cout << "Enter the output filename (including .txt): ";
    cin >> dataFile;
    cout << endl;

    SaveData( dataFile );
}

void CarProgram::MainLoop()
{
    bool done = false;
    while ( !done )
    {
        cout << endl;
        Menu::Header( "Car options" );

        cout << m_data_tree.GetCount() << " total cars" << endl << endl;

        int choice = Menu::ShowIntMenuWithPrompt( {
            "Find car by price",
            "Delete car by price",
            "Add new car",
            "Save and Exit" } );

        if ( choice == 1 )
        {
            float price;
            cout << endl << "Enter a price to search for: ";
            cin >> price;

            Timer timer;

            cout << endl << "\t Searching the tree..." << endl;
            timer.Start();
            CarData* car = m_data_tree.GetData( price );
            cout << "\t Done in " << timer.GetElapsedMilliseconds() << " milliseconds." << endl << endl;

            if ( car == nullptr )
            {
                cout << "Car not found in tree" << endl;
            }
            else
            {
                cout << endl
                    << "Car found in tree: "
                    << car->make << ", "
                    << car->model << endl;
            }

            cout << endl << "\t Searching the linked list..." << endl;
            timer.Start();
            CarData* car2 = m_data_linear.GetItemWithKey( price );
            cout << "\t Done in " << timer.GetElapsedMilliseconds() << " milliseconds." << endl << endl;

            if ( car2 == nullptr )
            {
                cout << "Car not found in list" << endl;
            }
            else
            {
                cout << endl
                    << "Car found in list: "
                    << car2->make << ", "
                    << car2->model << endl;
            }

            cout << endl;
        }
        else if ( choice == 2 )
        {
            float price;
            cout << endl << "Enter a price to delete for: ";
            cin >> price;

            m_data_tree.Delete( price );
            m_data_linear.Remove( price );
        }
        else if ( choice == 3 )
        {
            //cin.ignore();
            CarData newCar;

            cout << "Car make:          ";
            getline( cin, newCar.make );

            cout << "Car model:         ";
            getline( cin, newCar.model );

            string temp;
            cout << "Car price (no $):  ";
            cin >> temp;
            newCar.price = StringUtil::StringToFloat( temp );

            m_data_tree.Push( newCar.price, newCar );
            m_data_linear.PushBack( newCar.price, newCar );
        }
        else if ( choice == 4 )
        {
            done = true;
        }
    }
}

void CarProgram::LoadData( const string& carFile )
{
    cout << "Loading in data from \"" << carFile << "\"..." << endl;

    ifstream input( carFile );

    if ( !input.is_open() )
    {
        cout << "Error finding \"" << carFile << "\"!" << endl
            << "Make sure it is in your PROJECT directory." << endl << endl;
    }

    CarData newData;

    string buffer;

    Timer timer;
    timer.Start();
    while ( getline( input, buffer ) )
    {
        getline( input, newData.make );
        getline( input, newData.model );
        getline( input, buffer );
        newData.price = StringUtil::StringToFloat( buffer );
        getline( input, buffer ); // CAR_END
        getline( input, buffer ); // empty space

        m_data_tree.Push( newData.price, newData );
        m_data_linear.PushBack( newData.price, newData );
    }
    cout << "\t Done in " << timer.GetElapsedMilliseconds() << " milliseconds." << endl << endl;

    input.close();
}


void CarProgram::SaveData( const string& carFile )
{
    cout << endl << "Saving to \"" << carFile << "\"..." << endl;
    ofstream output( carFile );

    Timer timer;
    timer.Start();
    for ( int i = 0; i < m_data_linear.Size(); i++ )
    {
        if ( i % 1000 == 0 ) { cout << i << "..." << endl; }

        CarData car = m_data_linear.GetItemAtPosition( i );

        output << "CAR_BEGIN" << endl
            << car.make << endl
            << car.model << endl
            << car.price << endl
            << "CAR_END" << endl << endl;
    }
    cout << "\t Done in " << timer.GetElapsedMilliseconds() << " milliseconds." << endl << endl;

    output.close();
}

void CarProgram::PrintStats( const string& outFile, const string& orderFile )
{
    cout << "Writing out data to \"" << outFile << "\"..." << endl;
    ofstream output( outFile );

    Timer timer;
    timer.Start();

    output << "CAR STATS" << endl << endl;

    // Total cars?
    output << left
        << setw( 25 ) << "Total cars: "
        << setw( 10 ) << m_data_tree.GetCount() << endl;

    output << left
        << setw( 25 ) << "Tree height: "
        << setw( 10 ) << m_data_tree.GetHeight() << endl;

    // What is the cheapest?
    float* smallKey = m_data_tree.GetMinKey();
    CarData* smallCar = m_data_tree.GetData( *smallKey );
    if ( smallCar != nullptr )
    {
        output << left
            << setw( 25 ) << "Cheapest car:"
            << setw( 15 ) << smallCar->price
            << setw( 20 ) << smallCar->make
            << setw( 20 ) << smallCar->model
            << endl;
    }

    // What is the most expensive?
    float* bigKey = m_data_tree.GetMaxKey();
    CarData* bigCar = m_data_tree.GetData( *bigKey );
    if ( bigCar != nullptr )
    {
        output << left
            << setw( 25 ) << "Most expensive car:"
            << setw( 15 ) << bigCar->price
            << setw( 20 ) << bigCar->make
            << setw( 20 ) << bigCar->model
            << endl;
    }
    output.close();

    string filename = "preorder-" + orderFile;
    output.open( filename );

    output << endl << "PREORDER:" << endl
        << m_data_tree.GetPreOrder() << endl << endl;

    output.close();
    filename = "inorder-" + orderFile;
    output.open( filename );

    output << endl << "INORDER:" << endl
        << m_data_tree.GetInOrder() << endl << endl;

    output.close();
    filename = "postorder-" + orderFile;
    output.open( filename );

    output << endl << "POSTORDER:" << endl
        << m_data_tree.GetPostOrder() << endl << endl;

    cout << "\t Done in " << timer.GetElapsedMilliseconds() << " milliseconds." << endl << endl;

    output.close();
}
















