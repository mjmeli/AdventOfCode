/*
 * Day 17
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Reads an input file to get the number of containers in it
int getNumContainers(char *file)
{
    FILE *fp = fopen(file, "r");
    int i = 0, j;
    while (fscanf(fp, "%d", &j) != EOF) i++;
    return i;
}

int main(int argc, char **argv) {
    // Figure out how many containers we have in the input file to create array
    int numContainers = getNumContainers(argv[1]);
    int *containers = (int*)malloc(numContainers*sizeof(int));  // array
    int liters = atoi(argv[2]);

    // Parse input to get each container size
    FILE *fp = fopen(argv[1], "r");
    for (int i = 0; fscanf(fp, "%d", &containers[i]) != EOF && i < numContainers; i++);

    // Consider 2^n possibilities where each bit represents each container. When
    // bit = 1, container is used. When bit = 0, container is not used. See if
    // each possibility adds up to the required amount and track min # needed.
    int count = 0, minUses = numContainers, minUsesTimes = 0;
    for (int i = 1; i < (1 << numContainers); i++) {
        int this = 0, uses = 0;
        for (int j = 0; j < numContainers; j++) {
            if (i & (1 << j)) {
                this += containers[j];
                uses++;
            }
        }
        if (this == liters) {
            count++;
            if (uses < minUses) {
                minUses = uses;
                minUsesTimes = 1;
            }
            else if (uses == minUses) minUsesTimes++;
        }
    }
    printf("Part 1: %d possibilities\n", count);
    printf("Part 2: %d ways to use the minimum number\n", minUsesTimes);

    return 0;
}
