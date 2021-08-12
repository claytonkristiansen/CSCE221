#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ : MPQ<T>
{
private:
    BinaryHeap<T> m_heap;

public:

    // Remove minimum from MPQ and return it
    T remove_min()
    {
        return m_heap.remove_min();
    }
    // Get the minimum from MPQ
    T min()
    {
        return m_heap.min();
    }
    // Check if MPQ is empty
    bool is_empty()
    {
        return m_heap.is_empty();
    }
    // Insert into MPQ
    void insert(const T& data)
    {
        m_heap.insert(data);
    }
};

#endif