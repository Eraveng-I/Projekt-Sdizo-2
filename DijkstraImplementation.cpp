#include <iostream>
#include "DijkstraImplementation.h"
#include <fstream>
#include <list>
#include <algorithm>

#include <iomanip>
#include <windows.h>

#define INF -1

using namespace std;

fstream file;

//==========================================================================================================================================
DijkstraImplementation::DijkstraImplementation(int wF)
{
    // macierz
    whichFile = wF;
    //getFileInfo();
//dijkstraAlgorithmMatrix(0);
//printMatrix();
    //initTables();
//printDistances();
    //startDijkstraMatrix();
//printDistances();
//printPrevious();
//printVisited();

//cout<<"======================================================================================================================"<<endl;
// lista
    //getFileInfo();
//printList();
    //initTables();
//printDistancesList();
    //startDijkstraList();
//printDistancesList();
//printPreviousList();
//printVisitedList();

}
//==========================================================================================================================================
DijkstraImplementation::~DijkstraImplementation()
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] graphMatrix[i];
        graphList[i].clear();
    }

    delete[] distance;
    delete[] distanceList;
    delete[] visited;
    delete[] visitedList;
    delete[] graphMatrix;
    delete[] graphList;
}
//==========================================================================================================================================
long long int DijkstraImplementation::read_QPC()
{
    LARGE_INTEGER count;

    QueryPerformanceCounter(&count);
    return ((long long int)count.QuadPart);
}
//==========================================================================================================================================
void DijkstraImplementation::createGraphMatrix()
{
    int i, j;
    for (i = 0; i < numberOfVertices; i++)
    {

        graphMatrix[i] = new int[numberOfVertices];
        for (j = 0; j < numberOfVertices; j++)
        {
            if (i == j) graphMatrix[i][j] = 0;
            else graphMatrix[i][j] = INF;
        }
    }
}

