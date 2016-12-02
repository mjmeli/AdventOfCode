/*
 * Day 18
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Enable the corners as they are stuck on
void stickCornersOn(bool **lights, int gridSize)
{
    lights[1][1] = true;
    lights[1][gridSize] = true;
    lights[gridSize][1] = true;
    lights[gridSize][gridSize] = true;
}

// Solve, with different logic for Part 1/2
int getAnswer(char * fileName, int gridSize, int numSteps, int part)
{
    // Parse input file into 2D array with a ring of 1 buffer around to avoid
    // bounds checking later
    bool **lights = (bool**)malloc((gridSize + 2) * sizeof(bool*));
    FILE *fp = fopen(fileName, "r");
    char *str = (char *)malloc((gridSize + 1) * sizeof(char));
    for (int i = 0; i < gridSize + 2; i++) {
        lights[i] = (bool*)malloc((gridSize + 2) * sizeof(bool));
        for (int j = 0; (i == 0 || i == gridSize + 1) && j < gridSize + 2; j++)
            lights[i][j] = false;
        if (i > 0 && fscanf(fp, "%s", str) != EOF) {
            lights[i][0] = false;
            lights[i][gridSize-1] = false;
            for (int j = 0; j < gridSize; j++)
                if (str[j] == '.') lights[i][j+1] = false;
                else if (str[j] == '#') lights[i][j+1] = true;
        }
    }

    // If we are Part 2, "stick on the corners"
    if (part == 2) stickCornersOn(lights, gridSize);

    // Perform the # of animation steps necessary
    for (int i = 0; i < numSteps; i++) {
        // Create a copy of the grid so that the changes can occur at once
        bool **lightsCopy = (bool**)malloc((gridSize + 2) * sizeof(bool*));
        for (int j = 0; j < gridSize + 2; j++) {
            lightsCopy[j] = (bool*)malloc((gridSize + 2) * sizeof(bool));
            for (int k = 0; k < gridSize + 2; k++)
                lightsCopy[j][k] = lights[j][k];
        }

        // Update the original grid based on the algorithm
        for (int j = 1; j <= gridSize ; j++) {
            for (int k = 1; k <= gridSize; k++) {
                int onCount = 0;
                for (int l = -1; l <= 1; l++) {
                    for (int m = -1; m <= 1; m++) {
                        if (!(l == 0 && m == 0))
                            onCount += lightsCopy[j+l][k+m];  // count neighbors
                    }
                }
                lights[j][k] = (lights[j][k] == true) ?
                               (onCount == 2 || onCount == 3) : (onCount == 3);
            }
        }

        // If we are Part 2, "stick on the corners"
        if (part == 2) stickCornersOn(lights, gridSize);

        // Avoid memory leaks
        for (int j = 0; j < gridSize + 2; j++) free(lightsCopy[j]);
        free(lightsCopy);
    }

    // Count number of lights on
    int onCount = 0;
    for (int i = 1; i <= gridSize; i++)
        for (int j = 1; j <= gridSize; j++)
            onCount += lights[i][j];

    // Avoid memory leaks
    for (int j = 0; j < gridSize + 2; j++) free(lights[j]);
    free(lights);

    return onCount;
}

int main(int argc, char **argv) {
    printf("Part 1: %d lights are on\n",
            getAnswer(argv[1], atoi(argv[2]), atoi(argv[3]), 1));   // Part 1
    printf("Part 2: %d lights are on\n",
            getAnswer(argv[1], atoi(argv[2]), atoi(argv[3]), 2));   // Part 2
    return 0;
}
