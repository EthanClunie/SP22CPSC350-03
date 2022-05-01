
#ifndef FACULTYRECORDS_H
#define FACULTYRECORDS_H

#include "Faculty.h"
#include "StudentRecords.h"
#include "BST.h"
#include <vector>

class FacultyRecords
{
    public:
        FacultyRecords();
        ~FacultyRecords();

        void DisplayAllFacultyInfo();
        void DisplayFacultyInfo(int facID);
        std::vector<int> GetAdviseeList(int facID);

        void AddFacultyToRecord();
        void AddToAdviseeList(int stuID, int facID);
        
        void DeleteFacMember(int facId);
        void RemoveAdvisee(int stuID, int facID);

        int GetFacTableSize();

        bool IsInFacTable(int facID);

    private:
        BST<Faculty> *facultyRecord;
        std::vector<int> facultyIdList;

};

#endif