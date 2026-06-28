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

// NB - IF ARRAYS WILL BE NOT SORTED THE METHOD PROVIDE WRONG RESULTS.
int *mergeAndSortArraysAsc(int *firstArray, int sizeOfFirstArray, int *secondArray, int sizeOfSecondArray)
{
  int i = 0, j = 0, k = 0;
  const int finalArrayLength = sizeOfFirstArray + sizeOfSecondArray;
  int *summaryArray = new int[finalArrayLength];

  int *arr1 = bubbleSortArrayAsc(firstArray, sizeOfFirstArray);
  int *arr2 = bubbleSortArrayAsc(secondArray, sizeOfSecondArray);

  while (i < sizeOfFirstArray && j < sizeOfSecondArray)
  {
    if (arr1[i] <= arr2[j])
    {
      summaryArray[k] = arr1[i];
      i++;
    }
    else
    {
      summaryArray[k] = arr2[j];
      j++;
    }
    k++;
  }

  while (i < sizeOfFirstArray)
  {
    summaryArray[k] = arr1[i];
    i++;
    k++;
  }

  while (j < sizeOfSecondArray)
  {
    summaryArray[k] = arr2[j];
    j++;
    k++;
  }

  return summaryArray;
}

int main()
{

  /* FOLLOW UP TASK :
  Create a method that takes two arrays of variable length and merges them into one single array,
  sorting elements by asc. Do not use separate sorting.
  */

  int arr1[6] = {6, 15, -8, 4, 3, 2};
  int arr2[4] = {0, 182, -15, 29};

  int *summaryArray = mergeAndSortArraysAsc(arr1, 6, arr2, 4);

  std::cout << "SORTED ARRAY : " << std ::endl;
  printArray(summaryArray, 10);

  return 0;
}