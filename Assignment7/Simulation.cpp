/**
 * @file Simulation.cpp
 * @author Ethan Clunie, Samuel Bernsen
 * @brief Contains the function implementations to run a simulation of Assignment 7 database program
 * 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Simulation.h"

using namespace std;


/**
 * Simulation
 * @brief Construct a new Simulation:: Simulation object
 * 
 */
Simulation::Simulation()
{
    stuTable = new StudentRecords();
    facTable = new FacultyRecords();

    prevStuTables = new DLList<StudentRecords>();
    prevFacTables = new DLList<FacultyRecords>();
}


/**
 * ~Simulation
 * @brief Destroy the Simulation:: Simulation object
 * 
 */
Simulation::~Simulation()
{
    delete this;
}


/**
 * Simulate
 * @brief Simulates the main loop for the database project along with the user's choices for said database
 * 
 */
void Simulation::Simulate()
{
    int usrChoice;
    bool stuFileExists;
    bool facFileExists;

    try
    {
        stuFileExists = ReadStudentTableFromFile();
        facFileExists = ReadFacultyTableFromFile();

        do
        {
            usrChoice = GetUserMenuChoice();

            switch (usrChoice)
            {
            case 1: // Print all students and their information (sorted by ascending id #)
                if (stuTable->GetStuTableSize() == 0)
                {
                    cout << "No students to display" << endl;
                }
                else
                {
                    stuTable->DisplayAllStudentsInfo();
                }

                break;

            case 2: // Print all faculty and their information (sorted by ascending id #)
                if (facTable->GetFacTableSize() == 0)
                {
                    cout << "No faculty to display" << endl;
                }
                else
                {
                    facTable->DisplayAllFacultyInfo();
                }

                break;

            case 3: // Find and display student information given the students id
                givenID = GetNextID();

                if (stuTable->IsInStuTable(givenID))
                {
                    stuTable->DisplayStudentInfo(givenID);
                }
                else
                {
                    cout << "No student with given id exists" << endl;
                }

                break;
                
            case 4: // Find and display faculty information given the faculty id
                givenID = GetNextID();

                if (facTable->IsInFacTable(givenID))
                {
                    facTable->DisplayFacultyInfo(givenID);
                }
                else
                {
                    cout << "No faculty with given id" << endl;
                }

                break;

            case 5: // Given a student’s id, print the name and info of their faculty advisor
                givenID = GetNextID();

                break;

            case 6: // Given a faculty id, print ALL the names and info of his/her advisees
                givenID = GetNextID();
                
                if (facTable->IsInFacTable(givenID))
                {
                    memberList = facTable->GetAdviseeList(givenID);
                    stuTable->DisplayListOfStudents(memberList);
                }
                else
                {
                    cout << "No faculty with given id exists" << endl;
                }
                

                break;

            case 7: // Add a new student
                if (facTable->GetFacTableSize() == 0)
                {
                    cout << "Need a faculty member to act as advisee before adding students" << endl;
                }
                else
                {
                    ids = stuTable->AddStudentToRecord();
                    facTable->AddToAdviseeList(get<0>(ids), get<1>(ids));
                }

                StoreCurrTblStates();

                break;

            case 8: // Delete a student given the id
                givenID = GetNextID();
                if (stuTable->IsInStuTable(givenID))
                {
                    stuTable->DeleteStudentFromRecord(givenID);
                }
                else
                {
                    cout << "No student with given ID" << endl;
                }

                StoreCurrTblStates();
                
                break;

            case 9: // Add a new faculty member
                facTable->AddFacultyToRecord();

                StoreCurrTblStates();

                break;

            case 10: // Delete a faculty member given the id
                givenID = GetNextID();

                if (facTable->IsInFacTable(givenID))
                {
                    facTable->DeleteFacMember(givenID);
                }

                StoreCurrTblStates();

                break;
                
            case 11: // Change a student’s advisor given the student id and the new faculty id
                givenID = GetNextID();
                otherGivenID = GetNextID();

                if (stuTable->IsInStuTable(givenID) && facTable->IsInFacTable(otherGivenID))
                {
                    stuTable->ChangeStudentAdvisor(givenID, otherGivenID);
                }
                else
                {
                    cout << "Provided an invalid ID" << endl;
                }

                StoreCurrTblStates();

                break;

            case 12: // Remove an advisee from a faculty member given the ids
                givenID = GetNextID();
                otherGivenID = GetNextID();

                if (stuTable->IsInStuTable(givenID) && facTable->IsInFacTable(otherGivenID))
                {
                    // facTable->RemoveAdvisee(otherGivenID, givenID);
                }
                else
                {
                    cout << "Provided an invalid ID" << endl;
                }

                StoreCurrTblStates();

                break;

            case 13: // Rollback
                cout << "Rolling back the last " << numChanges << " database changes." << endl;
                Rollback();
                
                break;

            case 14: // Exit
                cout << "Exiting and saving current table states to files." << endl;

                // Save the two "tables" (BST's) for StudentRecords and FacultyRecords to output files
                WriteTablesToFile();
                return;
            
            default:
                string lineWithError = to_string(__LINE__);
                throw runtime_error("ERROR: Invalid menu choice (not between 1-14) in Simulation. Line: " + lineWithError);
            }

        } while (usrChoice != 14);

    }
    catch (const exception& e)
    {
        throw e.what();
    }
    
}


