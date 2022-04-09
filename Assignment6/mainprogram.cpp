/**
 * @file mainprogram.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Main driver file for Assignment 6 program. Calls Simulation.Simulate()
 * 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv)
{
    try
    {
        if (argc < 2)
        {
            throw runtime_error("ERROR: Not enough command line arguments.");
        }

        Simulation *sim = new Simulation();
        sim->Simulate(argv[1]);
        sim->ReportData();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}