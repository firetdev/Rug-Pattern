// A script to run a simulation which is apparently an infinite loop

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

int main() {
    // Set variables
    int x = 0;
    int y = 0;
    int increment = 1;
    std::vector<std::vector<int>> grid = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}
    };
    bool running = true;

    // Main loop
    while (running) {
        grid[y][x] += 1;  // Increment the cell at (x, y)

        // Update x and y
        x = (x == 0) ? 1 : 0;
        if (x == 1) {
            y += increment;
            increment++;
        }
        while (y > 4)
            y -= 5;

        // Check if every cell has been "tapped"
        int numberDone = 0;
        for (const auto& row : grid) {
            if (row[0] > 0 && row[1] > 0)
                numberDone++;
        }
        if (numberDone >= 5)
            running = false;
    }

    // Output the final grid state
    for (const auto& row : grid) {
        std::cout << row[0] << " " << row[1] << std::endl;
    }

    return 0;
}