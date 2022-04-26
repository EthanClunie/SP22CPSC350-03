/**
 * @file Student.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Contains all function and variable definitions necessary for a singular Student object
 * 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student
{
    public:
        Student();
        ~Student();

        void PrintInfo();
        void ChangeAdvisorID(int newAdvisorID);

        int GetStuID();

    private:
        int studentID;
        std::string name;
        std::string gradeLevel;
        std::string major;
        double GPA;
        int advisorID;

        void CreateNewStudent();

};

#endif