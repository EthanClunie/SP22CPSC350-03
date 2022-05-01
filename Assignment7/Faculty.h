
#ifndef FACULTY_H
#define FACULTY_H

#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

class Faculty
{
    public:
        Faculty();
        ~Faculty();

        void PrintFacultyInfo();
        void GetFacultyInformation();

        void AddAdvisee(int stuID);
        
        std::vector<int> GetAdviseesList();

        int GetFacID();

    private:
        int facultyID;
        std::string name;
        std::string facultyLevel;
        std::string department;
        std::vector<int> adviseesList;

        void CreateNewFacultyMember();

};

#endif