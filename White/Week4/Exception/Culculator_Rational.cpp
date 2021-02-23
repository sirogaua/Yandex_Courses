#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

using namespace std;

int NSD(int a, int b)
{
    int buff;
    while (b != 0)
    {
        buff = b;
        b = a % b;
        a = buff;
    }
    return a;  
}

class Rational {
  int num;
  int dom;
public:

  Rational() : num(0), dom(1)
  {}

  Rational(int numerator, int denominator)
  {
    Initialize(numerator, denominator);
  }

  int Numerator() const
  {
    return num;
  }
  int Denominator() const
  {
    return dom;
  }

  void Initialize(int numerator, int denominator)
  {
    if (denominator == 0)
    {
        throw runtime_error("Invalid argument");
    }

    int div = NSD(numerator, denominator);
    num = numerator / div;
    dom = denominator / div;

    if (dom < 0)
    {
        num *= -1;
        dom *= -1;
    }
  }
};

bool operator== (const Rational& val1, const Rational& val2)
{
    if (val1.Numerator() == val2.Numerator() && val1.Denominator() == val2.Denominator())
    {
        return true;
    }
    return false;
    
}

Rational operator+ (const Rational& val1, const Rational& val2)
{
    return {val1.Numerator() * val2.Denominator() + val2.Numerator() * val1.Denominator(), val1.Denominator() * val2.Denominator()};
}

Rational operator- (const Rational& val1, const Rational& val2)
{
    return {val1.Numerator() * val2.Denominator() - val2.Numerator() * val1.Denominator(), val1.Denominator() * val2.Denominator()};
}

Rational operator* (const Rational& val1, const Rational& val2)
{
    return {val1.Numerator() * val2.Numerator(), val1.Denominator() * val2.Denominator()};
}

Rational operator/ (const Rational& val1, const Rational& val2)
{
    if (val1.Denominator() * val2.Numerator() == 0)
    {
        throw runtime_error("Division by zero");
    }
    
    return {val1.Numerator() * val2.Denominator(), val1.Denominator() * val2.Numerator()};
}

istream& operator>> (istream& stream, Rational& r)
{    
    int p_t, q_t;

    if (!(stream >> p_t))
    {
        throw runtime_error("Invalid argument");
        return stream;
    }

    if (stream.peek() != '/')
    {
        throw runtime_error("Invalid argument");
        return stream;
    }
    
    stream.ignore(1);

    if (!(stream >> q_t))
    {
        throw runtime_error("Invalid argument");
        return stream;
    }

    r.Initialize(p_t, q_t);
    return stream;
}

ostream& operator<< (ostream& stream, const Rational& r)
{
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator< (const Rational& val1, const Rational& val2)
{
    return (val1.Numerator() * val2.Denominator()) < (val2.Numerator() * val1.Denominator());
}



int main() {

    Rational r1, r2;
    char operation;

    try 
    {
        cin >> r1 >> operation >> r2; 
        if (operation == '+')
    {
        cout << r1 + r2;
    }
    else
    {
        if (operation == '-')
        {
            cout << r1 - r2;
        }
        else
        {
            if (operation == '*')
            {
                cout << r1 * r2;
            }
            else
            {
                cout << r1 / r2;
            }
        }
    }

    } catch (runtime_error& er) 
    {
        cout << er.what() << endl;
        return 0;
    }

    return 0;
}