#include <iostream>
#define num_elements 10 //Define the size of the array

using namespace std;

class BinarySearch
{
public:
  void binary_search(int *array, int value, int min, int max, int index);
};

//Recursive binary search
void BinarySearch::binary_search(int* array, int value, int min, int max, int index)
{
  index = min + (max - min)/2;
  if (array[index] == value){
    cout << "The value is at index " << index << endl;
    return;
  }
  else if (min == index){
    cout << "The value isn't in the array" << endl;
    return;
  }
  else if (array[index] > value)
  {
    binary_search(array, value, min, index, index); //call function with midpoint as max
  }
  else if (array[index] < value)
  {
    binary_search(array, value, index, max, index); //call function with midpoint as min
  }
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
  cout << "Enter the value you want to find" << endl;
  cin >> value;

  int start = 0;
  int end = num_elements;
  int midpoint = 0;

  BinarySearch b;
  b.binary_search(test_array, value, start, end, midpoint);

  //Deallocate memory
  delete [] test_array;

}
