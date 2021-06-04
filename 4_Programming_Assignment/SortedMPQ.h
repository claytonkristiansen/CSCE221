#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include <string>
#include "MPQ.h"

using std::list;

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.

    list<T> m_list;
public:
    // Remove minimum from MPQ and return it
    T remove_min()
    {
        if(this->is_empty())
        {
            throw std::runtime_error(std::string("Empty"));
        }
        T min = m_list.front();
        m_list.pop_front();
        return  min;
    }
    // Get the minimum from MPQ
    T min()
    {
        if(this->is_empty())
        {
            throw std::runtime_error(std::string("Empty"));
        }
        T min = m_list.front();
        return  min;
    }
    // Check if MPQ is empty
    bool is_empty()
    {
        if(m_list.size() == 0) return true;
        return false;
    }
    // Insert into MPQ
    void insert(const T& data)
    {
        typename list<T>::iterator it;
        it = m_list.begin();

        if(this->is_empty())
        {
            m_list.push_front(data);
            return;
        }
        
        if(data < *it)
        {
            m_list.push_front(data);
            return;
        }
        while(it != m_list.end())
        {
            it++;
            if(data < *it)
            {
                m_list.insert(it, data);
                return;
            }
            else if(it == m_list.end())
            {
                m_list.push_back(data);
                return;
            }
        }
    }
};

#endif