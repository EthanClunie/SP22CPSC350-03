
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
    studentRecord->printStudentsInOrder();
}


/**
 * DisplayStudentInfo
 * @brief Displays the information of a student given stuID
 * 
 * @param stuID 
 */
void StudentRecords::DisplayStudentInfo(int stuID)
{
    studentRecord->find(stuID).PrintStudentInfo();
}


/**
 * DisplayStudentAdvisorInfo
 * @brief Displays the information of the student's advisor given student id stuID
 * 
 * @param stuID 
 */
void StudentRecords::DisplayStudentAdvisorInfo(int stuID)
{
    studentRecord->find(stuID).GetAdvisorID();
}


/**
 * DisplayListOfStudents
 * @brief Prints the information of a given list of students
 * 
 * @param stuList 
 */
void StudentRecords::DisplayListOfStudents(std::vector<int> stuList)
{
    for (int i = 0; i < stuList.size(); ++i)
    {
        studentRecord->find(stuList[i]).PrintStudentInfo();
        std::cout << std::endl;
    }
}


/**
 * AddStudentToRecord
 * @brief Adds a Student object to the studentRecord BST
 * 
 * @return std::tuple<int, int>
 */
std::tuple<int, int> StudentRecords::AddStudentToRecord()
{
    Student newStu;
    newStu.GetStudentInformation();
    TreeNode<Student> *newStuNode = new TreeNode<Student>(newStu.GetStuID(), newStu);
    studentRecord->insert(newStuNode);

    std::tuple<int, int> result(newStu.GetStuID(), newStu.GetAdvisorID());

    return result;
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
    // Update faculty records accordingly
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
    // Still need to change their advisor in the facultyrecords
}


/**
 * GetStuTableSize
 * @brief Returns the number of values within the studentRecord
 * 
 * @return int 
 */
int StudentRecords::GetStuTableSize()
{
    return studentRecord->length();
}


bool StudentRecords::IsInStuTable(int stuID)
{
    return (studentRecord->contains(stuID));
}


bool StudentRecords::StuIDLessThan(Student stu1, Student stu2)
{
    return (stu1.GetStuID() < stu2.GetStuID());
}