#include "Maze.h"

Maze::Maze(int w, int h) : width(w), height(h) {
    maze.resize(height, std::vector<int>(width, 1));
}

bool Maze::isValidMove(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height && maze[y][x] == 1;
}

bool Maze::isValidEntranceAndExit(int entranceX, int entranceY, int exitX, int exitY) {
    return maze[entranceY + 1][entranceX] == 0 && maze[exitY - 1][exitX] == 0;
}

void Maze::generateMazeDFS(int startX, int startY) {
    std::stack<Cell> cellStack;
    cellStack.push({ startX, startY });
    maze[startY][startX] = 0;

    while (!cellStack.empty()) {
        Cell current = cellStack.top();
        std::vector<Direction> directions = { UP, DOWN, LEFT, RIGHT };
        random_shuffle(directions.begin(), directions.end());
        bool moved = false;
        for (Direction dir : directions) {
            int newX = current.x;
            int newY = current.y;

            switch (dir) {
            case UP:    newY -= 2; break;
            case DOWN:  newY += 2; break;
            case LEFT:  newX -= 2; break;
            case RIGHT: newX += 2; break;
            }

            if (isValidMove (newX, newY)) {
                maze[newY][newX] = 0;
                maze[(current.y + newY) / 2][(current.x + newX) / 2] = 0;
                cellStack.push({ newX, newY });
                moved = true;
                break;
            }
        }

        if (!moved) {
            cellStack.pop();
        }
    }
}

void Maze::setEntranceAndExit() {
    entranceY = 0;
    entranceX = std::rand() % (width - 2) + 1;
    exitY = height - 1;
    exitX = std::rand() % (width - 2) + 1;

    if (!isValidEntranceAndExit(entranceX, entranceY, exitX, exitY)) {
        generateMaze();
        return;
    }
    else {
        maze[entranceY][entranceX] = 2;
        maze[exitY][exitX] = 3;
    }
    while (true) {
        int x = std::rand() % width;
        int y = std::rand() % height;

        if (maze[y][x] == 0) {
            maze[y][x] = 4;
            break;
        }
    }
}

void Maze::generateMaze() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    generateMazeDFS(1, 1);
    setEntranceAndExit();
}

void Maze::printMaze() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            switch (maze[y][x]) {
            case 0: std::cout << "  "; break; 
            case 1: std::cout << "* "; break;
            case 2: std::cout << "E "; break; // entrance
            case 3: std::cout << "X "; break; // exit
            case 4: std::cout << "T "; break; // treasure
            }
        }
        std::cout << std::endl;
    }
}

