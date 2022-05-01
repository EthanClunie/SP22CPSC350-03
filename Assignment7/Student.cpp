/**
 * @file Student.h
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Contains all code necessary to create and manipulate singular Student objects
 * 
 * @version 0.1
 * @date 2022-04-19
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
    
}


Student::~Student()
{

}


void Student::GetStudentInformation()
{
    CreateNewStudent();
}


void Student::PrintStudentInfo()
{
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Student name: " << name << std::endl;
    std::cout << "Student grade level: " << gradeLevel << std::endl;
    std::cout << "Student major: " << major << std::endl;
    std::cout << "Student GPA: " << GPA << std::endl;
    std::cout << "Student advisor ID: " << advisorID << std::endl;
}


void Student::ChangeAdvisorID(int newAdvisorID)
{
    this->advisorID = newAdvisorID;
}


int Student::GetStuID()
{
    return this->studentID;
}


int Student::GetAdvisorID()
{
    return advisorID;
}

bool Student::operator < (Student const &stud)
{
    return (this->studentID < stud.studentID);
}


void Student::CreateNewStudent()
{
    std::cout << "Student Details:" << std::endl;
    std::cout << "Enter ID: ";
    std::cin >> this->studentID;
    std::cin.ignore(1);

    std::cout << "Enter name: ";
    getline(std::cin, this->name);

    std::cout << "Student grade level: ";
    getline(std::cin, this->gradeLevel);

    std::cout << "Student major: ";
    getline(std::cin, this->major);

    std::cout << "Student GPA: ";
    std::cin >> this->GPA;

    std::cout << "Enter advisor ID: ";
    std::cin >> this->advisorID;
}