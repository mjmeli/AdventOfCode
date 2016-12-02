## Day 8

#### Problem
Space on the sleigh is limited this year, and so Santa will be bringing his list
as a digital copy. He needs to know how much space it will take up when stored.

##### Part 1

In many programming languages, special characters in strings are escaped.
However, this means that there is a difference between the number of characters
*in the code representation of the string literal* and the number of characters
*in the in-memory string itself*.

For example:

* `""` is 2 characters of code but the string contains zero characters
* `"\\\""` is 6 characters of code but the string contains 2 characters

Assume the following:

* Santa's file is `input.txt`.
* The file contains double-quoted string literals, one on each line.
* The only escape sequences used are `\\` for a backlash, `\"` for a double
quote, and `\x` plus two hexadecimal characters to represent a single character
with that ASCII code.

Disregarding the whitespace in the file, what is **the number of characters of
code for string literals** minus **the number of characters in memory for the
values of the strings** in total for the entire file?

##### Part 2

Now assume that Santa wants to encode the strings in his file so that each
string in the file can be represented in code exactly the same.

The encoding process includes the surrounding double quotes.

For example:

* `""` encodes to `"\"\""`, an increase from 2 characters to 9.
* `"\\\""` encodes to `"\"\\\\\\\"\""`, an increase from 6 characters to 14.

What is **the total number of characters to represent the newly encoded
strings** minus **the number of characters of code in each original string
literal**?

#### Solution
To solve this challenge, I implemented a simple C program to iterate and parse
the strings. In each part, I stepped through the string character by character,
looking either for escape sequences in part 1 or places where escape sequences
were needed in part 2.

While quite verbose compared to what could have been achieved in other
languages, the code is very fast to execute. Overall, the solution is pretty
straightforward.

`day8.c` - C code file that implemented solution
