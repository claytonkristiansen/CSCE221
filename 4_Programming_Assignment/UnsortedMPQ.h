#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

using std::vector;

/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ : MPQ<T>
{
    // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
    // To hold the elements use std::vector
    // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.

    vector<T> m_vec;

public:
    // Remove minimum from MPQ and return it
    T remove_min()
    {
        if(this->is_empty())
        {
            throw std::runtime_error(std::string("Empty"));
        }
        T min = m_vec[0];
        int minDex = 0;
        for(int i = 1; i < m_vec.size(); ++i)
        {
            if(m_vec[i] < min)
            {
                min = m_vec[i];
                minDex = i;
            }
        }
        typename vector<T>::iterator it = m_vec.begin();
        for(int i = 0; i < minDex; ++i) {it++;}
        m_vec.erase(it);
        return min;
    }
    // Get the minimum from MPQ
    T min()
    {
        if(this->is_empty())
        {
            throw std::runtime_error(std::string("Empty"));
        }
        T min = m_vec[0];
        for(int i = 1; i < m_vec.size(); ++i)
        {
            if(m_vec[i] < min)
            {
                min = m_vec[i];
            }
        }
        return min;
    }
    // Check if MPQ is empty
    bool is_empty()
    {
        if (m_vec.size() == 0)
            return true;
        return false;
    }
    // Insert into MPQ
    void insert(const T &data)
    {
        m_vec.push_back(data);
    }
};

#endif