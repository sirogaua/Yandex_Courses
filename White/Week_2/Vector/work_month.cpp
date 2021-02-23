#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Print_works_per_day(const vector<string>& day)
{
    cout << day.size() << " ";
    for(auto p : day)
    {
        cout << p << " ";   
    }
    cout << endl;
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
    int n, i, cur_month = 1;
    string s;
    cin >> n;

    
    map<int, int> month_day = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, 
                                {5, 31}, {6, 30}, {7, 31}, {8, 31}, 
                                {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    vector<vector<string>> months(month_day[1]);

    
    i = 0;
    while (i < n)
    {
        cin >> s;
        if (s == "ADD")
        {
            int index;
            string work;

            cin >> index >> work;
            months[index - 1].push_back(work);
        }
        else
        {
            if (s == "DUMP")
            {
                int index;
                
                cin >> index;

                Print_works_per_day(months[index - 1]);
            }
            else
            {
                cur_month++;
                if (cur_month == 13)
                {
                    cur_month -= 12;
                }
                
                if (month_day[cur_month] < months.size())
                {
                    for (int i = month_day[cur_month]; i < months.size(); i++)
                    {
                        months[month_day[cur_month] - 1].insert(end(months[month_day[cur_month] - 1]), begin(months[i]), end(months[i]));
                    }
                    months.resize(month_day[cur_month]);
                }
                else
                {
                    months.resize(month_day[cur_month]);
                }
                
                   
            }
               
        }
        
        
        i++;
    }
    
    
    
    return 0;
}
