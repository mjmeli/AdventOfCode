/*
 * Day 15
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "day15.h"

ingredient_t *ingredients = NULL;  // linked list containing ingredients

// Compute the score of a cookie
int computeCookieScore(cookie_t cookie)
{
    return POS(cookie.capacity) * POS(cookie.durability) * POS(cookie.flavor) * POS(cookie.texture);
}

// Generic method for creating a cookie with a certain number of ingredients
int createCookie(cookie_t *cookie, int numIngredients, int remaining, int part)
{
    int max = 0;
    cookie_t newCookie = *cookie, maxCookie = *cookie;
    for (int i = numIngredients > 1 ? 0 : remaining; i <= remaining; i++, newCookie = *cookie) {
        // Compute cookie value contributed by this/these ingredient(s)
        ingredient_t *ingredient = getIngredient(ingredients, numIngredients-1);
        newCookie.capacity += i * ingredient->capacity;
        newCookie.durability += i * ingredient->durability;
        newCookie.flavor += i * ingredient->flavor;
        newCookie.texture += i * ingredient->texture;
        newCookie.calories += i * ingredient->calories;

        // Recursively compute cookie contribution for remaining ingredients
        if (numIngredients > 1) {
            createCookie(&newCookie, numIngredients-1, remaining-i, part);
        }

        // Check if this score is max
        int this = computeCookieScore(newCookie);
        if (this > max && (part == 1 || (part == 2 && newCookie.calories == 500))) {
            max = this;
            maxCookie = newCookie;
        }
    }
    *cookie = maxCookie;    // update cookie with max cookie
    return max;
}

int main(int argc, char **argv) {
    FILE * f = fopen(argv[1], "r");
    char str[20];
    int lcnt = 1, *ingredientField;
    ingredient_t * ingredient;

    // Parse input - fscanf stops on whitespace, which we can take advantage of
    while(fscanf(f, "%s", str) != EOF) {
        switch (lcnt++ % LINE_LENGTH) {
            case INGREDIENT_NAME:
                ingredient = (ingredient_t*)malloc(sizeof(ingredient_t));
                addIngredient(&ingredients, ingredient);
                ingredientField = (int*)ingredient; // point to first field in struct
                break;
            case CAPACITY:
            case DURABILITY:
            case FLAVOR:
            case TEXTURE:
            case CALORIES:
                *ingredientField++ = atoi(str); // incrementing pointer to each int field
            default: break;
        }
    }

    // Solve the problem using brute force and recursion
    cookie_t cookie1 = {0};
    int part1 = createCookie(&cookie1, getCount(ingredients), 100, 1);
    cookie_t cookie2 = {0};
    int part2 = createCookie(&cookie2, getCount(ingredients), 100, 2);
    printf("Part 1 max score = %d\nPart 2 max score = %d\n", part1, part2);
    return 0;
}
