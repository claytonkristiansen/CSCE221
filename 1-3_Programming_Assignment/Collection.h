/**
 * There is no Collection.cpp for this assignment.
 * Move all the functions from Collection.cpp to this file except Operator>> 
 * Covert the Collection class to a templated form. (Stress_ball should be replaced with typename "Obj".
 *   Stress_ball_colors and Stress_ball_sizes should be replaced with typename "F2").
 * This file has to be uploaded to mimir.
 */

#ifndef Collection_H
#define Collection_H
#include <string>
#include <iostream>
#include "Stress_ball.h"
#include "Jeans.h"

using namespace std;

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

class Empty_Collection{};

inline std::string EnumToString(Stress_ball_colors color)
{
    std::string colorText = "";
    switch(color)
    {
    case Stress_ball_colors::red:
        colorText = "red";
        break;
    case Stress_ball_colors::blue:
        colorText = "blue";
        break;
    case Stress_ball_colors::green:
        colorText = "green";
        break;
    case Stress_ball_colors::yellow:
        colorText = "yellow";
        break;
    }
    return colorText;
}

inline std::string EnumToString(Stress_ball_sizes size)
{
    std::string sizeText = "";
    switch(size)
    {
    case Stress_ball_sizes::small:
        sizeText = "small";
        break;
    case Stress_ball_sizes::medium:
        sizeText = "medium";
        break;
    case Stress_ball_sizes::large:
        sizeText = "large";
        break;
    }
    return sizeText;
}

inline std::string EnumToString(Jeans_colors color)
{
    std::string colorText = "";
    switch(color)
    {
    case Jeans_colors::white:
        colorText = "white";
        break;
    case Jeans_colors::black:
        colorText = "black";
        break;
    case Jeans_colors::blue:
        colorText = "blue";
        break;
    case Jeans_colors::grey:
        colorText = "grey";
        break;
    }
    return colorText;
}

inline std::string EnumToString(Jeans_sizes size)
{
    std::string sizeText = "";
    switch(size)
    {
    case Jeans_sizes::small:
        sizeText = "small";
        break;
    case Jeans_sizes::medium:
        sizeText = "medium";
        break;
    case Jeans_sizes::large:
        sizeText = "large";
        break;
    case Jeans_sizes::xlarge:
        sizeText = "xlarge";
        break;
    }
    return sizeText;
}

//your code...
//Templated class collection
//Methods from Collection.cpp


