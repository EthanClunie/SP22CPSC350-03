
#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include "Student.h"
#include "BST.h"
#include <vector>
#include <iostream>
#include <tuple>

class StudentRecords
{
    public:
        StudentRecords();
        ~StudentRecords();

        void DisplayAllStudentsInfo();
        void DisplayStudentInfo(int stuID);
        void DisplayStudentAdvisorInfo(int stuID);
        void DisplayListOfStudents(std::vector<int> stuList);

        std::tuple<int, int> AddStudentToRecord();

        void DeleteStudentFromRecord(int stuID);
        void ChangeStudentAdvisor(int stuID, int newFacultyID);

        int GetStuTableSize();

        bool IsInStuTable(int stuID);

    private:
        BST<Student> *studentRecord;

        bool StuIDLessThan(Student stu1, Student stu2);

};

#endif