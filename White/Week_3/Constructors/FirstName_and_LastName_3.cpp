#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
    Person(const string& name, const string& sname, int y)
    {
        year_birth = y;
        ChangeFirstName(y, name);
        ChangeLastName(y, sname);
    }

  void ChangeFirstName(int year, const string& first_name) {
      if (year >= year_birth)
      {
          year_f_n[year] = first_name;
      }
  }
  void ChangeLastName(int year, const string& last_name) {
      if (year >= year_birth)
      {
          year_l_n[year] = last_name;
      }
  }
    string GetFullName(int year) const
    {
        if (year < year_birth)
        {
            return "No person";
        }
        
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

        return name + " " + sname;
    
    }

    string GetFullNameWithHistory(int year) const 
    {
        if (year < year_birth)
        {
            return "No person";
        }
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
            
            if (!fir.empty())
            {
                if (index.second != fir.back())
                {
                    fir.push_back(index.second);
                }
            }
            else
            {
                fir.push_back(index.second);
            }
        }

        for (int index = fir.size() - 2; index >= 0; index--)
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

        if (name_history != "")
        {
            name_history = " (" + name_history + ")";
        }

        for (const auto& index : year_l_n)
        {
            if (index.first > year)
            {
                break;
            }

            if (!sec.empty())
            {
                if (index.second != sec.back())
                {
                    sec.push_back(index.second);
                }
            }
            else
            {
                sec.push_back(index.second);
            }
        }

        for (int index = sec.size() - 2; index >= 0; index--)
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

        if (sname_history != "")
        {
            sname_history = " (" + sname_history + ")";
        }

        name = fir.back();
        sname = sec.back();

        return name + name_history + " " + sname + sname_history;
    }
private:
  map<int, string> year_f_n;
  map<int, string> year_l_n;

  int year_birth;
};

int main() {

	Person person("-1_first", "-1_last", -1);



	int year = 3;

	person.ChangeFirstName(year, std::to_string(year) + "_first");

	person.ChangeLastName(year, std::to_string(year) + "_last");



	year = 5;

	person.ChangeFirstName(year, std::to_string(year) + "_first");

	person.ChangeLastName(year, std::to_string(year) + "_last");



	year = 1;

	person.ChangeFirstName(year, std::to_string(3) + "_first");

	person.ChangeLastName(year, std::to_string(3) + "_last");



	year = 7;

	std::cout << "year: " << year << '\n';

	std::cout << person.GetFullNameWithHistory(year) << '\n';



	return 0;

}