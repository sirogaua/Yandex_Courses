#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n, i;
    int num;
    cin >> n;

	map<set<string>, int> buses;
     
    i = 0;
    while (i < n)
    {
        cin >> num;

        set<string> buff;

        for (int j = 0; j < num; j++)
        {
            string str;

            cin >> str;

            buff.insert(str);
        }

        if (!buses.count(buff))
        {
            int val = buses.size();
            buses[buff] = val + 1;
            cout << "New bus " << buses[buff] << endl; 
        }
        else
        {
            cout << "Already exists for " << buses[buff] << endl;
        }
                
        i++;
    }
    return 0;
}