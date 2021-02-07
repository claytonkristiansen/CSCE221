#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> strv;
    strv.push_back(0);
    strv.push_back(3);
    strv.push_back(5);
    strv.push_back(2);
    strv.push_back(12);
    strv.push_back(101);

    int k = strv.size();

    for(int i = 0; i < strv.size(); i++)
    {
      strv[i] *= 5;
      cout << strv[i] << "\n";
    }
    

    return 0;

}