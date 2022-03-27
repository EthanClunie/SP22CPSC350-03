/**
 * @file Simulation.h
 * @author Ethan Clunie
 * @brief Header file for Simulation class. Contains the method definitions for all
 * methods needed to simulate a single execution of Assignment5.
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SIMULATION_H
#define SIMULATION_H

#include "AStack.h"
#include "FileProcessor.h"
#include <iostream>
#include <string>

class Simulation
{
    public:
        Simulation();
        ~Simulation();

        void Simulate();

    private:
        FileProcessor* fp;
        std::string fileContents;

        void CheckFileContents();

        bool IsOpeningDelimiter(char testChar);
        bool IsClosingDelimiter(char testChar);
        bool ArePair(char c1, char c2);
        char FindMatchingDelimiter(char charToPair);

        bool ConfirmNextSimulation();

        short GetCorrectErrorPosition(short charNumWithError, std::vector<std::string> exactContents);
        int FindLineWithError(short charNumWithError, char c1);

};

#endif