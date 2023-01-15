#include <iostream>

class XO
{
private:


    char map[10];


    bool testOX();
    bool testX();
    bool testO();
public:
    XO();
    void out();
    bool stepX(int step);
    bool stepO(int step);
    char finish();
    char getMap(int num);
};

