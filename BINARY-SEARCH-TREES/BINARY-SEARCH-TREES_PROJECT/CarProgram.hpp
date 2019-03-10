#ifndef _CAR_PROGRAM_HPP
#define _CAR_PROGRAM_HPP

#include "cuTEST/Menu.hpp"

#include "CarData.hpp"
#include "BinarySearchTree.hpp"
#include "LinkedList.hpp"

class CarProgram
{
    public:
    void Start();
    void MainLoop();
    void PrintStats( const string& outFile, const string& orderFile );

    private:
    void LoadData( const string& carFile );
    void SaveData( const string& carFile );

    BinarySearchTree<float, CarData> m_data_tree;
    LinkedList<float, CarData> m_data_linear;
};

#endif
