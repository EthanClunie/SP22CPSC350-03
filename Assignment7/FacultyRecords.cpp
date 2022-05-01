
#include "FacultyRecords.h"


/**
 * FacultyRecords
 * @brief Construct a new Faculty Records:: Faculty Records object
 * 
 */
FacultyRecords::FacultyRecords()
{
    facultyRecord = new BST<Faculty>();
}


/**
 * ~FacultyRecords
 * @brief Destroy the Faculty Records:: Faculty Records object
 * 
 */
FacultyRecords::~FacultyRecords()
{

}


/**
 * DisplayAllFacultysInfo
 * @brief Displays the information of every Faculty object in the tree (in ascending order)
 * 
 */
void FacultyRecords::DisplayAllFacultyInfo()
{
    facultyRecord->printFacultyInOrder();
}


/**
 * DisplayFacultyInfo
 * @brief Displays the information of a Faculty given facID
 * 
 * @param facID 
 */
void FacultyRecords::DisplayFacultyInfo(int facID)
{
    facultyRecord->find(facID).PrintFacultyInfo();
}


/**
 * AddFacultyToRecord
 * @brief Adds a Faculty object to the facultyRecord BST
 * 
 */
void FacultyRecords::AddFacultyToRecord()
{
    Faculty newFac;
    newFac.GetFacultyInformation();
    
    TreeNode<Faculty> *newFacNode = new TreeNode<Faculty>(newFac.GetFacID(), newFac);
    facultyRecord->insert(newFacNode);
    
    facultyIdList.push_back(newFac.GetFacID());
}

/**
 * AddToAdviseeList
 * @brief Adds an advisee's id to a faculty member's adviseeList
 * 
 * @param stuID
 * @param facID
 */
void FacultyRecords::AddToAdviseeList(int stuID, int facID)
{
    facultyRecord->find(facID).AddAdvisee(stuID);
}

/**
 * DeleteFacMember
 * @brief Deletes the Faculty node with key facID
 * 
 * @param facID 
 */
void FacultyRecords::DeleteFacMember(int facID)
{
    facultyRecord->remove(facID);
}


std::vector<int> FacultyRecords::GetAdviseeList(int facID)
{
    std::vector<int> adviseeList = facultyRecord->find(facID).GetAdviseesList();
    return adviseeList;

}

/**
 * DisplayFacultyInfo
 * @brief Displays the information of a Faculty given facID
 * 
 * @param facID
 *
 * @return int
 */
int FacultyRecords::GetFacTableSize()
{
    return facultyRecord->length();
}

/**
 * IsInFacTable
 * @brief Checks is the given ID is in the facultyRecord BST
 * 
 * @param facID
 *
 * @return bool
 */
bool FacultyRecords::IsInFacTable(int facID)
{
    return (facultyRecord->contains(facID));
}