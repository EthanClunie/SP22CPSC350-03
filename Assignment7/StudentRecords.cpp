
#include "StudentRecords.h"


/**
 * StudentRecords
 * @brief Construct a new Student Records:: Student Records object
 * 
 */
StudentRecords::StudentRecords()
{
    studentRecord = new BST<Student>();
}


/**
 * ~StudentRecords
 * @brief Destroy the Student Records:: Student Records object
 * 
 */
StudentRecords::~StudentRecords()
{

}


/**
 * DisplayAllStudentsInfo
 * @brief Displays the information of every Student object in the tree (in ascending order)
 * 
 */
void StudentRecords::DisplayAllStudentsInfo()
{
    
}


/**
 * DisplayStudentInfo
 * @brief Displays the information of a student given stuID
 * 
 * @param stuID 
 */
void StudentRecords::DisplayStudentInfo(int stuID)
{
    studentRecord->find(stuID).PrintInfo();
}


/**
 * DisplayStudentAdvisorInfo
 * @brief Displays the information of the student's advisor given student id stuID
 * 
 * @param stuID 
 */
void StudentRecords::DisplayStudentAdvisorInfo(int stuID)
{

}


/**
 * AddStudentToRecord
 * @brief Adds a Student object to the studentRecord BST
 * 
 */
void StudentRecords::AddStudentToRecord()
{
    Student newStu;
    newStu.GetStudentInformation();
    TreeNode<Student> *newStuNode = new TreeNode<Student>(newStu.GetStuID(), newStu);
    studentRecord->insert(newStuNode);
}


/**
 * DeleteStudentFromRecord
 * @brief Deletes the entire TreeNode<Student> with the key stuID
 * 
 * @param stuID 
 */
void StudentRecords::DeleteStudentFromRecord(int stuID)
{
    bool success = studentRecord->remove(stuID);
    if (!success)
    {
        std::cout << "Failed to delete student with ID#: " << stuID << std::endl;
    }
}


/**
 * ChangeStudentAdvisor
 * @brief Accesses the student with ID studID and changes the value for their advisor's id
 * 
 * @param stuID 
 * @param newFacultyID 
 */
void StudentRecords::ChangeStudentAdvisor(int stuID, int newFacultyID)
{
    studentRecord->find(stuID).ChangeAdvisorID(newFacultyID);
}