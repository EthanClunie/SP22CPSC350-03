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

/* TODO:
- Implement Student class
- Implement StudentRecords class
- Implement Faculty class
- Implement FacultyRecords class

- Ensure that changes made to either the StudentRecords or FacultyRecords will also reflect in the other record as needed
    > Adding a Student to StudentRecords should also add to the corresponding Faculty member's list of advisees
    
- Implement all menu options fully
*/

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

    int stuToDelete;

    try
    {
        stuFileExists = ReadStudentTableFromFile();
        // facFileExists = ReadFacultyTableFromFile();

        do
        {
            usrChoice = GetUserMenuChoice();

            switch (usrChoice)
            {
            case 1:
                // Print all students and their information (sorted by ascending id #)

                break;

            case 2:
                // Print all faculty and their information (sorted by ascending id #)

                break;

            case 3:
                // Find and display student information given the students id

                break;
                
            case 4:
                // Find and display faculty information given the faculty id

                break;

            case 5:
                // Given a student’s id, print the name and info of their faculty advisor

                break;

            case 6:
                // Given a faculty id, print ALL the names and info of his/her advisees

                break;

            case 7:
                // Add a new student
                stuTable->AddStudentToRecord();
                stuTable->DisplayStudentInfo(1);

                break;

            case 8:
                // Delete a student given the id
                stuToDelete = GetIDStudent();
                stuTable->DeleteStudentFromRecord(stuToDelete);

                break;

            case 9:
                // Add a new faculty member

                break;

            case 10:
                // Delete a faculty member given the id

                break;
                
            case 11:
                // Change a student’s advisor given the student id and the new faculty id

                break;

            case 12:
                // Remove an advisee from a faculty member given the ids

                break;

            case 13:
                // Rollback
                // Use a stack to store function calls that need to be rolled back (store the previous 5 changes to BST's)

                break;

            case 14:
                // Exit
                cout << "Exiting and saving current table states to files." << endl;
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
    
    // Save the two "tables" (BST's) for StudentRecords and FacultyRecords to output files
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

        outFileStu.open(STU_FILE_NAME, ios::out|ios::binary);
        // outFileFac.open(FAC_FILE_NAME, ios::out|ios::binary);

        if (!outFileStu)
        {
            throw runtime_error("ERROR: Could not open studentTable.dat file");
        }
        if (!outFileFac)
        {
            throw runtime_error("ERROR: Could not open facultyTable.dat file");
        }

        outFileStu.write((char*)&stuTable, sizeof(stuTable));
        // outFileFac.write((char*)&facTable, sizeof(facTable));

        outFileStu.close();
        // outFileFac.close();
    }
    catch(const exception& e)
    {
        throw runtime_error(e.what());
    }
}


/**
 * GetIDStudent
 * @brief Returns a user given id number for a student
 * 
 * @return int 
 */
int Simulation::GetIDStudent()
{
    int id;
    cout << "Enter the ID of the Student you would like to access:" << endl << "ID: #";
    cin >> id;

    return id;
}


/**
 * GetIDFaculty
 * @brief Returns a user given id number for a faculty member
 * 
 * @return int 
 */
int Simulation::GetIDFaculty()
{
    int id;
    cout << "Enter the ID of the Faculty member you would like to access:" << endl << "ID: #";
    cin >> id;

    return id;
}