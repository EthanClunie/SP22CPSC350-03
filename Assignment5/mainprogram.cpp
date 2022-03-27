/**
 * @file mainprogram.cpp
 * @author Ethan Clunie
 * @brief Main driver for Assignment 5. Creates a pointer to the Simulation class and runs a single code simulation.
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Simulation.h"
#include "AStack.h"

using namespace std;

int main()
{
    Simulation* s = new Simulation;
    s->Simulate();
    
    return 0;
}