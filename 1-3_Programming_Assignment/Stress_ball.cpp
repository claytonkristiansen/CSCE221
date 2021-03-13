#include "Stress_ball.h"


Stress_ball::Stress_ball()
{
    srand(time(NULL));
    color = (Stress_ball_colors)(rand() % 4);
    size = (Stress_ball_sizes)(rand() % 4);
}

Stress_ball::Stress_ball(Stress_ball_colors ocolor, Stress_ball_sizes osize)
    : color(ocolor), size(osize) {}

Stress_ball_colors Stress_ball::get_color() const { return color; }

Stress_ball_sizes Stress_ball::get_size() const { return size; }

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