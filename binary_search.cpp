#include <iostream>
#define num_elements 10 //Define the size of the array

using namespace std;

class BinarySearch{
public:
  int binary_search(int *array, int value);
};

/* Implementation of binary search */
int BinarySearch::binary_search(int *array, int value)
{
  int max = num_elements - 1;
  int min = 0;
  int midpoint;
  while (min <= max)
  {
    midpoint = min + (max - min)/2; //This is necessary to ensure that the search doesn't overflow at 2^31-1
    if (array[midpoint] == value)
    {
      return midpoint;
    }
    else if (value > array[midpoint])
    {
      min = midpoint + 1;
    }
    else if (value < array[midpoint])
    {
      max = midpoint - 1;
    }
  }
  return -1;
}

int main()
{
  /* TEST ARRAY */
  int* test_array = new int[num_elements];
  for (int i = 0; i < 5; ++i)
  {
    test_array[i] = i;
  }

  for (int j = 5; j < 10; ++j)
  {
    test_array[j] = j  * 2;
  }

  int value;
  cout << "Enter the value you would like to find" << endl;
  cin >> value;

  BinarySearch b;
  int index = b.binary_search(test_array, value);

  if (index == -1)
  {
    cout << "The value wasn't in the array" << endl;
  }
  else
  {
    cout << "Found at index "  <<  index << endl;
  }

  //Deallocate memory
  delete [] test_array;
}
