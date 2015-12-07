#!/bin/bash

# Part 1
cat input.txt |             # read input file
grep -E '([aeiou].*){3,}' | # at least three vowels
grep -E '([a-z])\1' |       # have a letter appear twice in a row
grep -Ev 'ab|cd|pq|xy' |    # no 'naughty' strings
wc -l

# Part 2
cat input.txt |
grep -E '(..).*\1' |        # pair of letters that repeats, non-overlapping
grep -E '(.).\1' |          # repeating letters with exactly one letter between
wc -l
