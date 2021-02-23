#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Print (const vector<int>& nums)
{
    for (const auto& num : nums)
    {
        cout << num << " ";
    }
}

int main()
{
    int n, i;

    cin >> n;

    vector<int> nums;

    i = 0;
    while (i < n)
    {
        int num;

        cin >> num;

        nums.push_back(num);
        
        i++;
    }

    sort(begin(nums), end(nums),
        [](int a, int b){
            return abs(a) < abs(b);
        });

    Print(nums);
    

    return 0;
}