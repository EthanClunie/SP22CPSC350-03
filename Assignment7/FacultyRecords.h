
#ifndef FACULTYRECORDS_H
#define FACULTYRECORDS_H

#include "Faculty.h"
#include "BST.h"
#include <vector>

class FacultyRecords
{
    public:
        FacultyRecords();
        ~FacultyRecords();

        void AddFacultyToRecord(Faculty facultyToAdd);

    private:
        BST<Faculty> facultyRecord;
        std::vector<int> facultyIdList;

};

#endif