/*
Header file for Game class.
Contains the function definitions and any necessary private members
*/

using namespace std;

class Game
{
    public:
        Game();
        ~Game();
        void Play();

        short GetNumRows();

    private:
        short numRows;
        short numColumns;

        char **gameGrid;
        char **copyGrid;

        void SetNumRowsAndColumns();
        void InitGrid();
        void DisplayGrid();
        double CheckValidInitWorldPop(double population);
        void SwapGridPointer(char **Grid1, char **Grid2);

        short FindNumNeighbors() {} //no implementation in this class
        void DensityPlacement(double popDensity);
        bool AllDead();
        bool HasStagnated();
};