#include <iostream>
#include <fstream>
#include <vector>
// handy maze generator: https://www.dcode.fr/maze-generator

class Maze {
private:
    std::vector<std::vector<char> > maze;
    int startRow, startCol;

public:
    Maze(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }

        std::string line;
        while (getline(file, line)) {
            std::vector<char> row(line.begin(), line.end());
            maze.push_back(row);
        }
        file.close();

        // Find the starting point
        for (int i = 0; i < maze.size(); ++i) {
            for (int j = 0; j < maze[i].size(); ++j) {
                if (maze[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }
            }
        }
    }

    void printMaze() const {
        for(int i=0; i<maze.size(); i++){
            std::vector<char>  row = maze[i];
            for(int x=0; x<row.size(); x++){
                char cell = row[x];
                std::cout << cell;
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<char> >& getMaze() {
        return maze;
    }

    int getStartRow() const {
        return startRow;
    }

    int getStartCol() const {
        return startCol;
    }
};

class MazeSolver {
    private:
        std::vector<std::vector<char>>& maze;
        
        bool solve(int row, int col) {

            // implement recursive solve function here
            // When solving a recursive problem:
            //1. address the base-case (i.e. the cell we are on is the end, or we are out of bounds (any reasons to stop the recursion))
            //2. find the recursive relation (break the problem into sub problems).
            //3. combine the results of the recursion (often happens together with 2)

            return false;
        }
    
    public:
        MazeSolver(std::vector<std::vector<char>>& maze) : maze(maze) {}
    
        void findPath(int startRow, int startCol) {
            if (!solve(startRow, startCol)) {
                std::cout << "No path found." << std::endl;
            }
        }
    };


int main() {
    try {
        Maze maze("./maps/10x10.map");
        
        std::cout << "Original Maze:" << std::endl;
        maze.printMaze();


    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}