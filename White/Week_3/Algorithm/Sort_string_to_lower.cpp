#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Print (const vector<string>& chs)
{
    for (const auto& c : chs)
    {
        cout << c << " ";
    }
}

int main()
{
    int n;

    cin >> n;

    vector<string> chs(n);

    for (auto& item : chs)
    {
        cin >> item;
    }



    sort(begin(chs), end(chs), 
        [](string a, string b)
        {
            for (auto& c : a)
            {
                c = tolower(c);
            }
            for (auto& c : b)
            {
                c = tolower(c);
            }
            return a < b;
        });

    Print(chs);
    

    return 0;
}