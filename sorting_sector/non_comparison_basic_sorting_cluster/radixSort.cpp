#include <iostream>
#include <cmath>

class SortingElement {
    int originalValue = 0;
    int currentValue = 0;

public:

    SortingElement(int original, int current) {
        originalValue = original;
        currentValue = current;
    }


    SortingElement() {}


    int getOriginalValue() {
        return originalValue;
    }

    int getCurrentValue() {
        return currentValue;
    }
};

void printArray(int* array, int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int getMaximumValue(int* array, int size) {
    int maxVal = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

int getDigitByIndex(int number, int index) {
    number = std::abs(number);
    for (int i = 0; i < index; i++) {
        number /= 10;
    }
    return number % 10;
}

int getAmountOfDigits(int number) {
    if (number == 0) {
        return 1;
    }

    number = std::abs(number);
    int count = 0;

    while (number > 0) {
        number /= 10;
        count++;
    }

    return count;
}

void printStructure(SortingElement* structure, int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << "{ " << structure[i].getOriginalValue() << " : " << structure[i].getCurrentValue() << " } ";
    }
    std::cout << "]" << std::endl;
}

SortingElement* getStructure(int* array, int size, int digitIndex) {
    SortingElement* structure = new SortingElement[size];
    for (int i = 0; i < size; ++i) {
        SortingElement element = SortingElement(array[i], getDigitByIndex(array[i], digitIndex));
        structure[i] = element;
    }
    return structure;
}

SortingElement* sortStructure(SortingElement* structure, int size) {
    SortingElement* sortedStructure = new SortingElement[size];
    int count[10] = {0};

    for (int i = 0; i < size; ++i) {
        int digit = structure[i].getCurrentValue();
        count[digit]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        int digit = structure[i].getCurrentValue();
        sortedStructure[count[digit] - 1] = structure[i];
        count[digit]--;
    }
    return sortedStructure;
}

int* getSortedArray(SortingElement* structure, int size) {
    int* sortedArray = new int[size];
    for (int i = 0; i < size; ++i) {
        sortedArray[i] = structure[i].getOriginalValue();
    }
    return sortedArray;
}

int* radixSortArrayAsc(int* array, int size) {
    int arrayMaxValue = getMaximumValue(array, size);
    int amountOfPasses = getAmountOfDigits(arrayMaxValue);

    int* sortedArray = nullptr;

    for (int i = 0; i < amountOfPasses; ++i) {
        SortingElement* structure = getStructure(array, size, i);
        SortingElement* sortedStructure = sortStructure(structure, size);

        printStructure(sortedStructure, size);

        sortedArray = getSortedArray(sortedStructure, size);
        printArray(sortedArray, size);

        delete[] structure;
        delete[] sortedStructure;

        if (i > 0) {
            delete[] array;
        }
        array = sortedArray;
    }
    return sortedArray;
}

int main() {
    std::cout << "Compiler check OK" << std::endl;

    const int size = 5;
    int unsortedArray[] = {65, 5, 86, 174, 2569};

    int* sortedArray = radixSortArrayAsc(unsortedArray, size);

    std::cout << "FINAL SORTED ARRAY: " << std::endl;
    printArray(sortedArray, size);

    delete[] sortedArray;

    return 0;
}