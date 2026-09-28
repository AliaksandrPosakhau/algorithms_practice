#include <iostream>
#include <vector>
#include <algorithm>

class Bucket {

  std::vector<int> BucketValuesHandlerVector; 

  int lowestTier;
  int highestTier;
  int initialNumber;
  
  public:
  void setLowestTier(int value) {
    lowestTier = value;
  };

  void setHighestTier(int value) {   
    highestTier = value;
  }

  void setInitialNumber(int value){
    initialNumber = value;
  }

  void addValue(int value) {
    BucketValuesHandlerVector.push_back(value);
  }

  void sort() {  
    std::sort(BucketValuesHandlerVector.begin(), BucketValuesHandlerVector.end());
  }
    
  int getSize() {
        return BucketValuesHandlerVector.size();
  }
    
  int getValueAt(int j) {
        return BucketValuesHandlerVector[j];
  }

  int getInitialNumber(){
    return initialNumber;
  }

  int getLowestTier() {
    return lowestTier;
  }

  int getHighestTier() {
    return highestTier;
  }

  void assignValueIfInRange(int value) {
    if (value>=lowestTier && value<=highestTier) {
      BucketValuesHandlerVector.push_back(value);
      std::cout<< "ASSIGNED VALUE "<< value << " TO BUCKET # "<<getInitialNumber()<< " BETWEEN "<<getLowestTier() << " AND "<< getHighestTier() <<std::endl; 
    };
  }
};

void printArray(const int *arrayToPrint, int arraySize)
{
  for (int i = 0; i < arraySize; ++i)
  {
    std::cout << arrayToPrint[i] << " ";
  }
  std::cout << std::endl;
}

void swapValues(int *a, int *b) {
    int temporaryElement = *a;  
    *a = *b;                    
    *b = temporaryElement;      
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

int *bucketSortArrayAsc (int *unsortedArray, int size) {
  
    if (size==1) {
      return unsortedArray;
    } else if (size==2) {
        if (unsortedArray[0]>unsortedArray[1]) {
          swapValues(&unsortedArray[0],&unsortedArray[1]);
        } 
        return unsortedArray;
    }

    std::vector<Bucket> BucketsVector;

    int arrayMinimum = getArrayMinimum(unsortedArray, size);
    int arrayMaximum = getArrayMaximum(unsortedArray, size);
    int valuesRange = arrayMaximum - arrayMinimum;
    int bucketCapacity = valuesRange / size;

    int lowestTier = arrayMinimum;
    int highestTier = lowestTier+bucketCapacity;

    std::cout << "VALUES RANGE : "<<valuesRange<<std::endl;
    std::cout << "BUCKET CAPACITY : "<<bucketCapacity<<std::endl;

    for(int i=0;i<size;++i) {
       
       if (i == (size - 1)) {
           highestTier = arrayMaximum; 
       } else {
           highestTier = lowestTier + bucketCapacity;        
       }

       Bucket bucket;
       bucket.setInitialNumber(i+1);
       bucket.setLowestTier(lowestTier);
       bucket.setHighestTier(highestTier);
       BucketsVector.push_back(bucket);

       lowestTier = highestTier;   
       
    };

    for (int i=0;i<size;++i) {
      for (int j=0;j<size;++j) {
        BucketsVector[j].assignValueIfInRange(unsortedArray[i]);
      }
    }

    int *newArray = new int[size];

    for(int i=0;i<size;++i) {     
       BucketsVector[i].sort();
    };

    int pierceIndex = 0;
    for(int i=0;i<size;++i){
      for (int j=0;j<BucketsVector[i].getSize();++j) {
        newArray[pierceIndex] = BucketsVector[i].getValueAt(j);
        pierceIndex++;
      }
    }     
    return newArray;
}

int main() {

    int unsortedArray[] = {-127, -2, 656, 15, 64,2};
    int size = 6;

    std::cout<<"UNSORTED ARRAY : "<<std::endl;
    printArray(unsortedArray,size);

    int *sortedArray = bucketSortArrayAsc(unsortedArray,size);
    std::cout<<"SORTED ARRAY : "<<std::endl;
    printArray(sortedArray,size);

    return 0;
}