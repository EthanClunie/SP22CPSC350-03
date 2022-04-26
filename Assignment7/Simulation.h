
#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileProcessor.h"
#include "StudentRecords.h"
#include "FacultyRecords.h"
#include <iostream>
#include <iomanip>

#define STU_FILE_NAME "studentTable.dat"
#define FAC_FILE_NAME "facultyTable.dat"

class Simulation
{
    public:
        Simulation();
        ~Simulation();

        void Simulate();

    private:
        StudentRecords *stuTable;
        FacultyRecords *facTable;

        bool ReadStudentTableFromFile();
        bool ReadFacultyTableFromFile();
        void WriteTablesToFile();

        int GetUserMenuChoice();
        void PrintMenuOptions();

        int GetIDStudent();
        int GetIDFaculty();

};

#endif