#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> BuildChar(const string& str) 
{
  map<char, int> result;
  for (const auto& simbol : str)
  {
    ++result[simbol];
  }
  return result;
}

int main()
{
  int n, i = 0;
  
  cin >> n;

  while (i < n)
  {
    string word1, word2;
    cin >> word1 >> word2;

    if (BuildChar(word1) == BuildChar(word2))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
    


    i++;
  }
  


  return 0;
}
