/**
 * In this file, implement the methods from Jeans.h. The implementation is identical to Jeans
 * This file needs to be uploaded to Mimir
 */ 
#include "Jeans.h"

Jeans::Jeans()
{
    srand(time(NULL));
    color = (Jeans_colors)(rand() % 4);
    size = (Jeans_sizes)(rand() % 4);
}

Jeans::Jeans(Jeans_colors ocolor, Jeans_sizes osize)
    : color(ocolor), size(osize) {}

Jeans_colors Jeans::get_color() const { return color; }

Jeans_sizes Jeans::get_size() const { return size; }

bool Jeans::operator==(const Jeans &sb)
{
    if (sb.color == this->color && sb.size == this->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<<(std::ostream& o, const Jeans& sb)
{
    std::string sizeText, colorText = "";
    switch (sb.get_size())
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

    switch (sb.get_color())
    {
    case Jeans_colors::white:
        colorText = "white";
        break;
    case Jeans_colors::blue:
        colorText = "blue";
        break;
    case Jeans_colors::black:
        colorText = "black";
        break;
    case Jeans_colors::grey:
        colorText = "grey";
        break;
    }

    o << "(" << colorText << ", " << sizeText << ")";
    return o;
}