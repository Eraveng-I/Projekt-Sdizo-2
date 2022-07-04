#include <iostream>
#include "ShortestPathMenu.h"
#include "Menu.h"
#include "DijkstraImplementation.h"

#include <iomanip>
#include <windows.h>

using namespace std;

ShortestPathMenu::ShortestPathMenu(int fileChoice)
{
    work = 0;

    while (work == 0) // ciagle wyswietlaj menu
    {
        int choice = 0; // wybor struktury
        cout << endl << "SHORTEST PATH MENU:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. Algorytm Dijkstry " << endl;
        cout << "2. Algorytm Bellmana-Forda " << endl;
        cout << "3. Powrot do menu glownego " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Wybor: ";
        cin >> choice;
        system("cls"); // czyszczenie konsoli

        switch (choice)
        {
            case 1:
            {
                long long int matrixTime = 0;
                long long int listTime = 0;
                cout << "Algorytm Dijkstry" << endl;

                //for (int i = 0; i < 100; i++)
                //{
                    // macierz
                    DijkstraImplementation dijkstra(fileChoice);
                    dijkstra.getFileInfo();
                    dijkstra.printMatrix();
                    dijkstra.initTables();
                    matrixTime += dijkstra.startDijkstraMatrix();
                    dijkstra.printDistances();
                //}
                //for (int i = 0; i < 100; i++)
                //{
                    // lista
                    //DijkstraImplementation dijkstra(fileChoice);
                    dijkstra.getFileInfo();
                    dijkstra.printList();
                    dijkstra.initTables();
                    listTime += dijkstra.startDijkstraList();
                    dijkstra.printDistancesList();
                //}
                //cout << "Time [s] = " << fixed << setprecision(3) << (float)matrixTime /frequency << endl;
                //cout << "Time [ms] = " << setprecision(0) << (1000.0 * matrixTime) /frequency << endl;
                //cout << "Time [us] = " << setprecision(0) << (1000000.0 * matrixTime) /frequency << endl << endl;
                cout << "Matrix Time [us] = " << setprecision(0) << matrixTime << endl << endl;
                cout << "List Time [us] = " << setprecision(0) << listTime << endl << endl;
                //delete this;
            }
            break;

            case 2:
            {
                cout << "Algorytm Bellmana-Forda" << endl;
                //delete this;
            }
            break;

            case 3:
            {
                Menu menu; // powrot do menu glownego
                delete this;
            }
            break;
            default:
            cout << "Nieprawidlowy numer polecenia. Sprobuj jeszcze raz" << endl;
        }

    }
}

ShortestPathMenu::~ShortestPathMenu()
{
    //dtor
}
long long int ShortestPathMenu::read_QPC()
{
    LARGE_INTEGER count;

    QueryPerformanceCounter(&count);
    return ((long long int)count.QuadPart);
}
