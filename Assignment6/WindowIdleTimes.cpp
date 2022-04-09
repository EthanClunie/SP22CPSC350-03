/**
 * @file WindowIdleTimes.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Implementation file for WindowIdleTimes class. Contains funciton implementations for 
 * creating a WindowIdleTimes object, accessing the windows it contains, and report values depending
 * on the idle times of all the window objects stored
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "WindowIdleTimes.h"


/**
 * WindowIdleTimes
 * @brief Construct a new Window Idle Times:: Window Idle Times object
 * 
 * @param windowArraySize 
 */
WindowIdleTimes::WindowIdleTimes(int windowArraySize)
{
    size = windowArraySize;
    for (int i = 0; i < size; i++)
    {
        Window *someWindow = new Window();
        windows.push_back(*someWindow);
    }
}


/**
 * @brief Destroy the Window Idle Times:: Window Idle Times object
 * 
 */
WindowIdleTimes::~WindowIdleTimes()
{
    delete this;
}


/**
 * UpdateIdleTime
 * @brief Increments the idle time value of a window with a value of zero
 * 
 * @param windowToUpdate 
 */
void WindowIdleTimes::UpdateIdleTime(int windowToUpdate)
{
    windows[windowToUpdate].IncrementWindowIdleTime();
}


/**
 * GetMeanWindowIdleTime
 * @brief Returns the average value of all the windows stored in the 
 * WindowIdleTimes object
 * 
 * @return double 
 */
double WindowIdleTimes::GetMeanWindowIdleTime()
{
    int totalSumTimes = CalcSumWindowIdleTimes();
    double mean = 0.0;
    mean = totalSumTimes / (double)size;

    return mean;
}


/**
 * GetLongestWindowIdleTime
 * @brief Returns the longest(greatest) idle time value of all the windows
 * 
 * @return int 
 */
int WindowIdleTimes::GetLongestWindowIdleTime()
{
    int longestIdleTime = -1;
    
    for (Window w: windows)
    {
        int currTime = w.GetWindowIdleTime();
        if (currTime > longestIdleTime)
        {
            longestIdleTime = currTime;
        }
    }

    return longestIdleTime;
}


/**
 * GetNumIdleTimesOverFive
 * @brief Returns the number of window idle times above 5
 * 
 * @return int 
 */
int WindowIdleTimes::GetNumIdleTimesOverFive()
{
    int numTimesOverFive = 0;

    for (Window w : windows)
    {
        if (w.GetWindowIdleTime() > 5)
        {
            numTimesOverFive++;
        }
    }

    return numTimesOverFive;
}


/**
 * CalcSumWindowIdleTimes
 * @brief Calculates the total sum of the idle times for all windows
 * 
 * @return int 
 */
int WindowIdleTimes::CalcSumWindowIdleTimes()
{
    int sum = 0;
    for (Window w : windows)
    {
        sum += w.GetWindowIdleTime();
    }

    return sum;
}


/**
 * PrintIdleTimes
 * @brief Prints the idle time value for each window in the WindowIdleTimes object.
 * For debugging purposes.
 * 
 */
void WindowIdleTimes::PrintIdleTimes()
{
    std::cout << "Testing PrintIdleTimes values (Sim, Line: 145): " << std::endl;
    for (Window w : windows)
    {
        std::cout << "Idle Time: " << w.GetWindowIdleTime() << std::endl;
    }
}