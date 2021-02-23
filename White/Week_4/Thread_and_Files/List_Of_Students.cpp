#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string fname;
    string sname;
    int day_b;
    int month_b;
    int year_b;
};


int main()
{
    int n, i;
    vector<Student> students;

    cin >> n;

    i = 0;
    while (i < n)
    {
        string fname;
        string sname;
        int day;
        int month;
        int year;

        cin >> fname >> sname >> day >> month >> year;

        students.push_back({fname, sname, day, month, year});
        i++;
    }
    
    cin >> n;

    i = 0;
    while (i < n)
    {
        string command;
        cin >> command;
        if (command == "name")
        {
            int num_s;
            cin >> num_s;
            
            if (num_s > 0 && num_s <= students.size())
            {
                cout << students[num_s - 1].fname << " " << students[num_s - 1].sname << endl;
            }
            else
            {
                cout << "bad request" << endl;
            }
            
        }
        else
        {
            if (command == "date")
            {
                int num_s;
                cin >> num_s;

                if (num_s > 0 && num_s <= students.size())
                {
                    cout << students[num_s - 1].day_b << "." << students[num_s - 1].month_b << "." << students[num_s - 1].year_b << endl;
                }
                else
                {
                    cout << "bad request" << endl;
                }
                
            }
            else
            {
                int num_s;
                cin >> num_s;
                cout << "bad request" << endl;
            }
            
            
        }
        
        
        i++;
    }
    

    return 0;
}