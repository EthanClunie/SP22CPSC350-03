/**
 * @file Student.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Header file for the Student class. Houses the definitions of the totalWaitTime for 
 * each student object created and some functions to manipulate and access that wait time
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    private:
        int totalWaitTime;

    public:
        Student();
        ~Student();

        void IncrementTotalWaitTime();

        int GetTotalWaitTime();

};

#endif