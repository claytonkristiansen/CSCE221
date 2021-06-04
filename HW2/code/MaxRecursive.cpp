#include <iostream>
#include <vector>

using std::vector;

int find_max_value(vector<int> v, int index = 0)
{
    if(index + 1 >=  v.size())
    {
        return v[index];
    }
    int val = find_max_value(v, ++index);
    if(val > v[index])
    {
        return val;
    }
    return v[index];
}


int main()
{
    std::vector<int> vec;
    vec.push_back(12);
    vec.push_back(21);
    vec.push_back(3);
    vec.push_back(234);
    vec.push_back(3);
    vec.push_back(12);
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(2);

    std::cout << "First Test:\n\nSize: ";
    std::cout << find_max_value(vec);

    vec.clear();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);

    std::cout << "\n\n\n\nSecond Test:\n\nSize: ";
    std::cout << find_max_value(vec) << "\n";
}