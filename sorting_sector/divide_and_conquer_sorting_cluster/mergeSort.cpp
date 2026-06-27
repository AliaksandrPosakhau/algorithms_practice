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

// merging two arrays with sorting of elements of them of variable value
int *mergeTwoArraysWithSorting(int *firstArray, int sizeOfFirstArray, int *secondArray, int sizeOfSecondArray)
{
  int sizeOfSummaryArray = sizeOfFirstArray + sizeOfSecondArray;
  int *summaryArray = new int[sizeOfSummaryArray];

  int i = 0, j = 0, k = 0;

  while (i < sizeOfFirstArray && j < sizeOfSecondArray)
  {
    if (firstArray[i] <= secondArray[j])
    {
      summaryArray[k] = firstArray[i];
      i++;
    }
    else
    {
      summaryArray[k] = secondArray[j];
      j++;
    }
    k++;
  }

  while (i < sizeOfFirstArray)
  {
    summaryArray[k] = firstArray[i];
    i++;
    k++;
  }

  while (j < sizeOfSecondArray)
  {
    summaryArray[k] = secondArray[j];
    j++;
    k++;
  }

  return summaryArray;
}

int *mergeSortArrayAsc(int *unsortedArray, int arraySize)
{
  int *sortedArray = new int[arraySize];
  std::copy(unsortedArray, unsortedArray + arraySize, sortedArray);

  if (arraySize == 2)
  {
    if (sortedArray[0] > sortedArray[1])
    {
      swapValuesInArrayByIndex(sortedArray, 0, 1);
    }
  }
  else if (arraySize == 1)
  {
    return sortedArray;
  }
  else
  {
    int middlePont = arraySize / 2;
    int leftArraySize = middlePont;
    int rightArraySize = arraySize - middlePont;

    int *leftPartSubArray = new int[leftArraySize];
    int *rightPartSubArray = new int[rightArraySize];

    for (int i = 0; i < leftArraySize; ++i)
    {
      std::cout << "COPPYING ELEMENT " << unsortedArray[i] << " WITH POSITION : " << i << std::endl;
      leftPartSubArray[i] = unsortedArray[i];
    }

    int rightArrayInitialPosition = 0;
    for (int j = middlePont; j < arraySize; ++j)
    {

      std::cout << "COPPYING ELEMENT " << unsortedArray[j] << " WITH POSITION : " << j << std::endl;
      rightPartSubArray[rightArrayInitialPosition] = unsortedArray[j];
      ++rightArrayInitialPosition;
    }

    std::cout << "LEFT ARRAY SIZE : " << leftArraySize << std::endl;
    std::cout << "RIGHT ARRAY SIZE : " << rightArraySize << std::endl;
    std::cout << "MIDDLE POINT : " << middlePont << std::endl;
    printArray(leftPartSubArray, leftArraySize);
    printArray(rightPartSubArray, rightArraySize);

    int *sortedLeft = mergeSortArrayAsc(leftPartSubArray, leftArraySize);
    int *sortedRight = mergeSortArrayAsc(rightPartSubArray, rightArraySize);

    sortedArray = mergeTwoArraysWithSorting(sortedLeft, leftArraySize, sortedRight, rightArraySize);
  }
  return sortedArray;
}

int main()
{

  const int primaryArraySize = 11;
  int unsortedArray[primaryArraySize] = {179, 15, 5, 354, 9, 4, 0, -6, 0, 1, -786};

  std::cout << "UNSORTED ARRAY : " << std ::endl;
  printArray(unsortedArray, primaryArraySize);

  int *sortedArray = mergeSortArrayAsc(unsortedArray, primaryArraySize);
  std::cout << "SORTED ARRAY : " << std ::endl;
  printArray(sortedArray, primaryArraySize);

  return 0;
}