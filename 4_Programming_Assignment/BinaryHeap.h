#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        //Initialize binary heap as empty
        BinaryHeap()
        {
            elements = std::vector<T>();
            size = 0;
        }
        //Insert new element
        void insert(const T& data)
        {
            elements.push_back(data);
            up_heap(size++);
        }
        // Return true if BinaryHeap is empty otherwise false
        bool is_empty()
        {
            if(size == 0) return true;
            return false;
        }
        // Return minimum element in the BinaryHeap
        T min()
        {
            if(this->is_empty())
            {
                throw std::runtime_error(std::string("Empty"));
            }
            return elements[0];
        }
        // Remove minimum element in the BinaryHeap and return it
        T remove_min()
        {
            if(this->is_empty())
            {
                throw std::runtime_error(std::string("Empty"));
            }
            T min = elements[0];
            elements[0] = elements.back();
            elements.pop_back();
            size--;
            down_heap(0);
            return min;
        }
    private:
        //Vector of elements 
        std::vector<T> elements;
        int size = 0;
        //Implement down heap operation
        void down_heap(int i);
        //Implement up heap operation
        void up_heap(int i);
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        //Binary tree (Complete Binary tree) can be represented in vector form and hence, stored in a vector. 
        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}
        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}
        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}
        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i)
{
    if(size <= 1) return;
    bool swapped = true;
    while(swapped && left_child(i) <= size)
    {
        int left = left_child(i);
    
        if(right_child(i) <= size && elements[right_child(i)] < elements[left] && elements[right_child(i)] < elements[i])
        {
            swap(right_child(i), i);
            i = right_child(i);
            swapped = true;
        }
        else if(elements[left] < elements[i])
        {
            swap(left, i);
            i = left;
            swapped = true;
        }
        else
        {
            swapped = false;
        }
    }
    
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i)
{
    while(elements[i] < elements[parent(i)])
    {
        swap(parent(i), i);
        i = parent(i);
    }
}
#endif