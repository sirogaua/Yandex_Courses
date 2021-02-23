#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

struct PartFunction
{
    char operation;
    double operand;
    PartFunction(char opt, double opd) : operation(opt), operand(opd)
    {}

    void Invert_OP()
    {
        if (operation == '+')
        {
            operation = '-';
        }
        else
        {
            if (operation == '-')
            {
                operation = '+';
            }
            else
            {
                if (operation == '*')
                {
                    operation = '/';
                }
                else
                {
                    operation = '*';
                }
                
            }
        }   
    }
};


class Function
{
private:
    vector<PartFunction> ops;
public:
    void AddPart(char operation, double operand)
    {
        ops.push_back({operation, operand});
    }

    double Apply(double val) const
    {
        for(auto op : ops)
        {
            if (op.operation == '+')
            {
                val += op.operand;
            }
            else
            {
                if (op.operation == '-')
                {
                    val -= op.operand;
                }
                else
                {
                    if (op.operation == '*')
                    {
                        val *= op.operand;
                    }
                    else
                    {
                        val /= op.operand;
                    }
                    
                }
            }    
        }
        return val;
    }

    void Invert()
    {
        for (auto& op : ops)
        {
            op.Invert_OP();
        }
        reverse(begin(ops), end(ops));
    }
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
