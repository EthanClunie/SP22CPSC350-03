
#include "Simulation.h"

using namespace std;

/**
 * Simulation
 * @brief Construct a new Simulation:: Simulation object
 * 
 */
Simulation::Simulation()
{
    fp = new FileProcessor();

}


/**
 * ~Simulation
 * @brief Destroy the Simulation:: Simulation object
 * 
 */
Simulation::~Simulation()
{
    delete fp;
}


/**
 * 
 * @brief 
 * 
 */
void Simulation::CreateTestFile()
{
    ofstream outFile("randTest.txt", ios::out);
    const double MAX = 10000;
    const double MIN = 0;
    const int numDoubles = 100000;

    outFile << numDoubles << endl;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);

    for (int i = 0; i < numDoubles; ++i)
    {
        outFile << distr(eng) << endl;
    }

    outFile.close();
}

/**
 * Simulate
 * @brief Runs through a single simulation of the sorting algorithm program
 * 
 */
void Simulation::Simulate(string fileName)
{
    ReadInValues(fileName);

    DoMergeSort();

    DoSelectionSort();

    DoQuickSort();

}


/**
 * DoMergeSort
 * @brief Calls MergeSort() and prints time the algorithm was entered and exited
 * 
 */
void Simulation::DoMergeSort()
{
    cout << "Merge Sort: (Start/End printed as microseconds since epoch)" << endl;
    auto begin = std::chrono::steady_clock::now();
    cout << "Began: " << std::chrono::duration_cast<std::chrono::microseconds>(begin.time_since_epoch()).count() << endl;
    MergeSort(mergeList, 0, numValues - 1);
    auto end = std::chrono::steady_clock::now();
    cout << "Ended: " << std::chrono::duration_cast<std::chrono::microseconds>(end.time_since_epoch()).count() << endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "Duration: " << duration.count() << " microsecond(s)" << endl;
    cout << endl;
}


/**
 * DoSelectionSort
 * @brief Calls SelectionSort() and prints time the algorithm was entered and exited
 * 
 */
void Simulation::DoSelectionSort()
{
    cout << "Selection Sort: (Start/End printed as microseconds since epoch)" << endl;
    auto begin = std::chrono::steady_clock::now();
    cout << "Began: " << std::chrono::duration_cast<std::chrono::microseconds>(begin.time_since_epoch()).count() << endl;
    SelectionSort(selectionList);
    auto end = std::chrono::steady_clock::now();
    cout << "Ended: " << std::chrono::duration_cast<std::chrono::microseconds>(end.time_since_epoch()).count() << endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "Duration: " << duration.count() << " microsecond(s)" << endl;
    cout << endl;
}


/**
 * DoQuickSort
 * @brief Calls QuickSort() and prints time the algorithm was entered and exited
 * 
 */
void Simulation::DoQuickSort()
{

    cout << "Quick Sort: (Start/End printed as microseconds since epoch)" << endl;

    auto begin = std::chrono::steady_clock::now();
    cout << "Began: " << std::chrono::duration_cast<std::chrono::microseconds>(begin.time_since_epoch()).count() << endl;
    QuickSort(quickList, 0, numValues - 1);
    auto end = std::chrono::steady_clock::now();
    cout << "Ended: " << std::chrono::duration_cast<std::chrono::microseconds>(end.time_since_epoch()).count() << endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "Duration: " << duration.count() << " microsecond(s)" << endl;
    cout << endl;
}


/**
 * Merge
 * @brief Merges multiple partitions of the separated and sorted list for DoMergeSort()
 * 
 * @param list
 * @param i 
 * @param j 
 * @param k 
 */
