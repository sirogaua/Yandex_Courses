#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n, i;

    cin >> n;

    set<string> dict;

    i = 0;
    while (i < n)
    {
        string str;

        cin >> str;

        dict.insert(str);

        i++;
    }

    cout << dict.size() << endl;
    

    return 0;
}
