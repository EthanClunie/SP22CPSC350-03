/*

*/
#include "FileIO.h"
#include "Mirror.h"

using namespace std;

/**
 * Game
 * @brief Construct a new Game::Game object
 * 
 */
Game::Game()
{}

/**
 * ~Game
 * @brief Destroy the Game::Game object
 * 
 */
Game::~Game()
{}

/**
 * InitGridRand
 * @brief Initializes a grid for the game after obtaining input values for row/column sizes
 * 
 */
void Game::InitGridRand()
{
    gameGrid.InitGridRand();
    copyGrid = gameGrid;
}

/**
 * Play
 * @brief Plays through an entire simuation of the game
 * 
 */
void Game::Play()
{
    // TEST STUFF
    // DisplayGrid();

    int gameType = DetermineGameType();

    FileIO fileHandler;

    string userWorldChoice;
    string textSuffix = ".txt";
    int generationNumber = 0;

    cout << "Would you like to provide a map file for the simulated world or a random assignment?" << endl;
    cout << "Provide a file name with \".txt\". Anything else will be treated as desiring a random assignment: " << endl;
    cin >> userWorldChoice;

    // Checks if the input for userWorldChoice contained .txt. If yes, use it as a map. If not, random game.
    int foundTxt = userWorldChoice.find(textSuffix);

    if (foundTxt == -1) // Random game assignment
    {
        // Creates a grid based on user input for row/column amounts
        InitGridRand();

    }
    else // Use input as map file for simulated world
    {
        // fileHandler.LoadMapFile(userWorldChoice, gameGrid);

    }

    // Displays the current generation
    cout << "Gen ";
    cout << generationNumber << endl;
    DisplayGrid();

    TODO3:
    if (gameType == 1)
    {
        // aClassic classicGame;

    }

    else if (gameType == 2)
    {
        // TODO
        // create object of Doughnut type
    }

    else if (gameType == 3)
    {
        // TODO
        // create object of Mirror type
    }
    else
    {
        cout << "Oh god no. (File: " << __FILE__ << ", Line: " << __LINE__ << ")" << endl;
    }
    
    // Checks game rules/end conditions
    if (AllDead() || HasStagnated())
    {
        // Halt the simulation

        

        TODO2:
        // Prompt the user to press "ENTER" to exit the program
        char exitChar;
        
        while (true)
        {
            cout << "Press the ENTER key to exit the simulation." << endl;
            // Read for the ASCII value of the ENTER key, not for '\n' or whitespace
            cin.ignore();
            cin >> exitChar;

            if (exitChar == 'r') // TODO : hopefully this is the ascii value
            {
                break;
            }

        }

    }

    return;
}

/**
 * SwapGrids
 * @brief Swaps the pointers between the two grids of the game at the end of each generation
 * 
 */
void Game::SwapGrids(GameBoard Grid1, GameBoard Grid2)
{
    GameBoard temp = Grid1;
    Grid1 = Grid2;
    Grid2 = temp;
}

/**
 * AllDead
 * @brief Checks if all grid spaces are "-".
 * If so, return true; else, return false;
 * 
 * @return true 
 * @return false 
 */
bool Game::AllDead()
{
    bool allDead;
    int numEmptyLocations = 0;
    int totalNumLocations = (gameGrid.GetNumRows() * gameGrid.GetNumCols());

    // Checks if all locations of previous grid are same as those of current grid
    for (int iRow = 0; iRow < gameGrid.GetNumRows(); ++iRow)
    {
        for (int iColumn = 0; iColumn < gameGrid.GetNumCols(); ++iColumn)
        {
            if (gameGrid.GetCharAt(iRow, iColumn) == '-') 
            {
                ++numEmptyLocations;
            }
        }
    }

    if (numEmptyLocations == totalNumLocations)
    {
        allDead = true;
    }
    else
    {
        allDead = false;
    }

    return allDead;
}

/**
 * HasStagnated
 * @brief Checks if the current game state has stagnated.
 * True if the previous gen is the same as current gen
 * False if not.
 * 
 * @return true 
 * @return false 
 */
bool Game::HasStagnated()
{
    bool hasStagnated;
    int numSameLocations = 0;
    int totalNumLocations = (gameGrid.GetNumRows() * gameGrid.GetNumCols());

    // Checks if all locations of previous grid are same as those of current grid
    for (int iRow = 0; iRow < gameGrid.GetNumRows(); ++iRow)
    {
        for (int iColumn = 0; iColumn < gameGrid.GetNumCols(); ++iColumn)
        {
            if (gameGrid.GetCharAt(iRow, iColumn) == (copyGrid.GetCharAt(iRow, iColumn))) 
            {
                ++numSameLocations;
            }
        }
    }

    if (numSameLocations == totalNumLocations)
    {
        hasStagnated = true;
    }
    else
    {
        hasStagnated = false;
    }

    return hasStagnated;
}

/**
 * DisplayGrid
 * @brief Displays the game grid
 * 
 */
void Game::DisplayGrid()
{
    cout << endl;
    cout << gameGrid.GetNumRows() << endl;
	for (int iRow = 0; iRow < gameGrid.GetNumRows(); iRow++)
	{
		for (int iColumn = 0; iColumn < gameGrid.GetNumCols(); iColumn++)
		{
			cout << gameGrid.GetCharAt(iRow, iColumn);
		}
		cout << endl;
	}
    cout << endl;
}

/**
 * DetermineGameType
 * @brief Obtains the desired game mode from the user
 * 
 * @return int 
 */
int Game::DetermineGameType()
{
    cout << "Which type of game would you like to play? (respond with the number associated with each mode)" << endl;
    cout << "1: Classic" << endl;
    cout << "2: Doughnut" << endl;
    cout << "3: Mirror" << endl;
    cout << "Your Choice: ";

    int userChoice = 0;
    cin >> userChoice;

    return userChoice;
}