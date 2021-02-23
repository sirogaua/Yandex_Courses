#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, i;

    cin >> n;

    map<string, set<string>> dict_sin;

    i = 0;
    while (i < n)
    {
        string s;

        cin >> s;

        if (s == "ADD")
        {
            string word1, word2;

            cin >> word1 >> word2;

            dict_sin[word1].insert(word2);
            dict_sin[word2].insert(word1);
        }
        else
        {
            if (s == "COUNT")
            {
                string word;

                cin >> word;

                cout << dict_sin[word].size() << endl;
            }
            else
            {
                string word1, word2;

                cin >> word1 >> word2;

                if (dict_sin[word1].count(word2))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
                
                
            }
            
            
        }
        
        
        i++;
    }
    

    return 0;
}