#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

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
    return {val1.Numerator() * val2.Denominator(), val1.Denominator() * val2.Numerator()};
}

istream& operator>> (istream& stream, Rational& r)
{    
    int p_t, q_t;

    if (!(stream >> p_t))
    {
        return stream;
    }

    if (stream.peek() != '/')
    {
        return stream;
    }
    
    stream.ignore(1);

    if (!(stream >> q_t))
    {
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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}