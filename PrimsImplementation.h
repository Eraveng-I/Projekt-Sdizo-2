#ifndef PRIMSIMPLEMENTATION_H
#define PRIMSIMPLEMENTATION_H

#include <list>
#include <vector>
#include "ListElement.h"

using namespace std;

class PrimsImplementation
{
    public:

        PrimsImplementation(int);
        virtual ~PrimsImplementation();

        void createGraphMatrix();
        void createGraphList();

        void printMatrix();
        void printList();
        void getFileInfo();
        void primsAlgorithmMatrix(int);
        void primsAlgorithmList(int);
        void printDistances();
        void printDistancesList();
        void printPrevious();
        void printPreviousList();
        void printVisited();
        void printVisitedList();
        void initTables();
        void addToListVector(int, int, int);
        void printSum();
        void printSumList();
        void startPrimsMatrix();
        void startPrimsList();
        long long int read_QPC();

    protected:

    private:
        int numberOfVertices;
        int numberOfEdges;
        int** graphMatrix;
        int whichFile;
        int* distance;
        int* distanceList;
        bool* visited;
        bool* visitedList;
        int* previousVertex;
        int* previousVertexList;
        int primsMatrixIterations;
        int primsListIterations;

        list<ListElement>* primsGraphList;

        long long int frequency;
        long long int start;
        long long int elapsed;
};

#endif // PRIMSIMPLEMENTATION_H
