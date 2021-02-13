#include <vector>
#include <iostream>
#include <exception>
#include <math.h>

int num_comp = 0;

template<typename T, typename Comparator>
T binary_search(std::vector<T>& A, T x, Comparator cmp)
{
    int mid = 0;
    int low = 0; 
    int high = A.size() - 1;
    while (low < high ) 
    {
        mid = (low + high) / 2;
        if (++num_comp, !cmp.isGreaterThan(A[mid], x))
        { 
            high = mid;
            
        }
        else
        {
            
            low = mid + 1;
        }
    }
    if(++num_comp, cmp.isEqualTo(A[low], x))
    {
        return low;
    }
    throw std::domain_error("Unsuccessful Search");
}

std::vector<int>* VectorGenerator(unsigned int pow2)
{
    unsigned int size = std::pow(2, pow2);
    std::vector<int>* vec = new std::vector<int>();
    for(int i = size; i >= 1; --i)
    {
        vec->push_back(i);
    }
    return vec;
}

class IntCompare
{
public:
    bool isLessThan(int& lhs, int& rhs)
    {
        return lhs < rhs;
    }

    bool isEqualTo(int& lhs, int& rhs)
    {
        return lhs == rhs;
    }
    bool isGreaterThan(int& lhs, int& rhs)
    {
        return lhs > rhs;
    }
};


int main()
{
    IntCompare cmp;
    for(int i = 1; i <= 11; ++i)
    {
        std::cout << "Range [1, " << std::pow(2, i) << "]\t\t";
        std::cout << "Target: " << std::pow(2, i) << "\t\t";
        std::vector<int>* vec = VectorGenerator(i);
        binary_search<int>(*vec, std::pow(2, i), cmp);
        std::cout << "# comp: " << num_comp << "\n";
        num_comp = 0;
        delete vec;
    }

    std::cout << "|---------------------------------------------------------------|\n";

    for(int i = 1; i <= 11; ++i)
    { 
        std::cout << "Range [1, " << std::pow(2, i) - 1 << "]\t\t";
        std::cout << "Target: " << std::pow(2, i) - 1 << "\t\t";
        std::vector<int>* vec = VectorGenerator(i);
        vec->pop_back();
        binary_search<int>(*vec, std::pow(2, i) - 1, cmp);
        std::cout << "# comp: " << num_comp << "\n";
        num_comp = 0;
        delete vec;
    }






    std::vector<int> *myVec = new std::vector<int>();
    myVec->push_back(2);
    myVec->push_back(6);
    myVec->push_back(10);
    myVec->push_back(23);
    myVec->push_back(76);
    myVec->push_back(87);
    myVec->push_back(98);
    myVec->push_back(99);
    myVec->push_back(101);
    myVec->push_back(200);
    myVec->push_back(223);
    myVec->push_back(265);
    myVec->push_back(353);
    myVec->push_back(432);
    myVec->push_back(452);
    //myVec->push_back(863);

    num_comp = 0;
    std::cout << "First Element: ";
    std::cout << binary_search<int>((*myVec), 2, cmp) << "\n";
    std::cout << "Number of Comparisons: " << num_comp << "\n\n";

    num_comp = 0;
    std::cout << "Middle Element: ";
    std::cout << binary_search<int>((*myVec), 99, cmp) << "\n";
    std::cout << "Number of Comparisons: " << num_comp << "\n\n";

    num_comp = 0;
    std::cout << "Last Element: ";
    std::cout << binary_search<int>((*myVec), 432, cmp) << "\n";
    std::cout << "Number of Comparisons: " << num_comp << "\n\n";

    delete myVec;
}