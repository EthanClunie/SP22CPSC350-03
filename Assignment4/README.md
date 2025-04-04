## Ethan Clunie, Samuel Bernsen
## Description: This project is an implementation of Conway's Game of Life simulation using the C++ programming language. We created this project for our Data Structures and Algorithms course and implemented three "game modes": Classic, Donut, and Mirror. Each game mode will change how border behaviors occur within the simulation.
## Deliverables: mainprogram.cpp, FileIO.h/cpp, Game.h/cpp, Classic.h/cpp, Doughnut.h/cpp, Mirror.h/cpp
#### Ref for main.cpp: None
#### Ref for FileHandler Class: Max Starreveld (for fileWriter.eof())
#### Ref for GameSim Class: https://stackoverflow.com/questions/15672805/c-swapping-pointers, https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/, https://stackoverflow.com/questions/12657962, how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored, https://stackoverflow.com/questions/15672805/c-swapping-pointers, https://askubuntu.com/questions/906742/what-is-sh-1-pause-not-found
#### Ref for GameModes Class: None
#### Ref for GameBoards Class: None
#### Ref for BoundaryModes.h: Visual Programming Course (Enums)
##### Emergency Exit strategy implemented in GameSim.cpp which doesn't allow the simulation to exceed 150 generations
##### Known Errors: Segmentation Fault when attempting at save to file. Otherwise, no known errors
