#include <iostream>
#include <string>
#include <map>

using namespace std;

void Print_Country_and_Capital(const map<string, string>& c_c)
{
    if (c_c.empty())
    {
        cout << "There are no countries in the world" << endl;
    }
    else
    {
        for(const auto& p : c_c)
        {
            cout << p.first << "/" << p.second << " ";   
        }
        cout << endl;
    }
}

int main()
{
    int n, i;
    string s;
    cin >> n;

	map<string, string> country_capital;
    
    i = 0;
    while (i < n)
    {
        cin >> s;
        if (s == "CHANGE_CAPITAL")
        {
            string country;
            string new_capital;

            cin >> country >> new_capital;

			if (!country_capital.count(country))
			{
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                country_capital[country] = new_capital;
			}
			else
			{
				if (country_capital[country] == new_capital)
				{
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
                else
                {
                    cout << "Country "<< country << " has changed its capital from " 
                    << country_capital[country] << " to " << new_capital << endl;
                    country_capital[country] = new_capital;
                }
			}
			
			
        }
        else
        {
            if (s == "RENAME")
            {
                string old_name;
                string new_name;
                
                cin >> old_name >> new_name;

                if (!country_capital.count(old_name) || old_name == new_name || country_capital.count(new_name))
                {
                    cout << "Incorrect rename, skip" << endl;
                }
                else
                {
                    cout << "Country " << old_name << " with capital " << country_capital[old_name]
                    << " has been renamed to " << new_name << endl;
                    country_capital[new_name] = country_capital[old_name];
                    country_capital.erase(old_name);
                }
                
                
            }
            else
            {
                if (s == "ABOUT")
                {
                    string country;

                    cin >> country;

                    if (!country_capital.count(country))
                    {
                        cout << "Country " << country << " doesn't exist" << endl;
                    }
                    else
                    {
                        cout << "Country " << country  << " has capital " << country_capital[country] << endl;
                    }
                    
                    
                }
                else
                {
                    Print_Country_and_Capital(country_capital);   
                } 
            }
               
        }
        
        
        i++;
    }
    
    
    
    return 0;
}
