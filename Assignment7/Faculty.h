
#ifndef FACULTY_H
#define FACULTY_H

#include <string>

class Faculty
{
    public:
        Faculty();
        ~Faculty();

    private:
        int facultyID;
        std::string name;
        std::string facultyLevel;
        std::string department;

};

#endif