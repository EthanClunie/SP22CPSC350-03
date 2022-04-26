
#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include "Student.h"
#include "BST.h"
#include <vector>
#include <iostream>

class StudentRecords
{
    public:
        StudentRecords();
        ~StudentRecords();

        void DisplayAllStudentsInfo();
        void DisplayStudentInfo(int stuID);
        void DisplayStudentAdvisorInfo(int stuID);
        void AddStudentToRecord();
        void DeleteStudentFromRecord(int stuID);
        void ChangeStudentAdvisor(int stuID, int newFacultyID);

    private:
        BST<Student> *studentRecord;

};

#endif