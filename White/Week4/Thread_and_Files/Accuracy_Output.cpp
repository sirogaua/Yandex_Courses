#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");

    if (input)
    {
        double var;
        cout << fixed;
        cout << setprecision(3);
        while (input >> var)
        {
            cout << var << endl;
        }
        
    }
    
    return 0;
}