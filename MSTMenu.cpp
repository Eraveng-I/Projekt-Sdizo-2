#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
//chyba do wywalenia? //#include<bits/stdc++.h>

#include "MSTMenu.h"
#include "PrimsImplementation.h"
//#include "ShortestPathMenu.h"
#include "Menu.h"

using namespace std;

//int work;
fstream fileWrite;

struct EdgeOptions
{
    int v1;
    int v2;
};

MSTMenu::MSTMenu(int fileChoice)
{
    work = 0;

    while (work == 0) // ciagle wyswietlaj menu
    {
        int choice = 0; // wybor struktury
        cout << endl << "MST MENU:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. Algorytm Prima " << endl;
        cout << "2. Algorytm Kruskala " << endl;
        cout << "3. Powrot do menu glownego " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Wybor: ";
        cin >> choice;
        system("cls"); // czyszczenie konsoli

        switch (choice)
        {
            case 1:
            {
                cout << "Algorytm Prima" << endl;
                PrimsImplementation prim(fileChoice);
                //delete this;
            }
            break;

            case 2:
            {
                cout << "Algorytm Kruskala" << endl;
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

MSTMenu::~MSTMenu()
{

}

void MSTMenu::generateRandomGraph()
{
    cout << "Generowanie losowego grafu" << endl;
    int numEdgesMax;
    numEdgesMax = numVert * (numVert - 1) / 2;
    cout << "Maksymalna liczba krawedzi = " << numEdgesMax << endl;

    switch (edgeDensity)
    {
        case 1:
        {
            numEdges = floor(0.25 * numEdgesMax);
        }
        break;
        case 2:
        {
            numEdges = floor(0.5 * numEdgesMax);
        }
        break;
        case 3:
        {
            numEdges = floor(0.75 * numEdgesMax);
        }
        break;
        case 4:
        {
            numEdges = floor(0.99 * numEdgesMax);
        }
        break;
        default:
            cout << "Nieprawidlowy numer polecenia!" << endl;
            exit(0);
    }
    fileWrite.open("GraphRandom.txt", ios::out);
    if (fileWrite.good())
    {
        // liczba krawedzi i liczba wierzcholkow
        cout << numEdges << " " << numVert << "\n";
        fileWrite << numEdges << " " << numVert << "\n";
        cout << "\n";
        fileWrite << "\n";

        // tworzenie tablicy ktora przechowuje wszystkie mozliwe kombinacje wierzcholek-wierzcholek dla podanej ilosci
        // np 0-1, 0-2, 3-4 itd. Zawsze mniejsze do wiekszego
        edgeOptionsTable = new EdgeOptions[numEdgesMax];
        int i, j;
        int k = 0;
        for (i = 0; i < numEdgesMax; i++)
        {

            for (j = i + 1; j < numVert; j++)
            {
                edgeOptionsTable[k].v1 = i;
                edgeOptionsTable[k].v2 = j;
                k++;
            }
        }
        // pomieszanie kolejnosci
        for (int m = numEdgesMax - 1; m > 0; m--)
        {
            int n = rand() % (m)+1;
            EdgeOptions temp;
            temp = edgeOptionsTable[m];
            edgeOptionsTable[m] = edgeOptionsTable[n];
            edgeOptionsTable[n] = temp;
        }
        // wypisywanie kolejnych krawedzi
        for (int i = 0; i < numEdges; i++)
        {
            int edge = (rand() % 99) + 1;
            //cout<<edgeOptionsTable[i].v1<<" "<<edgeOptionsTable[i].v2<<" "<<edge<<"\n";
            fileWrite << edgeOptionsTable[i].v1 << " " << edgeOptionsTable[i].v2 << " " << edge << "\n";
        }
        fileWrite.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku!\n";
    }

    delete[] edgeOptionsTable;
}