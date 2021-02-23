#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, i, mid;
    cin >> n;
    vector<int> v (n);
    i = 0;
    mid =  0;
    while (i < n)
    {
        cin >> v[i];
        mid += v[i];
        i++;
    }
    mid /= n;
    
    vector<int> temp_great_mid;
    i = 0;
    while (i < n)
    {
        if (v[i] > mid)
        {
            temp_great_mid.push_back(i);
        }
        i++;
    }
    
    cout << temp_great_mid.size() << endl;
    
    for (auto day : temp_great_mid)
    {
        cout << day << " ";
    }
    return 0;
}
