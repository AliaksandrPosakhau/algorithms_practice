#include <iostream>

void printArray(const int *arrayToPrint, int arraySize)
{
  for (int i = 0; i < arraySize; ++i)
  {
    std::cout << arrayToPrint[i] << " ";
  }
  std::cout << std::endl;
}

int getMinimumInSegment(int *originalArray, int startPosition, int arraySize)
{
  int arrayMinimumValue = originalArray[startPosition];
  for (int i = startPosition; i < arraySize; i++)
  {
    if (originalArray[i] < arrayMinimumValue)
    {
      arrayMinimumValue = originalArray[i];
    }
  }
  return arrayMinimumValue;
}

int *selectionSortArrayAsc(int *originalArray, int arraySize)
{
  int *sortedArray = new int[arraySize];
  int *workingArray = new int[arraySize];
  std::copy(originalArray, originalArray + arraySize, workingArray);

  int minimumSegmentumValue;
  int valueTemporalStorage;

  for (int i = 0; i < arraySize; ++i)
  {
    minimumSegmentumValue = getMinimumInSegment(workingArray, i, arraySize);
    std::cout << "ITERATION " << i << " MINIMUM SEGMENTUM VALUE : " << minimumSegmentumValue << std::endl;

    for (int j = i; j < arraySize; ++j)
    {
      if (workingArray[j] == minimumSegmentumValue)
      {
        valueTemporalStorage = workingArray[i];
        workingArray[i] = minimumSegmentumValue;
        workingArray[j] = valueTemporalStorage;
      }
    }
    sortedArray[i] = workingArray[i];
  }

  return sortedArray;
}

int main()
{
  int unsortedArray[10] = {5, 18, 5, 3, 7, 17, 18, 0, 10, -8};
  int *sortedArray = selectionSortArrayAsc(unsortedArray, 10);

  std::cout << "UNSORTED ARRAY : " << std ::endl;
  printArray(unsortedArray, 10);

  std::cout << "SORTED ARRAY : " << std ::endl;
  printArray(sortedArray, 10);

  return 0;
}