void DijkstraImplementation::printMatrix()
{
    int i, j;
    for (i = 0; i < numberOfVertices; i++)
    {
        for (j = 0; j < numberOfVertices; j++)
        {
            if (graphMatrix[i][j] < 10 && graphMatrix[i][j] >= 0) cout << "  ";
            else if (graphMatrix[i][j] > 10 || graphMatrix[i][j] == INF) cout << " ";
            cout << graphMatrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout <<"Koniec algorytmu Dijkstry dla macierzy"<< endl;
}

void DijkstraImplementation::printDistances()
{
    cout << dijkstraMatrixIterations + 1 << ". " << "Odleglosci od wierzcholka 0:" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
}
void DijkstraImplementation::printPrevious()
{
    cout << dijkstraMatrixIterations + 1 << ". " << "Poprzednie wierzcholki:" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << previousVertex[i] << " ";
    }
    cout << endl;
}
void DijkstraImplementation::printVisited()
{
    cout << dijkstraMatrixIterations + 1 << ". " << "Odwiedzone wierzcholki:" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
}
void DijkstraImplementation::initTables()
{
    distance = new int[numberOfVertices];
    distanceList = new int[numberOfVertices];
    visited = new bool[numberOfVertices];
    visitedList = new bool[numberOfVertices];
    previousVertex = new int[numberOfVertices];
    previousVertexList = new int[numberOfVertices];

    for (int i = 0; i < numberOfVertices; i++)
    {
        distance[i] = INF;
        distanceList[i] = INF;
        visited[i] = false;
        visitedList[i] = false;
    }
    dijkstraMatrixIterations = 0;
    dijkstraListIterations = 0;
    distance[0] = 0;
    distanceList[0] = 0;
    previousVertex[0] = 0;
    previousVertexList[0] = 0;
}
//==========================================================================================================================================
void DijkstraImplementation::addToListVector(int source, int nextE, int edgeV)
{
    ListElement listElement;
    listElement.nextElement = nextE;
    listElement.edgeValue = edgeV;
    graphList[source].push_back(listElement);
}

void DijkstraImplementation::printList()
{
    int i;
    for (i = 0; i < numberOfVertices; i++)
    {
        cout << i << " -> ";
        for (const auto& iterate : graphList[i])
        {
            cout << "(" << iterate.nextElement << "," << iterate.edgeValue << ")" << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void DijkstraImplementation::printDistancesList()
{
    cout << dijkstraListIterations + 1 << ". " << "Odleglosci od wierzcholka 0:" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << distanceList[i] << " ";
    }
    cout << endl;
}
void DijkstraImplementation::printPreviousList()
{
    cout << dijkstraListIterations + 1 << ". " << "Poprzednie wierzcholki:" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << previousVertexList[i] << " ";
    }
    cout << endl;
}
void DijkstraImplementation::printVisitedList()
{
    cout << dijkstraListIterations + 1 << ". " << "Odwiedzone wierzcholki:" << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << visitedList[i] << " ";
    }
    cout << endl;
}
//==========================================================================================================================================
void DijkstraImplementation::getFileInfo() // odczytywanie wartosci z pliku do nowej tablicy
{

    if (whichFile == 2) 
    {
        file.open("GraphRandom.txt", ios::in);
    }
    else
        {
            file.open("Graph1.txt", ios::in);
        }
    int val;

    //cout<<"Wybrano plik do wczytania"<<endl;
    if (file.is_open())
    {
        file >> numberOfEdges >> numberOfVertices;
        if (file.fail())
        {
            cout << "File error - READ SIZE" << endl; // jesli plik jest pusty
        }
        else
            {
                // Inicjalizacja macierzy i listy
                graphMatrix = new int* [numberOfVertices];
                graphList = new list<ListElement>[numberOfVertices];

                createGraphMatrix();

                int i, j, k;
                for (k = 0; k < numberOfEdges; k++)
                {
                    file >> i >> j >> val;

                    if (file.fail())
                    {
                        cout << "File error - READ DATA" << endl; // jesli w pliku jest tylko rozmiar>0
                        break;
                    }
                    else
                        {
                            // macierz
                            graphMatrix[i][j] = val;
                            graphMatrix[j][i] = val;
                            // lista
                            addToListVector(i, j, val);
                            addToListVector(j, i, val);
                        }
                }
            }
        file.close();
    }
    else
        {
            cout << "File error - OPEN" << endl; // jesli nie znaleziono pliku o podanej nazwie
        }
}
//==========================================================================================================================================
void DijkstraImplementation::dijkstraAlgorithmMatrix(int vertex) // algorytm Dijkstry dla macierzy
{
    visited[vertex] = true;
    int changes = 0;
    dijkstraMatrixIterations++;

    for (int i = 0; i < numberOfVertices; i++)
    {
        //cout<<i<<endl;
        if ((visited[i] == false) && (graphMatrix[vertex][i] != INF))
        {
            if (distance[i] == INF || ((distance[vertex] + graphMatrix[vertex][i]) < distance[i]))
            {
                distance[i] = distance[vertex] + graphMatrix[vertex][i];
                previousVertex[i] = vertex;
                changes++;
            }
        }
    }
    int smallestAvailableVertex = INF;
    int distSmallestAV = INF;

    for (int i = 0; i < numberOfVertices; i++)
    {
        if ((visited[i] == false) && (distance[i] > 0) && ((distSmallestAV > distance[i]) || (distSmallestAV == INF)))
        {
            distSmallestAV = distance[i];
            smallestAvailableVertex = i;
        }
    }
    if (dijkstraMatrixIterations < numberOfVertices && changes != 0)
    {
        //printDistances();
        dijkstraAlgorithmMatrix(smallestAvailableVertex);
    }
    //else cout<<"\nKoniec algorytmu Dijkstry dla macierzy\n";

}
long long int DijkstraImplementation::startDijkstraMatrix()
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    dijkstraAlgorithmMatrix(0);

    elapsed = read_QPC() - start; // koniec pomiaru czasu

    //cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    //cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    //cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;

    //return elapsed;
    return ((1000000.0 * elapsed) / frequency);
}
//------------------------------------------------------------------------------------------------------------------------------------------
void DijkstraImplementation::dijkstraAlgorithmList(int vertex) // algorytm Dijkstry dla listy
{
    visitedList[vertex] = true;
    int changes = 0;
    dijkstraListIterations++;
    vector<int> nextVertexSet;
    // Deklaracja iteratora
    list<ListElement>::iterator ite;
    for (ite = graphList[vertex].begin(); ite != graphList[vertex].end(); ite++)
    {
        nextVertexSet.push_back(ite->nextElement);
    }

    for (int i = 0; i < numberOfVertices; i++)
    {
        // Sprawdzenie czy wierzcholek byl odwiedzony i sprawdzenie czy jest polaczony z wierzcholkiem "vertex\"
        bool isIn;
        if (find(nextVertexSet.begin(), nextVertexSet.end(), i) != nextVertexSet.end()) isIn = true;
        else isIn = false;

        if (isIn)
        {
            if ((visitedList[i] == false))
            {
                ite = graphList[vertex].begin();
                while (ite->nextElement != i)
                {
                    ite++;
                }

                if (((distanceList[vertex] + (ite->edgeValue)) < distanceList[i]) || (distanceList[i] == INF))
                {
                    distanceList[i] = distanceList[vertex] + ite->edgeValue;
                    previousVertexList[i] = vertex;
                    changes++;
                }
            }
        }
    }
    // Wyznaczenie kolejnego wierzcholka w algorytmie
    int smallestAvailableVertex = INF;
    int distSmallestAV = INF;

    for (int i = 0; i < numberOfVertices; i++)
    {
        if ((visitedList[i] == false) && (distanceList[i] > 0) && ((distSmallestAV == INF) || (distSmallestAV > distanceList[i])))
        {
            distSmallestAV = distanceList[i];
            smallestAvailableVertex = i;
        }
    }
    if (dijkstraListIterations < numberOfVertices && changes != 0)
    {
        //printDistancesList();
        nextVertexSet.clear();
        dijkstraAlgorithmList(smallestAvailableVertex);
    }
    //else cout<<"\nKoniec algorytmu Dijkstry dla listy\n";
}

long long int DijkstraImplementation::startDijkstraList()
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    start = read_QPC();  // poczatek pomiaru czasu

    dijkstraAlgorithmList(0);

    elapsed = read_QPC() - start; // koniec pomiaru czasu jesli nie znaleziono szukanej wartosci

    //cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /frequency << endl;
    //cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /frequency << endl;
    //cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /frequency << endl << endl;

    return ((1000000.0 * elapsed) / frequency);
}
