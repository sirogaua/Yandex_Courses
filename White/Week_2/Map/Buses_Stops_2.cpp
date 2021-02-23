#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, i;
    int num;
    cin >> n;

	map<vector<string>, int> buses;
     
    i = 0;
    while (i < n)
    {
        cin >> num;

        vector<string> buff;

        for (int j = 0; j < num; j++)
        {
            string str;
            cin >> str;
            buff.push_back(str);
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