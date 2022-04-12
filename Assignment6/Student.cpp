/**
 * @file Student.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Implementation file for the Student class. Allows for the creation and 
 * manipulation of all things related to a single Student object
 * 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Student.h"


/**
 * @brief Construct a new Student:: Student object
 * 
 */
Student::Student()
{
    totalWaitTime = 0;
}


/**
 * @brief Destroy the Student:: Student object
 * 
 */
Student::~Student()
{
}


/**
 * IncrementTotalWaitTime
 * @brief Increments the totalWaitTime private variable of the student this is called on
 * 
 */
void Student::IncrementTotalWaitTime()
{
    this->totalWaitTime += 1;
}


/**
 * GetTotalWaitTime
 * @brief Returns the totalWaitTime private variable of the student this is called on
 * 
 * @return int 
 */
int Student::GetTotalWaitTime()
{
    return this->totalWaitTime;
}