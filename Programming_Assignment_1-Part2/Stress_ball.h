#ifndef STRESS_BALL_H
#define STRESS_BALL_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

enum Stress_ball_colors {red, blue, yellow, green};
enum Stress_ball_sizes {small = 4, medium, large};

class Stress_ball
{
    Stress_ball_colors m_color;
    Stress_ball_sizes  m_size;
public:
    Stress_ball()
    {
        srand(time(NULL));
        m_color = (Stress_ball_colors)(rand() % 4);
        m_size = (Stress_ball_sizes)(rand() % 3 + 4);
    }

    Stress_ball(Stress_ball_colors color, Stress_ball_sizes size) 
        :   m_color(color), m_size(size) {}
    
    Stress_ball_colors get_color() const { return m_color; }

    Stress_ball_sizes get_size() const { return m_size; }

    std::string get_color_text() const 
    { 
        switch(m_color)
        {
        case red:
            return "red";
            break;
        case blue:
            return "blue";
            break;
        case yellow:
            return "yellow";
            break;
        case green:
            return "green";
            break;
        }
        return "ERROR"; 
    }

    std::string get_size_text() const
    {
        switch(m_size)
        {
        case small:
            return "small";
            break;
        case medium:
            return "medium";
            break;
        case large:
            return "large";
            break;
        }
        return "ERROR";
    }
    
    bool operator==(const Stress_ball& sb)
    {
        if(sb.m_color == this->m_color && sb.m_size == this->m_size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb)
{
    o << "(" << sb.get_color_text() << ", " << sb.get_size_text() << ")";
    return o;
}

// int main()
// {
//     Stress_ball testBall;

//     Stress_ball testBall0(red, small);
//     Stress_ball testBall1(red, small);

//     std::cout << "Random: " << testBall << std::endl;
//     std::cout << std::endl << testBall0 << std::endl << testBall1 << std::endl << "Equal: " << (testBall0 == testBall1) << std::endl;
// }

#endif