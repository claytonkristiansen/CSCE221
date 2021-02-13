#include <iostream>
#include <vector>

using std::vector;

bool OddProductN(vector<int> vec)
{
    int numEven = 0;
    int numOdd = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i] % 2 == 0)
        {
            ++numEven;
        }
        else
        {
            ++numOdd;
        }
        if(numOdd > 1)
        {
            return true;
        }
    }
    return false;
}


bool OddProductN2(vector<int> vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int k = 0; k < vec.size(); ++k)
        {
            if((vec[i] * vec[k]) % 2 != 0
             && i != k)
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    vector<int> vec;
    vec.push_back(18);
    vec.push_back(11);
    vec.push_back(12);
    vec.push_back(14);
    vec.push_back(18);
    vec.push_back(20);
    vec.push_back(22);

    std::cout << OddProductN(vec) << "\n";
    std::cout << OddProductN2(vec) << "\n\n";
    return 0;
}