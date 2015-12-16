/*
 * Day 16
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day16.h"

// Maps a trait to the number of that trait that our Sue has.
int mapTrait(char *str)
{
    int len = strlen(str);
    if (len == 12) return TRAIT_POMERANIANS;
    if (len == 8) return TRAIT_VIZSLAS;
    if (len == 7) return TRAIT_AKITAS;
    if (len == 6) return TRAIT_TREES;
    if (len == 5) {
        switch (str[2]) {
            case 't': return TRAIT_CATS;
            case 'r': return TRAIT_CARS;
            default: return -1;
        }
    }
    if (len == 9) {
        switch (str[0]) {
            case 'c': return TRAIT_CHILDREN;
            case 's': return TRAIT_SAMOYEDS;
            case 'g': return TRAIT_GOLDFISH;
            case 'p': return TRAIT_PERFUMES;
            default: return -1;
        }
    }
    return -1;
}

// Maps a string trait to comparison operation that must be performed.
// -1 = fewer than, 0 = equal, 1 = greater than
int mapOperation(char *str)
{
    int len = strlen(str);
    if (len == 12) return OP_POMERANIANS;
    if (len == 6) return OP_TREES;
    if (len == 5 && str[2] == 't') return OP_CATS;
    if (len == 9 && str[0] == 'g') return OP_GOLDFISH;
    return EQUAL;
}

// Find Sue logic for Parts 1 and 2.
int findSue(char * file, int part)
{
    FILE * f = fopen(file, "r");
    char str[20];
    int lcnt = 0, sueNum = 0, lastTrait = 0, lastOperation = EQUAL, found = 0;
    // Parse input - fscanf stops on whitespace, which we can take advantage of
    while(fscanf(f, "%s", str) != EOF && found != 3) {
        switch (lcnt++ % LINE_LENGTH) {
            case SUE_NUM:
                sueNum = atoi(str);
                found = 0;     // searching
                break;
            case TRAIT_1_NAME:
            case TRAIT_2_NAME:
            case TRAIT_3_NAME:
                lastTrait = mapTrait(str);
                if (part == 2) lastOperation = mapOperation(str);
                break;
            case TRAIT_1_NUM:
            case TRAIT_2_NUM:
            case TRAIT_3_NUM:
                if (lastOperation == EQUAL && atoi(str) == lastTrait) found++;
                if (lastOperation == FEWER_THAN && atoi(str) < lastTrait) found++;
                if (lastOperation == GREATER_THAN && atoi(str) > lastTrait) found++;
            default: break;
        }
    }
    fclose(f);
    return sueNum;
}

int main(int argc, char **argv) {
    printf("Part 1's Sue number is %d.\n", findSue(argv[1], 1));  // Part 2
    printf("Part 2's Sue number is %d.\n", findSue(argv[1], 2));  // Part 2
    return 0;
}
