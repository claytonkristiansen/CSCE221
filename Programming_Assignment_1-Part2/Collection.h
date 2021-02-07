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
    T* m_list;
    size_t m_size;
    size_t m_capacity;
public:
    Collection<T>();
    Collection<T>(size_t capacity);
    ~Collection();
};

template<typename T>
Collection<T>::Collection()
{

}

template<typename T>
Collection<T>::Collection(size_t capacity)
{
    m_capacity = capacity;
}

template<typename T>
Collection<T>::~Collection()
{
}


#endif 