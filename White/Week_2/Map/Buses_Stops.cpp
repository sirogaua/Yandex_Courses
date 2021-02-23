#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, i;
    string s;
    cin >> n;

	map<string, vector<string>> bus_stops;
    map<string, vector<string>> stop_buses;
     
    i = 0;
    while (i < n)
    {
        cin >> s;
        if (s == "NEW_BUS")
        {
            int bus_stop_count;
            string bus;

            cin >> bus;

            cin >> bus_stop_count;

			for (int j = 0; j < bus_stop_count; j++)
            {
                string stop;

                cin >> stop;

                bus_stops[bus].push_back(stop);
                stop_buses[stop].push_back(bus);
            }	
        }
        else
        {
            if (s == "BUSES_FOR_STOP")
            {
                string stop;
                
                cin >> stop;

                if (!stop_buses.count(stop))
                {
                    cout << "No stop" << endl;
                }
                else
                {
                    for (const auto& bus : stop_buses[stop])
                    {
                        cout << bus << " ";
                    }
                    cout << endl;
                }    
            }
            else
            {
                if (s == "STOPS_FOR_BUS")
                {
                    string bus;

                    cin >> bus;

                    if (!bus_stops.count(bus))
                    {
                        cout << "No bus" << endl;
                    }
                    else
                    {
                        for(const auto& stop : bus_stops[bus])
                        {
                            cout << "Stop " << stop << ": ";
                            if (stop_buses[stop].size() == 1)
                            {
                                cout << "no interchange" << endl;
                            }
                            else
                            {
                                for(const auto& b : stop_buses[stop])
                                {
                                    if (b != bus)
                                    {
                                        cout << b << " ";
                                    }
                                    
                                }
                                cout << endl;
                            }
                        }
                    }
                    
                    
                }
                else
                {
                    //bus_stops.empty();
                    if (bus_stops.empty())
                    {
                        cout << "No buses" << endl;
                    }
                    else
                    {
                        //cout << "Size: " << bus_stops.size() << endl;
                        for(const auto& bus : bus_stops)
                        {
                            cout << "Bus " << bus.first << ": ";
                            for(const auto& stop : bus.second)
                            {
                                cout << stop << " ";
                            }
                            cout << endl;
                        }
                    }                    
                }
            }    
        }
        i++;
    }
    return 0;
}
