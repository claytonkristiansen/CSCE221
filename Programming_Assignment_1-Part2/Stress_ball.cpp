#include "Stress_ball.h"


Stress_ball::Stress_ball()
{
    srand(time(NULL));
    color = (Stress_ball_colors)(rand() % 4);
    size = (Stress_ball_sizes)(rand() % 3 + 4);
}

Stress_ball::Stress_ball(Stress_ball_colors ocolor, Stress_ball_sizes osize)
    : color(ocolor), size(osize) {}

Stress_ball_colors Stress_ball::get_color() const { return color; }

Stress_ball_sizes Stress_ball::get_size() const { return size; }

// std::string Stress_ball::get_color_text() const
// {
//     switch (color)
//     {
//     case red:
//         return "red";
//         break;
//     case blue:
//         return "blue";
//         break;
//     case yellow:
//         return "yellow";
//         break;
//     case green:
//         return "green";
//         break;
//     }
//     return "ERROR";
// }

// std::string Stress_ball::get_size_text() const
// {
//     switch (size)
//     {
//     case small:
//         return "small";
//         break;
//     case medium:
//         return "medium";
//         break;
//     case large:
//         return "large";
//         break;
//     }
//     return "ERROR";
// }

bool Stress_ball::operator==(const Stress_ball &sb)
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

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb)
{
    std::string sizeText, colorText = "";
    switch (sb.get_size())
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

    switch (sb.get_color())
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

    o << "(" << colorText << ", " << sizeText << ")";
    return o;
}