void Simulation::Merge(double* list, int i, int j, int k)
{
    int mergedPartitionSize = k - i + 1;                // Size of merged partition
    int mergePos = 0;                                   // Position to insert merged number
    int leftPos = 0;                                    // Position of elements in left partition
    int rightPos = 0;                                   // Position of elements in right partition
    double* merged = new double[mergedPartitionSize];   // Dynamically allocates temporary array for merged numbers

    leftPos = i;                                        // Initialize left partition position
    rightPos = j + 1;                                   // Initialize right partition position

    // Add smallest element from left or right partition to merged
    while ((leftPos <= j) && (rightPos <= k))
    {
        if (list[leftPos] <= list[rightPos])
        {
            merged[mergePos] = list[leftPos];
            ++leftPos;
        }
        else
        {
            merged[mergePos] = list[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged
    while (leftPos <= j)
    {
        merged[mergePos] = list[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged
    while (rightPos <= k)
    {
        merged[mergePos] = list[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to list
    for (mergePos = 0; mergePos < mergedPartitionSize; ++mergePos)
    {
        list[i + mergePos] = merged[mergePos];
    }
}


/**
 * MergeSort
 * @brief Performs a merge sort on the given list of doubles
 * 
 * @param list 
 * @param i 
 * @param k 
 */
void Simulation::MergeSort(double* list, int i, int k)
{
    int j = 0;

    if (i < k)
    {
        // Find the midpoint in the partition
        j = (i + k) / 2;

        // Recursively sort left and right partitions
        MergeSort(list, i, j);
        MergeSort(list, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(list, i, j, k);
    }
}


/**
 * SelectionSort
 * @brief Performs a selection sort on the given list of doubles
 * 
 * @param list
 */
void Simulation::SelectionSort(double* list)
{
    int i = 0;
    int j = 0;
    double temp = 0;
    int smallestIndex = 0;

    for (i = 0; i < numValues; ++i)
    {
        smallestIndex = i;
        for (j = i+1; j < numValues; ++j)
        {
            if (list[j] < list[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        temp = list[i];
        list[i] = list[smallestIndex];
        list[smallestIndex] = temp;
    }
}


/**
 * QuickSort
 * @brief Performs a quick sort on the given list of doubles
 * 
 * @param list
 * @param lowIndex
 * @param highIndex
 */
void Simulation::QuickSort(double* list, int lowIndex, int highIndex)
{
    // Base case: If the partition size is 1 or zero 
   // elements, then the partition is already sorted
   if (lowIndex >= highIndex)
   {
      return;
   }
   
   // Partition the data within the array. Value lowEndIndex 
   // returned from partitioning is the index of the low 
   // partition's last element.
   int lowEndIndex = Partition(list, lowIndex, highIndex);
   
   // Recursively sort low partition (lowIndex to lowEndIndex) 
   // and high partition (lowEndIndex + 1 to highIndex)
   QuickSort(list, lowIndex, lowEndIndex);
   QuickSort(list, lowEndIndex + 1, highIndex);
}


/**
 * Partition
 * @brief Partitions the input list into low and high, unsorted parts
 * 
 * @param list 
 * @param lowIndex 
 * @param highIndex 
 * @return int : highIndex
 */
int Simulation::Partition(double* list, int lowIndex, int highIndex)
{
    // Pick middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    double pivot = list[midpoint];

    bool done = false;
    while (!done) 
    {
        // Increment lowIndex while list[lowIndex] < pivot
        while (list[lowIndex] < pivot) 
        {
        ++lowIndex;
        }

        // Decrement highIndex while pivot < list[highIndex]
        while (pivot < list[highIndex])
        {
            --highIndex;
        }

        // If zero or one elements remain, then all numbers are 
        // partitioned. Return highIndex.
        if (lowIndex >= highIndex)
        {
            done = true;
        }
        else
        {
            // Swap list[lowIndex] and list[highIndex]
            double temp = list[lowIndex];
            list[lowIndex] = list[highIndex];
            list[highIndex] = temp;

            // Update lowIndex and highIndex
            ++lowIndex;
            --highIndex;
        }
    }

    return highIndex;
}


/**
 * ReadInValues
 * @brief Reads in double values from the file into each dynamic array
 * 
 * @param fileName 
 */
void Simulation::ReadInValues(string fileName)
{
    vector<string> listVals = fp->ReadFromFile(fileName);

    numValues = stoi(listVals[0]);
    mergeList = new double[numValues];
    selectionList = new double[numValues];
    quickList = new double[numValues];

    double val;

    for (int i = 1; i < listVals.size(); ++i)
    {
        val = stod(listVals[i]);
        
        mergeList[i - 1] = val;
        selectionList[i - 1] = val;
        quickList[i - 1] = val;
    }

}