/**
 * GetUserMenuChoice
 * @brief Reads and returns the user's choice for what to do next with the database as an integer
 * 
 * @return int 
 */
int Simulation::GetUserMenuChoice()
{
    int usrChoice = 0;
    do
    {
        PrintMenuOptions();

        cout << "Your choice: ";
        cin >> usrChoice;
        cin.ignore();

        if (usrChoice < 1 || usrChoice > 14)
        {
            cout << "Invalid option. Choose from the list" << endl;
        }

    }
    while (usrChoice < 1 || usrChoice > 14);

    return usrChoice;
}


/**
 * PrintMenuOptions
 * @brief Diplays all options a user has for manipulating the database
 * 
 */
void Simulation::PrintMenuOptions()
{
    cout << setfill ('-') << setw (60) << "" << endl;
    cout << "Menu Options:" << endl;

    cout << "\tOption 1: Print all students and their information (sorted by ascending id #)" << endl;
    cout << "\tOption 2: Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "\tOption 3: Find and display student information given the students id" << endl;
    cout << "\tOption 4: Find and display faculty information given the faculty id" << endl;
    cout << "\tOption 5: Given a student\'s id, print the name and info of their faculty advisor" << endl;
    cout << "\tOption 6: Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "\tOption 7: Add a new student" << endl;
    cout << "\tOption 8: Delete a student given the id" << endl;
    cout << "\tOption 9: Add a new faculty member" << endl;
    cout << "\tOption 10: Delete a faculty member given the id" << endl;
    cout << "\tOption 11: Change a student\'s advisor given the student id and the new faculty id" << endl;
    cout << "\tOption 12: Remove an advisee from a faculty member given the ids" << endl;
    cout << "\tOption 13: Rollback" << endl;
    cout << "\tOption 14: Exit" << endl;

    cout << setfill ('-') << setw (60) << "" << endl;
}


void Simulation::StoreCurrTblStates()
{
    if (numChanges >= MAX_QUEUE_SIZE)
    {
        LimitTblSizes();
    }
    numChanges++;
    prevStuTables->insertBack(*stuTable);
    prevFacTables->insertBack(*facTable);
}


void Simulation::LimitTblSizes()
{
    numChanges--;
    prevStuTables->removeFront();
    prevFacTables->removeFront();
}


void Simulation::Rollback()
{
    for (int i = 0; i < numChanges; ++i)
    {
        *stuTable = prevStuTables->removeBack();
        *facTable = prevFacTables->removeBack();
    }
    numChanges = 0;
}


/**
 * ReadStudentTableFromFile
 * @brief Reads studentTable file into the stuTable object if file exists. If not, return false
 * 
 * @return true 
 * @return false 
 */
bool Simulation::ReadStudentTableFromFile()
{
    fstream inFile;
    inFile.open(STU_FILE_NAME, ios::in|ios::binary);

    if (!inFile)
    {
        cout << "No previous studentTable.dat file, creating empty tree." << endl;
        return false;
    }

    if(inFile.read((char*)&stuTable,sizeof(stuTable)))
    {
        cout << "Data extracted from file successfully." << endl;
        return true;
	}
	else
    {
        throw runtime_error("ERROR in reading data from studentTable.dat file");
	}
}


/**
 * ReadFacultyTableFromFile
 * @brief Reads facultyTable file into the facTable object if file exists. If not, return false
 * 
 * @return true 
 * @return false 
 */
bool Simulation::ReadFacultyTableFromFile()
{
    fstream inFile;
    inFile.open(FAC_FILE_NAME, ios::in|ios::binary);

    if (!inFile)
    {
        cout << "No previous facultyTable.dat file, creating empty tree." << endl;
        return false;
    }

    if(inFile.read((char*)&facTable,sizeof(facTable)))
    {
        cout << "Data extracted from file successfully." << endl;
        return true;
	}
	else
    {
        throw runtime_error("ERROR in reading data from facultyTable.dat file");
	}
}


/**
 * WriteTablesToFile
 * @brief Writes the contents of the two tables as two binary files
 * 
 */
void Simulation::WriteTablesToFile()
{
    try
    {
        fstream outFileStu;
        fstream outFileFac;

        outFileStu.open("studentTable.dat", ios::out|ios::binary);
        outFileFac.open("facultyTable.dat", ios::out|ios::binary);

        if (!outFileStu)
        {
            cout << "ERROR: Could not open studentTable.dat file" << endl;
        }
        if (!outFileFac)
        {
            cout << "ERROR: Could not open facultyTable.dat file" << endl;
        }

        outFileStu.write((char*)&stuTable, sizeof(stuTable));
        outFileFac.write((char*)&facTable, sizeof(facTable));

        outFileStu.close();
        outFileFac.close();

        cout << "Saved successfully" << endl;
    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }
}


/**
 * GetNextID
 * @brief Returns a user given id number for a faculty member
 * 
 * @return int 
 */
int Simulation::GetNextID()
{
    int id;
    cout << "Enter the ID of the next Person (Student/Faculty) you would like to access:" << endl << "ID: #";
    cin >> id;

    return id;
}