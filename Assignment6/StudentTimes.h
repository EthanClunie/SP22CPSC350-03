/**
 * @file StudentTimes.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Header file containing the definitions of methods needed to handle the student metrics
 * in a Simulation of the registrar program
 * 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STUDENTTIMES_H
#define STUDENTTIMES_H

#include "DLQueue.h"
#include "Student.h"
#include <vector>
#include <string>

class StudentTimes
{
    private:
        vector<Student> studentsList;

        int FindNumStudentsOverTen();
        int FindSumTotalWaitTime();

    public:
        StudentTimes();
        ~StudentTimes();

        void IncrementStuTimeInList();
        void IncrementStuTimeInLine(int sizeOfLine);

        double GetMeanStudentWaitTime();
        int GetMedianStudentWaitTime();
        int GetLongestStudentWaitTime();
        int GetNumStuTimeOverTen();

        void PrintStudentTimes();

};

#endif