template<typename T, typename F1, typename F2>
class Collection
{
    T* array;
    int size;
    int capacity;

    

public:
    void resize()
    {
        if (capacity == 0)
        {
            array = new T();
            size = 0;
            capacity = 1;
            return;
        }
        capacity *= 2;
        T *newArr = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            newArr[i] = array[i];
        }
        delete[] array;
        array = newArr;
        newArr = nullptr;
    }

    //template<typename T>
    Collection() //Default Constructor
    {
        size = 0;
        capacity = 0;
        array = nullptr;
    }

    //template<typename T>
    Collection(int cap) //Size Constructor
    {
        size = 0;
        capacity = cap;
        array = new T[capacity];
    }

    //template<typename T>
    Collection(const Collection &o) //Copy Constructor
    {
        size = o.size;
        capacity = o.capacity;
        array = new T[capacity];
        for(int i = 0; i < size; ++i)
        {
            array[i] = o.array[i];
        }
    }

    //template<typename T>
    Collection(Collection &&o) //Move Constructor
    {
        size = o.size;
        capacity = o.capacity;
        array = o.array;
        o.size = 0;
        o.capacity = 0;
        o.array = nullptr;
    }

    //template<typename T>
    ~Collection() //Destructor
    {
        size = 0;
        capacity = 0;
        delete[] array;
        array = nullptr;
    }

    //template<typename T>
    Collection &operator=(const Collection &o) //Copy Assignment
    {
        size = o.size;
        capacity = o.capacity;
        array = new T[capacity];
        for(int i = 0; i < size; ++i)
        {
            array[i] = o.array[i];
        }
        return *this;
    }

    //template<typename T>
    Collection &operator=(Collection &&o) //Move Assignment
    {
        size = o.size;
        capacity = o.capacity;
        array = o.array;
        o.size = 0;
        o.capacity = 0;
        o.array = nullptr;
        return *this;
    }

    T &operator[](int i)
    {
        return array[i];
    }

    const T &operator[](int i) const
    {
        return array[i];
    }


    //template<typename T>
    void insert_item(const T &sb)
    {
        if (size >= capacity)
        {
            resize();
        }
        array[size++] = sb;
    }

    bool contains(const T &sb) const
    {
        for (int i = 0; i < size; ++i)
        {
            if (array[i] == sb)
            {
                return true;
            }
        }
        return false;
    }

    T remove_any_item() //
    {
        if (size == 0)
        {
            throw std::exception();
        }
        std::srand(time(0));
        int index = std::rand() % size;
        T out = array[index];
        
        T *newArr = new T[capacity];
        for (int i = 0, k = 0; i < size; ++i)
        {
            if (i != index)
            {
                newArr[k] = array[i];
                //std::cout << newArr[k] << "\n";
                ++k;
            }
        }
        --size;
        delete[] array;
        array = newArr;
        newArr = nullptr;
        
        return out;
    }

    void remove_this_item(const T &sb) //
    {
        if (size == 0)
        {
            throw std::exception();
        }
        for (int index = 0; index < size; ++index)
        {
            if (array[index] == sb)
            {
                T *newArr = new T[capacity];
                for (int i = 0, k = 0; i < size; ++i)
                {
                    if (i != index)
                    {
                        newArr[k] = array[i];
                        //std::cout << newArr[k] << "\n";
                        ++k;
                    }
                }
                --size;
                delete[] array;
                array = newArr;
                newArr = nullptr;
                return;
            }
        }
    }

    void make_empty() //
    {
        size = 0;
        capacity = 0;
        delete[] array;
        array = nullptr;
    }

    bool is_empty() const //
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

    int total_items() const //
    {
        return size;
    }

    int total_items(F2 s) const //
    {
        int count = 0;
        for (int i = 0; i < size; ++i)
        {
            if (array[i].get_size() == s)
            {
                ++count;
            }
        }
        return count;
    }

    int total_items(F1 c) const //
    {
        int count = 0;
        for (int i = 0; i < size; ++i)
        {
            if (array[i].get_color() == c)
            {
                ++count;
            }
        }
        return count;
    }

    void print_items() const //
    {
        for (int i = 0; i < size; ++i)
        {
            std::string sizeText = EnumToString(array[i].get_size());
            std::string colorText = EnumToString(array[i].get_color());
            
            std::cout << "(" << colorText << ", " << sizeText << ")\n";
        }
    }
};


template<typename T, class F1, class F2>
inline ostream &operator<<(ostream &os, const Collection<T, F1, F2> &c)
{
    for (int i = 0; i < c.total_items(); ++i)
    {
        std::string sizeText = EnumToString(c[i].get_size());
        std::string colorText = EnumToString(c[i].get_color());

        os << "(" << colorText << ", " << sizeText << ")\n";
    }
    return os;
}

template<typename T, class F1, class F2>
inline Collection<T, F1, F2> make_union(const Collection<T, F1, F2> &c1, const Collection<T, F1, F2> &c2)
{
    Collection<T, F1, F2> newColl(c1.total_items() + c2.total_items());
    for (int i = 0; i < c1.total_items(); ++i)
    {
        newColl.insert_item(c1[i]);
    }
    for (int i = 0; i < c2.total_items(); ++i)
    {
        newColl.insert_item(c2[i]);
    }
    return newColl;
}

template<typename T, class F1, class F2>
inline void swap(Collection<T, F1, F2> &c1, Collection<T, F1, F2> &c2)
{
    Collection<T, F1, F2> temp = std::move(c1);
    c1 = std::move(c2);
    c2 = std::move(temp);
}

template<typename T, class F1, class F2>
inline void sort_by_size(Collection<T, F1, F2> &c, Sort_choice sort)
{
    if (true /*sort == Sort_choice::bubble_sort*/)
    {
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            for (int i = 0; i < c.total_items() - 1; ++i)
            {
                if (c[i].get_size() > c[i + 1].get_size())
                {
                    T temp = c[i];
                    c[i] = c[i + 1];
                    c[i + 1] = temp;
                    swapped = true;
                }
            }
        }
    }
}



#endif