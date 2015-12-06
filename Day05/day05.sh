#!/bin/bash
cat input.txt |             # read input file
grep -E '([aeiou].*){3,}' | # at least three vowels
grep '\(.\)\1' |            # have a character appear twice in a row
grep -Ev 'ab|cd|pq|xy' |    # no 'naughty' strings
wc -l
