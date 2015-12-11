/*
 * Day 08
 * Advent of Code
 * Michael Meli
 *
 */

#include <stdio.h>
#include <string.h>

// Part 1 - Compute the difference in code representation of strings with
// the in-memory representation of strings.
void Part1(char * file)
{
    FILE * f = fopen(file, "r");
    char str[100];
    int codeLength=0, memLength=0;
    while(fscanf(f, "%s", str) != EOF){
        // Start by naively assuming memory length is the same
        int len = strlen(str);
        memLength += len;
        codeLength += len;

        // Account for in-memory differences from escapes
        memLength -= 2;     // opening/closing quotes
        for (int i = 0; i < len; i++){
            if (str[i] == '\\') {
                switch (str[i+1]) {
                    case '\\':
                    case '\"':
                        memLength -= 1;
                        i = i + 1;
                        break;
                    case 'x':
                        memLength -= 3;
                        i = i + 3;
                        break;
                    default: break;
                }
            }
        }
    }
    fclose(f);
    printf("Part 1 difference = %d\n", codeLength - memLength);
}

// Part 2 - Compute the difference in the encoded strings and the original
// string literals.
void Part2(char * file)
{
    FILE * f = fopen(file, "r");
    char str[100];
    int codeLength=0, encLength=0;
    while(fscanf(f, "%s", str) != EOF){
        // Start by naively assuming encoded length is the same
        int len = strlen(str);
        codeLength += len;
        encLength += len;

        // Account for encoded differences from quotes and escapes
        encLength += 2;     // opening/closing quotes
        for (int i = 0; i < len; i++){
            if (str[i] == '\"' || str[i] == '\\') {
                encLength += 1;
            }
        }
    }
    fclose(f);
    printf("Part 2 difference = %d\n", encLength - codeLength);
}

int main(int argc, char **argv) {
    Part1(argv[1]);
    Part2(argv[1]);
    return 0;
}
