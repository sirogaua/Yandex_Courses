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
        int n, m, num;
        input >> n;
        input.ignore(1);
        input >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                input >> num;
                cout << setw(10) << num;
                input.ignore(1);
                
                if (j != m - 1)
                {
                    cout << ' ';
                }
                
            }
            if (i != n - 1)
            {
                cout << endl;
            }
            
            
        }
        
        
    }
    
    return 0;
}