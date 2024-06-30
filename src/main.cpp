#include "Maze.h"

int main() {
    int width, height;
    std::cout << "Enter maze width: ";
    std::cin >> width;
    std::cout << "Enter maze height: ";
    std::cin >> height;
    std::cout << std::endl;

    if (height % 2 == 0) height += 1;
    if (width % 2 == 0) width += 1;

    Maze maze(width, height);
    maze.generateMaze();
    maze.printMaze();
    return 0;
}
