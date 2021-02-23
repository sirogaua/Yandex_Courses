#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Print_nums_worry(const vector<bool>& turn)
{
    int counter = 0;
    for(auto p : turn)
    {
        if (p == true)
        {
            counter++;
        }
        
    }
    cout << counter << endl;
}

// void Print_size_and_value (const vector<bool>& turn)
// {
//     for(auto p : turn)
//     {
//         cout << p << " "; 
//     }
//     cout << endl << turn.size() << endl;
// }

int main()
{
    int n, i;
    cin >> n;
    
    vector<string> commands(n);
    vector<int> args(n);

    i = 0;
    while (i < n)
    {
        cin >> commands[i];
        if (commands[i] != "WORRY_COUNT")
        {
            cin >> args[i];
        }
        i++;
    }

    vector<bool> turn;
    
    i = 0;
    while (i < n)
    {
        //Print_size_and_value(turn);
        if (commands[i] == "COME")
        {
            turn.resize(turn.size() + args[i]);
        }
        else
        {
            if (commands[i] == "WORRY")
            {
                turn[args[i]] = true;
            }
            else
            {
                if (commands[i] == "QUIET")
                {
                    turn[args[i]] = false;
                }
                else
                {
                    Print_nums_worry(turn);
                }
                
            }
               
        }
        
        
        i++;
    }
    
    
    
    return 0;
}
