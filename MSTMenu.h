#ifndef MSTMENU_H
#define MSTMENU_H

class MSTMenu
{
    public:
        MSTMenu(int);
        virtual ~MSTMenu();

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
        int work;
        int fileChoice;
        int numVert;
        int numEdges;
        int edgeDensity;
        EdgeOptions* edgeOptionsTable;
};

#endif // MSTMENU_H