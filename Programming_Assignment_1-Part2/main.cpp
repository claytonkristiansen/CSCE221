#include "Collection.h"
#include <fstream>


using std::string;
using std::cout;

int main()
{
    Collection c1;
    Collection c2;

    std::ifstream fileIn;
    fileIn.open("testdata.txt");

    fileIn >> c1;
    sort_by_size(c1, Sort_choice::bubble_sort);

    c2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
    c2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
    c2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
    c2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));

    //swap(c1, c2);

    std::cout << c1 << "\n\n";
    c1.remove_this_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
    std::cout << c1 << "\n\n";
    std::cout << c1.contains(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small)) << "\n";
    cout << c1.total_items() << "\n";
    cout << c1.total_items(Stress_ball_colors::red) << "\n";
    //std::cout << c2;
    //std::cout << make_union(c1, c2);



    return 0;
}