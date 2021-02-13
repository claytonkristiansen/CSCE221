#include "Collection.h"



void Collection::resize()
{
    if (capacity == 0)
    {
        array = new Stress_ball();
        size = 0;
        capacity = 1;
        return;
    }
    capacity *= 2;
    Stress_ball *newArr = new Stress_ball[capacity];
    for (int i = 0; i < size; ++i)
    {
        newArr[i] = array[i];
    }
    delete[] array;
    array = newArr;
    newArr = nullptr;
}

// void Collection::Remove(int index)
// {
//     //print_items();
//     //std::cout << "\n\n";
//     Stress_ball *newArr = new Stress_ball[capacity];
//     for (int i = 0, k = 0; i < size; ++i)
//     {
//         if (i != index)
//         {
//             newArr[k] = array[i];
//             //std::cout << newArr[k] << "\n";
//             ++k;
//         }
//     }
//     --size;
//     delete[] array;
//     array = newArr;
//     newArr = nullptr;
// }

//template<typename T>
Collection::Collection() //Default Constructor
{
    size = 0;
    capacity = 0;
    array = nullptr;
}

//template<typename T>
Collection::Collection(int cap) //Size Constructor
{
    size = 0;
    capacity = cap;
    array = new Stress_ball[capacity];
}

//template<typename T>
Collection::Collection(const Collection &o) //Copy Constructor
{
    size = o.size;
    capacity = o.capacity;
    array = new Stress_ball[capacity];
    for(int i = 0; i < size; ++i)
    {
        array[i] = o.array[i];
    }
}

//template<typename T>
Collection::Collection(Collection &&o) //Move Constructor
{
    size = o.size;
    capacity = o.capacity;
    array = o.array;
    o.size = 0;
    o.capacity = 0;
    o.array = nullptr;
}

//template<typename T>
Collection::~Collection() //Destructor
{
    size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}

//template<typename T>
Collection &Collection::operator=(const Collection &o) //Copy Assignment
{
    size = o.size;
    capacity = o.capacity;
    array = new Stress_ball[capacity];
    for(int i = 0; i < size; ++i)
    {
        array[i] = o.array[i];
    }
    return *this;
}

//template<typename T>
Collection &Collection::operator=(Collection &&o) //Move Assignment
{
    size = o.size;
    capacity = o.capacity;
    array = o.array;
    o.size = 0;
    o.capacity = 0;
    o.array = nullptr;
    return *this;
}

Stress_ball &Collection::operator[](int i)
{
    return array[i];
}

const Stress_ball &Collection::operator[](int i) const
{
    return array[i];
}


//template<typename T>
void Collection::insert_item(const Stress_ball &sb)
{
    if (size >= capacity)
    {
        resize();
    }
    array[size++] = sb;
}

bool Collection::contains(const Stress_ball &sb) const
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

Stress_ball Collection::remove_any_item() //
{
    if (size == 0)
    {
        throw std::exception();
    }
    std::srand(time(0));
    int index = std::rand() % size;
    Stress_ball out = array[index];
    
    Stress_ball *newArr = new Stress_ball[capacity];
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

void Collection::remove_this_item(const Stress_ball &sb) //
{
    if (size == 0)
    {
        throw std::exception();
    }
    for (int index = 0; index < size; ++index)
    {
        if (array[index] == sb)
        {
            Stress_ball *newArr = new Stress_ball[capacity];
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

void Collection::make_empty() //
{
    size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}

bool Collection::is_empty() const //
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

int Collection::total_items() const //
{
    return size;
}

int Collection::total_items(Stress_ball_sizes s) const //
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

int Collection::total_items(Stress_ball_colors c) const //
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

void Collection::print_items() const //
{
    for (int i = 0; i < size; ++i)
    {
        std::string sizeText, colorText = "";
        switch (array[i].get_size())
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

        switch (array[i].get_color())
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
        std::cout << "(" << colorText << ", " << sizeText << ")\n";
    }
}

istream &operator>>(istream &is, Collection &c)
{
    while (!is.eof())
    {
        string colorStr, sizeStr = "";
        Stress_ball_colors color;
        Stress_ball_sizes size;
        is >> colorStr;
        is >> sizeStr;
        if (colorStr == "red")
            color = Stress_ball_colors::red;
        else if (colorStr == "blue")
            color = Stress_ball_colors::blue;
        else if (colorStr == "yellow")
            color = Stress_ball_colors::yellow;
        else if (colorStr == "green")
            color = Stress_ball_colors::green;

        if (sizeStr == "small")
            size = Stress_ball_sizes::small;
        if (sizeStr == "medium")
            size = Stress_ball_sizes::medium;
        if (sizeStr == "large")
            size = Stress_ball_sizes::large;

        c.insert_item(Stress_ball(color, size));
    }

    return is;
}

ostream &operator<<(ostream &os, const Collection &c)
{
    for (int i = 0; i < c.total_items(); ++i)
    {
        std::string sizeText, colorText = "";
        switch (c[i].get_size())
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

        switch (c[i].get_color())
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
        os << "(" << colorText << ", " << sizeText << ")\n";
    }
    return os;
}

Collection make_union(const Collection &c1, const Collection &c2)
{
    Collection newColl(c1.total_items() + c2.total_items());
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

void swap(Collection &c1, Collection &c2)
{
    Collection temp = std::move(c1);
    c1 = std::move(c2);
    c2 = std::move(temp);
}

void sort_by_size(Collection &c, Sort_choice sort)
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
                    Stress_ball temp = c[i];
                    c[i] = c[i + 1];
                    c[i + 1] = temp;
                    swapped = true;
                }
            }
        }
    }
}