/*
 * Day 21
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "day21.h"

/* Weapons */
const item_t weapons[] = {
    {WEAPON, 8, 4, 0},
    {WEAPON, 10, 5, 0},
    {WEAPON, 25, 6, 0},
    {WEAPON, 40, 7, 0},
    {WEAPON, 74, 8, 0}
};

/* Armor */
const item_t armor[] = {
    {ARMOR, 0, 0, 0},   // empty to reprsent no armor
    {ARMOR, 13, 0, 1},
    {ARMOR, 31, 0, 2},
    {ARMOR, 53, 0, 3},
    {ARMOR, 75, 0, 4},
    {ARMOR, 102, 0, 5}
};

/* Rings */
const item_t rings[] = {
    {RING, 0, 0, 0},  // empty to represent no ring
    {RING, 0, 0, 0},  // can have two no rings
    {RING, 25, 1, 0},
    {RING, 50, 2, 0},
    {RING, 100, 3, 0},
    {RING, 20, 0, 1},
    {RING, 40, 0, 2},
    {RING, 80, 0, 3}
};

// Determines whether the player or boss wins. Returns 1 if player wins, 0 else.
int determineWinner(player_t player, player_t boss)
{
    // Compute the number of turns it takes for each player to win
    int numTurnsPlayer =
        ceil((float)boss.health / MAX(1.0, (player.damage - boss.armor)));
    int numTurnsBoss =
        ceil((float)player.health / MAX(1.0, (boss.damage - player.armor)));

    // Since player goes first, if numTurnsPlayer <= numTurnsBoss, player wins
    return (numTurnsPlayer <= numTurnsBoss);
}

int main(int argc, char **argv) {
    // Create players
    player_t player = {100, 0, 0};  // initial, prior to purchases
    player_t boss = {103, 9, 2};    // from boss.txt

    // Brute force - try every possible combination
    int minGold = INT_MAX;
    int maxGold = INT_MIN;
    int numWeapons = sizeof(weapons) / sizeof(weapons[0]);
    int numArmor = sizeof(armor) / sizeof(armor[0]);
    int numRings = sizeof(rings) / sizeof(rings[0]);
    for (int i = 0; i < numWeapons; i++) {
        for (int j = 0; j < numArmor; j++) {
            for (int k = 0; k < numRings; k++) {
                for (int l = 0; l < numRings; l++) {
                    // Make sure we aren't trying to buy the same ring twice
                    if (k == l) continue;

                    // Compute new gold value and player's damage/armor values
                    int gold =
                        weapons[i].cost + armor[j].cost + rings[k].cost +
                        rings[l].cost;
                    player_t playerNew = player;
                    playerNew.damage =
                        weapons[i].damage + rings[k].damage + rings[l].damage;
                    playerNew.armor =
                        armor[j].armor + rings[k].armor + rings[l].armor;

                    // Determine winner and then check the min/max gold values
                    if (determineWinner(playerNew, boss) == 1) {
                        if (gold < minGold) minGold = gold;
                    }
                    else {
                        if (gold > maxGold)
                            maxGold = gold;
                    }
                }
            }
        }
    }
    printf("Part 1: Least amount of gold to win is %d\n", minGold);
    printf("Part 2: Max amount of gold to lose is %d\n", maxGold);
    return 0;
}
