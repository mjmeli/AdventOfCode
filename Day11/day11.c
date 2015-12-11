/*
 * Day 11
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>

// Increments a string of length n starting at the ith-to-last character
char * increment(char str[], int i, int n)
{
    if (str[n-i] == 'z') {
        str[n-i] = 'a';
        increment(str, i+1, n); // recursion
    }
    else str[n-i]++;
    return str;
}

// Verifies that a string fits the password requirements
int verifyPassword(char str[], int n)
{
    int pass1=0, pass2=1, pass3=0;
    for (int i = 0; i < n; i++) {
        if (str[i+1] == (str[i] + 1) && str[i+2] == (str[i+1] + 1))
            pass1 = 1;
        if (str[i] == 'i' || str[i] == 'o' || str[i] == 'l')
            pass2 = 0;
    }
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i-1]) {
            i++;
            pass3++;
        }
    }
    return pass1 && pass2 && (pass3 >= 2);
}

int main(int argc, char **argv) {
    char input[] = "hepxcrrq";
    while (!verifyPassword(increment(input, 1, 8), 8));
    printf("Santa's first new password should be %s.\n", input);
    while (!verifyPassword(increment(input, 1, 8), 8));
    printf("Santa's second new password should be %s.\n", input);
    return 0;
}
