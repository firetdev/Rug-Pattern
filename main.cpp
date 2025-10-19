#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

int main() {
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

    while (running) {
        grid[y][x] += 1;

        x = 0 ? x = 1 : x = 0;
        y += increment;
        if (y > 5)
            y -= 5;

        int numberDone = 0;
        for (const auto& row : grid) {
            if (row[0] > 0 && row[1] > 0) {
                numberDone++;
            }
        }
        if (numberDone >= 10) {
            running = false;
        }
    }

    for (const auto& row : grid) {
        std::cout << row[0] << " " << row[1] << std::endl;
    }

    return 0;
}