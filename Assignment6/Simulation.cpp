/**
 * @file Simulation.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Contains the implementations of all the method definitions from the Simulation header file.
 * Runs through a single simulation of the registrar metric testing program
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
    lineQueue = new DLQueue<int>();
    studentTimes = new StudentTimes();

    currClockTick = 0;
}


/**
 * @brief Destroy the Simulation:: Simulation object
 * 
 */
Simulation::~Simulation()
{
    delete fp;
    delete lineQueue;
    delete this;
}


/**
 * Simulate
 * @brief Runs through a single simulation of the registrar metrics checking program
 * 
 */
void Simulation::Simulate(string file)
{
    try
    {
        PushFileDataToStack(file);
        
        MainRegistrarLoop();

    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }
    
}


/**
 * ReportData
 * @brief Reports all seven data points gathered throughout simulation of registrar program
 * 
 */
void Simulation::ReportData()
{
    try
    {
        cout << setfill ('-') << setw (60) << "";
        cout << endl << "Reporting data findings (in ticks):" << endl;

        cout << "\t1) Mean student wait time in queue: " << studentTimes->GetMeanStudentWaitTime() << endl;
        cout << "\t2) Median student wait time in queue: " << studentTimes->GetMedianStudentWaitTime()<< endl;
        cout << "\t3) Longest student wait time in queue: " << studentTimes->GetLongestStudentWaitTime() << endl;
        cout << "\t4) Number of student times over 10 ticks: " << studentTimes->GetNumStuTimeOverTen() << endl;
        
        cout << "\t5) Mean window idle time: " <<  windowTimes->GetMeanWindowIdleTime() << endl;
        cout << "\t6) Longest window idle time: " << windowTimes->GetLongestWindowIdleTime() << endl;
        cout << "\t7) Number of window idle times over 5 ticks: " <<  windowTimes->GetNumIdleTimesOverFive() << endl;
        cout << setfill ('-') << setw (55) << "" << endl;
    }
    catch(const std::exception& e)
    {
        throw(e.what());
    }

}


/**
 * MainRegistrarLoop
 * @brief Main loop of the registrar program to check the windows and students in a Simulation
 * 
 */
void Simulation::MainRegistrarLoop()
{
    const int numWindows = fileData->pop();
    windowTimes = new WindowIdleTimes(numWindows);
    
    windowArray = new int[numWindows];
    // Initialize windowArray values to all 0s
    for (int i = 0; i < numWindows; i++)
    {
        windowArray[i] = 0;
    }

    int clockTimeToCheck = -1;
    int numVisitors = -1;

    // Main loop of the registrar metrics program
    while (true)
    {
        // Get the next clock time to check
        clockTimeToCheck = fileData->topValue();

        // Confirm that the current clock tick is equal to the clock to time check
        if (currClockTick == clockTimeToCheck)
        {
            // Removes the clockTimeToCheck value from the fileData stack
            fileData->pop();

            // Get the number of visitors to go through
            numVisitors = fileData->pop();

            // Loop through every single visitor and enqueue them onto the linkedQueue
            for (int i = 0; i < numVisitors; i++)
            {
                studentTimes->IncrementStuTimeInList();
                lineQueue->enqueue(fileData->pop());
            }
        }

        // Loop through every position in the windowArray
        for (int i = 0; i < numWindows; i++)
        {
            // Check if the windowArray has open spots (arr[i] == 0) and place accordingly
            if (windowArray[i] == 0)
            {
                windowTimes->UpdateIdleTime(i);
                if (!lineQueue->isEmpty())
                {
                    windowArray[i] = lineQueue->dequeue();
                }
            }
            else
            {
                windowArray[i] -= 1;
            }
            
        }

        // Checks if there are still students in line
        // If so, increment their total wait time values

        int lineLength = lineQueue->length();
        if (lineLength != 0)
        {
            studentTimes->IncrementStuTimeInLine(lineLength);
        }

        // Breaks out of the main registrar loop depending on the conditions
        if (AreAllStudentsProcessed(numWindows))
        {
            break;
        }
        
        currClockTick++;
    }
}


/**
 * AreAllStudentsProcessed
 * @brief Returns a boolean which determines whether to exit the main program loop 
 * depending on whether all students have been processed
 * 
 * @param windowSize 
 * @return true 
 * @return false 
 */
bool Simulation::AreAllStudentsProcessed(int windowSize)
{
    int zeroCounter = 0;
    for (int i = 0; i < windowSize; i++)
    {
        if (windowArray[i] == 0)
        {
            zeroCounter++;
        }
    }

    return ((lineQueue->length() == 0) && (fileData->length() == 0) && (zeroCounter == windowSize));
}


/**
 * PushFileDataToStack
 * @brief Reads data from a given file into a private LStack object
 * 
 */
void Simulation::PushFileDataToStack(string file)
{
    vector<string> fileContents = fp->ReadFromFile(file);
    int numLines = fp->GetNumLinesInFile();

    fileData = new LStack<int>(numLines);

    for (int i = (numLines-1); i >= 0; i--)
    {
        fileData->push(stoi(fileContents[i]));
    }

}