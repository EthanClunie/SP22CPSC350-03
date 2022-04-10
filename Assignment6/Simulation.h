/**
 * @file Simulation.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Header file for Simulation class. Contains the method definitions for all
 * methods needed to simulate a single execution of Assignment6.
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileProcessor.h"
#include "DLQueue.h"
#include "LStack.h"
#include "StudentTimes.h"
#include "WindowIdleTimes.h"
#include <iostream>
#include <iomanip>

class Simulation
{
    private:
        // Main objects to run the registrar program
        
        FileProcessor *fp;
        DLQueue<int> *lineQueue;
        LStack<int> *fileData;
        StudentTimes *studentTimes;
        WindowIdleTimes *windowTimes;

        // Private dynamic int[] for the windows
        int *windowArray;
        // Private int to track current clock tick
        int currClockTick;

        // Main program sections
        void MainRegistrarLoop();
        
        // Helper methods for readability
        void PushFileDataToStack(string file);
        bool AreAllStudentsProcessed(int windowSize);

    public:
        // Constructors and destructors
        Simulation();
        ~Simulation();

        // Main methods to execute and run the program from main
        void Simulate(string file);
        void ReportData();

};

#endif