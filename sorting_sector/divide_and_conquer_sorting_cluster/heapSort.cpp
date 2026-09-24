#include <iostream>

class ArrayElement {   
    int currentIndex;
    int currentValue;

    public:    
    ArrayElement(int value, int index) {
        currentIndex = index;
        currentValue = value;
    };

    int getValue() {
        return currentValue;
    };

    int getIndex() {
        return currentIndex;
    };
};

void printArray(int *array, int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void swapValues(int *a, int *b) {
    int temporaryElement = *a;  
    *a = *b;                    
    *b = temporaryElement;      
}

int getLargestElement(int a, int b) {
    if (a > b) return a;
    return b;
}

int getLargestElementIndex (ArrayElement a, ArrayElement b) {
  if (a.getValue() > b.getValue()) return a.getIndex();
    return b.getIndex();
};

void structurizeArrayAsHeap(int *array, int size, int lastNonLeafElementIndex) {    

    int leftChildIndex = 2*lastNonLeafElementIndex+1;
    int rightChildIndex = 2*lastNonLeafElementIndex+2;

    std::cout << "Left child index for parent with index "<<lastNonLeafElementIndex<< " - "<<leftChildIndex<<std::endl;
    std::cout << "Right child index for parent with index "<<lastNonLeafElementIndex<< " - "<<rightChildIndex<<std::endl;

    // case 1. There is no right child for the element 
    if (rightChildIndex>=size) {
        // in this case we just checking left child element and root and swap if needed
        std::cout << "Left child for element "<< array[lastNonLeafElementIndex] << " is " << array[leftChildIndex] << std::endl;
        std::cout << "Right child for element "<< array[lastNonLeafElementIndex] << " - there is no right child index for this element" << std::endl;

        if(array[lastNonLeafElementIndex]<array[leftChildIndex]) {
            swapValues(&array[lastNonLeafElementIndex],&array[leftChildIndex]);
        }
    }

    //case 2. if there are two childs, we need to check who is the largest one
    else if ((rightChildIndex<size)) {

    std::cout << "Left child for element "<< array[lastNonLeafElementIndex] << " is " << array[leftChildIndex] << std::endl;
    std::cout << "Right child for element "<< array[lastNonLeafElementIndex] << " is " << array[rightChildIndex] << std::endl;

        ArrayElement leftChild(array[leftChildIndex], leftChildIndex);
        ArrayElement rightChild(array[rightChildIndex], rightChildIndex);        
  
        int largestChildElementIndex = getLargestElementIndex(leftChild,rightChild);

        std::cout << "TAKING THE LARGEST CHILD BETWEEN "<< array[leftChildIndex] << " AND "<<array[rightChildIndex]<<std::endl;
        std::cout << "LARGEST CHILD IS "<<array[largestChildElementIndex]<<std::endl;

        if (array[lastNonLeafElementIndex]<array[largestChildElementIndex]) {
            swapValues(&array[lastNonLeafElementIndex], &array[largestChildElementIndex]);
            std::cout << "SWAPPED "<< *(&array[lastNonLeafElementIndex]) << " AND "<<*(&array[largestChildElementIndex])<<std::endl;
        }
    }    
}

int *heapSortArrayAsc(int *unsortedArray, int size) {
    int *sortedArray = new int[size];
    sortedArray = unsortedArray;

    if (size == 1) {
        return sortedArray;
    }

    if (size == 2) {
        if (sortedArray[0] > sortedArray[1]) {
            swapValues(&sortedArray[0], &sortedArray[1]);
        }
        return sortedArray;
    }
    
    int lastNonLeafElementIndex = (size / 2) - 1;
    std::cout << "Last non-leaf element is " << unsortedArray[lastNonLeafElementIndex] << std::endl;
    
    for (int i = lastNonLeafElementIndex; i >= 0; i--) {
        structurizeArrayAsHeap(unsortedArray, size, i);
    }
    
    return sortedArray; 
}


int main() {

    int unsortedArray[] = {11,12,13,5,6,7};
    int size = 6;

    std::cout<<"UNSORTED ARRAY : "<<std::endl;
    printArray(unsortedArray,size);
    
    std::cout<<"SORTED ARRAY : "<<std::endl;
    int *sortedArray = heapSortArrayAsc(unsortedArray,size);
    printArray(sortedArray,size);

    return  0;
}