#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <exception>
#include <sstream>

using namespace std;

class Date 
{
    int year;
    int day;
    int month;

public:
    Date() : year(0), month(0), day(0)
    {}
    
    Date(int y, int m, int d)
    {
        if (m > 12 || m < 1)
        {
            throw runtime_error("Month value is invalid: " + to_string(m));
        }

        if (d > 31 || d < 1)
        {
            throw runtime_error("Day value is invalid: " + to_string(d));
        }
        
        year = y;
        day = d;
        month = m;
    }

    int GetYear() const
    {
        return year;
    }

    int GetMonth() const
    {
        return month;
    }

    int GetDay() const
    {
        return day;
    }
};

bool operator== (const Date& d1, const Date& d2)
{
    if (d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay() == d2.GetDay())
    {
        return true;
    }
    return false;
}

bool operator< (const Date& d1, const Date& d2)
{
    if (d1.GetYear() != d2.GetYear())
    {
        return d1.GetYear() < d2.GetYear();
    }
    else
    {
        if (d1.GetMonth() != d2.GetMonth())
        {
            return d1.GetMonth() < d2.GetMonth();
        }
        else
        {
            return d1.GetDay() < d2.GetDay();
        }  
    }
}

class Database {
    map <Date, set<string>> date_events;
public:
    void AddEvent(const Date& date, const string& event)
    {
        date_events[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event)
    {
        for(const auto& e : date_events.at(date))
        {
            if (e == event)
            {
                date_events.at(date).erase(event);
                return true;
            }
        }
        return false;
    }

    int DeleteDate(const Date& date)
    {
        int N = date_events.at(date).size();
        date_events.at(date).clear();

        return N;
    }

    set<string> Find(const Date& date) const
    {
        return date_events.at(date);
    }
    
    void Print() const
    {
        for (const auto& d : date_events)
        {
            for (const auto& e : d.second)
            {
                cout << setw(4) << setfill('0') << d.first.GetYear()
                << "-" << setw(2) << setfill('0') << d.first.GetMonth()
                << "-" << setw(2) << setfill('0') << d.first.GetDay()
                << " " << e << endl;
            }
        }
    }
};

Date Buld_Date (stringstream& stream)
{
    stringstream d_d(stream.str());
    string d;
    d_d >> d;
    d_d >> d;

    int year, month, day;

    stream >> year;

    if (stream.peek() != '-')
    {
        throw runtime_error("Wrong date format: " + d);
    }
    stream.ignore(1);

    if (!(stream >> month))
    {
        throw runtime_error("Wrong date format: " + d);
    }

    if (stream.peek() != '-')
    {
        throw runtime_error("Wrong date format: " + d);
    }
    stream.ignore(1);

    if (!(stream >> day))
    {
        throw runtime_error("Wrong date format: " + d);
    }

    return {year, month, day};
}

bool Parse_Date_and_Procces_Command(stringstream& stream, Database& db)
{
    string command;

    stream >> command;

    if (command == "Add")
    {
        Date d = Buld_Date(stream);

        string event;
        stream >> event;

        db.AddEvent(d, event);
    }
    else
    {
        if (command == "Del")
        {
            Date d = Buld_Date(stream);

            string event;
            if (stream >> event)
            {
                if (db.DeleteEvent(d, event))
                {
                    cout << "Deleted successfully" << endl;
                }
                else
                {
                    cout << "Event not found" << endl; 
                }
            }
            else
            {
                int N = db.DeleteDate(d);
                cout << "Deleted " << N << " events" << endl;
            }
        }
        else
        {
            if (command == "Find")
            {
                Date d = Buld_Date(stream);
                set<string> events = db.Find(d);

                for (const auto& event : events)
                {
                    cout << event << endl;
                }
            }
            else
            {
                if (command == "Print")
                {
                    db.Print();
                }
                else
                {
                    throw runtime_error("Unknown command: " + command);
                } 
            }
            
        }
        
        
    }
}

int main() 
{
    Database db;
    string command;
    while (getline(cin, command)) 
    {
        if (command != "")
        {
            stringstream s(command);
            try
            {
                Parse_Date_and_Procces_Command(s, db);
            }
            catch(const runtime_error& e)
            {
                cout << e.what() << endl;
                return 0;
            }
        }
    }

    return 0;
}