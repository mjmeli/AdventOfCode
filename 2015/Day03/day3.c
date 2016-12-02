/*
 * Day 03
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include "uthash.h"

// X-Y position
typedef struct {
    int x;
    int y;
} location_t ;

// Structure to hash
typedef struct {
    location_t loc;     // key
    int visits;         // value
    UT_hash_handle hh;  // makes this structure hashable
} house_t;

// Hash tables
house_t *housesPart1 = NULL;  // Santa in part 1
house_t *housesPart2 = NULL;  // Two Santas in part 2

// Visit a house. If the house is not in the hash table, at it. If it is,
// increase the count
void visitHouse(house_t **houses, location_t loc) {
    house_t *h;
    // Check if the location is already in the hash table
    HASH_FIND(hh, *houses, &loc, sizeof(location_t), h);
    if (h == NULL) {
      h = (house_t *)malloc(sizeof(house_t));
      h->loc.x = loc.x;
      h->loc.y = loc.y;
      h->visits = 1;
      HASH_ADD(hh, *houses, loc, sizeof(location_t), h);
    }
    else {
        h->visits += 1;     // increase the visit count
    }
}

// Count the number of houses visited.
int countHouses(house_t **houses) {
    return HASH_COUNT(*houses);
}

int main(int argc, char **argv) {
    FILE * f = fopen(argv[1], "r");
    char c;
    int whichSanta = 0;

    // Begin at the first house
    location_t loc = {0, 0};
    location_t locPart2[2] = {{0,0},{0,0}}; // Part 2 locations for Santa and Robot, respectively
    visitHouse(&housesPart1, loc);
    visitHouse(&housesPart2, locPart2[0]);
    visitHouse(&housesPart2, locPart2[1]);

    // Use drunk elf's directions
    while((c = (char)fgetc(f)) != EOF) {
        switch (c) {
            case '^':
                loc.y += 1;
                locPart2[whichSanta].y += 1;
                break;
            case 'v':
                loc.y -= 1;
                locPart2[whichSanta].y -= 1;
                break;
            case '>':
                loc.x += 1;
                locPart2[whichSanta].x += 1;
                break;
            case '<':
                loc.x -= 1;
                locPart2[whichSanta].x -= 1;
                break;
            default: break;
        }
        visitHouse(&housesPart1, loc);
        visitHouse(&housesPart2, locPart2[whichSanta]);
        whichSanta = (whichSanta + 1) % 2;
    }

    printf("In part 1, Santa visited %d houses!\n", countHouses(&housesPart1));
    printf("In part 2, the two Santas visited %d houses!\n",
            countHouses(&housesPart2));
    fclose(f);
    return 0;
}
