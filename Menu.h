#ifndef MENU_H
#define MENU_H

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        struct EdgeOptions
        {
            public:
                int v1;
                int v2;
        };

        void generateRandomGraph();
        int binomialCoefficients(int, int);
        void shuffle_array(EdgeOptions, int);

    protected:

    private:
        int choice;
        int working;
        int fileChoice;
        int numVert;
        int numEdges;
        int edgeDensity;
        EdgeOptions* edgeOptionsTable;
};
#endif // MENU_H