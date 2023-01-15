#include "XO.h"


char XO::finish()
{
    if (testOX())return 'H';
    if (testX()) return 'X';
    if (testO()) return 'O';
    return ' ';
}

char XO::getMap(int num)
{
    if ((num < 0) && (num > 8)) return '?';
    return this->map[num];
}


bool XO::testOX()
{
    for (int i = 0; i < 9; i++)
    {
        if (map[i] == ' ')return false;
    }
    return true;
}

bool XO::testX()
{
    if ((map[0] == 'X') && (map[4] == 'X') && (map[8] == 'X'))return true;
    if ((map[2] == 'X') && (map[4] == 'X') && (map[6] == 'X'))return true;
    int i = 0;
    if ((map[i] == 'X') && (map[1 + i] == 'X') && (map[2 + i] == 'X'))return true;
    i = 3;
    if ((map[i] == 'X') && (map[1 + i] == 'X') && (map[2 + i] == 'X'))return true;
    i = 6;
    if ((map[i] == 'X') && (map[1 + i] == 'X') && (map[2 + i] == 'X'))return true;
    i = 0;
    if ((map[i] == 'X') && (map[3 + i] == 'X') && (map[6 + i] == 'X'))return true;
    i = 1;
    if ((map[i] == 'X') && (map[3 + i] == 'X') && (map[6 + i] == 'X'))return true;
    i = 2;
    if ((map[i] == 'X') && (map[3 + i] == 'X') && (map[6 + i] == 'X'))return true;

    return false;

}

bool XO::testO()
{
    if ((map[0] == 'O') && (map[4] == 'O') && (map[8] == 'O'))return true;
    if ((map[2] == 'O') && (map[4] == 'O') && (map[6] == 'O'))return true;
    int i = 0;
    if ((map[i] == 'O') && (map[1 + i] == 'O') && (map[2 + i] == 'O'))return true;
    i = 3;
    if ((map[i] == 'O') && (map[1 + i] == 'O') && (map[2 + i] == 'O'))return true;
    i = 6;
    if ((map[i] == 'O') && (map[1 + i] == 'O') && (map[2 + i] == 'O'))return true;
    i = 0;
    if ((map[i] == 'O') && (map[3 + i] == 'O') && (map[6 + i] == 'O'))return true;
    i = 1;
    if ((map[i] == 'O') && (map[3 + i] == 'O') && (map[6 + i] == 'O'))return true;
    i = 2;
    if ((map[i] == 'O') && (map[3 + i] == 'O') && (map[6 + i] == 'O'))return true;

    return false;
}

bool XO::stepO(int step)
{
    if (map[step] == ' ')
        map[step] = 'O';
    else
        return false;
    return true;
}

bool XO::stepX(int step)
{
    if (map[step] == ' ')
        map[step] = 'X';
    else
        return false;
    return true;
}

XO::XO()
{
    for (int i = 0; i < 10; i++)
    {
        map[i] = ' ';
    }
}

void
XO::out()
{
    std::cout << "   1   2   3   \n";
    std::cout << " +---+---+---+ \n";
    std::
        cout << "1| " << map[0] << " | " << map[1] << " | " << map[2] << " |\n";
    std::cout << " +---+---+---+ \n";
    std::
        cout << "2| " << map[3] << " | " << map[4] << " | " << map[5] << " |\n";
    std::cout << " +---+---+---+ \n";
    std::
        cout << "3| " << map[6] << " | " << map[7] << " | " << map[8] << " |\n";
    std::cout << " +---+---+---+ \n";
}
