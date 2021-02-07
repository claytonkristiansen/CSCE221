#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

template<typename T>
class Collection
{
private:
    T* m_array;
    size_t m_size;
    size_t m_capacity;
public:
    Collection();
    Collection(size_t capacity);
    Collection(Collection<T> &o);
    ~Collection();

    Collection<T> &operator=(Collection<T> &o)
    {
        m_size = o.m_size;
        m_capacity = o.m_capacity;
        m_array = o.m_array;
    }

    Collection(Collection<T>&& o)
    {
        m_size = o.m_size;
        m_capacity = o.m_capacity;
        m_array = o.m_array;
        o.m_size = 0;
        o.m_capacity = 0;
        o.m_array = nullptr;
    }
};

template<typename T>
Collection<T>::Collection()
{
    m_size = 0;
    m_capacity = 0;
    m_array = nullptr;
}

template<typename T>
Collection<T>::Collection(const size_t capacity)
{
    m_size = 0;
    m_capacity = capacity;
    m_array = new T[capacity];
}

template<typename T>
Collection<T>::Collection(Collection<T> &o)
{
    m_size = o.m_size;
    m_capacity = o.m_capacity;
    m_array = o.m_array;
}

template<typename T>
Collection<T>::~Collection()
{
    m_size = 0;
    m_capacity = 0;
    delete [] m_array;
    m_array = nullptr;
}


#endif 