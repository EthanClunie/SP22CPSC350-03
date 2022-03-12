#include "GameBoards.h"

using namespace std;

/**
 * GameBoards
 * @brief Construct a new Game Boards:: Game Boards object
 * 
 */
GameBoards::GameBoards()
{
    fh = new FileHandler();
}


/**
 * GameBoards
 * @brief Construct a copy of a Game Boards:: Game Boards object
 * 
 * @param boardToCopy 
 */
GameBoards::GameBoards(const GameBoards &boardToCopy){
    numRows = boardToCopy.numRows;
    numColumns = boardToCopy.numColumns;

    board = new char* [numRows+2];
    for (int i = 0; i < numRows+2; ++i){
        board[i] = new char[numColumns+2];
    }

    for (int i = 0; i < numRows+2; i++){
        for (int j = 0; j < numColumns+2; j++){
            board[i][j] = boardToCopy.board[i][j];
        }
    }
}


/**
 * ~GameBoards
 * @brief Destroy the Game Boards:: Game Boards object
 * 
 */
GameBoards::~GameBoards()
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}


/**
 * CreateRandomBoard
 * @brief Creates a random initial board with rows and columns determined by the user input
 * 
 */
void GameBoards::CreateRandomBoard()
{
    do
    {
        cout << "Enter the number of rows you would like: ";
        cin >> numRows;
        cout << "Enter the number of columns you would like: ";
        cin >> numColumns;
    } while (!((numRows > 0) && (numColumns > 0)));
    
    board = new char* [numRows+2];
    for (int iRow = 0; iRow < numRows+2; ++iRow) {
        board[iRow] = new char[numColumns+2];  //Allocate an array of numRow characters
    }

    // assign '-' to element of 2-D array a_cGrid indexed by iRow and iColumn
	for (int iRow = 0; iRow < numRows+2; ++iRow)
	{
		for (int iColumn = 0; iColumn < numColumns+2; ++iColumn)
		{
			board[iRow][iColumn] = '-';
		}
	}

    DensityPlacement();
}


/**
 * CreatePredefinedBoard
 * @brief Creates a board for the game based on a user provided map file
 * 
 */
void GameBoards::CreatePredefinedBoard()
{
    string userInFile;
    cout << "Name of the file: ";
    cin >> userInFile;

    fh->OpenInFile(userInFile);

    // Reads and converts the number of rows and columns designated in the file into
    // the private member variables: numRows and numColumns
    string strRows = fh->ReadLine();
    string strCols = fh->ReadLine();
    numRows = stoi(strRows);
    numColumns = stoi(strCols);

    board = new char* [numRows+2];
    for (int iRow = 0; iRow < numRows+2; ++iRow) {
        board[iRow] = new char[numColumns+2];  //Allocate an array of numRow characters
    }

    // Reads every line of the inFile and passes those into the actual board
    int rowPos = 1;
    string str;
    while (!fh->IsEndOfFile())
    {
        str = fh->ReadLine();
        for (int j = 1; j < numColumns+2; ++j) // offset by 1 to center
        {
            board[rowPos][j] = str[j-1];
        }
        ++rowPos;
    }

    fh->CloseInFile();
}



/**
 * SaveMapToFile
 * @brief Saves all generations of a single simulation to an outFile
 * 
 */
void GameBoards::SaveMapToFile(string outFileName)
{
    fh->OpenOutFile(outFileName);

    // Reads every line of the boardToSave, mainBoard, and passes those into the outFile
    for (int iRow = 0; iRow < numRows; iRow++)
    {
        string tempLine = "";
        for (int jCol = 0; jCol < numColumns; jCol++)
        {
            tempLine += this->GetCharAt(iRow, jCol);
        }
        fh->WriteLineToFile(tempLine);
    }
    CloseOutputFile();
}


/**
 * CloseOutputFile
 * @brief Closes the outFile
 * 
 */
void GameBoards::CloseOutputFile()
{
    fh->CloseOutFile();
}


