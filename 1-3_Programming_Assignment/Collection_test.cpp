/**
* DO NOT MODIFY THIS FILE
* DO NOT UPLOAD THIS FILE TO MIMIR
* THIS FILE CALLS TESTING FUNCTIONS OF Stress_ball and Jeans
*/
#include <iostream>
#include "Stress_ball_test.h"
#include "Jeans_test.h"
using namespace std;

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

int main() 
{   
    test_stress_balls();
    test_jeans();

    // Jeans jeans_1 = Jeans(Jeans_colors::grey, Jeans_sizes::xlarge);
    // Jeans jeans_2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
    // Jeans jeans_3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
    // Jeans jeans_4 = Jeans(Jeans_colors::black, Jeans_sizes::medium);
    // CollectionJN collection;

    // collection.insert_item(jeans_1);
    // collection.insert_item(jeans_1);
    // collection.insert_item(jeans_1);
    // collection.insert_item(jeans_1);
    // collection.insert_item(jeans_2);
    // collection.insert_item(jeans_1);
    // collection.insert_item(jeans_2);
    // collection.insert_item(jeans_2);

    // std::cout << collection.total_items(Jeans_sizes::xlarge) << "\n\n\n";


    return 0; 
} 