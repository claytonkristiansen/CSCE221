#ifndef _TESTABLES__H
#define _TESTABLES__H

#include <vector>

/*
 * Testing Activity
 * ================
 *
 * Three functions which operate on vectors have been provided. There are two sorting function
 * which sort an arrays of integers. There is also a function which takes the product of all elements in
 * a vector. Each function may or may not contain bugs. Your job is to test these functions as 
 * individual units and answer the following questions for each algorithm.
 *
 * 1. Yes or no: is the implementation correct?
 * 2. If it is incorrect, in what cases does it fail?
 *
 * NOTE: You DON'T have to fix any issues you encounter. Just take note of them.
 *
 * Create a separate file called "test_driver.cpp". Then, try various inputs to the function.
 *
 * Test each function for evidence that it succeeds or fails. Tips:
 *
 * - Start by testing a few inputs which demonstrate the work you expected the function to do. (E.g. the normal behavior)
 * - After you're confident it is "generally correct" test the plausible edge cases. What happens when you have an empty collection? How about a null pointer?
 *
 * The functions are documented below. Please test them according to their documented usage. That is, don't test beyond the validity of the assumptions in
 * the documentation comments.
 */

/*
 * Example & Starter Code:
 * Here is an example test. There may be more clever ways to test this code. But 
 * make sure not to duplicate the code you're testing.
 *
 * =============================================================================
  std::ostream & operator<<(std::ostream & stream, const std::vector<int> & v) {
    for (size_t i = 0; i < v.size(); ++i)
      stream << v[i] << (i != v.size() - 1 ? " " : "");

    return stream;
  }

  int main(int argc, char *argv[]) {
    {
      std::vector<int> a = {8, 7, 6};

      if(vec_product(a) != 335)
        std::cout << "FAIL: vec_product(" << a << ")" << std::endl;
    }  

    return 0;
  }
* ===============================================================================
*/


/*
 * Insertion sort: Sorts a vector of integers using the insertion sort algorithm.
 * 
 * 
 * Parameters:
 * a: vector of less than 1000 integers
 */
void insertion_sort(std::vector<int> & a);

/*
 * Selection sort: Sorts a vector of integers using the selection sort algorithm.
 * 
 * Parameters:
 * a: vector of less than 1000 integers
 */
void selection_sort(std::vector<int> & a);

/*
 * Array product: Calculates the product of vector. Does not modify it.
 *
 * Return value: Calculates the product in the form (a[0] * a[1] * a[2] ...). If the array is empty, it returns one.
 * 
 * Parameters:
 * a: vector of less than 10 integers, integers must be small (e.g. in the range [-78, 78])
 */
long vec_product(const std::vector<int> & a);

#endif