/**
 * DetermineBoardMode
 * @brief Prompts the user with three choices to decide the boundary mode of the game and returns the choice
 * 
 * @return int 
 */
int GameBoards::DetermineBoardMode()
{
    int userModeChoice;

    do
    {
        cout << "There are three options for the boundary mode:" << endl;
        cout << "Select one of the three by entering their matching value" << endl;
        cout << "\t(1) Classic" << endl << "\t(2) Doughnut" << endl << "\t(3) Mirror" << endl;
        cout << "Your choice: ";

        cin >> userModeChoice;
        cout << endl;
    } while ((userModeChoice < 1) || (userModeChoice > 3));

    return userModeChoice;
}


/**
 * DetermineBoardType
 * @brief Prompts user to provide the board type and returns either 0 or 1
 * 
 * @return int 
 */
int GameBoards::DetermineBoardType()
{
    int userBoardType;

    do
    {
        cout << "There are 2 options for the board type:" << endl;
        cout << "Select one of the two by entering their matching value" << endl;
        cout << "\t(0) Randomly generated maps" << endl << "\t(1) Pre-generated maps" << endl;
        cout << "Your choice: "; 

        cin >> userBoardType;
        cout << endl;
    } while ((userBoardType < 0) || (userBoardType > 1));
    
    return userBoardType;
}


/**
 * DensityPlacement
 * @brief Randomly assigns postions on the mainBoard to be populated or not based
 * on the user provided value for initial population density
 * 
 */
void GameBoards::DensityPlacement()
{
    // prompting the user for a valid population density
    double densityValue = -1.0;
    do
    {
        cout << "Provide a decimal value for initial population density of the world (0 < population <= 1):" << endl;
        cin >> densityValue;
    } while (!((densityValue > 0) && (densityValue <= 1.0)));
    
    int randomNum;
    srand(time(NULL));

    int maxVal = 100;
    int densityNum = densityValue * 100;
    
    // Generating board:
    // Places an X or - based on some randomly generated chance for each location
    for (int iRow = 1; iRow < numRows+1; ++iRow)
    {
        for (int iColumn = 1; iColumn < numColumns+1; ++iColumn)
        {
            randomNum = rand() % maxVal;

            if (randomNum < densityNum)
            {
                board[iRow][iColumn] = 'X';
            }
            else 
            {
                board[iRow][iColumn] = '-';
            }
        }
    }
}


/**
 * GetNumRows
 * @brief Returns the number of rows of the board this is called on
 * 
 * @return int 
 */
int GameBoards::GetNumRows()
{
    return numRows;
}


/**
 * GetNumColumns
 * @brief Returns the number of columns of the board this is called on
 * 
 * @return int 
 */
int GameBoards::GetNumColumns()
{
    return numColumns;
}


/**
 * GetCharAt
 * @brief Returns the character at some given position
 * 
 * @param rowPos 
 * @param columnPos 
 * @return char 
 */
char GameBoards::GetCharAt(int rowPos, int columnPos)
{
    char elem = board[rowPos][columnPos];
    return elem;
}


/**
 * ChangeElementAt
 * @brief Changes the element at a given position to some provided character
 * based on game rules (BoundaryMode)
 * 
 * @param rowPos 
 * @param columnPos 
 * @param charToChangeTo 
 */
void GameBoards::ChangeElementAt(int rowPos, int columnPos, char charToChangeTo)
{
    this->board[rowPos][columnPos] = charToChangeTo;
}


/**
 * @brief 
 * 
 *
 * @brief Displays the current game board to terminal
 *
 */
void GameBoards::DisplayBoard()
{
    for(int iRow = 1; iRow < numRows+1; iRow++){
        for(int jCol = 1; jCol < numColumns+1; jCol++){
            cout << board[iRow][jCol];
        }
        cout << endl;
    }
}

void GameBoards::DisplayPaddedBoard()
{
 for(int iRow = 0; iRow < numRows+2; iRow++){
     for(int jCol = 0; jCol < numColumns+2; jCol++){
        cout << board[iRow][jCol];
      }
      cout << endl;
    }
}