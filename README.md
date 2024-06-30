# Maze Generator Application

## Overview

This application generates a maze using the Depth-First Search (DFS) algorithm. The maze includes a single entrance, exit, and a randomly placed treasure.

## Project Structure
- `Maze.h` - Header file containing the declarations of the `Maze` class and its methods.
- `Maze.cpp` - File with the implementation of the `Maze` class methods.
- `main.cpp` - Main program file containing the `main` function.
- `Makefile` - File to simplify the build process.

## Efficiency

### Time Complexity

- **Maze Generation (DFS)**: O(n), where n is the number of cells in the maze. Each cell is visited exactly once during the maze generation process.

### Space Complexity

- **Stack Storage**: O(n), due to the stack used for DFS.
- **Maze Grid Storage**: O(n), for storing the maze grid.

### Why This Solution is Efficient
- Optimal Path Creation: DFS ensures a unique solution path, reducing dead-ends and loops.
- Randomized Paths: Randomizing the direction of movements during DFS ensures a varied and interesting maze structure.
- Linear Complexity: Both time and space complexity are linear, making the solution scalable for larger mazes.

## How to Compile

1. Ensure you have a `g++` compiler and `make` utility installed on your system.

2. Open your terminal or command prompt.

3. Navigate to the directory where your project files (Maze.h, Maze.cpp, main.cpp, and Makefile) are located.

4. Compile the project by running the following command:
    ```sh
    make

## How to Run

1. Once compilation is successful, run the executable by executing:
    ```sh
    cd bin/
    ./maze

2. Follow the prompts to enter the width and height of the maze:
    ```sh
    Enter maze width: 21
    Enter maze height: 21

## Example Usage

- `*` represents walls.
- ` `represents paths.
- `E` represents the entrance.
- `X` represents the exit.
- `T` represents the treasure.

## Additional Information
- The entrance and exit are placed at random positions on the top and bottom rows, respectively.
- The treasure is placed at a random position within the maze, ensuring it is on a path.