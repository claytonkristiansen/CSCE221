// Add code everywhere you see this:
// Your code >>>

#include <iostream>
#include <vector>

using namespace std;

int num_resize; // the number of resizes
int num_copy;  // the number of copied elements

void resize_array(int*& array, int& capacity)
{
  // Your code >>> resize array by doubling its capacity
  // Your code >>> use tracker variables:
  //           >>> num_resize and num_copy

    int* newArray = new int[capacity * 2];
    for(int i = 0; i < capacity; ++i)
    {
        newArray[i] = array[i];
        ++num_copy;
    }
    ++num_resize;
    delete[] array;
    array = newArray;
    newArray = nullptr;
    capacity *= 2;
}

void add_elements(int start, int total_elem)
{
    num_resize = 0;
    num_copy = 0;
    // Clear tracker variables
    num_resize = num_copy = 0;

    // Initialize array
    int capacity = start;
    int size = 0;
    int* A = new int[capacity];

    // Add elements to array
    while (size < total_elem)
    {
        if (size == capacity) // Array is full; add more space
        {
            resize_array(A, capacity);
        }
        ++size;
        int index = size - 1;
        A[index] = index*index; // new values
    }

    // Print tracking info
    cout << "Total elements: " << total_elem << endl;
    cout << "Resize " << num_resize << " times." << endl;
    cout << "Copied " << num_copy << " elements in total." << endl;

}


bool foo(std::vector<int> v1, std::vector<int> v2)
{
    //loops v1
        //loops v2
            //does something
    //F(n, m) = n * m
    //n = MAX(n, m)
    //F(n) = 2 * n
    return false;
}

int num_comp = 0;
int search_algorithm(std::vector<int> &v, int x) { 
    int m, i = 0;
    int j = v.size()-1;
    while (i < j) {
      m = (i+j)/2;
      if (num_comp++, v[m] < x) i = m+1;
      else j = m;
    }
    if (num_comp++, x == v[i]) return i; //found
}

int main()
{
  // test this program
//   int total_elem[]= {1, 2, 4, 64, 1024};
//   for (int i = 0; i < 5; i++)
//     add_elements(1, total_elem[i]);
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(12);
    search_algorithm(vec, 6);
    std::cout << num_comp;
}