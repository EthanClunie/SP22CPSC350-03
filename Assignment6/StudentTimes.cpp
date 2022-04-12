/**
 * @file StudentTimes.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Implementation file for StudentTimes class. Handles creation of students
 * and calculations relating to their wait times
 * 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "StudentTimes.h"


/**
 * @brief Construct a new Student Times:: Student Times object
 * 
 */
StudentTimes::StudentTimes()
{
}


/**
 * @brief Destroy the StudentTimes:: StudentTimes object
 *
 */
StudentTimes::~StudentTimes()
{
    delete this;
}


/**
 * IncrementStuTimeInList
 * @brief Pushes a new integer value representing the waitTime of a student in the queue
 * onto a doubly-linked list
 * 
 */
void StudentTimes::IncrementStuTimeInList()
{
    Student *s = new Student();
    studentsList.push_back(*s);
}


/**
 * IncrementStuTimeInLine
 * @brief Increases the total student wait time when there are extra students left in the queue
 * and the windows are full in the registrar simulation
 * 
 * @param sizeOfLine 
 */
void StudentTimes::IncrementStuTimeInLine(int sizeOfLine)
{
    int startingPosition = studentsList.size() - sizeOfLine;
    for (int i = startingPosition; i < studentsList.size(); i++)
    {
        studentsList[i].IncrementTotalWaitTime();
    }
}

/**
 * GetMeanStudentWaitTime
 * @brief Returns the average student wait time
 * 
 * @return double 
 */
double StudentTimes::GetMeanStudentWaitTime()
{
    int sumWaitTime = FindSumTotalWaitTime();
    int numStudents = studentsList.size();
    return sumWaitTime / (double)numStudents;
}


/**
 * GetMedianStudentWaitTime
 * @brief Returns the median value of the vector<int> studentWaitTimes. Checks if 
 * the vector has a multiple of 2 for its number of items. If so, return the item 
 * at (size/2)+1. Else, return the item at size/2
 * 
 * @return int 
 */
int StudentTimes::GetMedianStudentWaitTime()
{
    int median = -1;

    median = studentsList[(studentsList.size()/2)].GetTotalWaitTime();

    if (median == -1)
    {
        std::string fileWithError = __FILE__;
        std::string lineWithError = std::to_string(__LINE__);
        throw runtime_error("ERROR: Could not properly find a median value. Loc: (File: " + fileWithError + ", Line: " + lineWithError + ")");
    }

    return median;
}


/**
 * GetLongestStudentWaitTime
 * @brief Loops through all of the student wait times and returns the largest integer value
 * 
 * @return int 
 */
int StudentTimes::GetLongestStudentWaitTime()
{
    int longestWaitTime = 0;

    for (Student stu : studentsList)
    {
        int currTotalTime = stu.GetTotalWaitTime();
        if (currTotalTime > longestWaitTime)
        {
            longestWaitTime = currTotalTime;
        }
    }
    
    return longestWaitTime;
}


/**
 * GetNumStuTimeOverTen
 * @brief Returns the number of student wait times that were over 10 minutes
 * 
 * @return int 
 */
int StudentTimes::GetNumStuTimeOverTen()
{
    int numOverTen = FindNumStudentsOverTen();
    return numOverTen;
}


/**
 * PrintStudentTimes
 * @brief Prints the total wait times of each student in the vector to terminal
 * 
 */
void StudentTimes::PrintStudentTimes()
{
    cout << "Printing studentsList time values in StudentTimes class: (top of Report)" << endl;
    for (Student stu : studentsList)
    {
        cout << stu.GetTotalWaitTime() << endl;
    }
}


/**
 * FindNumStudentsOverTen
 * @brief Loops through every student to determine whether their total wait times
 * were over ten minutes
 * 
 * @return int
 */
int StudentTimes::FindNumStudentsOverTen()
{
    int numWaitTimesOverTen = 0;

    for (Student stu : studentsList)
    {
        if (stu.GetTotalWaitTime() > 10)
        {
            numWaitTimesOverTen++;
        }
    }

    return numWaitTimesOverTen;
}


/**
 * FindSumTotalWaitTime
 * @brief Loops through every student to calculate the sum of all their totalWaitTime values
 * 
 * @return int
 */
int StudentTimes::FindSumTotalWaitTime()
{
    int sum = 0;

    for (Student stu : studentsList)
    {
        sum += stu.GetTotalWaitTime();
    }

    return sum;
}