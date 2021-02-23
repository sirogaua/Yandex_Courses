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

  string GetFullNameWithHistory(int year) {
    string name = "";
    string sname = "";
    string name_history = "";
    string sname_history = "";

    vector<string> fir;
    vector<string> sec;

    for (const auto& index : year_f_n)
    {
        if (index.first > year)
        {
            break;
        }

        if (name != "" && index.second != name)
        {
            fir.push_back(name); 
        }
        
        name.clear();
        name = index.second;
    }

    if (!fir.empty())
    {
        for (int index = fir.size() - 1; index >= 0; index--)
        {
            if (name_history != "")
            {
                name_history += ", " + fir[index];
            }
            else
            {
                name_history += fir[index];
            }
        }
        name_history = " (" + name_history + ")";
    }
    

    for (const auto& index : year_l_n)
    {
        if (index.first > year)
        {
            break;
        }
        if (sname != "" && index.second != sname)
        {
            sec.push_back(sname); 
        }
        sname.clear();
        sname = index.second;
    }

    if (!sec.empty())
    {
        for (int index = sec.size() - 1; index >= 0; index--)
        {
            if (sname_history != "")
            {
                sname_history += ", " + sec[index];
            }
            else
            {
                sname_history += sec[index];
            }
        }
        sname_history = " (" + sname_history + ")";
    }
    

    if (name == "")
    {
        if (sname == "")
        {
            return "Incognito";
        }
        else
        {
            return sname + sname_history + " with unknown first name";
        }      
    }
    else
    {
        if (sname == "")
        {
            return name + name_history + " with unknown last name";
        }
        else
        {
            return name + name_history + " " + sname + sname_history;
        }
        
    }
  }
private:
  map<int, string> year_f_n;
  map<int, string> year_l_n;
};