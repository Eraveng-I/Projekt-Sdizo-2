#ifndef SHORTESTPATHMENU_H
#define SHORTESTPATHMENU_H

class ShortestPathMenu
{
public:
    ShortestPathMenu(int);
    virtual ~ShortestPathMenu();

    long long int read_QPC();

protected:

private:
    int work;
    int choice;

    long long int frequency;
    long long int start;
    long long int elapsed;
};

#endif // SHORTESTPATHMENU_H