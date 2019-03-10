#ifndef _HOMEWORK_GENERATOR
#define _HOMEWORK_GENERATOR

#include <string>
#include <iostream>
using namespace std;

#include "Job.hpp"

#include <cstdlib>
#include <ctime>
using namespace std;

class HomeworkGenerator
{
    public:
    HomeworkGenerator();
    vector<Job> GetHomework( int amount );

    private:
    string GetRandomVerb();
    string GetRandomNoun();

    vector<string> verbs;
    vector<string> nouns;
};

HomeworkGenerator::HomeworkGenerator()
{
    srand( time( NULL ) );

    verbs = {
        "Program",
        "Write a paper about",
        "Discuss",
        "Do a quiz about",
        "Review",
        "Research"
        };
    nouns = {
        "Dynamic Arrays",
        "Linked Lists",
        "Stacks",
        "Queues",
        "Binary Search Trees",
        "Heaps",
        "Balanced Search Trees",
        "Graphs",
        "Compression Algorithms",
        "Breadth-first Search",
        "Depth-first Search",
        "Combinatorics",
        "Propositional Logic",
        "Set Theory",
        "Boolean Algebra",
        "Circuit Diagrams",
        "Mathematical Induction"
    };
}

vector<Job> HomeworkGenerator::GetHomework( int amount )
{
    vector<Job> homework;

    for ( int i = 0; i < amount; i++ )
    {
        Job task;
        task.id = i;
        task.assignment = GetRandomVerb() + " " + GetRandomNoun();
        task.dueOnDay = rand() % 30 + 10;
        task.timeRemaining = rand() % (task.dueOnDay/2) + 1;
        task.done = false;
        homework.push_back( task );
    }

    return homework;
}




string HomeworkGenerator::GetRandomVerb()
{
    return verbs[ rand() % verbs.size() ];
}

string HomeworkGenerator::GetRandomNoun()
{
    return nouns[ rand() % nouns.size() ];
}


#endif

