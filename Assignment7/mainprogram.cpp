/**
 * @file mainprogram.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Main driver file for programs. Calls Simulation.Simulate()
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
        Simulation *sim = new Simulation();
        sim->Simulate();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}