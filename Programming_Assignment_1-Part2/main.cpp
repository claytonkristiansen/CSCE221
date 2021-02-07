#include "Collection.h"
#include "Stress_ball.h"

int main()
{
    Collection<int> test(10);
    Collection<int> test2(std::move(test));
    return 0;
}