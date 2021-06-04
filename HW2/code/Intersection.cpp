#include <list>
#include <iostream>

std::list<int> intersection(const std::list<int> & l1, const std::list<int> & l2) 
{
    std::list<int> l3;
    
    std::list<int>::const_iterator el1 = l1.begin();
    std::list<int>::const_iterator el2 = l2.begin();

    while(el1 != l1.end())
    {
        el2 = l2.begin();
        while(el2 != l2.end())
        {
            if(*el1 == *el2)
            {
                l3.push_back(*el1);
                std::cout << *el1 << "\n";
            }
            el2++;
        }
        el1++;
    }

    return l3;
}

int main()
{
    std::list<int> l1;
    std::list<int> l2;
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_back(6);
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(7);
    std::cout << "TEST CASE 1:\n";
    intersection(l1, l2);
    l1.clear();
    l2.clear();
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_back(10);
    l2.push_back(5);
    l2.push_back(4);
    l2.push_back(3);
    l2.push_back(8);
    std::cout << "\n\n\nTEST CASE 2:\n";
    intersection(l1, l2);
}