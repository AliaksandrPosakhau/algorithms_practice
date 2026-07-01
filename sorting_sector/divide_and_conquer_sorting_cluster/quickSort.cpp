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

int getCorrectPivotIndex(int *currentArray, int arraySize)
{
  int specialIndex = -1;
  int iterationIndex = 0;

  int pivotPosition = arraySize - 1;
  for (iterationIndex = 0; iterationIndex < arraySize; ++iterationIndex)
  {
    if (currentArray[iterationIndex] <= currentArray[pivotPosition])
    {
      ++specialIndex;
      swapValuesInArrayByIndex(currentArray, iterationIndex, specialIndex);
    }
  }

  return specialIndex;
}

int *quickSortArrayAsc(int *originalArray, int arraySize)
{
  int *sortedArray = new int[arraySize];
  std::copy(originalArray, originalArray + arraySize, sortedArray);

  if (arraySize == 0)
  {
    return nullptr;
  }
  if (arraySize == 1)
  {
    return sortedArray;
  }
  else if (arraySize == 2)
  {
    if (sortedArray[0] > sortedArray[1])
    {
      swapValuesInArrayByIndex(sortedArray, 0, 1);
    }
    return sortedArray;
  }
  else
  {
    int pivotSettledIndex = getCorrectPivotIndex(sortedArray, arraySize);
    std::cout << "PIVOT POSITION NOW IS : " << pivotSettledIndex << std::endl;
    int pivotElement = sortedArray[pivotSettledIndex];
    int smallerArraySize = pivotSettledIndex;
    int *smallerArray = new int[smallerArraySize];

    int biggerArraySize = arraySize - pivotSettledIndex - 1;
    int *biggerArray = new int[biggerArraySize];

    int totalCopyIndex = 0;

    for (int i = 0; i < smallerArraySize; i++)
    {
      smallerArray[i] = sortedArray[totalCopyIndex];
      totalCopyIndex++;
    }

    for (int j = 0; j < biggerArraySize; j++)
    {
      biggerArray[j] = sortedArray[totalCopyIndex + 1];
      totalCopyIndex++;
    }

    std::cout << "SMALLER ELEMENTS ARRAY : " << std::endl;
    printArray(smallerArray, smallerArraySize);

    std::cout << "BIGGER ELEMENTS ARRAY : " << std::endl;
    printArray(biggerArray, biggerArraySize);

    int *sortedArrayLesser = quickSortArrayAsc(smallerArray, smallerArraySize);
    int *sortedArrayBigger = quickSortArrayAsc(biggerArray, biggerArraySize);

    totalCopyIndex = 0;
    for (int i = 0; i < smallerArraySize; ++i)
    {
      sortedArray[totalCopyIndex] = sortedArrayLesser[i];
      totalCopyIndex++;
    }

    sortedArray[totalCopyIndex] = pivotElement;
    totalCopyIndex++;

    for (int i = 0; i < biggerArraySize; ++i)
    {
      sortedArray[totalCopyIndex] = sortedArrayBigger[i];
      totalCopyIndex++;
    }

    return sortedArray;
  }
}

int main()
{

  const int primaryArraySize = 10;
  int unsortedArray[primaryArraySize] = {59, 715, 655, 354, -969, 4, 0, -6, 0, 1};

  // const int primaryArraySize = 6;
  // int unsortedArray[primaryArraySize] = {0, 15, 5, -1, 0, 8};

  std::cout << "UNSORTED ARRAY : " << std ::endl;
  printArray(unsortedArray, primaryArraySize);

  int *sortedArray = quickSortArrayAsc(unsortedArray, primaryArraySize);
  std::cout << "SORTED ARRAY : " << std ::endl;
  printArray(sortedArray, primaryArraySize);

  return 0;
}