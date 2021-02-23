#include <iostream>

using namespace std;

class Incognizable
{
private:
    int x;
    int y;
public:
    Incognizable() : x(0), y(0)
    {}

    Incognizable(int X) : x(X), y(0)
    {}

    Incognizable(int X, int Y) : x(X), y(Y)
    {}
};


int main() 
{
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}