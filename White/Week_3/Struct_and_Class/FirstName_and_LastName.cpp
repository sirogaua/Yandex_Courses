#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    year_f_n[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    year_l_n[year] = last_name;
  }
  string GetFullName(int year) {
    string name = "";
    string sname = "";
    for (const auto& index : year_f_n)
    {
        if (index.first > year)
        {
            break;
        }
        name.clear();
        name = index.second;
    }

    for (const auto& index : year_l_n)
    {
        if (index.first > year)
        {
            break;
        }
        sname.clear();
        sname = index.second;
    }

    if (name == "")
    {
        if (sname == "")
        {
            return "Incognito";
        }
        else
        {
            return sname + " with unknown first name";
        }      
    }
    else
    {
        if (sname == "")
        {
            return name + " with unknown last name";
        }
        else
        {
            return name + " " + sname;
        }
        
    }
    
    
    
  }
private:
  map<int, string> year_f_n;
  map<int, string> year_l_n;
};