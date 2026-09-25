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
 

    // case 1. There is no right child for the element 
    if (rightChildIndex>=size) {
        // in this case we just checking left child element and root and swap if needed    
 if (leftChildIndex < size) {
        if(array[lastNonLeafElementIndex]<array[leftChildIndex]) {
            swapValues(&array[lastNonLeafElementIndex],&array[leftChildIndex]);    
            structurizeArrayAsHeap(array,size,leftChildIndex);        
        }
    }
}

    //case 2. if there are two childs, we need to check who is the largest one
    else if ((rightChildIndex<size)) {
 
        ArrayElement leftChild(array[leftChildIndex], leftChildIndex);
        ArrayElement rightChild(array[rightChildIndex], rightChildIndex);        
  
        int largestChildElementIndex = getLargestElementIndex(leftChild,rightChild);
 
        if (array[lastNonLeafElementIndex]<array[largestChildElementIndex]) {
            swapValues(&array[lastNonLeafElementIndex], &array[largestChildElementIndex]);
            structurizeArrayAsHeap(array, size, largestChildElementIndex);   
          
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
    
    // Common phase 01. Building heap based on array values
    for (int i = lastNonLeafElementIndex; i >= 0; i--) {
        structurizeArrayAsHeap(unsortedArray, size, i);
    }     

    // Common phase 02. Sorting array 
    for (int barrierElement = size-1; barrierElement>0;barrierElement--) {
        swapValues(&sortedArray[0],&sortedArray[barrierElement]);
        structurizeArrayAsHeap(sortedArray,barrierElement,0);
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

/**
 * The main idea of this sorting algorithm lies in such approach - every array may be 
 * transformed - or counted - as a tree.
 * 
 * Our first move will be to find last non-leaf element of the tree. 
 * For this we use formula LNLE index = (arraySize-1)/2
 * 
 * Then we put this array to special function what: (PHASE ONE)
 *  - starts from last non-leaf element of the array, checking its childs : 
 *  - it takes the largest of the childs 
 *  - then in checks is largest child is bigger then parent - if so, swaps the parent and child
 *  - and moves further till reach root of the tree - element [0] of the array
 * 
 *  After that goes stage two: (PHASE TWO)
 *  - we swapping root and the last element of the array
 *  - then we bar last element of the array - meaning that we will no further operate with it 
 *  - and again structurizing the array like a tree as in phase one, except last element (see point above)
 *  - so moving recurseively to the root - first element of array.
 */