/**
 * @file WindowIdleTimes.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Header file for WindowIdleTimes object. Contains the function definitions 
 * of a dynamic array of windows.
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WINDOWIDLETIMES_H
#define WINDOWIDLETIMES_H

#include "Window.h"
#include <vector>
#include <string>
#include <iostream>

class WindowIdleTimes
{
    private:
        // Vector to store each window (which contains idle times)
        std::vector<Window> windows;
        int size;

        int CalcSumWindowIdleTimes();

    public:
        WindowIdleTimes(int windowArraySize);
        ~WindowIdleTimes();

        void UpdateIdleTime(int windowToUpdate);
        
        double GetMeanWindowIdleTime();
        int GetLongestWindowIdleTime();
        int GetNumIdleTimesOverFive();

        void PrintIdleTimes();

};

#endif