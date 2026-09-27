#include <iostream>
#include <vector>
#include <algorithm>

class Bucket {

  std::vector<int> BucketValuesHandlerVector; 
  
  void addValue(int value) {
    BucketValuesHandlerVector.push_back(value);
  }

  void sort() {  
    std::sort(BucketValuesHandlerVector.begin(), BucketValuesHandlerVector.end());
  }

};

void printArray(const int *arrayToPrint, int arraySize)
{
  for (int i = 0; i < arraySize; ++i)
  {
    std::cout << arrayToPrint[i] << " ";
  }
  std::cout << std::endl;
}

void swapValues(int *a, int *b) {
    int temporaryElement = *a;  
    *a = *b;                    
    *b = temporaryElement;      
}


int getArrayMinimum(int *array, int arraySize)
{
  int currentMinimum = array[0];

  for (int i = 0; i < arraySize; ++i)
  {
    if (array[i] < currentMinimum)
    {
      currentMinimum = array[i];
    }
  }

  return currentMinimum;
}

int getArrayMaximum(int *array, int arraySize)
{
  int currentMaximum = array[0];

  for (int i = 0; i < arraySize; ++i)
  {
    if (array[i] > currentMaximum)
    {
      currentMaximum = array[i];
    }
  }

  return currentMaximum;
}

int *bucketSortArrayAsc (int *unsortedArray, int size) {
    int* sortedArray = new int[size];
    sortedArray = unsortedArray;

    if (size=1) {
      return sortedArray;
    } else if (size==2) {
        if (sortedArray[0]>sortedArray[1]) {
          swapValues(&sortedArray[0],&sortedArray[1]);
        } 
        return sortedArray;
    }

    std::vector<Bucket> BucketsVector;

    int valuesRange = getArrayMaximum(sortedArray, size) - getArrayMinimum(sortedArray, size);

    
    
    return sortedArray;
}

int main() {

    return 0;
}