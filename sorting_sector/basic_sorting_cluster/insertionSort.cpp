#include <iostream>

void printArray(const int *arrayToPrint, int arraySize)
{
  for (int i = 0; i < arraySize; ++i)
  {
    std::cout << arrayToPrint[i] << " ";
  }
  std::cout << std::endl;
}

void swapValuesInArrayByIndex(int *originalArray, int firstValuePosition, int secondValuePosition)
{
  int temporalStorageForValue;
  temporalStorageForValue = originalArray[firstValuePosition];
  originalArray[firstValuePosition] = originalArray[secondValuePosition];
  originalArray[secondValuePosition] = temporalStorageForValue;
}

int *setValueOnCorrectPosition(int *array, int arraySize)
{
  int *workingArray = array;
  for (int currentElementIndex = 1; currentElementIndex < arraySize; ++currentElementIndex)
  {
    if (workingArray[currentElementIndex] < workingArray[currentElementIndex - 1])
    {
      swapValuesInArrayByIndex(workingArray, currentElementIndex, currentElementIndex - 1);
      setValueOnCorrectPosition(workingArray, arraySize);
    }
  }
  return workingArray;
}

int *insertionSortArrayAsc(const int *unsortedArray, int arraySize)
{
  int *sortedArray = new int[arraySize];
  std::copy(unsortedArray, unsortedArray + arraySize, sortedArray);

  sortedArray = setValueOnCorrectPosition(sortedArray, arraySize);
  return sortedArray;
}

int main()
{
  const int primaryArraySize = 11;
  int unsortedArray[primaryArraySize] = {179, 15, 5, 354, 9, 4, 0, -6, 0, 1, 1};

  std::cout << "UNSORTED ARRAY : " << std ::endl;
  printArray(unsortedArray, primaryArraySize);

  int *sortedArray = insertionSortArrayAsc(unsortedArray, primaryArraySize);
  std::cout << "SORTED ARRAY : " << std ::endl;
  printArray(sortedArray, primaryArraySize);

  return 0;
}