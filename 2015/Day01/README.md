## Day 1

#### Problem
Santa arrives at an apartment building in the hope of delivering presents to a
specific floor. However, the directions he receives are a bit confusing. He
follows the directions one character at a time. Assume the following:

* The directions are contained in `input.txt`.
* An opening parenthesis, `(`, means he should go up a floor
* A closing parenthesis, `)`, means he should go down a floor.
* He enters the building on floor 0.
* The building is very tall and the basement is very deep.

Based on these assumptions, determine the following:

1. To what floor do the instructions take Santa?
2. What is the position of the first character that causes him to enter the
basement (floor `-1`)? Assume the first character has position 1.

#### Solution
To solve this problem, I implemented a simple scanner using Flex. The scanner
identifies `(`'s and `)`'s and tracks each occurrence with specific counters
that are used to solve the problems.

For example, `floorNum` tracks the current floor Santa is on. Meanwhile,
`enteredBasementAt` tracks the position of the first floor in which Santa enters
the basement.

Scanner: `day1.lex`
