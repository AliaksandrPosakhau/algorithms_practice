#include <iostream>

void printArray(const int *arrayToPrint, int arraySize)
{
  for (int i = 0; i < arraySize; ++i)
  {
    std::cout << arrayToPrint[i] << " ";
  }
  std::cout << std::endl;
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

int getCounterArraySize(int *array, int arraySize)
{
  return getArrayMaximum(array, arraySize) - getArrayMinimum(array, arraySize) + 1;
}

int *getCounterArray(int *originalArray, int arraySize)
{
  int counterArraySize = getCounterArraySize(originalArray, arraySize);
  int *counterArray = new int[counterArraySize];
  for (int i = 0; i < counterArraySize; ++i)
  {
    counterArray[i] = 0;
  }
  return counterArray;
}

int getAmountOfDuplicatedValues(int *originalArray, int arraySize, int valueToDetect)
{
  int amountOfDuplicatedValues = 0;

  for (int i = 0; i < arraySize; ++i)
  {
    if (originalArray[i] == valueToDetect)
    {
      ++amountOfDuplicatedValues;
    }
  }
  return amountOfDuplicatedValues;
}

int *getCumulativeArray(int *counterArray, int arraySize)
{
  int *cumulativeArray = new int[arraySize];
  cumulativeArray[0] = counterArray[0];

  for (int i = 1; i < arraySize; i++)
  {
    cumulativeArray[i] = cumulativeArray[i - 1] + counterArray[i];
  }
  return cumulativeArray;
}

int *countingSortArrayAsc(int *originalArray, int arraySize)
{
  int *sortedArray = new int[arraySize];
  std::copy(originalArray, originalArray + arraySize, sortedArray);

  int counterArraySize = getCounterArraySize(sortedArray, arraySize);
  int *counterArray = getCounterArray(originalArray, arraySize);

  int counterArrayIndex;
  int originalArrayMinimumValue = getArrayMinimum(originalArray, arraySize);
  int originalArrayMaxValue = getArrayMaximum(originalArray, arraySize);

  // Mapping Values to Counter Array Indices
  int counterArrayIteratorIndex = 0;
  int amountOfValueRepetitions = 0;

  for (int i = originalArrayMinimumValue; i <= originalArrayMaxValue; ++i)
  {
    amountOfValueRepetitions = getAmountOfDuplicatedValues(originalArray, arraySize, i);
    counterArray[counterArrayIteratorIndex] = amountOfValueRepetitions;
    counterArrayIteratorIndex++;
  }

  // [1,0,2,2,0,2,0,1,1,0,0,1]
  std::cout << "COUNTER ARRAY WITH SIZE OF " << counterArraySize << ": " << std ::endl;
  printArray(counterArray, counterArraySize);

  /**
   * So, our COUNTER ARRAY WITH SIZE OF 12:
     1 0 2 2 0 2 0 1 1 0 0 1

     Cumulative array:
     cu[0]=1
     cu[1]=cu[0]+ca[1]=1+0=1
     cu[2]=cu[1]+ca[2]=1+2=3
     cu[3]=cu[2]+ca[3]=3+2=5
     cu[4]=cu[3]+ca[4]=5+0=5
     cu[5]=cu[4]+ca[5]=5+2=7
     cu[6]=cu[5]+ca[6]=7+0=7
     cu[7]=cu[6]+ca[7]=7+1=8
     cu[8]=cu[7]+ca[8]=8+1=9
     cu[9]=cu[8]+ca[9]=9+0=9
     cu[10]=cu[9]+ca[10]=9+0=9
     cu[11]= cu[10]+ca[11]=9+1=10

      {1,1,3,5,5,7,7,8,9,9,9,10}
   */

  int *cumulativeArray = getCumulativeArray(counterArray, counterArraySize);
  std::cout << "CUMULATIVE ARRAY WITH SIZE OF " << counterArraySize << ": " << std ::endl;
  printArray(cumulativeArray, counterArraySize);

  int *outputArray = new int[arraySize];
  int positionIndexInCumulativeArray;
  int positionInOutputArray;

  for (int i = arraySize - 1; i >= 0; --i)
  {
    positionIndexInCumulativeArray = originalArray[i] - originalArrayMinimumValue;
    positionInOutputArray = cumulativeArray[positionIndexInCumulativeArray] - 1;
    outputArray[positionInOutputArray] = originalArray[i];
    cumulativeArray[positionIndexInCumulativeArray]--;
  }

  return outputArray;
}

int main()
{
  const int primaryArraySize = 10;
  int unsortedArray[primaryArraySize] = {0, 6, 9, -2, 0, 1, 1, 3, 3, 5};

  std::cout << "UNSORTED ARRAY : " << std ::endl;
  printArray(unsortedArray, primaryArraySize);

  int *sortedArray = countingSortArrayAsc(unsortedArray, primaryArraySize);
  std::cout << "SORTED ARRAY : " << std ::endl;
  printArray(sortedArray, primaryArraySize);

  return 0;
}

/*
The true essence of this intricating sorting mechanism lies deeply and remains hidden in depths of
 mathematical numbers theory. It is mostly based on properties of numbers, not on the pure logic,
  as we observed in all previous mechanisms. Core of those quite weird actions relies the following truth,
   such as :
1. Firs of all, we need to find minimum and maximum value in original array. It is required for creation
 of so called counter array,
 2. And the size of the counter array will definitely be different then size of original array,
 cause main thing here is a range - range between minimum value and maximum value.
3. So our first element would be minimum, and the last one - maximum, and all the rest elements would be
 differ from each one by 1.
4. After this we need to form - to fill this counter array, where every element of it will be a summ
 of occurences of each element of original array. In simple words - how many times element repeats in
  original array.
5 After we go through all range of values of counter array - so we taking value from counter array
 and see how much times it presents in original array - we forming so called cumulative array.
6. Forming this array we following another specific mechanism - we summarizing previous element
 of cumuative array with the element of counter array.
7. After this, we in a very specific manner retrieving position of the each element of original
 arrray in sorted array. For this we again taking element from original array, extracting from it
  minimal value, and by that index retrieving element from cumulative array , in turn extracting 1.
   and it is an index for the element of unsorted array in sorted array. After that we reducing
    element in position of cumulative array by 1.
*/