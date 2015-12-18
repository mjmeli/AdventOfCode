/*
 * Day 18
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Solve, with different logic for Part 1/2
int getAnswer(char * fileName, int gridSize, int numSteps, int part)
{
    // Parse input file into 2D array
    bool **lights = (bool**)malloc(gridSize * sizeof(bool*));
    FILE *fp = fopen(fileName, "r");
    char *str = (char *)malloc((gridSize + 1) * sizeof(char));
    for (int i = 0; fscanf(fp, "%s", str) != EOF && i < gridSize; i++) {
        lights[i] = (bool*)malloc(gridSize * sizeof(bool));
        for (int j = 0; j < gridSize; j++)
            if (str[j] == '.') lights[i][j] = false;
            else if (str[j] == '#') lights[i][j] = true;
    }

    // If we are Part 2, "stick on the corners"
    if (part == 2) {
        lights[0][0] = true;
        lights[0][gridSize-1] = true;
        lights[gridSize-1][0] = true;
        lights[gridSize-1][gridSize-1] = true;
    }

    // Perform the # of animation steps necessary
    for (int i = 0; i < numSteps; i++) {
        // Create a copy of the grid so that the changes can occur at once
        bool **lightsCopy = (bool**)malloc(gridSize * sizeof(bool*));
        for (int j = 0; j < gridSize; j++) {
            lightsCopy[j] = (bool*)malloc(gridSize * sizeof(bool));
            for (int k = 0; k < gridSize; k++)
                lightsCopy[j][k] = lights[j][k];
        }

        // Update the original grid based on the algorithm
        for (int j = 0; j < gridSize ; j++) {
            for (int k = 0; k < gridSize; k++) {
                int onCount = 0;
                for (int l = -1; l <= 1; l++) {
                    for (int m = -1; m <= 1; m++) {
                        if (!(l == 0 && m == 0) &&  // do not count itself
                            j + l >= 0 && j + l < gridSize && // stay in up/down
                            k + m >= 0 && k + m < gridSize)   // stay in left/right
                            {
                                onCount += lightsCopy[j+l][k+m];
                            }
                    }
                }
                lights[j][k] = (lights[j][k] == true) ?
                               (onCount == 2 || onCount == 3) : (onCount == 3);
            }
        }

        // If we are Part 2, "stick on the corners"
        if (part == 2) {
            lights[0][0] = true;
            lights[0][gridSize-1] = true;
            lights[gridSize-1][0] = true;
            lights[gridSize-1][gridSize-1] = true;
        }

        // Avoid memory leaks
        for (int j = 0; j < gridSize; j++) free(lightsCopy[j]);
        free(lightsCopy);
    }

    // Count number of lights on
    int onCount = 0;
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            onCount += lights[i][j];

    // Avoid memory leaks
    for (int j = 0; j < gridSize; j++) free(lights[j]);
    free(lights);

    return onCount;
}

int main(int argc, char **argv) {
    int gridSize = atoi(argv[2]);
    int numSteps = atoi(argv[3]);
    printf("Part 1: %d lights are on\n", getAnswer(argv[1], gridSize, numSteps, 1));
    printf("Part 2: %d lights are on\n", getAnswer(argv[1], gridSize, numSteps, 2));
    return 0;
}
