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
    if (denominator == 0)
    {
        throw invalid_argument("invalid_argument");
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
        throw domain_error("domain_error");
    }
    
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}