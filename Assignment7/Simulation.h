
#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileProcessor.h"
#include "StudentRecords.h"
#include "FacultyRecords.h"
#include "DLList.h"
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

        DLList<StudentRecords> *prevStuTables;
        DLList<FacultyRecords> *prevFacTables;
        int numChanges = 0;

        const int MAX_QUEUE_SIZE = 5;
        
        int givenID;
        int otherGivenID;
        std::tuple<int, int> ids;
        
        std::vector<int> memberList;

        bool ReadStudentTableFromFile();
        bool ReadFacultyTableFromFile();
        void WriteTablesToFile();

        int GetSizeOfPrevTables();
        void StoreCurrTblStates();
        void LimitTblSizes();
        void Rollback();

        int GetUserMenuChoice();
        void PrintMenuOptions();

        int GetNextID();

};

#endif