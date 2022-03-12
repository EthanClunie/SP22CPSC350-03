#ifndef GAMESIM_H
#define GAMESIM_H

#include "BoundaryMode.h"
#include "GameModes.h"
#include "GameBoards.h"
#include "FileHandler.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

class GameSim
{
    private:
        GameBoards *mainBoard;
        GameBoards *copyBoard;

        GameModes gameMode;

        BoundaryMode bMode;
        bool isRandomBoardOrMapFile; // 0 -> mapfile, 1 -> random
        int delayType;

        void GameLoop();
        
        bool HasStagnated();

        void SwapBoardsPointers(GameBoards **Grid1, GameBoards **Grid2);

        void DetermineDelayType();
        void PerfromDelayType(int userDelayType);

        void DoBriefPause();
        void PromptEnterBetweenGens();
        void SaveToFile();

        void CloseOutFile();

    public:
        GameSim();
        ~GameSim();

        void Play();
};


#endif