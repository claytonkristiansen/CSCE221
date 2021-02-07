


// sorting items from the heaviest to lightest
// by selecting the heaviest item at each time  

#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

ostream& operator<<(ostream& out, vector<int>& v)
{
  for(int i = 0; i < v.size(); ++i)
  {
    if(i == v.size() - 1)
    {
      out << v[i];
      break;
    }
    out << v[i] << ", ";
  }
  return out;
}

void sort_heaviest(vector<int>& v)
{  
  vector<int> sorted;
  for(int i = 0; i < v.size(); ++i)
  {
    sorted.push_back(v[i]);
  }
  v.erase(v.begin(), v.end());

  
  while(sorted.size() > 0)
  {
    int heaviest = sorted[0];
    int heaviestDex = 0;
    for(int i = 1; i < sorted.size(); ++i)
    {
      if(sorted[i] > heaviest)
      {
        heaviest = sorted[i];
        heaviestDex = i;
        comparisons++;
      }
      else
      {
        comparisons++;
      }
    }
    v.push_back(heaviest);
    sorted.erase(sorted.begin() + heaviestDex);
  }

  // implement the sorting algorithm based on video
 
}

int main()
{
 
  cout << "//////Test 2 for vector v ///////////////////////////////"<< endl;
  vector<int> v{10,9,8,7,6,5,4,3,2,1};

  cout << "initial vector v:\n";
  // use overloaded output operator to display vector's elements
  // use comma to separate the vector's elements
  std::cout << v;
  cout << endl;
  // call the sorting function for vector v
  sort_heaviest(v); 
  cout << "# of comparisons to sort v: " << comparisons << endl << endl;
  comparisons = 0;
  cout << "vector v after sorting:\n";
  // use overloaded output operator to display elements of sorted vector
  // use comma to separate the vector's elements
  std::cout << v;
  cout << endl;
  
  cout << "//////Test 2 for vector v1 ///////////////////////////////"<< endl;

  vector<int> v1{1,2,3,4,5,6,7,8,9,10};
  cout << "initial vector v1:\n";
  // use overloaded output operator to display vector's elements
  // use comma to separate the vector's elements
  cout << v1;
  cout << endl;
   // call the sorting function for vector v2 
   sort_heaviest(v1);
  cout << "# of comparisons to sort v1: " << comparisons << endl << endl;
  cout << "vector v1 after sorting:\n";
  // use overloaded output operator to display elements of sorted vector
  // use comma to separate the vector's elements
  cout << v1;
  cout << endl;
    
}
