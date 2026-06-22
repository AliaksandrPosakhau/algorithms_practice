#include <iostream>

void printArray(const int *arrayToPrint, int arraySize)
{
  for (int i = 0; i < arraySize; ++i)
  {
    std::cout << arrayToPrint[i] << " ";
  }
  std::cout << std::endl;
}

int *bubbleSortArrayAsc(int *originalArray, int originalArraySize)
{
  int *sortedArray = originalArray;
  int temporalVariableStorage;

  for (int i = 0; i < originalArraySize - 1; ++i)
  {
    if (sortedArray[i] > sortedArray[i + 1])
    {
      temporalVariableStorage = sortedArray[i];
      sortedArray[i] = sortedArray[i + 1];
      sortedArray[i + 1] = temporalVariableStorage;
      bubbleSortArrayAsc(sortedArray, originalArraySize);
    }
  }

  return sortedArray;
}

int main()
{
  int unsortedArray[10] = {5, 15, 150, 18, 96, 0, 1, 1, 8, 3};
  std::cout << "ORIGINAL ARRAY : " << std::endl;
  printArray(unsortedArray, 10);

  int *sortedArray = bubbleSortArrayAsc(unsortedArray, 10);
  std::cout << "SORTED ARRAY : " << std::endl;
  printArray(sortedArray, 10);
  return 0;
}

/**
// REVISION NOTES:
1. Avoid Modifying the Original Array

int *sortedArray = new int[originalArraySize];
std::copy(originalArray, originalArray + originalArraySize, sortedArray);


2. Optimize the Algorithm
you can optimize it slightly by adding a flag to detect if the array is already sorted:

 bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < originalArraySize - 1; ++i) {
            if (sortedArray[i] > sortedArray[i + 1]) {
                temporalVariableStorage = sortedArray[i];
                sortedArray[i] = sortedArray[i + 1];
                sortedArray[i + 1] = temporalVariableStorage;
                swapped = true;
            }
        }
    } while (swapped);

    return sortedArray;

 3. If you use new to allocate memory for the sorted array, ensure you delete the memory after use to avoid memory leaks:
    delete[] sortedArray;

*/
