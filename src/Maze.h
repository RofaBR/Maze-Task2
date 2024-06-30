#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Cell {
    int x, y;
};

class Maze {
private:
    int width, height;
    std::vector<std::vector<int>> maze;
    int entranceX, entranceY, exitX, exitY;

    bool isValidMove(int x, int y);
    bool isValidEntranceAndExit(int entranceX, int entranceY, int exitX, int exitY);
    void generateMazeDFS(int startX, int startY);
    void setEntranceAndExit();

public:
    Maze(int w, int h);
    void generateMaze();
    void printMaze();
};

#endif // MAZE_H
