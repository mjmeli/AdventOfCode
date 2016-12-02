## Day 5

#### Problem
Santa wants to figure out whether some strings in his text file are naughty or
nice. Santa's text file is `input.txt`.

##### Part 1

Santa uses the following rules to determine whether a string is naughty or nice:

* It contains at least three vowels (`aeiou` only).
* It contains at least one letter that appears twice in a row.
* It does **not** contain the strings `ab`, `cd`, `pq`, `xy`, even if they are
part of one of the other requirements.

How many strings are nice?

##### Part 2

Santa revises his rules to the following:

* It contains a pair of **any** two letters that appears at least twice in the
string without overlapping, like `xyxy` (`xy`) or `aabcdefgaa` (`aa`), but not
like `aaa` (`aa`, but it overlaps).
* It contains at least one letter which repeats with exactly one letter between
them, like `xyx`, `abcdefeghi` (`efe`), or even `aaa`.

How many strings are nice?

#### Solution
The solution I selected was to make use of `grep`, as a solution could be
implemented easily using regular expressions, to filter out strings for each
rule, and then to count the number of strings remaining at the end.

`day05.sh`: script that makes use of `grep`
