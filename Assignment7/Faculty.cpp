
#include "Faculty.h"


Faculty::Faculty()
{
    
}


Faculty::~Faculty()
{

}


void Faculty::GetFacultyInformation()
{
    CreateNewFacultyMember();
}


void Faculty::PrintFacultyInfo()
{
    std::cout << "Faculty ID: " << facultyID << std::endl;
    std::cout << "Faculty name: " << name << std::endl;
    std::cout << "Faculty level: " << facultyLevel << std::endl;
    std::cout << "Faculty department: " << department << std::endl;
    std::cout << "List of student advisee ID numbers: ";

    for (int i = 0; i < adviseesList.size(); i++)
    {
        std::cout << adviseesList[i] << ", ";
    }
    std::cout << std::endl;
}


void Faculty::AddAdvisee(int stuID)
{
    adviseesList.push_back(stuID);
}


std::vector<int> Faculty::GetAdviseesList()
{
    return adviseesList;
}


int Faculty::GetFacID()
{
    return facultyID;
}

void Faculty::CreateNewFacultyMember()
{
    std::cout << "Faculty Details:" << std::endl;
    std::cout << "Enter ID: ";
    std::cin >> facultyID;
    std::cin.ignore(1);

    std::cout << "Enter name: ";
    getline(std::cin, this->name);

    std::cout << "Faculty Level: ";
    getline(std::cin, this->facultyLevel);

    std::cout << "Faculty department: ";
    getline(std::cin, this->department);
}