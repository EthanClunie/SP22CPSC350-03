
#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileProcessor.h"
#include <chrono>
#include <ctime>
#include <random>

class Simulation
{
    public:
        Simulation();
        ~Simulation();

        void Simulate(std::string fileName);
        void CreateTestFile();

    private:
        FileProcessor* fp;
        double* mergeList;
        double* selectionList;
        double* quickList;
        int numValues;

        void DoMergeSort();
        void DoSelectionSort();
        void DoQuickSort();

        void Merge(double* list, int i, int j, int k);
        void MergeSort(double* list, int i, int k);

        void SelectionSort(double* list);

        int Partition(double* list, int lowIndex, int highIndex);
        void QuickSort(double* list, int lowIndex, int highIndex);

        void ReadInValues(std::string fileName);
};

#endif