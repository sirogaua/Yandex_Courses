#include <iostream>
#include <string>

using namespace std;

class ReversibleString
{
private:
    string str;
public:
    ReversibleString() : str("")
    {}

    ReversibleString(const string& s) : str(s)
    {}

    void Reverse()
    {
        for(int i = 0; i < str.size() / 2; i++)
        {
            char buff = str[i];
            str[i] = str[str.size() - 1 - i];
            str[str.size() - 1 - i] = buff;
        }
    }

    string ToString() const
    {
        return str;
    }
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}